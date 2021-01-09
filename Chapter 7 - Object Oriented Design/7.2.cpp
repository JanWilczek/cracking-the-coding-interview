class Employee : public CallHandler  {
public:	
    virtual ~Employee() = 0;
	virtual Employee& getSupervisor() = 0;
};

class CallHandler {
public:
	virtual bool canHandle(Call) = 0;
	virtual void handleCall(Call) = 0;
};

class Call {
};

class Fresher : public Employee, public CallHandler {
public:
	Fresher(TechLead& supervisor);
    virtual ~Fresher() override = default;

	virtual Employee& getSupervisor() noexcept override
	{
		return supervisor;
	}
private:
	TechLead& supervisor;
};

class TechLead : public Employee
{
public:
	TechLead(ProductManager& supervisor);
    virtual ~TechLead() override = default;
    virtual Employee& getSupervisor() noexcept override
    {
        return supervisor;
    }
private:
	ProductManager& supervisor;
};

class ProductManager : public Employee, public CallHandler
{
public:
	virtual ~ProductManager() = default;
	virtual Employee& getSupervisor() noexcept(false) override
	{
		throw NoSupervisorException{"The product manager has no supervisor."};
	}
};

Employee& getAFresher();

CallHandler& getCallHandler(Call c)
{
	auto employee = getAFresher();

	try {
        while (!employee.canHandle(c))
        {
            employee = employee.getSupervisor();
        }
        
        return employee;
    }
    catch (NoSupervisorException& nse)
    {
        // Throw a new exception, retry call handling in a loop, or return a CallHandler that informs the user that the call cannot be handled.
    }
}

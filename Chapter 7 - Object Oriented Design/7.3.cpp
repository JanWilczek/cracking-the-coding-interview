class Jukebox
{
public:
	void insertCoin();
	void selectTune(TuneId);
	
private:
	void play();
	std::atomic<int> coinsInserted = 0;
	TuneId selectedTune;
	TuneProvider tuneProvider;
	AudioOutput audioOutput;
};

void Jukebox::insertCoin()
{	
	coinsInserted++;
	if (selectedTune != TuneId::None)
	{
		play();
	}
}

void Jukebox::selectTune(TuneId id)
{
	selectedTune = TuneId;
	if (coinsInserted)
	{
		play();
	}
}

void Jukebox::play()
{
    coinsInserted--;
	auto tune = tuneProvider.getTune(selectedTune);
	audioOutput.play(tune);
		
	selectedTune = TuneId::None;  // Ignore any button presses while playing
}

class TuneId{
public:
	TuneId(std::string buttonName);
	TuneId& operator=(TuneId);
	TuneId& operator=(const std::string& buttonName);

	std::string getId() {return tuneId;};

static const std::string None = "";

private:
	std::string tuneId;
};

class AudioOutput{	// e.g., sound card drivers, specialized library adapter, etc.
public:
	virtual ~AudioOutput() = 0;
	virtual void play(AudioFile) = 0;
};

class TuneProvider {	// e.g., a database lookup
public:
	virtual ~TuneProvider () = 0;
	virtual AudioFile getTune(TuneId) = 0;
};


#include <iostream>
#include <memory>

struct Node
{
    std::shared_ptr<int> next{nullptr};
    int data;
    Node(int d) : data{d} {};
    void appendToTail(int d)
    {
        
    }
};

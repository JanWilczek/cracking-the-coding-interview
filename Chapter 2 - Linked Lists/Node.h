struct Node {
    Node * next = nullptr;
    int data;
    Node(int d) : data{d} {}
    void appendToTail(int d) {
        auto n = this;
        while (n->next != nullptr) n = n->next;
        n->next = new Node{d};
    }
};

Node* deleteNode(Node* head, int d)
{
    if (!head) return nullptr;

    bool shouldDeleteHead = false;
    if (head->data == d) shouldDeleteHead = true;
    
    auto n = head;

    while (n->next)
    {
        if (n->next->data == d)
        {
            auto nodeToDelete = n->next;
            n->next = n->next->next;
            delete nodeToDelete;
        }

        n = n->next;
    }
}

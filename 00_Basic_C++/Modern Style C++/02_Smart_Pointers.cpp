#include <iostream>
#include <memory>
using namespace std;

struct Node
{
    int data;
    Node(int val) : data(val) {}
};

int main()
{
    // Unique Pointer
    unique_ptr<Node> uNode = make_unique<Node>(10);
    cout << "Unique: " << uNode->data << "\n";

    // Shared Pointer
    shared_ptr<Node> sNode1 = make_shared<Node>(20);
    shared_ptr<Node> sNode2 = sNode1;
    cout << "Shared (sNode1): " << sNode1->data << "\n";
    cout << "Shared (sNode2): " << sNode2->data << "\n";
    cout << "Shared Use Count: " << sNode1.use_count() << "\n";

    return 0;
}

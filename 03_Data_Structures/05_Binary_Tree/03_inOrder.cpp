#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node *createTree(vector<int> v)
{
    idx++;
    if (v[idx] == -1)
        return NULL;
    Node *root = new Node(v[idx]);
    root->left = createTree(v);
    root->right = createTree(v);
    return root;
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    vector<int> vec = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = createTree(vec);

    inOrder(root);
}
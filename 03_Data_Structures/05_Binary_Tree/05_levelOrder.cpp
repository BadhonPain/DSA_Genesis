#include <iostream>
#include <vector>
#include <queue>

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

void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        cout << current->data << " ";
        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
    }
}

int main()
{
    vector<int> vec = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = createTree(vec);

    levelOrder(root);
}
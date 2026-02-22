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

Node *insert(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);
    if (root->data > val)
        root->left = insert(root->left, val);
    else if (root->data < val)
        root->right = insert(root->right, val);
    return root;
}

Node *createBSTWithMinimalHeight(vector<int> &v)
{
    Node *root = new Node(v[v.size() / 2]);

    for (auto i : v)
    {
        root = insert(root, i);
    }

    return root;
}

int BstHeight(Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(BstHeight(root->left), BstHeight(root->right));
}

void levelOrderTraversal(Node *root)
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
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    Node *root = createBSTWithMinimalHeight(v);
    cout << "Height of the BST: " << BstHeight(root) << endl;
    levelOrderTraversal(root);
}
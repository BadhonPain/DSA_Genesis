#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// here a BST is created from a vector

class node
{
public:
    int val;
    node *left;
    node *right;

    node(int item)
    {
        val = item;
        left = right = NULL;
    }
};

node *insert(node *root, int item)
{
    if (root == NULL)
        return new node(item);
    if (item < root->val)
        root->left = insert(root->left, item);
    else
        root->right = insert(root->right, item);
    return root;
}

node *BST(vector<int> &v)
{
    node *root = NULL;

    for (auto x : v)
        root = insert(root, x);

    return root;
}

void inOrder(node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main()
{
    vector<int> v = {6, 4, 3, 5, 1, 2};
    node *root = BST(v);
    cout << "Created BST: ";
    inOrder(root);
    cout << endl;
    node *newRoot = insert(root, 87);
    cout << "New BST: ";
    inOrder(newRoot);
    cout << endl;
}
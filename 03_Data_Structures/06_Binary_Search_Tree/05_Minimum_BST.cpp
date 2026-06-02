#include <iostream>
#include <vector>
using namespace std;

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

node *minBST(node *root)
{
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}


int main()
{
    vector<int> v = {6, 4, 3, 5, 1, 2};
    node *root = BST(v);
    cout << "Minimum is BST: ";
    cout << minBST(root)->val << endl;
}
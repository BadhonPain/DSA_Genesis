#include <iostream>
using namespace std;

#include <iostream>
#include <vector>
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

bool Search(node *root, int item)
{
    if (root == NULL)
        return false;

    if (root->val == item)
        return true;

    else if (root->val > item)
        return Search(root->left, item);
    else
        return Search(root->right, item);
}

int main()
{
    vector<int> v = {6, 4, 3, 5, 1, 2};
    node *root = BST(v);

    cout << Search(root, 9) << endl;
}
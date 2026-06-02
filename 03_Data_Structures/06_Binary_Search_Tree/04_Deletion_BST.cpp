#include <iostream>
#include <vector>
#include <algorithm>
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

node *minValueNode(node *root)
{
    node *curr = root;
    while (curr && curr->left != NULL)
        curr = curr->left;
    return curr;
}

node *deleteNode(node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor
        node *temp = minValueNode(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
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
    cout << "Original BST: ";
    inOrder(root);
    cout << endl;

    node *newRoot = deleteNode(root, 4);
    cout << "After Deletion of 4: ";
    inOrder(newRoot);
    cout << endl;
}

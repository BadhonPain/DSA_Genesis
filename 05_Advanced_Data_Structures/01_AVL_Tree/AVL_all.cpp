#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Node
{
public:
    int key, height;
    Node *left, *right;
    Node(int val)
    {
        key = val;
        height = 1;
        left = right = nullptr;
    }
};

class AVL
{
    Node *root = nullptr;

    int tree_height(Node *node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    Node *rotate_right(Node *y)
    {
        Node *x = y->left;
        Node *B = x->right;
        x->right = y;
        y->left = B;

        y->height = 1 + max(tree_height(y->left), tree_height(y->right));
        x->height = 1 + max(tree_height(x->left), tree_height(x->right));
        return x;
    }

    Node *rotate_left(Node *x)
    {
        Node *y = x->right;
        Node *B = y->left;
        y->left = x;
        x->right = B;

        x->height = 1 + max(tree_height(x->left), tree_height(x->right));
        y->height = 1 + max(tree_height(y->left), tree_height(y->right));
        return y;
    }

    Node *retrace(Node *node)
    {
        if (node == nullptr)
            return nullptr;

        node->height = 1 + max(tree_height(node->left), tree_height(node->right));

        int actual_bf = tree_height(node->left) - tree_height(node->right);

        // Left Heavy Tree (LL or LR)
        if (actual_bf > 1)
        {
            int left_bf = tree_height(node->left->left) - tree_height(node->left->right);
            if (left_bf < 0) // LR Rotation
                node->left = rotate_left(node->left);
            return rotate_right(node);
        }
        // Right Heavy Tree (RR or RL)
        else if (actual_bf < -1)
        {
            int right_bf = tree_height(node->right->left) - tree_height(node->right->right);
            if (right_bf > 0) // RL Rotation
                node->right = rotate_right(node->right);
            return rotate_left(node);
        }

        return node;
    }

    Node *insert_helper(Node *node, int val, bool &is_inserted)
    {
        if (node == nullptr)
        {
            is_inserted = true;
            return new Node(val);
        }

        if (val < node->key)
            node->left = insert_helper(node->left, val, is_inserted);
        else if (val > node->key)
            node->right = insert_helper(node->right, val, is_inserted);
        else
        {
            is_inserted = false;
            return node;
        }
        return retrace(node);
    }

    Node *min_helper(Node *node)
    {
        Node *current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    Node *delete_helper(Node *node, int val, bool &is_deleted)
    {
        if (node == nullptr)
        {
            is_deleted = false;
            return nullptr;
        }

        if (val < node->key)
            node->left = delete_helper(node->left, val, is_deleted);
        else if (val > node->key)
            node->right = delete_helper(node->right, val, is_deleted);
        else
        {
            is_deleted = true;
            // 0 or 1 children case
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            else
            {
                // 2 children case
                Node *temp = min_helper(node->right);
                node->key = temp->key;
                node->right = delete_helper(node->right, temp->key, is_deleted);
            }
        }

        return retrace(node);
    }

    bool find_helper(Node *node, int val)
    {
        if (node == nullptr)
            return false;
        if (node->key == val)
            return true;
        if (val < node->key)
            return find_helper(node->left, val);
        return find_helper(node->right, val);
    }

    void inOrder(Node *node, vector<int> &trav_order)
    {
        if (node == nullptr)
            return;
        inOrder(node->left, trav_order);
        trav_order.push_back(node->key);
        inOrder(node->right, trav_order);
    }

    string parethesize_tree(Node *node)
    {
        if (node == nullptr)
            return "";
        if (node->left == nullptr && node->right == nullptr)
            return to_string(node->key);
        return to_string(node->key) + "(" + parethesize_tree(node->left) + "," + parethesize_tree(node->right) + ")";
    }

    void destroy(Node *node)
    {
        if (!node)
            return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    ~AVL() { destroy(root); }
    bool insert(int key)
    {
        bool is_inserted = false;
        root = insert_helper(root, key, is_inserted);
        return is_inserted;
    }

    bool erase(int key)
    {
        bool is_erased = false;
        root = delete_helper(root, key, is_erased);
        return is_erased;
    }

    bool find(int key)
    {
        return find_helper(root, key);
    }

    vector<int> traverse()
    {
        vector<int> trav_order;
        inOrder(root, trav_order);
        return trav_order;
    }

    string tree_str()
    {
        return parethesize_tree(root);
    }
};

void show(AVL &t, const string &label)
{
    cout << label << "\n";
    cout << "  Structure: " << t.tree_str() << "\n";
    cout << "  In-order:  ";
    for (int x : t.traverse())
        cout << x << " ";
    cout << "\n\n";
}

int main()
{
    AVL rr;
    for (int k : {30, 20, 10})
        rr.insert(k);
    show(rr, "RR case (insert 30,20,10)");

    AVL ll;
    for (int k : {10, 20, 30})
        ll.insert(k);
    show(ll, "LL case (insert 10,20,30)");

    AVL lr;
    for (int k : {30, 10, 20})
        lr.insert(k);
    show(lr, "LR case (insert 30,10,20)");

    AVL rl;
    for (int k : {10, 30, 20})
        rl.insert(k);
    show(rl, "RL case (insert 10,30,20)");

    AVL t;
    for (int k : {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45})
        t.insert(k);
    show(t, "Full tree after 11 inserts");

    cout << "Insert duplicate 40: " << (t.insert(40) ? "Inserted" : "Rejected") << "\n\n";

    t.erase(10);
    show(t, "After deleting leaf 10");

    t.erase(20);
    show(t, "After deleting single-child node 20");

    t.erase(30);
    show(t, "After deleting two-child node 30 (root of subtree)");

    t.erase(50);
    show(t, "After deleting root 50 (two children)");

    cout << "Find 45: " << (t.find(45) ? "Found" : "Not found") << "\n";
    cout << "Find 999: " << (t.find(999) ? "Found" : "Not found") << "\n";

    cout << "Erase non-existent 999: " << (t.erase(999) ? "Erased" : "Not found") << "\n";

    return 0;
}
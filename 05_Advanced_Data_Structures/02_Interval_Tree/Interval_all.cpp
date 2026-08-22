#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class INode
{
public:
    int start, end, id;
    int height, maxEnd;
    INode *left, *right;

    INode(int start, int end, int id)
    {
        this->start = start;
        this->end = end;
        this->id = id;
        maxEnd = end;
        height = 1;
        left = right = nullptr;
    }
};

class Interval
{
    INode *root = nullptr;
    int next_id = 1;
    unordered_map<int, pair<int, int>> intervals_mp;

    int tree_height(INode *node)
    {
        if (node == nullptr) // NIL nodes
            return 0;
        return node->height; // Regular nodes
    }

    int tree_maxEnd(INode *node)
    {
        if (node == nullptr) // NIL nodes
            return INT_MIN;
        return node->maxEnd; // Regular nodes
    }

    void update_inode(INode *node)
    {
        if (node == nullptr)
            return;
        node->height = 1 + max(tree_height(node->left), tree_height(node->right));
        node->maxEnd = max(node->end, max(tree_maxEnd(node->left), tree_maxEnd(node->right)));
    }

    bool less_comparator(int start1, int id1, int start2, int id2)
    {
        if (start1 != start2)
            return start1 < start2;
        return id1 < id2;
    }

    INode *rotate_right(INode *y)
    {
        INode *x = y->left;
        INode *B = x->right;
        x->right = y;
        y->left = B;

        update_inode(y);
        update_inode(x);
        return x;
    }

    INode *rotate_left(INode *x)
    {
        INode *y = x->right;
        INode *B = y->left;
        y->left = x;
        x->right = B;

        update_inode(x);
        update_inode(y);

        return y;
    }

    INode *retrace(INode *node)
    {
        if (node == nullptr)
            return nullptr;

        update_inode(node);
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

    INode *insert_helper(INode *node, int start, int end, int id, bool &is_inserted)
    {
        if (node == nullptr)
        {
            is_inserted = true;
            return new INode(start, end, id);
        }
        if (less_comparator(start, id, node->start, node->id))
            node->left = insert_helper(node->left, start, end, id, is_inserted);
        else
            node->right = insert_helper(node->right, start, end, id, is_inserted);

        return retrace(node);
    }

    INode *min_helper(INode *node)
    {
        INode *current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    INode *delete_helper(INode *node, int start, int id, bool &is_deleted)
    {
        if (node == nullptr)
            return nullptr;

        if (less_comparator(start, id, node->start, node->id))
            node->left = delete_helper(node->left, start, id, is_deleted);
        else if (less_comparator(node->start, node->id, start, id))
            node->right = delete_helper(node->right, start, id, is_deleted);
        else
        {
            is_deleted = true;
            // 0 or 1 children case
            if (node->left == nullptr)
            {
                INode *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                INode *temp = node->left;
                delete node;
                return temp;
            }

            else
            {
                // 2 children case
                INode *temp = min_helper(node->right);
                node->start = temp->start;
                node->end = temp->end;
                node->id = temp->id;
                node->right = delete_helper(node->right, temp->start, temp->id, is_deleted);
            }
        }

        return retrace(node);
    }

    string parenthesize_tree(INode *node)
    {
        if (node == nullptr)
            return "";

        if (node->left == nullptr && node->right == nullptr)
            return to_string(node->id);

        return to_string(node->id) + "(" + parenthesize_tree(node->left) + "," + parenthesize_tree(node->right) + ")";
    }

    bool is_overlapping(int start1, int end1, int start2, int end2)
    {
        return start1 < end2 && start2 < end1;
    }

    bool conflict_helper(INode *node, int start, int end)
    {
        if (node == nullptr)
            return false;

        // current node
        if (is_overlapping(node->start, node->end, start, end))
            return true;

        // left subtree
        if (node->left != nullptr && tree_maxEnd(node->left) > start)
            if (conflict_helper(node->left, start, end))
                return true;

        // right subtree
        if (node->start < end)
            return conflict_helper(node->right, start, end);
        return false;
    }

    void overlaps_helper(INode *node, int start, int end, vector<int> &out_order)
    {
        if (node == nullptr)
            return;

        // left subtree overlaps
        if (node->left != nullptr && tree_maxEnd(node->left) > start)
            overlaps_helper(node->left, start, end, out_order);

        // root
        if (is_overlapping(node->start, node->end, start, end))
            out_order.push_back(node->id);

        // right subtree overlaps
        if (node->right != nullptr && node->start < end)
            overlaps_helper(node->right, start, end, out_order);
    }

    void at_helper(INode *node, int t, vector<int> &ids)
    {
        if (node == nullptr)
            return;

        // left subtree
        if (node->left != nullptr && tree_maxEnd(node->left) > t)
            at_helper(node->left, t, ids);

        // root
        if (node->start <= t && t < node->end)
            ids.push_back(node->id);

        // right subtree
        if (node->right != nullptr && node->start <= t)
            at_helper(node->right, t, ids);
    }

    INode *next_helper(INode *node, int t)
    {
        INode *temp = nullptr;
        while (node != nullptr)
        {
            if (node->start >= t)
            {
                temp = node;
                node = node->left;
            }
            else
                node = node->right;
        }
        return temp;
    }

public:
    void add(int start, int end)
    {
        bool inserted = false;
        int id = next_id++;
        root = insert_helper(root, start, end, id, inserted);
        intervals_mp[id] = {start, end};
    }

    bool remove(int id)
    {
        bool removed = false;
        auto it = intervals_mp.find(id);
        if (it == intervals_mp.end())
            return false;

        int start = it->second.first;
        root = delete_helper(root, start, id, removed);

        intervals_mp.erase(it);
        return true;
    }

    bool update(int id, int new_start, int new_end)
    {
        auto it = intervals_mp.find(id);
        if (it == intervals_mp.end())
            return false;
        int old_start = it->second.first;
        bool removed = false;
        root = delete_helper(root, old_start, id, removed);
        bool inserted = false;
        root = insert_helper(root, new_start, new_end, id, inserted);

        it->second = {new_start, new_end};
        return true;
    }

    string tree_str()
    {
        return parenthesize_tree(root);
    }

    bool conflict(int start, int end)
    {
        return conflict_helper(root, start, end);
    }

    vector<int> overlaps(int start, int end)
    {
        vector<int> overlapping_ids;
        overlaps_helper(root, start, end, overlapping_ids);
        return overlapping_ids;
    }

    vector<int> at(int t)
    {
        vector<int> ids;
        at_helper(root, t, ids);
        return ids;
    }

    INode *next(int t)
    {
        return next_helper(root, t);
    }
};

void printIds(const string &label, const vector<int> &ids)
{
    cout << label << ": ";
    if (ids.empty())
        cout << "none";
    for (int id : ids)
        cout << id << " ";
    cout << "\n";
}

int main()
{
    Interval tree;

    tree.add(15, 20);
    tree.add(10, 30);
    tree.add(17, 19);
    tree.add(5, 20);
    tree.add(12, 15);
    tree.add(30, 40);

    cout << "Tree structure: " << tree.tree_str() << "\n\n";

    cout << "conflict(14,16): " << (tree.conflict(14, 16) ? "true" : "false") << "\n";
    cout << "conflict(40,50): " << (tree.conflict(40, 50) ? "true" : "false") << "\n\n";

    printIds("overlaps(14,16)", tree.overlaps(14, 16));
    printIds("overlaps(0,5)", tree.overlaps(0, 5));
    printIds("overlaps(0,100)", tree.overlaps(0, 100));
    cout << "\n";

    printIds("at(18)", tree.at(18));
    printIds("at(35)", tree.at(35));
    printIds("at(50)", tree.at(50));
    cout << "\n";

    if (INode *n = tree.next(13))
        cout << "next(13): id=" << n->id << " [" << n->start << "," << n->end << ")\n";
    if (INode *n = tree.next(41))
        cout << "next(41): id=" << n->id << " [" << n->start << "," << n->end << ")\n";
    else
        cout << "next(41): none\n";
    cout << "\n";

    cout << "remove(3): " << (tree.remove(3) ? "removed" : "not found") << "\n";
    cout << "Tree structure: " << tree.tree_str() << "\n";
    printIds("overlaps(14,16) after remove", tree.overlaps(14, 16));
    cout << "\n";

    cout << "update(2, 50, 60): " << (tree.update(2, 50, 60) ? "updated" : "not found") << "\n";
    cout << "Tree structure: " << tree.tree_str() << "\n";
    printIds("overlaps(14,16) after update", tree.overlaps(14, 16));
    printIds("overlaps(55,58) after update", tree.overlaps(55, 58));
    cout << "\n";

    cout << "remove(999): " << (tree.remove(999) ? "removed" : "not found") << "\n";
    cout << "update(999, 0, 1): " << (tree.update(999, 0, 1) ? "updated" : "not found") << "\n\n";

    tree.add(20, 20);
    cout << "conflict(20,20) zero-length: " << (tree.conflict(20, 20) ? "true" : "false") << "\n";
    cout << "conflict(19,21) around zero-length: " << (tree.conflict(19, 21) ? "true" : "false") << "\n\n";

    Interval same_start;
    same_start.add(5, 10);
    same_start.add(5, 25);
    same_start.add(5, 15);
    printIds("overlaps(5,6) with duplicate starts", same_start.overlaps(5, 6));

    Interval empty;
    cout << "conflict on empty tree: " << (empty.conflict(0, 100) ? "true" : "false") << "\n";
    printIds("overlaps on empty tree", empty.overlaps(0, 100));
    cout << "next on empty tree: " << (empty.next(0) == nullptr ? "none" : "found") << "\n";

    return 0;
}

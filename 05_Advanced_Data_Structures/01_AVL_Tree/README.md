# AVL Tree

A self-balancing binary search tree implementation in C++. After every insertion or deletion, the tree retraces the path back to the root and applies rotations to keep the height difference between left and right subtrees within `{-1, 0, 1}` at every node — guaranteeing `O(log n)` time for insert, delete, and find.

## Structure

```cpp
class Node {
    int key, height;
    Node *left, *right;
};

class AVL {
    Node *root;
public:
    bool insert(int key);
    bool erase(int key);
    bool find(int key);
    vector<int> traverse();   // in-order
    string tree_str();        // parenthesized structure
};
```

`height` is cached on each node and used to compute the balance factor without re-walking subtrees on every check.

## Balance Factor & Rotations

For any node, `balance factor = height(left) - height(right)`.

| Balance factor | Meaning         |
|----------------|-----------------|
| `> 1`          | left-heavy      |
| `< -1`         | right-heavy     |
| `-1, 0, 1`      | balanced (OK)   |

When a node becomes unbalanced after insert/delete, one of four rotation cases applies:

### LL — left-left heavy
Left child's left subtree caused the imbalance. Fixed with a single **right rotation**.

```
      z                y
     /                / \
    y        -->     x   z
   /
  x
```

### RR — right-right heavy
Mirror of LL. Fixed with a single **left rotation**.

```
  z                    y
   \                  / \
    y        -->     z   x
     \
      x
```

### LR — left-right heavy
Left child's right subtree caused the imbalance. Fixed with a **left rotation on the left child**, then a **right rotation on the node**.

```
    z              z                x
   /              /                / \
  y      -->     x       -->      y   z
   \             /
    x           y
```

### RL — right-left heavy
Mirror of LR. **Right rotation on the right child**, then **left rotation on the node**.

```
  z                z                  x
   \                \                / \
    y      -->       x      -->     z   y
   /                  \
  x                    y
```

`retrace()` walks back up from the insertion/deletion point, recalculates each ancestor's height, checks its balance factor, and applies the matching rotation above whenever it falls outside `[-1, 1]`.

## Operations

### Insert
Standard BST insertion (recurse left/right by key comparison), then `retrace()` up the path to rebalance. Duplicate keys are rejected — `insert()` returns `false` if the key already exists.

### Delete
Standard BST deletion with three cases:
- **Leaf node** — remove directly.
- **One child** — replace the node with its only child.
- **Two children** — replace the node's key with its in-order successor (minimum of the right subtree), then recursively delete that successor from the right subtree.

`retrace()` runs on the way back up here too, so deletions rebalance the tree exactly like insertions.

### Find
Plain BST search — `O(log n)` because the tree is always balanced.

### Traverse
In-order traversal returns keys in sorted order — the standard way to verify a BST is valid.

### tree_str()
Returns a parenthesized string like `50(30(20,40),70)`, useful for printing/debugging the shape of the tree without a visualizer.

## Example

```cpp
AVL t;
for (int k : {50, 30, 70, 20, 40, 60, 80})
    t.insert(k);

cout << t.tree_str();
// 50(30(20,40),70(60,80))
```

Inserting `10, 20, 30` in that order would normally produce a degenerate right-leaning chain in a plain BST — the AVL tree instead detects the RR imbalance and rotates to keep `20` as the root of that subtree.

## Complexity

| Operation | Time       | Space  |
|-----------|-----------|--------|
| Insert    | O(log n)  | O(log n) recursion stack |
| Delete    | O(log n)  | O(log n) recursion stack |
| Find      | O(log n)  | O(log n) recursion stack |
| Traverse  | O(n)      | O(n)   |
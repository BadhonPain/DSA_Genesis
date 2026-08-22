# Interval Tree

An augmented AVL tree that stores intervals `[start, end)` and answers overlap queries in `O(log n + k)`, where `k` is the number of matching results. Every node is keyed by `(start, id)` for BST ordering and additionally stores `maxEnd` — the largest `end` value in its subtree — which is what makes overlap queries sub-linear instead of a full scan.

Intervals are treated as **half-open**: `[start, end)`. Two intervals `[s1, e1)` and `[s2, e2)` overlap iff `s1 < e2 && s2 < e1`. A zero-length interval (`start == end`) never overlaps anything, including itself.

## Structure

```cpp
class INode {
    int start, end, id;
    int height, maxEnd;
    INode *left, *right;
};

class Interval {
    INode *root;
    unordered_map<int, pair<int,int>> intervals_mp;  // id -> (start, end)
public:
    void add(int start, int end);
    bool remove(int id);
    bool update(int id, int new_start, int new_end);
    bool conflict(int start, int end);
    vector<int> overlaps(int start, int end);
    vector<int> at(int t);
    INode* next(int t);
    string tree_str();
};
```

Each interval gets an auto-incrementing `id` on insert, which is the handle used for `remove`, `update`, and result reporting. `intervals_mp` gives O(1) lookup of an id's current `(start, end)`, which `remove`/`update` need to locate the node in the tree.

## The `maxEnd` Augmentation

Ordinary BST ordering is by `start` only, which tells you nothing about `end` values. Interval trees fix this by having every node also track the maximum `end` across its entire subtree:

```
maxEnd(node) = max(node.end, maxEnd(node.left), maxEnd(node.right))
```

This is recalculated in `update_inode()` every time a node's children change — after insertion, deletion, and every rotation. It's the reason a subtree can be skipped entirely during a query: if `maxEnd(left subtree) <= queryStart`, nothing in that subtree can possibly overlap the query, no matter how deep it is.

```
                [20,30] maxEnd=45
               /                \
     [10,15] maxEnd=15      [25,45] maxEnd=45
                                  /
                          [22,28] maxEnd=28
```

Querying `[16, 19)`: at the root, `maxEnd(left) = 15 <= 16`, so the entire left subtree is skipped without visiting `[10,15]`.

## Balancing

Same AVL mechanics as a plain BST — `retrace()` walks back up after insert/delete, and `rotate_left`/`rotate_right` fix any node whose balance factor leaves `{-1, 0, 1}`. The only difference from a plain AVL tree is that `update_inode()` also refreshes `maxEnd`, and it must be called *after* re-pointing children in every rotation — a rotation changes which nodes are whose subtree, so `maxEnd` has to be recomputed bottom-up on both the old and new subtree roots.

## Operations

### `add(start, end)`
Inserts a new interval with position determined by `(start, id)`, so intervals sharing the same `start` are still totally ordered and both survive in the tree. Rebalances via `retrace()`.

### `remove(id)`
Looks up the interval's `start` in `intervals_mp` (O(1)), then deletes the node by `(start, id)` from the tree — same three-case BST deletion as a plain AVL (leaf / one child / two children, successor swap for the two-child case), rebalanced afterward.

### `update(id, new_start, new_end)`
Removes the interval and re-inserts it with the new range. Necessary because `start` determines the interval's position in the tree — changing it without moving the node would break the BST invariant.

### `conflict(start, end)`
Returns `true` as soon as **any** stored interval overlaps `[start, end)`. Prunes subtrees using `maxEnd` — descends left only if `maxEnd(left) > start`, descends right only if `node.start < end` (everything further right has an even larger `start`, so if the current node's start already fails to overlap, none of its right siblings can either).

### `overlaps(start, end)`
Same pruning as `conflict`, but collects every matching id instead of stopping at the first. Because it visits left–root–right in that order, results come back sorted by `start`.

### `at(t)`
Point-containment query: which intervals contain the instant `t`? Same tree-pruning idea, checking `start <= t < end` at each node.

### `next(t)`
Finds the interval with the smallest `start >= t` — a standard BST lower-bound search, `O(log n)`, no subtree pruning needed since it's not an overlap query.

### `tree_str()`
Parenthesized dump of the tree by id, e.g. `3(1,5(4,))` — for visualizing shape/balance, not interval content.

## Example

```cpp
Interval tree;
tree.add(15, 20);   // id 1
tree.add(10, 30);   // id 2
tree.add(17, 19);   // id 3
tree.add(5, 20);    // id 4
tree.add(12, 15);   // id 5
tree.add(30, 40);   // id 6

tree.conflict(14, 16);     // true  — overlaps id 1, 2, 5
tree.overlaps(14, 16);     // [5, 1, 2]  (sorted by start)
tree.at(18);                // ids of every interval containing t=18
tree.next(25).start;        // first interval starting at or after 25
```

## Complexity

| Operation   | Time              | Notes |
|-------------|-------------------|-------|
| add         | O(log n)          | insert + rebalance |
| remove      | O(log n)          | O(1) start lookup + delete + rebalance |
| update      | O(log n)          | remove + add |
| conflict    | O(log n)          | stops at first match |
| overlaps    | O(log n + k)      | k = number of results |
| at          | O(log n + k)      | k = number of results |
| next        | O(log n)          | BST lower-bound |
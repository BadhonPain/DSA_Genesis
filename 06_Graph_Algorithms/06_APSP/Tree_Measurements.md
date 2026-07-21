# Tree Radius, Diameter, Eccentricity, and Center

Computing these four metrics on a **tree** instead of a general graph — no
Floyd-Warshall, no distance matrix, just three BFS passes.

## Why trees are different

In a general weighted graph, computing radius/diameter/center requires
all-pairs shortest paths (Floyd-Warshall, O(N³)) followed by an
eccentricity scan per node.

A tree has exactly one path between any two nodes — no cycles, no
alternate routes to compare. That structural guarantee lets us skip the
distance matrix entirely and get everything in **O(N)**.

## The algorithm

**1. First BFS — from any node**

Start at an arbitrary node (node `1` here) and run BFS. The farthest node
found, call it `A`, is guaranteed to be one endpoint of the tree's
diameter. This is a classic tree property: the farthest node from *any*
starting point is always an end of the longest path in the tree.

**2. Second BFS — from A**

BFS from `A` finds the farthest node from it, call it `B`. The distance
`dist(A, B)` is the **diameter** of the tree, and the path `A → B` is the
diameter path.

**3. Third BFS — from B**

BFS from `B` gives `distB[]` for every node.

**4. Eccentricity without a full scan**

For any node `i`, its eccentricity is:

    eccentricity[i] = max(distA[i], distB[i])

This holds because the farthest node from *any* node in a tree is always
one of the two diameter endpoints (`A` or `B`) — never some other node.
So there's no need to compare against every other node individually.

**5. Radius and center**

    radius = min(eccentricity[1..N])
    center = { i : eccentricity[i] == radius }

The center is the set of nodes achieving the minimum eccentricity — the
node(s) that minimize the worst-case distance to the rest of the tree.

## Complexity

| Step                  | Cost |
|------------------------|------|
| BFS from arbitrary node | O(N) |
| BFS from A              | O(N) |
| BFS from B              | O(N) |
| Eccentricity + radius/center scan | O(N) |
| **Total**              | **O(N)** |

Compare to a general weighted graph, where the same four metrics cost
O(N³) via Floyd-Warshall.

## Correctness on weighted trees

The BFS here uses a plain FIFO queue, not Dijkstra's priority queue — and
that's still correct even with unequal edge weights, because a tree has
no alternate path to relax later. Each node is reached exactly once, via
its one true path from the source. This shortcut breaks down on general
graphs, where a queue-based traversal would give wrong distances for
weighted edges.


## Example

Tree edges: `1-2, 2-3, 3-4, 4-5, 5-6, 3-7` (all weight 1).

| node | eccentricity |
|------|--------------|
| 1    | 5            |
| 2    | 4            |
| 3    | 3            |
| 4    | 3            |
| 5    | 4            |
| 6    | 5            |
| 7    | 4            |

- First BFS from node `1` → farthest is node `6` (`A = 6`)
- Second BFS from `6` → farthest is node `1` (`B = 1`), diameter = 5
- Third BFS from `1` gives `distB[]`
- radius = 3, center = {3, 4}, diameter = 5
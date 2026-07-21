# Graph Radius, Diameter, Eccentricity, Center

Given a weighted undirected graph, this program computes four related metrics
in the same order the code executes them.

## 1. Build the distance matrix
`dist[u][v]` starts at `INF` everywhere except `dist[i][i] = 0` and the given
edges. Floyd-Warshall then fills in every pair's shortest path:

    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

for every intermediate node `k`.

## 2. Eccentricity — e[i]
The eccentricity of a node is the distance to its *farthest* node:

    e[i] = max over all j of dist[i][j]

Intuition: "if I stood at node i, how far would I have to go to reach the
node that's hardest for me to reach?"

## 3. Radius and diameter
- **Radius** = the smallest eccentricity in the graph — the most "central"
  node's worst-case distance.
- **Diameter** = the largest eccentricity — the longest shortest-path
  distance anywhere in the graph.

    radius   = min(e[1..N])
    diameter = max(e[1..N])

## 4. Center
The **center** is the set of all nodes whose eccentricity equals the radius
— the node(s) that minimize the worst-case distance to everything else.

    center = { i : e[i] == radius }

## Example
Five nodes, edges (1-2:2, 2-3:3, 3-4:1, 4-5:4, 2-4:5):

| node | eccentricity |
|------|--------------|
| 1    | 10           |
| 2    | 8            |
| 3    | 5            |
| 4    | 6            |
| 5    | 10           |

- radius = 5, achieved at node 3
- diameter = 10, achieved at nodes 1 and 5
- center = {3}
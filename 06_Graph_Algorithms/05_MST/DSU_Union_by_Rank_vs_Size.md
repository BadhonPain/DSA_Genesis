# DSU: Union by Rank vs Union by Size

## Goal

Both heuristics try to keep the DSU tree shallow so that `find()`
remains almost constant time.

------------------------------------------------------------------------

## Union by Size

**Idea:** Attach the smaller component under the larger component.

Each root stores:

``` text
size[root] = number of vertices in that component
```

### Example

Initially

``` text
1    2    3    4

size = 1 1 1 1
```

Union(1,2)

``` text
1
|
2

size(1) = 2
```

Union(3,4)

``` text
3
|
4

size(3) = 2
```

Union(1,3)

Both components have size 2.

``` text
      1
     / \
    2   3
         \
          4
```

Now

``` text
size(1) = 4
```

The stored value always equals the exact number of vertices.

------------------------------------------------------------------------

## Union by Rank

**Idea:** Attach the tree with the smaller **rank** under the larger
**rank**.

Rank is **an upper bound on the tree height** (after path compression).

Initially

``` text
1    2    3    4

rank = 0 0 0 0
```

Union(1,2)

``` text
1
|
2

rank(1) = 1
```

Union(3,4)

``` text
3
|
4

rank(3) = 1
```

Union(1,3)

Ranks are equal.

``` text
      1
     / \
    2   3
         \
          4
```

Increase the winner's rank.

``` text
rank(1) = 2
```

If instead we later attach a single node:

``` text
      1
     /|\
    2 3 5
       \
        4
```

The height does **not** increase, so

``` text
rank(1) = 2
```

remains unchanged.

------------------------------------------------------------------------

## Why Rank is an Upper Bound

Before path compression:

``` text
1
|
2
|
3
|
4

height = 3
rank   = 3
```

After calling `find(4)`:

``` text
    1
  / | \
 2  3  4
```

Actual height becomes **1**, but the stored rank may still be **3**.

Therefore,

``` text
rank >= actual height
```

Rank is **not updated** during path compression because it is only a
heuristic.

------------------------------------------------------------------------

## Comparison

  ----------------------------------------------------------------------------
  Feature          Union by Size                   Union by Rank
  ---------------- ------------------------------- ---------------------------
  Stores           Number of vertices              Upper bound on tree height

  Initial value    `1`                             `0`

  Update after     `size[parent] += size[child]`   Increase only if both ranks
  merge                                            are equal

  Useful for       ✅ Yes                          ❌ No
  component size                                   
  queries                                          

  Keeps tree       ✅ Yes                          ✅ Yes
  shallow                                          

  Time Complexity  O(α(n))                         O(α(n))
  (with path                                       
  compression)                                     
  ----------------------------------------------------------------------------

------------------------------------------------------------------------

## Which One Should You Use?

**Use Union by Size** if you need the size of connected components.

**Use Union by Rank** if you only care about connectivity.

In competitive programming, **Union by Size** is often preferred because
it offers the same performance while also providing component sizes for
free.

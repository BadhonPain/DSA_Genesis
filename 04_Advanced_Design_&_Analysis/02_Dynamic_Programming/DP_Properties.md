# Dynamic Programming — Core Properties

> **Two fundamental properties** that make Dynamic Programming applicable to a problem:
> 1. **Optimal Substructure** — an optimal solution to the problem contains optimal solutions to its subproblems.
> 2. **Overlapping Subproblems** — the same subproblems are solved repeatedly during recursion.
>
> If a problem has *both*, DP is the right tool. If it only has optimal substructure but *not* overlapping subproblems, plain Divide & Conquer suffices.

---

## 📑 Table of Contents

1. [Properties Defined](#1-properties-defined)
2. [Rod Cutting Problem](#2-rod-cutting-problem)
3. [Longest Common Subsequence (LCS)](#3-longest-common-subsequence-lcs)
4. [Edit Distance](#4-edit-distance)
5. [Matrix Chain Multiplication (MCM)](#5-matrix-chain-multiplication-mcm)
6. [Summary Comparison](#6-summary-comparison)

---

## 1. Properties Defined

### 🔷 Optimal Substructure

A problem has **optimal substructure** if an **optimal solution to the whole problem** can be constructed from **optimal solutions to its subproblems**.

> Formally: if the optimal solution to problem $P$ uses solutions to subproblems $P_1, P_2, \ldots$, then each of those sub-solutions must itself be optimal.

**Proof technique — "Cut and Paste":**
Suppose the global optimal solution uses a sub-optimal solution to some subproblem. Then we can "cut" that sub-optimal part and "paste" the optimal sub-solution in its place, getting a better overall solution — contradicting the assumption that we started with the global optimum.

---

### 🔷 Overlapping Subproblems

A problem has **overlapping subproblems** if a naive recursive solution visits the **same subproblem multiple times**.

> This is what distinguishes DP from Divide & Conquer. In D&C (e.g., Merge Sort), subproblems are *independent*. In DP, they *overlap* — so we store and reuse results instead of recomputing.

**Two DP strategies:**
- **Memoization (Top-Down):** Recurse naturally; cache results in a table.
- **Tabulation (Bottom-Up):** Fill a table iteratively from smallest subproblems upward.

---

## 2. Rod Cutting Problem

### Problem Statement

Given a rod of length $n$ and a price table $p[1..n]$ where $p[i]$ is the price of a rod of length $i$, determine the maximum revenue obtainable by cutting the rod and selling the pieces.

| Length $i$ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|------------|---|---|---|---|---|---|---|---|
| Price $p[i]$ | 1 | 5 | 8 | 9 | 10 | 17 | 17 | 20 |

---

### ✅ Optimal Substructure

**Claim:** The optimal way to cut a rod of length $n$ contains optimal solutions to subproblems of smaller lengths.

**Recursive structure:**

$$r(n) = \max_{1 \leq i \leq n} \bigl(p[i] + r(n - i)\bigr)$$

where $r(n)$ is the maximum revenue for a rod of length $n$, and $r(0) = 0$.

**Intuition:** When we make the first cut of length $i$:
- We get price $p[i]$ for that piece.
- The remaining piece of length $n - i$ must itself be cut optimally to get $r(n-i)$.

**Cut-and-Paste Proof:**  
Suppose in the optimal solution for $n$, the remaining rod $(n-i)$ is cut sub-optimally, yielding revenue $r'(n-i) < r(n-i)$. Then replacing with the optimal cut of $(n-i)$ gives total revenue $p[i] + r(n-i) > p[i] + r'(n-i)$, contradicting optimality. $\square$

---

### ✅ Overlapping Subproblems

**Claim:** A naive recursive solution recomputes $r(k)$ for the same $k$ many times.

**Recursive call tree for $n = 4$:**

```
                        r(4)
              /      /      \      \
           r(3)   r(2)     r(1)   r(0)
          / | \   /  \      |
       r(2) r(1) r(0) r(1) r(0) r(0)
       / \   |        |
     r(1) r(0) r(0)  r(0)
      |
     r(0)
```

**Count of calls for $r(0)$:** called at least **5 times**.  
**Count of calls for $r(1)$:** called at least **4 times**.  
**Count of calls for $r(2)$:** called at least **3 times**.

Without memoization, the naive recursion has exponential time complexity $O(2^n)$.

**Subproblem space:** only $n+1$ distinct subproblems: $r(0), r(1), \ldots, r(n)$.

---

### DP Solution

```python
def rod_cutting(p, n):
    r = [0] * (n + 1)          # r[0] = 0 (base case)
    for j in range(1, n + 1):
        q = float('-inf')
        for i in range(1, j + 1):
            q = max(q, p[i] + r[j - i])
        r[j] = q
    return r[n]
```

**Time:** $O(n^2)$ &nbsp;|&nbsp; **Space:** $O(n)$

---

## 3. Longest Common Subsequence (LCS)

### Problem Statement

Given two sequences $X = \langle x_1, x_2, \ldots, x_m \rangle$ and $Y = \langle y_1, y_2, \ldots, y_n \rangle$, find the length of their **longest common subsequence** — a subsequence that appears in both (not necessarily contiguous).

**Example:**  
$X = \texttt{ABCBDAB}$, $Y = \texttt{BDCABA}$ &nbsp;→&nbsp; LCS = $\texttt{BCBA}$, length = **4**

---

### ✅ Optimal Substructure

Let $LCS(i, j)$ = length of LCS of $X[1..i]$ and $Y[1..j]$.

**Recurrence:**

$$LCS(i,j) = \begin{cases} 0 & \text{if } i = 0 \text{ or } j = 0 \\ LCS(i-1,\; j-1) + 1 & \text{if } x_i = y_j \\ \max\!\bigl(LCS(i-1,\; j),\; LCS(i,\; j-1)\bigr) & \text{if } x_i \neq y_j \end{cases}$$

**Why optimal substructure holds — two cases:**

**Case 1:** $x_i = y_j$ (last characters match)  
The last character must be in the LCS. Any LCS of $X[1..i]$ and $Y[1..j]$ that includes this match is built on an optimal LCS of $X[1..i-1]$ and $Y[1..j-1]$.

> *Cut-and-paste:* If the LCS of the prefixes were sub-optimal, appending $x_i = y_j$ would still give a sub-optimal LCS for the full sequences — contradiction.

**Case 2:** $x_i \neq y_j$ (last characters differ)  
The LCS cannot include both $x_i$ and $y_j$. So we try excluding one at a time:
- Exclude $x_i$: optimal LCS of $X[1..i-1]$ and $Y[1..j]$
- Exclude $y_j$: optimal LCS of $X[1..i]$ and $Y[1..j-1]$

The overall LCS is the max of these two — each of which must themselves be optimal.

---

### ✅ Overlapping Subproblems

**Recursive call overlap for $X = \texttt{ABC}$, $Y = \texttt{AC}$:**

```
                    LCS(3,2)
                  /          \
           LCS(2,2)           LCS(3,1)
          /       \          /        \
      LCS(1,2)  LCS(2,1)  LCS(2,1)  LCS(3,0)
       /    \    /    \    /    \
  LCS(0,2) LCS(1,1) LCS(1,1) LCS(2,0) ...
                  ↑_____________↑
                  LCS(1,1) called TWICE
```

**Subproblem space:** $(m+1) \times (n+1)$ distinct subproblems.

Without memoization, naive recursion is $O(2^{m+n})$ in the worst case.

---

### DP Solution

```python
def lcs(X, Y):
    m, n = len(X), len(Y)
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if X[i-1] == Y[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    return dp[m][n]
```

**Time:** $O(mn)$ &nbsp;|&nbsp; **Space:** $O(mn)$ (reducible to $O(\min(m,n))$)

---

## 4. Edit Distance

### Problem Statement

Given two strings $s_1$ of length $m$ and $s_2$ of length $n$, find the **minimum number of operations** (insert, delete, replace) to transform $s_1$ into $s_2$.

**Example:**  
$s_1 = \texttt{SUNDAY}$, $s_2 = \texttt{SATURDAY}$ &nbsp;→&nbsp; Edit Distance = **3**

---

### ✅ Optimal Substructure

Let $ED(i, j)$ = minimum edit distance between $s_1[1..i]$ and $s_2[1..j]$.

**Recurrence:**

$$ED(i,j) = \begin{cases} j & \text{if } i = 0 \quad \text{(insert j characters)} \\ i & \text{if } j = 0 \quad \text{(delete i characters)} \\ ED(i-1,\;j-1) & \text{if } s_1[i] = s_2[j] \\ 1 + \min\!\begin{cases} ED(i-1,\;j) & \text{(delete from } s_1) \\ ED(i,\;j-1) & \text{(insert into } s_1) \\ ED(i-1,\;j-1) & \text{(replace)} \end{cases} & \text{if } s_1[i] \neq s_2[j] \end{cases}$$

**Why optimal substructure holds:**

At each step, we align the last characters $s_1[i]$ and $s_2[j]$ and consider all possible last operations:

| Last Operation | Subproblem Reduced To |
|---------------|-----------------------|
| **Match** ($s_1[i] = s_2[j]$) | $ED(i-1, j-1)$ — no cost |
| **Replace** $s_1[i]$ with $s_2[j]$ | $ED(i-1, j-1) + 1$ |
| **Delete** $s_1[i]$ | $ED(i-1, j) + 1$ |
| **Insert** $s_2[j]$ after $s_1[i]$ | $ED(i, j-1) + 1$ |

The optimal solution uses the minimum-cost operation, and whatever subproblem that operation leads to must be solved optimally. If any sub-solution were sub-optimal, we could replace it with a cheaper one, reducing total cost — contradicting optimality. $\square$

---

### ✅ Overlapping Subproblems

**Call tree fragment for $s_1 = \texttt{AB}$, $s_2 = \texttt{B}$:**

```
                   ED(2, 1)
              /       |       \
         ED(1,1)   ED(2,0)   ED(1,0)
        /   |   \
   ED(0,1) ED(1,0) ED(0,0)
               ↑
         ED(1,0) appears in BOTH ED(2,1) and ED(1,1)
```

**Subproblem space:** $(m+1) \times (n+1)$ distinct subproblems.

Without memoization, the naive recursion has time complexity $O(3^{\max(m,n)})$ in the worst case, since each call branches into up to 3 sub-calls.

---

### DP Solution

```python
def edit_distance(s1, s2):
    m, n = len(s1), len(s2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    # Base cases
    for i in range(m + 1): dp[i][0] = i   # delete all of s1
    for j in range(n + 1): dp[0][j] = j   # insert all of s2

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i-1] == s2[j-1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = 1 + min(dp[i-1][j],    # delete
                                   dp[i][j-1],    # insert
                                   dp[i-1][j-1])  # replace
    return dp[m][n]
```

**Time:** $O(mn)$ &nbsp;|&nbsp; **Space:** $O(mn)$ (reducible to $O(\min(m,n))$)

---

## 5. Matrix Chain Multiplication (MCM)

### Problem Statement

Given a sequence of $n$ matrices $A_1, A_2, \ldots, A_n$ with dimensions $p_0 \times p_1$, $p_1 \times p_2$, $\ldots$, $p_{n-1} \times p_n$, find the **optimal parenthesization** that minimizes the total number of scalar multiplications.

**Key fact:** Matrix multiplication is associative — the result is the same regardless of parenthesization, but the **cost differs dramatically**.

**Example:**  
$A_1: 10 \times 30$, $A_2: 30 \times 5$, $A_3: 5 \times 60$

- $(A_1 A_2) A_3$: $(10 \times 30 \times 5) + (10 \times 5 \times 60) = 1500 + 3000 = \mathbf{4500}$
- $A_1 (A_2 A_3)$: $(30 \times 5 \times 60) + (10 \times 30 \times 60) = 9000 + 18000 = \mathbf{27000}$

Optimal is the first: **4500 multiplications**.

---

### ✅ Optimal Substructure

Let $m[i][j]$ = minimum cost to compute $A_i \cdot A_{i+1} \cdots A_j$.

**Recurrence:** For each possible "last split" at position $k$ (where $i \leq k < j$):

$$m[i][j] = \begin{cases} 0 & \text{if } i = j \\ \displaystyle\min_{i \leq k < j} \bigl(m[i][k] + m[k+1][j] + p_{i-1} \cdot p_k \cdot p_j\bigr) & \text{if } i < j \end{cases}$$

The term $p_{i-1} \cdot p_k \cdot p_j$ is the cost of multiplying the two resulting matrices $A_{i..k}$ and $A_{k+1..j}$.

**Why optimal substructure holds:**

For any split $k$, the optimal solution for $A_{i..j}$ requires:
1. Optimally computing $A_{i..k}$ (cost $m[i][k]$)
2. Optimally computing $A_{k+1..j}$ (cost $m[k+1][j]$)
3. Multiplying the two results ($p_{i-1} \cdot p_k \cdot p_j$ cost)

> *Cut-and-paste:* Suppose for the optimal split $k^*$, we used a sub-optimal solution for $A_{i..k^*}$ with cost $m'[i][k^*] > m[i][k^*]$. Replacing with the optimal sub-solution reduces total cost — contradicting optimality. The same argument applies to $A_{k^*+1..j}$. $\square$

---

### ✅ Overlapping Subproblems

**Number of distinct subproblems:** $\binom{n}{2} = O(n^2)$  
**Total recursive calls (naive):** $\Omega(2^n)$ — exponential.

**Example overlap for 4 matrices $A_1, A_2, A_3, A_4$:**

```
                        m[1][4]
            /           |           \
      m[1][1]+m[2][4]  m[1][2]+m[3][4]  m[1][3]+m[2][4]... wait
         = split k=1      split k=2        split k=3

      m[2][4] appears in split k=1
      m[2][4]:
           m[2][2]+m[3][4]   m[2][3]+m[4][4]
                    ↑
               m[3][4] appears both here and when computing m[1][4] with k=2
               m[3][4] computed MULTIPLE TIMES
```

**Subproblem table for $n=4$:**

| Subproblem | Needed by |
|-----------|-----------|
| $m[1][2]$ | $m[1][3]$, $m[1][4]$ |
| $m[2][3]$ | $m[1][3]$, $m[2][4]$ |
| $m[3][4]$ | $m[2][4]$, $m[1][4]$ |
| $m[2][4]$ | $m[1][4]$ (via two different splits) |

Without memoization, naive recursion is $\Omega(2^n)$.

---

### DP Solution

```python
def matrix_chain(p):
    n = len(p) - 1                        # number of matrices
    m = [[0] * n for _ in range(n)]       # m[i][j]: min cost
    s = [[0] * n for _ in range(n)]       # s[i][j]: optimal split point

    # chain length l (l=1 is base case: single matrix, cost 0)
    for l in range(2, n + 1):             # chain length
        for i in range(n - l + 1):       # starting index
            j = i + l - 1               # ending index
            m[i][j] = float('inf')
            for k in range(i, j):        # try all splits
                cost = m[i][k] + m[k+1][j] + p[i] * p[k+1] * p[j+1]
                if cost < m[i][j]:
                    m[i][j] = cost
                    s[i][j] = k

    return m[0][n-1], s
```

**Time:** $O(n^3)$ &nbsp;|&nbsp; **Space:** $O(n^2)$

---

## 6. Summary Comparison

| Problem | Subproblem Definition | Optimal Substructure Argument | # Distinct Subproblems | Naive Complexity | DP Complexity |
|---------|----------------------|-------------------------------|------------------------|-----------------|---------------|
| **Rod Cutting** | $r(k)$: max revenue for rod of length $k$ | Optimal first cut + optimal cut of remainder | $O(n)$ | $O(2^n)$ | $O(n^2)$ |
| **LCS** | $LCS(i,j)$: LCS of $X[1..i]$, $Y[1..j]$ | Match or exclude last char; sub-LCS must be optimal | $O(mn)$ | $O(2^{m+n})$ | $O(mn)$ |
| **Edit Distance** | $ED(i,j)$: min ops for $s_1[1..i] \to s_2[1..j]$ | Last operation (match/replace/delete/insert) sub-problem must be optimal | $O(mn)$ | $O(3^{\max(m,n)})$ | $O(mn)$ |
| **MCM** | $m[i][j]$: min cost to multiply $A_i \cdots A_j$ | Optimal split $k$; both sub-chains must be optimal | $O(n^2)$ | $O(2^n)$ | $O(n^3)$ |

---

> 💡 **Key Takeaway:** Every DP problem above satisfies both properties — the recurrence structure *embeds* optimal substructure, and the recursive call trees *expose* overlapping subproblems. DP turns exponential naive recursion into polynomial time by storing $O(\text{polynomial})$ subproblem solutions.
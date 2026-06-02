# Greedy Algorithms — Core Properties

> Greedy algorithms build a solution **piece by piece**, always choosing the locally optimal option at each step.  
> Unlike DP, greedy does **not** explore all subproblems — it commits irrevocably to the best-looking choice at each stage.
>
> For a greedy algorithm to be **correct**, the problem must satisfy:
> 1. **Optimal Substructure** — an optimal global solution contains optimal solutions to subproblems.
> 2. **Greedy Choice Property** — a globally optimal solution can be reached by making a locally optimal (greedy) choice at each step.
>
> ⚠️ Note: The **Overlapping Subproblems** property is **not required** for greedy algorithms — greedy never revisits subproblems. However, it is still insightful to examine *why* greedy problems do **not** exhibit overlapping subproblems (which is part of why greedy works without memoization).

---

## 📑 Table of Contents

1. [Greedy vs DP — Key Distinction](#1-greedy-vs-dp--key-distinction)
2. [Activity Selection Problem](#2-activity-selection-problem)
3. [Fractional Knapsack Problem](#3-fractional-knapsack-problem)
4. [Summary Comparison](#4-summary-comparison)

---

## 1. Greedy vs DP — Key Distinction

| Property | Dynamic Programming | Greedy |
|----------|-------------------|--------|
| Optimal Substructure | ✅ Required | ✅ Required |
| Overlapping Subproblems | ✅ Required (exploited by memoization) | ❌ Not present / not needed |
| Greedy Choice Property | ❌ Not applicable | ✅ Required |
| Decision style | Considers **all** choices; builds table | Makes **one** locally optimal choice; moves on |
| Backtracking | Never (once computed, stored) | Never (commits irrevocably) |

**Why greedy doesn't need overlapping subproblems:**  
After making the greedy choice, the problem reduces to exactly **one** smaller subproblem — not multiple. There is no branching, so no subproblem is ever visited twice.

---

## 2. Activity Selection Problem

### Problem Statement

Given $n$ activities, each with a **start time** $s_i$ and **finish time** $f_i$, select the **maximum number of non-overlapping activities** that can be performed by a single resource.

Two activities $i$ and $j$ are **compatible** if their intervals don't overlap: $f_i \leq s_j$ or $f_j \leq s_i$.

**Example:**

| Activity | $s_i$ | $f_i$ |
|----------|--------|--------|
| $a_1$ | 1 | 4 |
| $a_2$ | 3 | 5 |
| $a_3$ | 0 | 6 |
| $a_4$ | 5 | 7 |
| $a_5$ | 3 | 9 |
| $a_6$ | 5 | 9 |
| $a_7$ | 6 | 10 |
| $a_8$ | 8 | 11 |
| $a_9$ | 8 | 12 |
| $a_{10}$ | 2 | 14 |
| $a_{11}$ | 12 | 16 |

**Sorted by finish time:** $a_1, a_2, a_3, a_4, a_5, a_6, a_7, a_8, a_9, a_{10}, a_{11}$

**Greedy picks:** $\{a_1, a_4, a_8, a_{11}\}$ — **4 activities** ✅

---

### ✅ Optimal Substructure

**Setup:**  
Let activities be sorted by finish time: $f_1 \leq f_2 \leq \cdots \leq f_n$.  
Define $S_{ij}$ = set of activities that start after $a_i$ finishes and finish before $a_j$ starts:

$$S_{ij} = \{ a_k : f_i \leq s_k < f_k \leq s_j \}$$

Let $c[i][j]$ = size of the maximum-size subset of mutually compatible activities in $S_{ij}$.

**Recurrence:**

$$c[i][j] = \begin{cases} 0 & \text{if } S_{ij} = \emptyset \\ \displaystyle\max_{a_k \in S_{ij}} \bigl(c[i][k] + 1 + c[k][j]\bigr) & \text{if } S_{ij} \neq \emptyset \end{cases}$$

**Why optimal substructure holds:**

Suppose we choose activity $a_k \in S_{ij}$ as part of an optimal solution.  
Then we need to solve two independent subproblems:
- Select max activities from $S_{ik}$ (activities compatible before $a_k$)
- Select max activities from $S_{kj}$ (activities compatible after $a_k$)

> *Cut-and-paste argument:* Suppose the activities chosen from $S_{ik}$ are sub-optimal — say they yield $c'[i][k] < c[i][k]$ activities. Then substituting the optimal selection for $S_{ik}$ gives $c[i][k] + 1 + c[k][j] > c'[i][k] + 1 + c[k][j]$, contradicting the assumption that our original solution was optimal. $\square$

This DP formulation is $O(n^3)$. **But greedy does better.**

---

### ✅ Greedy Choice Property

**Greedy strategy:** Always pick the activity with the **earliest finish time** that is compatible with previously selected activities.

**Theorem:** There exists an optimal solution that includes the activity $a_1$ with the earliest finish time.

**Proof:**  
Let $A^*$ be any optimal solution. Let $a_m$ be the first activity in $A^*$ (earliest finish time in $A^*$).

- If $a_m = a_1$: greedy choice is already in $A^*$. ✅
- If $a_m \neq a_1$: since $a_1$ has the globally earliest finish time, $f_1 \leq f_m$. Construct $A' = (A^* \setminus \{a_m\}) \cup \{a_1\}$.
  - $a_1$ ends no later than $a_m$, so $a_1$ is compatible with everything $a_m$ was compatible with.
  - $|A'| = |A^*|$ — same number of activities.
  - $A'$ is still optimal and now contains the greedy choice $a_1$. ✅

**After choosing $a_1$:** the problem reduces to selecting the maximum number of compatible activities from those starting after $f_1$ — a **single** smaller subproblem, not multiple.

---

### ❌ Overlapping Subproblems — Not Present

**Why there are no overlapping subproblems in the greedy approach:**

After the greedy choice of $a_1$, we solve **one** subproblem: activities in $\{a_k : s_k \geq f_1\}$.  
After choosing the next activity, we again have **one** subproblem.  
The algorithm follows a **single linear path** — no branching, no repeated subproblems.

```
Greedy path (no branching):

  Full set S
      ↓  pick a₁ (earliest finish)
  S' = activities starting after f₁
      ↓  pick next (earliest finish in S')
  S'' = activities starting after f of that pick
      ↓  ...
  ∅
```

Compare this to the DP formulation above, where each step branches into $|S_{ij}|$ sub-trees — which is what causes overlapping subproblems in the DP version.

**This is precisely why greedy is $O(n \log n)$ (dominated by sorting) while the DP version is $O(n^3)$.**

---

### Greedy Algorithm

```python
def activity_selection(activities):
    # Sort by finish time
    activities.sort(key=lambda x: x[1])
    
    selected = [activities[0]]
    last_finish = activities[0][1]
    
    for i in range(1, len(activities)):
        s, f = activities[i]
        if s >= last_finish:           # compatible with last selected
            selected.append((s, f))
            last_finish = f
    
    return selected
```

**Time:** $O(n \log n)$ (sorting) &nbsp;|&nbsp; **Space:** $O(1)$ extra

---

## 3. Fractional Knapsack Problem

### Problem Statement

Given $n$ items, each with weight $w_i$ and value $v_i$, and a knapsack of capacity $W$, maximize the total value. **Fractions of items are allowed.**

**Example:**

| Item | Weight $w_i$ | Value $v_i$ | Value/Weight |
|------|-------------|------------|--------------|
| 1 | 10 | 60 | **6.0** |
| 2 | 20 | 100 | **5.0** |
| 3 | 30 | 120 | **4.0** |

Knapsack capacity $W = 50$.

**Greedy solution (sort by value/weight descending):**
- Take all of item 1: weight 10, value 60. Remaining capacity: 40.
- Take all of item 2: weight 20, value 100. Remaining capacity: 20.
- Take 2/3 of item 3: weight 20, value 80. Remaining capacity: 0.

**Total value = 60 + 100 + 80 = 240** ✅

---

### ✅ Optimal Substructure

**Claim:** An optimal solution to the fractional knapsack of capacity $W$ contains optimal solutions to fractional knapsack subproblems of smaller capacity.

**Argument:**

Let $OPT$ be an optimal solution for capacity $W$. Suppose item $i$ is included with fraction $x_i$ ($0 < x_i \leq 1$).

Now consider the **remaining capacity** $W - x_i \cdot w_i$ after including $x_i$ of item $i$.  
The items filling the rest of the knapsack must form an **optimal solution** for this reduced capacity and remaining items.

> *Cut-and-paste:* If the selection for the remaining capacity were sub-optimal, we could replace it with a better selection, increasing total value — contradicting the optimality of $OPT$. $\square$

**Recurrence view:**

$$V(W, \text{items}) = \max_{0 \leq x_i \leq 1} \bigl( x_i \cdot v_i + V(W - x_i \cdot w_i,\; \text{items} \setminus \{i\}) \bigr)$$

---

### ✅ Greedy Choice Property

**Greedy strategy:** Always take as much as possible of the item with the **highest value-to-weight ratio** $v_i / w_i$.

**Theorem:** There exists an optimal solution that takes the maximum possible fraction of the item with the highest $v_i/w_i$ ratio.

**Proof:**  
Let item 1 have the highest ratio $v_1/w_1 \geq v_i/w_i$ for all $i$.  
Let $OPT$ be an optimal solution where item 1 is taken with fraction $x_1 < \min(1, W/w_1)$ (i.e., not maximally).

Since the knapsack is not full (or item 1 could fill more), there exists some other item $j$ taken with fraction $x_j > 0$.

**Exchange argument:** Remove $\delta$ fraction of item $j$ (reducing value by $\delta \cdot v_j$) and add $\delta \cdot w_j / w_1$ more of item 1 (increasing value by $\delta \cdot w_j \cdot v_1/w_1$).

Net change in value:
$$\Delta = \delta \cdot w_j \cdot \frac{v_1}{w_1} - \delta \cdot v_j = \delta \cdot w_j \left(\frac{v_1}{w_1} - \frac{v_j}{w_j}\right) \geq 0$$

since $v_1/w_1 \geq v_j/w_j$ by assumption. So this exchange never decreases total value, confirming the greedy choice is safe. $\square$

---

### ❌ Overlapping Subproblems — Not Present

**Why there are no overlapping subproblems in fractional knapsack:**

The greedy approach makes a **single irreversible decision** at each step — take as much of the best-ratio item as possible — then moves to the next item with remaining capacity. The subproblems form a **strict linear chain**:

```
Greedy execution path:

  Capacity W, all items
      ↓  take x₁ of item with highest ratio
  Capacity W - x₁w₁, remaining items
      ↓  take x₂ of next-best ratio item
  Capacity W - x₁w₁ - x₂w₂, remaining items
      ↓  ...
  Capacity 0 or no items left
```

There is **no branching** at any stage. Each state (remaining capacity + remaining items) appears **at most once** in the execution.

**Contrast with 0/1 Knapsack:**  
In the 0/1 Knapsack (no fractions allowed), the greedy approach fails because not taking a fraction forces you to try both including and excluding each item — creating exponential branching and **overlapping subproblems**, which is why 0/1 Knapsack requires DP with $O(nW)$ time.

| Knapsack Variant | Greedy Works? | Overlapping Subproblems? | Approach |
|-----------------|--------------|------------------------|---------|
| Fractional | ✅ Yes | ❌ No | Greedy — $O(n \log n)$ |
| 0/1 | ❌ No | ✅ Yes | DP — $O(nW)$ |

---

### Greedy Algorithm

```python
def fractional_knapsack(items, W):
    # Sort by value/weight ratio (descending)
    items.sort(key=lambda x: x[1]/x[0], reverse=True)
    
    total_value = 0.0
    remaining = W
    
    for weight, value in items:
        if remaining == 0:
            break
        fraction = min(1.0, remaining / weight)   # take as much as possible
        total_value += fraction * value
        remaining  -= fraction * weight
    
    return total_value
```

**Time:** $O(n \log n)$ (sorting) &nbsp;|&nbsp; **Space:** $O(1)$ extra

---

## 4. Summary Comparison

### Property Checklist

| Property | Activity Selection | Fractional Knapsack |
|----------|--------------------|---------------------|
| **Optimal Substructure** | ✅ Yes — choosing activity $a_k$ reduces to two independent subproblems; each must be optimal | ✅ Yes — after filling fraction $x_i$ of item $i$, remaining capacity must be filled optimally |
| **Greedy Choice Property** | ✅ Yes — earliest-finish activity is always in some optimal solution (proved by exchange) | ✅ Yes — highest value/weight item should always be maximized first (proved by exchange) |
| **Overlapping Subproblems** | ❌ No — greedy reduces to single linear path; no subproblem repeated | ❌ No — greedy reduces to single linear path; no subproblem repeated |
| **Algorithm Complexity** | $O(n \log n)$ | $O(n \log n)$ |

---

### Greedy vs DP for These Problems

| Aspect | Activity Selection (DP) | Activity Selection (Greedy) |
|--------|------------------------|----------------------------|
| Time | $O(n^3)$ | $O(n \log n)$ |
| Subproblems explored | $O(n^2)$ — branches at each step | $O(n)$ — one path only |
| Correctness guarantee | Always correct (explores all) | Correct due to greedy-choice property |

---

> 💡 **Key Takeaway:**
>
> Both greedy problems satisfy **optimal substructure** — which is the bridge between greedy and DP.  
> What makes greedy *faster* and *simpler* is the **greedy choice property** — it guarantees we never need to branch or backtrack, eliminating overlapping subproblems entirely.  
>
> **Greedy = Optimal Substructure + Greedy Choice Property** (no need to store or revisit subproblems)  
> **DP = Optimal Substructure + Overlapping Subproblems** (must store and reuse subproblem solutions)
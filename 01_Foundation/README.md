# 📚 DSA Foundation Notes
> **Topic:** Asymptotic Analysis & Characterizing Running Time  
> Handwritten notes converted to structured reference — covers Big-O, Big-Omega, Big-Theta, Little notations, Time Complexity Analysis, Recurrence Relations (Master Theorem, Recursion Tree, Akra-Bazzi), and Loop Analysis patterns.

---

## 📑 Table of Contents

1. [Why Asymptotic Analysis?](#1-why-asymptotic-analysis)
2. [Asymptotic Notations Overview](#2-asymptotic-notations-overview)
3. [Big-O Notation (Upper Bound)](#3-big-o-notation-upper-bound)
4. [Big-Omega Notation (Lower Bound)](#4-big-omega-notation-lower-bound)
5. [Big-Theta Notation (Tight Bound)](#5-big-theta-notation-tight-bound)
6. [Little-o and Little-ω Notations](#6-little-o-and-little-ω-notations)
7. [Ordering of Common Growth Rates](#7-ordering-of-common-growth-rates)
8. [Time Complexity Analysis of Iterative Code](#8-time-complexity-analysis-of-iterative-code)
9. [Loop Analysis Patterns](#9-loop-analysis-patterns)
10. [Time Complexity of Recursive Functions](#10-time-complexity-of-recursive-functions)
11. [The Master Theorem (Divide & Conquer)](#11-the-master-theorem-divide--conquer)
12. [The Recursion Tree Method](#12-the-recursion-tree-method)
13. [The Akra-Bazzi Method](#13-the-akra-bazzi-method)
14. [Space Complexity](#14-space-complexity)
15. [Quick Reference Cheat Sheet](#15-quick-reference-cheat-sheet)

---

## 1. Why Asymptotic Analysis?

In most cases, we care only about **asymptotic behavior** — i.e., how an algorithm behaves for **very large N**.

- Even with powerful computers, inefficient programs can take **too long** or use **too much memory**.
- We care about how our algorithm **behaves for very large N**.
- **Order of Growth:** Describes how fast a function grows as input size becomes large — **ignoring lower-order terms, constant factors, and higher-order terms**.

> In the expression $2n^2 + 10n + 50$, as $n \to \infty$, the $n^2$ term **dominates**. So the order of growth is $n^2$.

---

## 2. Asymptotic Notations Overview

| Notation | Name | Meaning |
|----------|------|---------|
| $O$ | Big-Oh | Upper Bound |
| $\Omega$ | Big-Omega | Lower Bound |
| $\Theta$ | Big-Theta | Average / Tight Bound |
| $o$ | Little-oh | Strictly Upper (not tight) |
| $\omega$ | Little-omega | Strictly Lower (not tight) |

---

## 3. Big-O Notation (Upper Bound)

### Definition

$f(n) = O(g(n))$ iff there **exist** positive constants $c$ and $n_0$ such that:

$$f(n) \leq c \cdot g(n) \quad \forall \; n \geq n_0$$

### Example

$$f(n) = 2n + 3$$

```
2n + 3 ≤ 10n  ;  n ≥ 1     ∴ f(n) = O(n)  ✓   (c can be 7, 8, etc.)

Idea:
  2n + 3 ≤ 2n + 3n = 5n    ∴ f(n) = O(n)  ✓  ← useful / tightest
  2n + 3 ≤ 2n² + 3n²       ∴ f(n) = O(n²) ✓  ← valid but not tight
```

> ✅ Both $O(n)$ and $O(n^2)$ are technically correct, but **we should always write the closest / tightest one.**

### Growth Rate Hierarchy

$$1 < \log n < \sqrt{n} < n < n\log n < n^2 < n^3 < \cdots < 2^n < 3^n < n^n$$

```
←————————————————————————————————————————————————————→
lower bound         average bound            upper bound
```

### Common Big-O Examples

| Expression | Tightest Big-O |
|------------|---------------|
| $2n + 3$ | $O(n)$ |
| $2n^2 + 4\log n$ | $O(n^2)$ |
| $2n + 3$ written as $O(n^2)$ | Valid but **not tight** |

### Big-O of Common Algorithms

| Algorithm | Time Complexity |
|-----------|----------------|
| Linear Search | $O(n)$ |
| Binary Search | $O(\log n)$ |
| Merge Sort | $O(n \log n)$ |
| Element Access (array) | $O(1)$ |
| Insertion Sort (worst) | $O(n^2)$ |

---

## 4. Big-Omega Notation (Lower Bound)

### Definition

$f(n) \in \Omega(g(n))$ means there exist positive constants $c$ and $n_0$ such that:

$$f(n) \geq c \cdot g(n) \quad \forall \; n \geq n_0$$

> **Informal:** Big-Omega can be informally thought of as **"greater than or equal to"** something. Big-Theta as **"equal"**, and Big-Oh as **"less than or equal."**

$f(n) \in \Omega(g(n))$ is called the **asymptotically lower bound** of $f(n)$.

---

## 5. Big-Theta Notation (Tight Bound)

### Definition

$f(n) \in \Theta(g(n))$ means $g(n)$ is an **asymptotically tight bound** for $f(n)$:

$$\Theta(g(n)) = \{ f(n) \;:\; \exists \text{ positive constants } c_1, c_2, n_0 \text{ s.t. } 0 \leq c_1 \cdot g(n) \leq f(n) \leq c_2 \cdot g(n) \quad \forall\; n \geq n_0 \}$$

### Worked Proof Example

**Claim:** $f(n) = \frac{n^2}{2} - 3n \in \Theta(n^2)$, i.e., find $c_1$, $c_2$, $n_0$ such that:

$$c_1 \cdot n^2 \leq \frac{n^2}{2} - 3n \leq c_2 \cdot n^2$$

**Finding $c_2$ (upper bound):**

$$\frac{n^2}{2} - 3n \leq \frac{n^2}{2} \leq c_2 \cdot n^2 \implies c_2 = \frac{1}{2}$$

**Finding $c_1$ (lower bound):**

$$\frac{n^2}{2} - 3n \geq c_1 \cdot n^2$$

Divide through by $n^2$:

$$\frac{1}{2} - \frac{3}{n} \geq c_1$$

For large $n$, the $\frac{3}{n}$ term → 0. Pick $n_0$ large enough so $\frac{3}{n}$ is small:

```
Try c₁ = 1/4:
  n²/2 - 3n ≥ n²/4
  => 2n² - 12n ≥ n²
  => n² ≥ 12n
  => n ≥ 12      ∴ holds for all n ≥ 12

∴ c₁ = 1/4,  c₂ = 1/2,  n₀ = 12
```

$$\therefore \frac{n^2}{2} - 3n = \Theta(n^2) \quad \checkmark$$

> **Key insight:** Any positive value of $c_1$ is valid here, but the constants are shown above — for simplicity they are not shown explicitly but *exist* for large enough $n$.

### Quick Examples

| Expression | Classification |
|------------|---------------|
| $N^3 + 3N^4$ | $\Theta(N^4)$ |
| $\frac{1}{N} + 5$ | $\Theta(1)$ |
| $N^N + N$ | $\Theta(N^N)$ |
| $5\log N + N^2$ | $\Theta(N^2)$ |
| $n^3 + 3n^4$ | $\in O(n^5)$ and $\in \Omega(n^3)$ and $\in \Theta(n^4)$ |

---

## 6. Little-o and Little-ω Notations

$$\text{little-}o \to 0 \qquad \text{little-}\omega \to \infty$$

### Little-o (Strict Upper Bound)

$f(n) \in o(g(n))$ iff:

$$\lim_{n \to \infty} \frac{f(n)}{g(n)} = 0$$

**Key difference from Big-O:**
- In $f(n) = O(g(n))$: bound $f(n) \leq c \cdot g(n)$ holds for **some** constant $c > 0$
- In $f(n) = o(g(n))$: bound $f(n) < c \cdot g(n)$ holds for **all** constants $c > 0$

**Example:** $2n = o(n^2)$ but $2n^2 \neq o(n^2)$

Also: $\frac{n^2}{2} = o(n^2)$ ✓ &nbsp; but &nbsp; $\frac{n^2}{2} \neq \omega(n^2)$ ✗

### Little-ω (Strict Lower Bound)

$f(n) \in \omega(g(n))$ iff:

$$\lim_{n \to \infty} \frac{f(n)}{g(n)} = \infty$$

### Summary Table

| Notation | Limit Condition | Informal Meaning |
|----------|----------------|-----------------|
| $f = O(g)$ | $\lim \frac{f}{g} < \infty$ | f grows **no faster** than g |
| $f = \Omega(g)$ | $\lim \frac{f}{g} > 0$ | f grows **at least as fast** as g |
| $f = \Theta(g)$ | $0 < \lim \frac{f}{g} < \infty$ | f and g grow at the **same rate** |
| $f = o(g)$ | $\lim \frac{f}{g} = 0$ | f grows **strictly slower** than g |
| $f = \omega(g)$ | $\lim \frac{f}{g} = \infty$ | f grows **strictly faster** than g |

---

## 7. Ordering of Common Growth Rates

$$1 \;<\; \log n \;<\; \sqrt{n} \;<\; n \;<\; n\log n \;<\; n^2 \;<\; n^3 \;<\; \cdots \;<\; 2^n \;<\; 3^n \;<\; n^n$$

> This ordering tells you which function is "bigger" asymptotically. If $f(n)$ is to the **left** of $g(n)$ in this chain, then $f(n) = o(g(n))$.

---

## 8. Time Complexity Analysis of Iterative Code

### Insertion Sort — Pseudocode

```
for (int i = 1; i < n; i++)          // line ①
    key = arr[i];                     // line ②
    int j = i - 1;                    // line ③
    while (j >= 0 && arr[j] > key)    // line ④
        arr[j+1] = arr[j];            // line ⑤
        j--;                          // line ⑥
    arr[j+1] = key;                   // line ⑦
```

### Cost Analysis per Line

| Line | Cost | # of Executions |
|------|------|-----------------|
| ① | $c_1$ | $n$ |
| ② | $c_2$ | $n - 1$ |
| ③ | $c_3$ | $n - 1$ |
| ④ | $c_4$ | $\sum_{i=1}^{n} t_i$ |
| ⑤ | $c_5$ | $\sum_{i=1}^{n} (t_i - 1)$ |
| ⑥ | $c_6$ | $\sum_{i=1}^{n} (t_i - 1)$ |
| ⑦ | $c_7$ | $n - 1$ |

### General Running Time

$$T(n) = c_1(n+1) + c_2 n + c_3 n + c_4\sum t_i + c_5\sum(t_i-1) + c_6\sum(t_i-1) + c_7 n$$

### Best Case (Already Sorted — lines ⑤,⑥ never execute)

$$T(n) = c_1(n+1) + c_2 n + c_3 n + c_4 n + c_7 n + c$$

$$\boxed{T(n) = O(n)}$$

### Worst Case (Reverse Sorted)

$$T(n) = (c_1+c_2+c_3+c_7)n + c_4 \cdot \frac{n(n+1)}{2} + (c_5+c_6)\left(\frac{n(n+1)}{2} - n\right) + c$$

$$\boxed{T(n) = O(n^2)}$$

> To characterize time complexity, we always consider the **worst case** scenario.

---

## 9. Loop Analysis Patterns

### Quick Reference Table

| # | Loop Pattern | Complexity | Key Insight |
|---|-------------|------------|-------------|
| i | `p=0; for(i=1; p<=n; i++) p=p+i;` | $O(\sqrt{n})$ | $p = k(k+1)/2 \leq n \Rightarrow k \leq \sqrt{n}$ |
| ii | `for(i=1; i<n; i=i*2)` | $O(\log_2 n)$ | $i$ doubles: $2^k \geq n \Rightarrow k = \log_2 n$ |
| iii | `for(i=n; i>=1; i=i/2)` | $O(\log_2 n)$ | $i$ halves: $n/2^k < 1 \Rightarrow k = \log_2 n$ |
| iv | `for(i=0; i*i<n; i++)` | $O(\sqrt{n})$ | $i^2 < n \Rightarrow i = \sqrt{n}$ |
| v | Single loop `for(i=0; i<n; i++)` | $O(n)$ | Runs $n$ times |
| vi | `for(i=0;i<n;i++) for(j=0;j<n;j++)` | $O(n^2)$ | Nested: $n \times n$ |
| vii | `for(i=n;i>=1;i=i/2)` | $O(\log_2 n)$ | Same as iii |
| viii | `for(i=0;i*i<n;i++)` | $O(\sqrt{n})$ | Loop stops when $i = \sqrt{n}$ |
| ix | Outer $n$, inner runs $n$ total across all outer iterations | $O(n)$ | Total inner = $n$ not $n^2$ |
| x | `p=0; for(i=0;i<n;i*=2){p++} for(j=1;j<p;j*=2)` | $O(\log\log n)$ | $p = \log_2 n$, then $\log_2 p = \log_2(\log_2 n)$ |

### Detailed Derivations

#### Pattern i — `p=0; for(i=1; p<=n; i++) { p = p+i; }`

```
After k iterations:
  p = 1 + 2 + 3 + ... + k = k(k+1)/2

Loop continues while p ≤ n:
  k(k+1)/2 ≤ n
  => k² + k ≤ 2n
  => k² ≤ 2n
  => k ≤ √(2n)
```

$$\therefore O(\sqrt{n})$$

---

#### Pattern ii — `for(i=1; i<n; i=i*2)`

```
i goes: 1 → 2 → 4 → 8 → ... → 2ᵏ

Assume loop ends when i >= n:
  2ᵏ >= n
  2ᵏ = n
  k = log₂n
```

$$\therefore O(\log_2 n)$$

---

#### Pattern iii — `for(i=n; i>=1; i=i/2)`

```
i goes: n → n/2 → n/4 → ... → n/2ᵏ

Assume loop ends when i < 1:
  n/2ᵏ < 1
  n < 2ᵏ
  n = 2ᵏ
  k = log₂n
```

$$\therefore O(\log_2 n)$$

---

#### Pattern iv — `for(i=0; i*i<n; i++)`

$$i^2 < n \implies i < \sqrt{n} \qquad \therefore O(\sqrt{n})$$

---

#### Pattern ix — Double Loop where inner depends on outer

```
for (i=0; i<n; i++) {
    for (j=0; j<n; j++) {       // runs n times total (not n² — see below)
        statement;
    }
}
```

**With `<` condition (outer runs n+1 times):**
```
Inner loop iterations:
  i=0: j = 1,...,n      → n   times
  i=1: j = 2,...,n      → n-1 times
  i=2: j = 3,...,n      → n-2 times
  ...
  i=n-1: j = n          → 1   time

Total count = (n+1) + n(n+1)/2 = (n²+3n+2)/2
```

$$\therefore O(n^2)$$

**With `<=` condition:**

$$\text{Total} = n + \frac{n(n-1)}{2} = \frac{n^2+n}{2} \qquad \therefore O(n^2)$$

**With `==` condition:** inner loop runs $\frac{n(n-1)}{2}$ times.

---

#### Pattern x — `for(i=0; i<n; i*=2)` then `for(j=1; j<p; j*=2)`

```
First loop:  p = log₂n      (p increments until i >= n)
Second loop: runs log₂p times = log₂(log₂n)
```

$$\therefore O(\log_2(\log_2 n))$$

---

## 10. Time Complexity of Recursive Functions

### Recurrence Relations

A recurrence relation expresses $T(n)$ in terms of $T$ on smaller inputs.

**Three methods to solve:**

| Method | Best For |
|--------|---------|
| Master Theorem | $T(n) = aT(n/b) + f(n)$ form |
| Recursion Tree | Visual intuition, unbalanced splits |
| Akra-Bazzi | Multiple sub-problems with different sizes |

---

## 11. The Master Theorem (Divide & Conquer)

### Setup

$$T(n) = aT\!\left(\frac{n}{b}\right) + f(n) \qquad a > 0,\; b > 1$$

where $f(n)$ is the **driving function** (cost of dividing/combining).

A master recurrence describes a divide-and-conquer algorithm that:
- Divides a problem of size $n$ into **$a$ sub-problems**, each of size $n/b$
- Solves each recursively in $T(n/b)$
- The driving function $f(n)$ is the cost of dividing the problem **before** recursion

Let $E = \log_b a$

### The 3 Cases

#### ⭐ Case 1 — Leaf-Heavy (recursion dominates)

> If $f(n) = O\!\left(n^{E - \varepsilon}\right)$ for some constant $\varepsilon > 0$  
> *(f(n) is polynomially smaller than $n^E$)*

$$\boxed{T(n) = \Theta\!\left(n^{\log_b a}\right)}$$

---

#### ⭐ Case 2 — Balanced (equal work at every level)

> If $f(n) = \Theta\!\left(n^E \cdot \log^k n\right)$ for some $k \geq 0$  
> *(f(n) equals $n^E$ up to a log factor)*

$$\boxed{T(n) = \Theta\!\left(n^{\log_b a} \cdot \log^{k+1} n\right)}$$

**Example — Merge Sort:**

$$T(n) = 2T\!\left(\frac{n}{2}\right) + \Theta(n)$$

```
a=2, b=2, f(n) = n

n^(log_b a) = n^(log₂2) = n¹

f(n) = n = Θ(n¹ · log⁰n)  →  k=0
```

$$\therefore T(n) = \Theta(n \log n) \checkmark$$

---

#### ⭐ Case 3 — Root-Heavy (driving function dominates)

> If $f(n) = \Omega\!\left(n^{E + \varepsilon}\right)$ for some $\varepsilon > 0$  
> **and** regularity condition holds: $a \cdot f(n/b) \leq c \cdot f(n)$  
> *(f(n) is polynomially larger than $n^E$)*

$$\boxed{T(n) = \Theta(f(n))}$$

**Example:**

$$T(n) = 2T\!\left(\frac{n}{2}\right) + \Theta(n^2)$$

```
a=2, b=2, f(n) = n²

n^(log_b a) = n

n² >> n polynomially (n² grows faster)
```

$$\therefore T(n) = \Theta(n^2) \checkmark$$

### Quick Decision Rule *(Unofficial Shortcut)*

```
Compare f(n) with n^(log_b a):

  f(n) smaller  →  T(n) = Θ(n^(log_b a))     [Case 1]
  f(n) equal    →  T(n) = Θ(f(n) × log n)    [Case 2]
  f(n) larger   →  T(n) = Θ(f(n))            [Case 3]
```

---

## 12. The Recursion Tree Method

### Concept

In a recursion tree, each **node** represents the cost of a **single subproblem** somewhere in the set of recursive function invocations. We sum costs level by level.

---

### Example i: $T(n) = 3T(n/4) + cn^2$

```
                        cn²                         Level 0 cost: cn²
                 /       |       \
           c(n/4)²   c(n/4)²   c(n/4)²              Level 1 cost: 3·c(n/4)² = (3/16)cn²
           /  |  \   /  |  \   /  |  \
          ...      ...      ...                      Level 2 cost: 9·c(n/16)² = (3/16)²cn²
                                                     ...
         Θ(1) Θ(1) ... Θ(1)                          Leaves: Θ(n^(log₄3))
```

**Total cost:**

$$T(n) = cn^2 \left(1 + \frac{3}{16} + \left(\frac{3}{16}\right)^2 + \cdots\right) = cn^2 \cdot \frac{1}{1 - 3/16} = cn^2 \cdot k$$

$$\boxed{T(n) = \Theta(n^2)}$$

*(Geometric series converges since 3/16 < 1 → cost dominated by root)*

---

### Example ii: $T(n) = T(n/3) + T(2n/3) + \Theta(n)$

```
                         cn                          Level 0: cn
                  /              \
           c(n/3)             c(2n/3)                Level 1: cn/3 + 2cn/3 = cn
          /       \           /       \
     c(n/9)    c(2n/9)   c(2n/9)  c(4n/9)           Level 2: cn
       ...        ...       ...      ...             ...
    Θ(1)  Θ(1)  ...  Θ(1)  Θ(1)  ...  Θ(1)
                                                     Each level sums to: cn
```

**Height of tree:**
- Left branch: $n \to n/3 \to n/9 \to \ldots$ reaches 1 after $\log_3 n$ levels
- Right branch: $n \to 2n/3 \to \ldots$ reaches 1 after $\log_{3/2} n$ levels
- Height $h = \Theta(\log n)$

$$T(n) = cn \times h = cn \times \Theta(\log n)$$

$$\boxed{T(n) = \Theta(n \log n)}$$

---

## 13. The Akra-Bazzi Method

### Form

Akra-Bazzi recurrences generalize the Master Theorem for **multiple sub-problems of different sizes**:

$$T(n) = f(n) + \sum_{i=1}^{k} a_i \, T\!\left(\frac{n}{b_i}\right) \qquad k > 0,\; a_i, b_i \in \mathbb{R},\; a_i, b_i > 1$$

### General Solution

$$T(n) = \Theta\!\left(n^p \left(1 + \int_1^n \frac{f(x)}{x^{p+1}}\, dx\right)\right)$$

where $p$ is found by solving:

$$\sum_{i=1}^{k} \frac{a_i}{b_i^p} = 1$$

### Worked Example

$$T(n) = T\!\left(\frac{n}{3}\right) + T\!\left(\frac{2n}{3}\right) + \Theta(n)$$

$$a_1 = 1,\; a_2 = 1,\; b_1 = 3,\; b_2 = \frac{3}{2},\; f(n) = n$$

**Step 1 — Find p:**

$$\frac{1}{3^p} + \frac{1}{(3/2)^p} = 1 \implies \frac{1}{3^p} + \left(\frac{2}{3}\right)^p = 1 \implies p = 1$$

**Step 2 — Apply formula:**

$$T(n) = \Theta\!\left(n^1 \left(1 + \int_1^n \frac{x}{x^{2}}\, dx\right)\right) = \Theta\!\left(n \left(1 + \int_1^n \frac{1}{x}\, dx\right)\right)$$

$$= \Theta\!\left(n \left(1 + [\log x]_1^n\right)\right) = \Theta(n(1 + \log n)) = \Theta(n + n\log n)$$

$$\boxed{T(n) = \Theta(n \log n)}$$

---

## 14. Space Complexity

**Space Complexity** measures how much **memory** an algorithm uses as input size $n$ grows.

| Data Structure / Scenario | Space Complexity |
|--------------------------|-----------------|
| 1D array of size $n$ | $O(n)$ |
| 2D array of size $n \times n$ | $O(n^2)$ |
| Constant extra variables | $O(1)$ |

> Some algorithms improve **time** complexity at the cost of **space** complexity — there's often a time-space tradeoff.

---

## 15. Quick Reference Cheat Sheet

### Notation Summary

| Notation | Formal Condition | Meaning |
|----------|-----------------|---------|
| $f = O(g)$ | $\exists\, c, n_0 : f(n) \leq c\cdot g(n) \;\forall n \geq n_0$ | Upper bound |
| $f = \Omega(g)$ | $\exists\, c, n_0 : f(n) \geq c\cdot g(n) \;\forall n \geq n_0$ | Lower bound |
| $f = \Theta(g)$ | $\exists\, c_1,c_2,n_0 : c_1 g \leq f \leq c_2 g \;\forall n \geq n_0$ | Tight bound |
| $f = o(g)$ | $\lim_{n\to\infty} \frac{f(n)}{g(n)} = 0$ | Strict upper (not tight) |
| $f = \omega(g)$ | $\lim_{n\to\infty} \frac{f(n)}{g(n)} = \infty$ | Strict lower (not tight) |

### Common Algorithm Complexities

| Algorithm | Best | Average | Worst | Space |
|-----------|------|---------|-------|-------|
| Linear Search | $O(1)$ | $O(n)$ | $O(n)$ | $O(1)$ |
| Binary Search | $O(1)$ | $O(\log n)$ | $O(\log n)$ | $O(1)$ |
| Insertion Sort | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ |
| Merge Sort | $O(n\log n)$ | $O(n\log n)$ | $O(n\log n)$ | $O(n)$ |
| Element Access | $O(1)$ | $O(1)$ | $O(1)$ | — |

### Master Theorem at a Glance

$$T(n) = aT(n/b) + f(n), \quad E = \log_b a$$

| Case | Condition | Result |
|------|-----------|--------|
| 1 — Leaf-Heavy | $f(n) = O(n^{E-\varepsilon})$ | $T(n) = \Theta(n^E)$ |
| 2 — Balanced | $f(n) = \Theta(n^E \cdot \log^k n)$ | $T(n) = \Theta(n^E \cdot \log^{k+1} n)$ |
| 3 — Root-Heavy | $f(n) = \Omega(n^{E+\varepsilon})$ | $T(n) = \Theta(f(n))$ |

### Loop Complexity Quick Reference

| Loop Pattern | Complexity |
|-------------|------------|
| `for i in range(n)` | $O(n)$ |
| `for i in range(n): for j in range(n)` | $O(n^2)$ |
| `while i < n: i *= 2` | $O(\log n)$ |
| `while p <= n: p += i; i++` | $O(\sqrt{n})$ |
| `while i*i < n: i++` | $O(\sqrt{n})$ |
| double halving loop | $O(\log \log n)$ |

---

<div align="center">

**Happy Coding! 🚀**

*"First, solve the problem. Then, write the code."*

</div>
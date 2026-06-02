You are given two categories of theme park attractions: land rides and water rides.

Land rides
landStartTime[i] – the earliest time the ith land ride can be boarded.
landDuration[i] – how long the ith land ride lasts.
Water rides
waterStartTime[j] – the earliest time the jth water ride can be boarded.
waterDuration[j] – how long the jth water ride lasts.
A tourist must experience exactly one ride from each category, in either order.

A ride may be started at its opening time or any later moment.
If a ride is started at time t, it finishes at time t + duration.
Immediately after finishing one ride the tourist may board the other (if it is already open) or wait until it opens.
Return the earliest possible time at which the tourist can finish both rides.

 

Example 1:

Input: landStartTime = [2,8], landDuration = [4,1], waterStartTime = [6], waterDuration = [3]

Output: 9

Explanation:​​​​​​​

Plan A (land ride 0 → water ride 0):
Start land ride 0 at time landStartTime[0] = 2. Finish at 2 + landDuration[0] = 6.
Water ride 0 opens at time waterStartTime[0] = 6. Start immediately at 6, finish at 6 + waterDuration[0] = 9.
Plan B (water ride 0 → land ride 1):
Start water ride 0 at time waterStartTime[0] = 6. Finish at 6 + waterDuration[0] = 9.
Land ride 1 opens at landStartTime[1] = 8. Start at time 9, finish at 9 + landDuration[1] = 10.
Plan C (land ride 1 → water ride 0):
Start land ride 1 at time landStartTime[1] = 8. Finish at 8 + landDuration[1] = 9.
Water ride 0 opened at waterStartTime[0] = 6. Start at time 9, finish at 9 + waterDuration[0] = 12.
Plan D (water ride 0 → land ride 0):
Start water ride 0 at time waterStartTime[0] = 6. Finish at 6 + waterDuration[0] = 9.
Land ride 0 opened at landStartTime[0] = 2. Start at time 9, finish at 9 + landDuration[0] = 13.
Plan A gives the earliest finish time of 9.

Example 2:

Input: landStartTime = [5], landDuration = [3], waterStartTime = [1], waterDuration = [10]

Output: 14

Explanation:​​​​​​​

Plan A (water ride 0 → land ride 0):
Start water ride 0 at time waterStartTime[0] = 1. Finish at 1 + waterDuration[0] = 11.
Land ride 0 opened at landStartTime[0] = 5. Start immediately at 11 and finish at 11 + landDuration[0] = 14.
Plan B (land ride 0 → water ride 0):
Start land ride 0 at time landStartTime[0] = 5. Finish at 5 + landDuration[0] = 8.
Water ride 0 opened at waterStartTime[0] = 1. Start immediately at 8 and finish at 8 + waterDuration[0] = 18.
Plan A provides the earliest finish time of 14.​​​​​​​

 

Constraints:

1 <= n, m <= 100
landStartTime.length == landDuration.length == n
waterStartTime.length == waterDuration.length == m
1 <= landStartTime[i], landDuration[i], waterStartTime[j], waterDuration[j] <= 1000


```
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int minLand = INT_MAX, minWater = INT_MAX, ans = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++) {
            minLand = min(minLand, landStartTime[i] + landDuration[i]);
        }
        for (int i = 0; i < waterStartTime.size(); i++) {
            minWater = min(minWater, waterStartTime[i] + waterDuration[i]);
            ans = min(ans, max(minLand, waterStartTime[i]) + waterDuration[i]);
        }
        for (int i = 0; i < landStartTime.size(); i++) {
            ans = min(ans, max(minWater, landStartTime[i]) + landDuration[i]);
        }
        return ans;
    }
};
```

```
class Solution {
    int solve(vector<int>& start1, vector<int>& duration1, vector<int>& start2,
              vector<int>& duration2) {
        int finish1 = INT_MAX;
        for (int i = 0; i < start1.size(); i++) {
            finish1 = min(finish1, start1[i] + duration1[i]);
        }

        int finish2 = INT_MAX;
        for (int i = 0; i < start2.size(); i++) {
            finish2 = min(finish2, max(start2[i], finish1) + duration2[i]);
        }
        return finish2;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int land_water =
            solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int water_land =
            solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(land_water, water_land);
    }
};
```

Here is the breakdown of the complexity and an explanation of how this algorithm functions.

Let **$L$** be the number of elements in the land vectors (`landStartTime.size()`) and **$W$** be the number of elements in the water vectors (`waterStartTime.size()`).

---

## Complexity Analysis

### Time Complexity (TC): $O(L + W)$

The algorithm processes the inputs using three independent, sequential loops (no nested loops):

1. **First loop:** Iterates through the land arrays to find `minLand`. This takes $O(L)$ time.
2. **Second loop:** Iterates through the water arrays to find `minWater` and a partial answer. This takes $O(W)$ time.
3. **Third loop:** Iterates through the land arrays again to finalize the answer. This takes $O(L)$ time.

Total Time Complexity = $O(L) + O(W) + O(L) = O(2L + W)$, which simplifies to **$O(L + W)$** (Linear Time).

### Space Complexity (SC): $O(1)$

The algorithm only allocates a few integer variables (`minLand`, `minWater`, `ans`, and loop counters) to store tracking values. It does not use any additional data structures (like arrays, vectors, or hash maps) that scale with input size. Thus, it runs in **$O(1)$** (Constant Space).

---

## Code Explanation

This code aims to find the **earliest possible finish time** considering two separate sets of tasks or paths (Land and Water). The logic assumes dependencies between the two mediums where the absolute fastest path through one medium influences the starting constraints of the other.

### Step 1: Finding the Absolute Fastest Land Route

```cpp
for (int i = 0; i < landStartTime.size(); i++) {
    minLand = min(minLand, landStartTime[i] + landDuration[i]);
}

```

This loop finds `minLand`, which represents the **earliest possible time any land activity can completely finish**.

### Step 2: Evaluating Water Paths

```cpp
for (int i = 0; i < waterStartTime.size(); i++) {
    minWater = min(minWater, waterStartTime[i] + waterDuration[i]);
    ans = min(ans, max(minLand, waterStartTime[i]) + waterDuration[i]);
}

```

* **`minWater`**: Simultaneously tracks the earliest time any water activity can completely finish on its own.
* **`ans` (Scenario A)**: It calculates a potential bottleneck finish time. If a water activity $i$ cannot start until the quickest land activity finishes, its effective start time becomes $\max(\text{minLand}, \text{waterStartTime}[i])$. Adding its duration gives a potential overall finish time. The code tracks the minimum of these values.

### Step 3: Evaluating Land Paths against Water Constraints

```cpp
for (int i = 0; i < landStartTime.size(); i++) {
    ans = min(ans, max(minWater, landStartTime[i]) + landDuration[i]);
}

```

* **`ans` (Scenario B)**: This mirrors the logic of Step 2 but in reverse. It calculates the finish times assuming a land activity $i$ is bottlenecked by the absolute earliest water finish time (`minWater`).

Finally, the code returns `ans`, which holds the minimum total completion time found across both cross-medium dependency checks.


First, let's look at the complexities of this second implementation, and then we will compare both codes side-by-side to see why this one is significantly better.

Let $L$ be the size of the land vectors and $W$ be the size of the water vectors.

---

## Complexity Analysis

### Time Complexity (TC): $O(L + W)$

The `solve` helper function contains two independent loops: One runs in $O(\text{size1})$ and the other in $O(\text{size2})$.

* `land_water` calls `solve` passing Land then Water $\rightarrow O(L + W)$
* `water_land` calls `solve` passing Water then Land $\rightarrow O(W + L)$

Total Time Complexity = $O(L + W) + O(W + L) = O(2L + 2W)$, which simplifies to **$O(L + W)$** (Linear Time).

### Space Complexity (SC): $O(1)$

The code only allocates scalar tracking variables (`finish1`, `finish2`, `land_water`, `water_land`) inside the functions. Vectors are passed by reference (`&`), meaning no duplicate memory is created. Thus, the auxiliary space is **$O(1)$** (Constant Space).

---

## Which Code is Better and Why?

**The second code (using the `solve` helper function) is drastically better.** Even though both codes share the exact same asymptotic Time Complexity ($O(L + W)$) and Space Complexity ($O(1)$), the second implementation wins on every software engineering metric:

### 1. Zero Code Duplication (DRY Principle)

* **First Code:** You had to manually write three separate loops. If you look closely, the second loop and third loop are doing almost the exact same logic, just swapping the variables between land and water. This copy-pasting is what caused the subtle typo bugs in your first draft (like mixing up `minLand` and `minWater`).
* **Second Code:** It follows the **DRY** (*Don't Repeat Yourself*) principle. By abstracting the core logic into a single `solve()` function, you write the mathematical logic exactly once.

### 2. Readability and Intent

The second code reads like a story. Look at the main function:

```cpp
int land_water = solve(landStartTime, ..., waterStartTime, ...);
int water_land = solve(waterStartTime, ..., landStartTime, ...);
return min(land_water, water_land);

```

It instantly tells the reader: *"We are calculating the minimum time if we clear Land first then Water, and comparing it to clearing Water first then Land."* The first code buries this structural symmetry inside a wall of loops.

### 3. Maintainability and Bug Fixes

If the math or business logic for how a "finish time" is calculated changes in the future, you only have to update it **once** inside the `solve()` helper function. In the first code, you would have to carefully modify multiple separate loops, which heavily increases the risk of introducing new bugs.

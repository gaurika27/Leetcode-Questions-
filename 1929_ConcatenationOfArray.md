Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

Specifically, ans is the concatenation of two nums arrays.

Return the array ans.

 

Example 1:

Input: nums = [1,2,1]
Output: [1,2,1,1,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]
Example 2:

Input: nums = [1,3,2,1]
Output: [1,3,2,1,1,3,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]
 

Constraints:

n == nums.length
1 <= n <= 1000
1 <= nums[i] <= 1000

### M1

```
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(2*n);
        for(int i=0; i<n; ++i){
           
            ans[i]=nums[i];
            ans[i+n]=nums[i];
           

        }
        return ans;       
    }
};
```

### M2

```
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> v;
        for(int j = 0;j<2;j++){
            for(int i = 0;i<size(nums);i++){
            v.push_back(nums[i]);
        }
        }
        return v;
    }
};
```
### M3

<img width="569" height="640" alt="image" src="https://github.com/user-attachments/assets/a0a72e8e-08da-47c2-9b83-a672b1672eda" />

TC=O(n)
SC=O(n)

```
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();      
        vector<int> ans(2*n);
        for(int i=0; i<2*n; i++){
            ans[i]=nums[i%n];
        }
        return ans;
    }
};

```

All three methods are correct and have the same **asymptotic time complexity**, but they differ in efficiency and coding style.

---

# Method 1 (Best)

```cpp
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n);

        for(int i = 0; i < n; ++i){
            ans[i] = nums[i];
            ans[i+n] = nums[i];
        }

        return ans;
    }
};
```

## How it works

For each element:

```cpp
nums[i]
```

copy it to

```cpp
ans[i]
```

and

```cpp
ans[i+n]
```

simultaneously.

Example:

```cpp
nums = [1,2,1]
n = 3
```

| i | ans[i] | ans[i+n] |
| - | ------ | -------- |
| 0 | 1      | 1        |
| 1 | 2      | 2        |
| 2 | 1      | 1        |

Result:

```cpp
[1,2,1,1,2,1]
```

---

## Time Complexity

Loop runs `n` times.

Each iteration performs:

```cpp
ans[i] = nums[i];
ans[i+n] = nums[i];
```

Both are O(1).

Therefore:

[
TC = O(n)
]

---

## Space Complexity

Output array size:

```cpp
2n
```

Therefore:

[
SC = O(n)
]

(We ignore constants in Big-O.)

---

## Why it's good

✅ Single loop

✅ No extra computations

✅ No dynamic resizing

✅ Direct indexing

This is usually the most efficient solution.

---

# Method 2

```cpp
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> v;

        for(int j = 0; j < 2; j++){
            for(int i = 0; i < size(nums); i++){
                v.push_back(nums[i]);
            }
        }

        return v;
    }
};
```

---

## How it works

Append the whole array twice.

Example:

```cpp
v = []

Pass 1:
[1,2,1]

Pass 2:
[1,2,1,1,2,1]
```

---

## Time Complexity

Outer loop:

```cpp
2 times
```

Inner loop:

```cpp
n times
```

Total operations:

```cpp
2*n
```

Therefore:

[
TC = O(n)
]

---

## Space Complexity

Result stores:

```cpp
2n elements
```

Therefore:

[
SC = O(n)
]

---

## Hidden Cost

Because:

```cpp
vector<int> v;
```

starts empty, `push_back()` may trigger reallocations.

For example:

```cpp
capacity:
1 → 2 → 4 → 8 → 16 ...
```

The amortized complexity remains O(1) per push, so overall still O(n).

But there is some extra overhead compared to Method 1.

You could improve it:

```cpp
v.reserve(2*nums.size());
```

---

## Pros

✅ Very readable

✅ Easy to understand

---

## Cons

❌ Possible reallocations

❌ More memory copying internally

❌ Slightly slower in practice

---

# Method 3

```cpp
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(2*n);

        for(int i = 0; i < 2*n; i++){
            ans[i] = nums[i % n];
        }

        return ans;
    }
};
```

---

## How it works

Use modulo to cycle through the original array.

Example:

```cpp
nums = [1,2,1]
n = 3
```

| i | i%n | value |
| - | --- | ----- |
| 0 | 0   | 1     |
| 1 | 1   | 2     |
| 2 | 2   | 1     |
| 3 | 0   | 1     |
| 4 | 1   | 2     |
| 5 | 2   | 1     |

Result:

```cpp
[1,2,1,1,2,1]
```

---

## Time Complexity

Loop runs:

```cpp
2n times
```

Each iteration:

```cpp
i % n
```

plus assignment.

Therefore:

[
TC = O(n)
]

---

## Space Complexity

Output vector:

```cpp
2n
```

Therefore:

[
SC = O(n)
]

---

## Hidden Cost

Modulo:

```cpp
i % n
```

is more expensive than simple indexing.

Big-O doesn't change, but constant factors are larger.

---

# Comparison

| Method | Time | Space | Notes                                  |
| ------ | ---- | ----- | -------------------------------------- |
| M1     | O(n) | O(n)  | Fastest, direct indexing               |
| M2     | O(n) | O(n)  | May reallocate during push_back        |
| M3     | O(n) | O(n)  | Extra modulo operation every iteration |

---

# Which is best?

**Method 1 is the best solution.** 💖

Reasons:

1. Only `n` loop iterations.
2. No modulo calculations.
3. No vector growth/reallocation.
4. Direct writes to final positions.
5. Smallest constant factor.

In interviews and competitive programming, **Method 1 is generally considered the optimal and cleanest approach** for this problem. 💕

https://neetcode.io/solutions/concatenation-of-array

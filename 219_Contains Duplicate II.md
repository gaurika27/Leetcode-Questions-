Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105

```
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      unorderest_set<int> window;
      int L=0;
      for(int R=0; R<nums.size(); R++){
        if(R-L<k){
          window.erase(nums[L]);
          L++;
        }
        if(window.find(nums[R})!=window.end()){
          return true;
        }
        window.insert(nums[R]);
      }
      return false;        
    }
};
```

TC=O(n)
SC=O(min(n,k))

Let's analyze it carefully, because many students mistakenly think the nested-looking operations make it O(n²). They don't. 💖

```cpp id="z6e7uh"
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        int L = 0;

        for (int R = 0; R < nums.size(); R++) {
            if (R - L > k) {
                window.erase(nums[L]);
                L++;
            }
            if (window.find(nums[R]) != window.end()) {
                return true;
            }
            window.insert(nums[R]);
        }
        return false;
    }
};
```

---

### Time Complexity

#### Outer Loop

```cpp id="8t9g4r"
for (int R = 0; R < nums.size(); R++)
```

runs exactly `n` times.

So we start with:

[
O(n)
]

---

### Operations inside the loop

#### 1. Erase

```cpp id="w3u40v"
window.erase(nums[L]);
```

For an `unordered_set`:

[
O(1)
]

average case.

---

#### 2. Find

```cpp id="izg2bk"
window.find(nums[R])
```

Average:

[
O(1)
]

---

#### 3. Insert

```cpp id="wfrv22"
window.insert(nums[R]);
```

Average:

[
O(1)
]

---

### Total Work

For each iteration we do a constant number of:

```cpp id="lj8t2l"
find
insert
erase
```

operations.

Each is O(1) average.

Therefore:

[
n x O(1)=O(n)
]

---

### Why isn't it O(n²)?

A common doubt:

> "The window keeps changing, so are we repeatedly scanning it?"

No.

Because:

```cpp id="0a29vb"
unordered_set
```

uses hashing.

We never iterate through the set.

We only do:

```cpp id="k0hzrj"
find
insert
erase
```

which are O(1) average.

So there is no nested traversal.

---

#### Space Complexity

##### What is stored?

```cpp id="9b2qsk"
unordered_set<int> window;
```

The set contains only elements inside the current window.

---

#### Window Size

This condition:

```cpp id="h1vmp8"
if (R - L > k)
```

ensures the window never grows too large.

At any moment:

```text id="1l5yr4"
R - L <= k
```

Therefore the set contains at most:

```text id="77c7w0"
k + 1
```

elements.

---

#### Space Complexity

[
O(k+1)
]

Ignoring constants:

[
\boxed{O(k)}
]

---

#### Worst Case

If:

```cpp id="i53ubn"
k >= n
```

then the set may store all elements.

So worst-case space becomes:

[
\boxed{O(n)}
]

---

### Final Answer

##### Time Complexity

[
\boxed{O(n)}
]

because each element is inserted, searched, and possibly erased once, and all hash-table operations are O(1) average.

---

##### Space Complexity

[
\boxed{O(\min(n,k))}
]

because the sliding window stores at most `k + 1` elements, but never more than `n` elements. 💕

https://neetcode.io/solutions/contains-duplicate-ii

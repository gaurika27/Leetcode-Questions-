A shop is selling candies at a discount. For every two candies sold, the shop gives a third candy for free.

The customer can choose any candy to take away for free as long as the cost of the chosen candy is less than or equal to the minimum cost of the two candies bought.

For example, if there are 4 candies with costs 1, 2, 3, and 4, and the customer buys candies with costs 2 and 3, they can take the candy with cost 1 for free, but not the candy with cost 4.
Given a 0-indexed integer array cost, where cost[i] denotes the cost of the ith candy, return the minimum cost of buying all the candies.

 

Example 1:

Input: cost = [1,2,3]
Output: 5
Explanation: We buy the candies with costs 2 and 3, and take the candy with cost 1 for free.
The total cost of buying all candies is 2 + 3 = 5. This is the only way we can buy the candies.
Note that we cannot buy candies with costs 1 and 3, and then take the candy with cost 2 for free.
The cost of the free candy has to be less than or equal to the minimum cost of the purchased candies.
Example 2:

Input: cost = [6,5,7,9,2,2]
Output: 23
Explanation: The way in which we can get the minimum cost is described below:
- Buy candies with costs 9 and 7
- Take the candy with cost 6 for free
- We buy candies with costs 5 and 2
- Take the last remaining candy with cost 2 for free
Hence, the minimum cost to buy all candies is 9 + 7 + 5 + 2 = 23.
Example 3:

Input: cost = [5,5]
Output: 10
Explanation: Since there are only 2 candies, we buy both of them. There is not a third candy we can take for free.
Hence, the minimum cost to buy all candies is 5 + 5 = 10.
 

Constraints:

1 <= cost.length <= 100
1 <= cost[i] <= 100


```
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int ans=0;
        int n=cost.size();
        for(int i=0; i<n; i++){
            if(i%3==2) continue;
            else ans+=cost[i];            
        }    
        return ans;    
    }
};
```

Time Complexity
Step 1: Sorting
sort(cost.begin(), cost.end(), greater<int>());

Sorting n elements takes:

O(nlogn)

This is the most expensive operation in the algorithm.

Step 2: Traversing the array
for(int i = 0; i < n; i++)

The loop runs n times.

Inside the loop:

i % 3

and

ans += cost[i]

are both O(1).

Therefore the loop takes:

O(n)
Total Time Complexity
O(nlogn)+O(n)

Since O(n log n) grows faster than O(n), we keep the dominant term:

O(nlogn)
	​

Space Complexity

Extra variables used:

int ans;
int n;
int i;

These take constant space.

No additional arrays, vectors, maps, or sets are created.

Therefore:

O(1)
	​


auxiliary space.

Why does the algorithm work?

After sorting descending:

9 8 7 6 5 4 3 2 1

The candies are naturally grouped as:

(9,8,7)
(6,5,4)
(3,2,1)

For every group of three:

Pay for first candy
Pay for second candy
Third candy is free

The free candies are at indices:

2, 5, 8, 11, ...

which satisfy:

i % 3 == 2

So you simply skip adding those candies to ans.

Interview Explanation

You could say:

"I sort the candies in descending order so that in every group of three candies, the cheapest candy in that group becomes free while the two more expensive candies are paid for. After sorting, every third candy (indices 2, 5, 8, ...) is the free one, so I skip those indices and add the rest to the total cost. Sorting takes O(n log n) time, and the traversal takes O(n), giving an overall time complexity of O(n log n). Since I only use a few variables besides the input array, the auxiliary space complexity is O(1)." 💕

# [2105. Watering Plants II](https://leetcode.com/problems/watering-plants-ii/)


## Description:

<p>Alice and Bob want to water <code>n</code> plants in their garden. The plants are arranged in a row and are labeled from <code>0</code> to <code>n - 1</code> from left to right where the <code>i<sup>th</sup></code> plant is located at <code>x = i</code>.</p>

<p>Each plant needs a specific amount of water. Alice and Bob have a watering can each, <strong>initially full</strong>. They water the plants in the following way:</p>
<ul>
  <li>Alice waters the plants in order from <strong>left to right</strong>, starting from the <code>0<sup>th</sup></code> plant. Bob waters the plants in order from <strong>right to left</strong>, starting from the <code>(n - 1)<sup>th</sup></code> plant. They begin watering the plants <strong>simultaneously</strong>.</li>
  <li>It takes the same amount of time to water each plant regardless of how much water it needs.</li>
  <li>Alice/Bob <strong>must</strong> water the plant if they have enough in their can to <strong>fully</strong> water it. Otherwise, they <strong>first</strong> refill their can (instantaneously) then water the plant.</li>
  <li>In case both Alice and Bob reach the same plant, the one with <strong>more</strong> water currently in his/her watering can should water this plant. If they have the same amount of water, then Alice should water this plant.</li>
</ul>
<p>Given a <strong>0-indexed</strong> integer array <code>plants</code> of <code>n</code> integers, where <code>plants[i]</code> is the amount of water the <code>i<sup>th</sup> plant needs, and two integers <code>capacityA</code> and <code>capacityB</code> representing the capacities of Alice's and Bob's watering cans respectively, return <em>the <strong>number of times</strong> they have to refill to water all the plants.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> plants = [2,2,3,3], capacityA = 5, capacityB = 5
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
- Initially, Alice and Bob have 5 units of water each in their watering cans.
- Alice waters plant 0, Bob waters plant 3.
- Alice and Bob now have 3 units and 2 units of water respectively.
- Alice has enough water for plant 1, so she waters it. Bob does not have enough water for plant 2, so he refills his can then waters it.
So, the total number of times they have to refill to water all the plants is 0 + 0 + 1 + 0 = 1.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> plants = [2,2,3,3], capacityA = 3, capacityB = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
- Initially, Alice and Bob have 3 units and 4 units of water in their watering cans respectively.
- Alice waters plant 0, Bob waters plant 3.
- Alice and Bob now have 1 unit of water each, and need to water plants 1 and 2 respectively.
- Since neither of them have enough water for their current plants, they refill their cans and then water the plants.
So, the total number of times they have to refill to water all the plants is 0 + 1 + 1 + 0 = 2.
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> plants = [5], capacityA = 10, capacityB = 8
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
- There is only one plant.
- Alice's watering can has 10 units of water, whereas Bob's can has 8 units. Since Alice has more water in her can, she waters this plant.
So, the total number of times they have to refill is 0.
</pre>


## Constraints:

<ul>
  <li><code>n == plants.length</code></li>
  <li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
  <li><code>1 &lt;= plants[i] &lt;= 10<sup>6</sup></code></li>
  <li><code>max(plants[i]) &lt;= capacityA, capacityB &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution :

<strong>Logical Thinking</strong>
<p>Just use <strong>Two Pointers</strong> and <strong>Simulate</strong> the whole process.</p>


<strong>C++</strong>

```
//  Topic   : 2105. Watering Plants II (https://leetcode.com/problems/watering-plants-ii/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int l = 0, r = plants.size() - 1, ans = 0, ca = capacityA, cb = capacityB;
        while (l <= r)
        {
            if (l == r)
            {
                int cf, c = max<int>(ca, cb);
                if (c == ca)
                    cf = capacityA;
                else
                    cf = capacityB;
                if (c < plants[l])
                    ans++;
            }
            else
            {
                if (ca >= plants[l])
                    ca -= plants[l];
                else
                {
                    ans++;
                    ca = capacityA - plants[l];
                }
                if (cb >= plants[r])
                    cb -= plants[r];
                else
                {
                    ans++;
                    cb = capacityB - plants[r];
                }
            }
            l++;
            r--;
        }
        return ans;
    }
};
```
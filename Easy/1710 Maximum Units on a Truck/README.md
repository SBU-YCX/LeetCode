# [1710. Maximum Units on a Truck](https://leetcode.com/problems/maximum-units-on-a-truck/)


## Description:

<p>You are assigned to put some amount of boxes onto <strong>one truck</strong>. You are given a 2D array <code>boxTypes</code>, where <code>boxTypes[i] = [numberOfBoxes<sub>i</sub>, numberOfUnitsPerBox<sub>i</sub>]</code>:</p>

<ul>
    <li><code>numberOfBoxes<sub>i</sub></code> is the number of boxes of type <code>i</code>.</li>
    <li><code>numberOfUnitsPerBox<sub>i</sub></code> is the number of units in each box of the type <code>i</code>.</li>
</ul>

<p>You are also given an integer <code>truckSize</code>, which is the <strong>maximum</strong> number of <strong>boxes</strong> that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed <code>truckSize</code>.</p>

<p>Return <em>the <strong>maximum</strong> total number of <strong>units</strong> that can be put on the truck.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
<strong>Output:</strong> 8
<strong>Explanation:</strong> There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
<strong>Output:</strong> 91
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= boxTypes.length &lt;= 1000</code></li>
    <li><code>1 &lt;= numberOfBoxes<sub>i</sub>, numberOfUnitsPerBox<sub>i</sub> &lt;= 1000</code>
    <li><code>1 &lt;= truckSize &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since the total allowed number of boxes is fixed, we should choose those with more units first. So, we can <strong>sort</strong> the boxes by their units and add the boxes in a <strong>greedy</strong> way.</p>


<strong>C++</strong>

```
//  Topic   : 1710. Maximum Units on a Truck
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(logN)


class Solution {
public:       
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    });
        int ans = 0;
        for (int i = 0; i < boxTypes.size(); i++)
        {
            ans += boxTypes[i][1] * min(truckSize, boxTypes[i][0]);
            truckSize -= boxTypes[i][0];
            if (truckSize <= 0)
                break;
        }
        return ans;
    }
};
```
# [2126. Destroying Asteroids](https://leetcode.com/problems/destroying-asteroids/)


## Description:

<p>You are given an integer <code>mass</code>, which represents the original mass of a planet. You are further given an integer array <code>asteroids</code>, where <code>asteroids[i]</code> is the mass of the <code>i<sup>th</sup></code> asteroid.</p>

<p>You can arrange for the planet to collide with the asteroids in <strong>any arbitrary order</strong>. If the mass of the planet is <strong>greater than or equal to</strong> the mass of the asteroid, the asteroid is <strong>destroyed</strong> and the planet <strong>gains</strong> the mass of the asteroid. Otherwise, the planet is destroyed.</p>

<p>Return <em><code>true</code> if <strong>all</strong> asteroids can be destroyed.</em> Otherwise, return <em><code>false</code>.</em></p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> mass = 10, asteroids = [3,9,19,5,21]
<strong>Output:</strong> true
<strong>Explanation:</strong> 
One way to order the asteroids is [9,19,5,3,21]:
- The planet collides with the asteroid with a mass of 9. New planet mass: 10 + 9 = 19
- The planet collides with the asteroid with a mass of 19. New planet mass: 19 + 19 = 38
- The planet collides with the asteroid with a mass of 5. New planet mass: 38 + 5 = 43
- The planet collides with the asteroid with a mass of 3. New planet mass: 43 + 3 = 46
- The planet collides with the asteroid with a mass of 21. New planet mass: 46 + 21 = 67
All asteroids are destroyed.
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> mass = 5, asteroids = [4,9,23,4]
<strong>Output:</strong> false
<strong>Explanation:</strong> 
The planet cannot ever gain enough mass to destroy the asteroid with a mass of 23.
After the planet destroys the other asteroids, it will have a mass of 5 + 4 + 9 + 4 = 22.
This is less than 23, so a collision would not destroy the last asteroid.
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= mass &lt;= 10<sup>5</sup></code></li>
    <li><code>1 &lt;= asteroids.length &lt;= 10<sup>5</sup></code></li>
    <li><code>1 &lt;= asteroids[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Since the planet can gain the mass of the asteroid after destroying it, the optimal order is to collide with the smaller asteroids first, then the planet will become larger and larger, and is more probable to destroy those larger asteroids. Thus, we can <strong>sort</strong> the array <code>asteroids</code> first, and try to destroy them one by one. If <code>mass &lt; asteroids[i]</code>, the planet will be destroyed.</p>


<strong>C++</strong>

```
//  Topic   : 2126. Destroying Asteroids (https://leetcode.com/problems/destroying-asteroids/)
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(1)


class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int n = asteroids.size();
        long long massl = mass;
        for (int i = 0; i < n; i++)
        {
            if (asteroids[i] <= massl)
                massl += asteroids[i];
            else
                return false;
        }
        return true;
    }
};
```

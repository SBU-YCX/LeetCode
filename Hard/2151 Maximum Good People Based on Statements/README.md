# [2151. Maximum Good People Based on Statements](https://leetcode.com/problems/maximum-good-people-based-on-statements/)


## Description:

<p>There are two types of persons:</p>

<ul>
    <li>The <strong>good person</strong>: The person who always tells the truth.</li>
    <li>The <strong>bad person</strong>: The person who might tell the truth and might lie.</li>
</ul>

<p>You are given a <strong>0-indexed</strong> 2D integer array <code>statements</code> of size <code>n x n</code> that represents the statements made by <code>n</code> people about each other. More specifically, <code>statements[i][j]</code> could be one of the following:</p>

<ul>
    <li><code>0</code> which represents a statement made by person <code>i</code> that person <code>j</code> is a <strong>bad</strong> person.</li>
    <li><code>1</code> which represents a statement made by person <code>i</code> that person <code>j</code> is a <strong>good</strong> person.</li>
    <li><code>2</code> represents that <strong>no statement</strong> is made by person <code>i</code> about person <code>j</code>.</li>
</ul>

<p>Additionally, no person ever makes a statement about themselves. Formally, we have that <code>statements[i][i] = 2</code> for all <code>0 &lt;= i &lt; n</code>.</p>

<p>Return <em>the <strong>maximum</strong> number of people who can be <strong>good</strong> based on the statements made by the <code>n</code> people.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2022/01/15/logic1.jpg)
<pre>
<strong>Input:</strong> statements = [[2,1,2],[1,2,2],[2,0,2]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Each person makes a single statement.
- Person 0 states that person 1 is good.
- Person 1 states that person 0 is good.
- Person 2 states that person 1 is bad.
Let's take person 2 as the key.
- Assuming that person 2 is a good person:
    - Based on the statement made by person 2, person 1 is a bad person.
    - Now we know for sure that person 1 is bad and person 2 is good.
    - Based on the statement made by person 1, and since person 1 is bad, they could be:
        - telling the truth. There will be a contradiction in this case and this assumption is invalid.
        - lying. In this case, person 0 is also a bad person and lied in their statement.
    <strong>- Following that person 2 is a good person, there will be only one good person in the group.</strong>
- Assuming that person 2 is a bad person:
    - Based on the statement made by person 2, and since person 2 is bad, they could be:
        - telling the truth. Following this scenario, person 0 and 1 are both bad as explained before.
            <strong>- Following that person 2 is bad but told the truth, there will be no good persons in the group.</strong>
        - lying. In this case person 1 is a good person.
            - Since person 1 is a good person, person 0 is also a good person.
            <strong>- Following that person 2 is bad and lied, there will be two good persons in the group.</strong>
We can see that at most 2 persons are good in the best case, so we return 2.
Note that there is more than one way to arrive at this conclusion.
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2022/01/15/logic2.jpg)
<pre>
<strong>Input:</strong> statements = [[2,0],[0,2]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> Each person makes a single statement.
- Person 0 states that person 1 is bad.
- Person 1 states that person 0 is bad.
Let's take person 0 as the key.
- Assuming that person 0 is a good person:
    - Based on the statement made by person 0, person 1 is a bad person and was lying.
    <strong>- Following that person 0 is a good person, there will be only one good person in the group.</strong>
- Assuming that person 0 is a bad person:
    - Based on the statement made by person 0, and since person 0 is bad, they could be:
        - telling the truth. Following this scenario, person 0 and 1 are both bad.
            <strong>- Following that person 0 is bad but told the truth, there will be no good persons in the group.</strong>
        - lying. In this case person 1 is a good person.
            <strong>- Following that person 0 is bad and lied, there will be only one good person in the group.</strong>
We can see that at most, one person is good in the best case, so we return 1.
Note that there is more than one way to arrive at this conclusion.
</pre>


## Constraints:

<ul>
    <li><code>n == statements.length == statements[i].length</code></li>
    <li><code>2 &lt;= n &lt;= 15</code></li>
    <li><code>statements[i][j]</code> is either <code>0</code>, <code>1</code>, or <code>2</code>.</li>
    <li><code>statements[i][i] == 2</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>From the given description, we can infer that</p>

<ul>
    <li>if <code>i</code> is a <strong>good</strong> person, then</li>
    <ul>
        <li><code>j</code> is a <strong>good</strong> person if <code>statements[i][j] == 1</code></li>
        <li><code>j</code> is a <strong>bad</strong> person if <code>statements[i][j] == 0</code> or <code>statements[j][i] == 0</code></li>
    </ul>
</ul> 

<p>From above, we can solve the problem with <strong>backtracking</strong> and use a vector <code>good</code> to indicate the judgement up to now, then iterate over each person <code>i</code> and</p>

<ul>
    <li>if <code>good[i] == 1</code>, i.e., <code>i</code> is already judged as a good person, just update <code>good</code>, check if there is a conflict with the previous judgements and go to the next index</li>
    <li>if <code>good[i] == -1</code>, i.e., <code>i</code> is already judged as a bad person, check the conflict and go to the next index</li>
    <li>if <code>good[i] == 0</code>, i.e., <code>i</code> is not judged yet, we can assume he/she is</li>
    <ul>
        <li>good person, i.e. <code>good[i] = 1</code> and recheck <code>i</code></li>
        <li>bad person, i.e. <code>good[i] = -1</code> and recheck <code>i</code></li>
    </ul>
</ul>


<strong>C++</strong>

```
// Topic     : 2151. Maximum Good People Based on Statements
// Author    : YCX 
// Time      : O(N * 2 ^ N) 
// Space     : O(N * 2 ^ N)


class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        unordered_map<int, vector<int>> can, cannot;
        int n = statements.size(), ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (statements[i][j] == 1)
                    can[i].push_back(j);
                else if (statements[i][j] == 0)
                {
                    cannot[j].push_back(i);
                    cannot[i].push_back(j);
                }
            }
        vector<int> good(n, 0);
        backtracking(can, cannot, 0, n, good, ans);
        return ans;
    }
    
private: 
    void backtracking(unordered_map<int, vector<int>>& can, unordered_map<int, vector<int>>& cannot, int k, int& n, vector<int> good, int& ans)
    {
        if (k == n)
        {
            int cur = 0;
            for (auto& i : good)
                if (i == 1)
                    cur++;
            ans = max<int>(ans, cur);
            return;
        }
        if (good[k] == -1)
            backtracking(can, cannot, k + 1, n, good, ans);
        else if (good[k] == 1)
        {
            for (auto& j : can[k])
            {
                if (good[j] == -1)
                    return;
                good[j] = 1;
            }
            for (auto& j : cannot[k])
            {
                if (good[j] == 1)
                    return;
                good[j] = -1;
            }
            backtracking(can, cannot, k + 1, n, good, ans);
        }
        else
        {
            good[k] = 1;
            backtracking(can, cannot, k, n, good, ans);
            good[k] = -1;
            backtracking(can, cannot, k, n, good, ans);
        }
    }
};
```

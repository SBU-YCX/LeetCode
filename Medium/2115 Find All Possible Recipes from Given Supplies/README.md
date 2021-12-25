# [2115. Find All Possible Recipes from Given Supplies](https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/)


## Description:

<p>You have information about <code>n</code> different recipes. You are given a string array <code>recipes</code> and a 2D string array <code>ingredients</code>. The <code>i<sup>th</sup></code> recipe has the name <code>recipes[i]</code>, and you can <strong>create</strong> it if you have <strong>all</strong> the needed ingredients from <code>ingredients[i]</code>. Ingredients to a recipe may need to be created from <strong>other</strong> recipes, i.e., <code>ingredients[i]</code> may contain a string that is in <code>recipes</code>.</p>

<p>You are also given a string array <code>supplies</code> containing all the ingredients that you initially have, and you have an infinite supply of all of them.</p>

<p>Return <em>a list of all the recipes that you can create.</em> You may return the answer in <strong>any order</strong>.</p>

<p>Note that two recipes may contain each other in their ingredients.</p>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
<strong>Output:</strong> ["bread"]
<strong>Explanation:</strong>
We can create "bread" since we have the ingredients "yeast" and "flour".
</pre>

<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
<strong>Output:</strong> ["bread","sandwich"]
<strong>Explanation:</strong> 
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
<strong>Output:</strong> ["bread","sandwich","burger"]
<strong>Explanation:</strong> 
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".
</pre>


## Constraints:

<ul>
  <li><code>n == recipes.length == ingredients.length</code></li>
  <li><code>1 &lt;= n &lt;= 100</code></li>
  <li><code>1 &lt;= ingredients[i].length, supplies.length &lt;= 100</code></li>
  <li><code>1 &lt;= recipes[i].length, ingredients[i][j].length, supplies[k].length &lt;= 10</code></li>
  <li><code>recipes[i]</code>, <code>ingredients[i][j]</code>, and <code>supplies[k]</code> consist only of lowercase English letters.</li>
  <li>All the values of <code>recipes</code> and <code>supplies</code> combined are unique.</li>
  <li>Each <code>ingredients[i]</code> does not contain any duplicate values.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Actually, since every recipe can only be created with all the needed ingredients and the ingredients may contain other recipes, we can regard this problem as a <strong>topological order</strong> problem. Firstly, using a <strong>hash table</strong> to store each ingredient and all the recipes which need it. Then, a vector <code>degree</code> is used to indicate whether all the ingredients are obtained for each recipe. We push all the initial supplies into a queue <code>q</code>, for each item in the queue, decrese the degree of the its recipes, if the recipe's degree is <code>0</code>, push it into the queue. Continuously doing this until <code>q</code> is empty, record all the recipes which occurs in the queue.</p>

 
<strong>C++</strong>

```
//  Topic   ：2115. Find All Possible Recipes from Given Supplies (https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N + M)


class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size(), k = supplies.size();
        unordered_map<string, vector<string>> ingred;
        unordered_map<string, int> degree;
        for (int i = 0; i < n; i++)
        {
            degree[recipes[i]] = ingredients[i].size();
            for (auto& j : ingredients[i])
                ingred[j].push_back(recipes[i]);
        }
        unordered_set<string> s(recipes.begin(), recipes.end());
        queue<string> q;
        for (int i = 0; i < k; i++)
            q.push(supplies[i]);
        vector<string> ans;
        while (!q.empty())
        {
            string cur = q.front();
            q.pop();
            if (s.count(cur))
                ans.push_back(cur);
            for (auto& nxt : ingred[cur])
            {
                degree[nxt]--;
                if (degree[nxt] == 0)
                    q.push(nxt);
            }
        }
        return ans;
    }
};
```

# [1598. Crawler Log Folder](https://leetcode.com/problems/crawler-log-folder/)


## Description:

<p>The Leetcode file system keeps a log each time some user performs a <strong>change folder</strong> operation.</p>

<p>The operations are described below:</p>

<ul>
    <li><code>"../"</code> : Move to the parent folder of the current folder. (If you are already in the main folder, <strong>remain in the same folder</strong>).</li>
    <li><code>"./"</code> : Remain in the same folder.</li>
    <li><code>"x/"</code> : Move to the child folder named <code>x</code> (This folder is <strong>guaranteed to always exist</strong>).</li>
</ul>

<p>You are given a list of strings <code>logs</code> where <code>logs[i]</code> is the operation performed by the user at the <code>i<sup>th</sup></code> step.</p>

<p>The file system starts in the main folder, then the operations in <code>logs</code> are performed.</p>

<p>Return <em>the minimum number of operations needed to go back to the main folder after the change folder operations.</em></p>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2020/09/09/sample_11_1957.png)
<pre>
<strong>Input:</strong> logs = ["d1/","d2/","../","d21/","./"]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Use this change folder operation "../" 2 times and go back to the main folder.
</pre>

<strong>Example 2:</strong>
<br/>![ex2](https://assets.leetcode.com/uploads/2020/09/09/sample_22_1957.png)
<pre>
<strong>Input:</strong> logs = ["d1/","d2/","./","d3/","../","d31/"]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
</pre>

<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> logs = ["d1/","../","../","../"]
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
</pre>


## Constraints:

<ul>
    <li><code>1 &lt;= logs.length &lt;= 10<sup>3</sup></code></li>
    <li><code>2 &lt;= logs[i].length &lt;= 10</code></li>
    <li><code>logs[i]</code> contains lowercase English letters, digits, <code>'.'</code>, and <code>'/'</code>.</li>
    <li><code>logs[i]</code> follows the format described in the statement.</li>
    <li>Folder names consist of lowercase English letters and digits.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Use a <strong>stack</strong>.</p>


<strong>C++</strong>

```
//  Topic   : 1598. Crawler Log Folder
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> folders;
        int m = logs.size();
        for (int i = 0; i < m; i++)
        {
            if (logs[i] == "./")
                continue;
            else if (logs[i] == "../")
            {
                if (!folders.empty())
                    folders.pop();
            }
            else
                folders.push(logs[i]);
        }
        return folders.size();
    }
};
```
# [2043. Simple Bank System](https://leetcode.com/problems/simple-bank-system/)


## Description:

<p>You have been tasked with writing a program for a popular bank that will automate all its incoming transactions (transfer, deposit, and withdraw). The bank has <code>n</code> accounts numbered from <code>1</code> to <code>n</code>. The initial balance of each account is stored in a <strong>0-indexed</strong> integer array <code>balance</code>, with the <code>(i + 1)<sup>th</sup></code> account having an initial balance of <code>balance[i]</code>.</p>
<p>Execute all the <strong>valid</strong> transactions. A transaction is <strong>valid</strong> if:</p>
<ul>
  <li>The given account number(s) are between <code>1</code> and <code>n</code>, and</li>
  <li>The amount of money withdrawn or transferred from is <strong>less than or equal to</strong> the balance of the account.</li>
</ul>
<p>Implement the <code>Bank</code> class:</p>
<ul>
  <li><code>Bank(long[] balance)</code> Initializes the object with the <strong>0-indexed</strong> integer array <code>balance</code>.</li>
  <li><code>boolean transfer(int account1, int account2, long money)</code> Transfers <code>money</code> dollars from the account numbered <code>account1</code> to the account numbered <code>account2</code>. Return <code>true</code> if the transaction was successful, <code>false</code> otherwise.</li>
  <li><code>boolean deposit(int account, long money)</code> Deposit <code>money</code> dollars into the account numbered <code>account</code>. Return <code>true</code> if the transaction was successful, <code>false</code> otherwise.</li>
  <li><code>boolean withdraw(int account, long money)</code> Withdraw <code>money</code> dollars from the account numbered <code>account</code>. Return <code>true</code> if the transaction was successful, <code>false</code> otherwise.</li>
</ul>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong>
["Bank", "withdraw", "transfer", "deposit", "transfer", "withdraw"]
[[[10, 100, 20, 50, 30]], [3, 10], [5, 1, 20], [5, 20], [3, 4, 15], [10, 50]]
<strong>Output:</strong>
[null, true, true, true, false, false]
<strong>Explanation:</strong> 
Bank bank = new Bank([10, 100, 20, 50, 30]);
bank.withdraw(3, 10);    // return true, account 3 has a balance of $20, so it is valid to withdraw $10.
                         // Account 3 has $20 - $10 = $10.
bank.transfer(5, 1, 20); // return true, account 5 has a balance of $30, so it is valid to transfer $20.
                         // Account 5 has $30 - $20 = $10, and account 1 has $10 + $20 = $30.
bank.deposit(5, 20);     // return true, it is valid to deposit $20 to account 5.
                         // Account 5 has $10 + $20 = $30.
bank.transfer(3, 4, 15); // return false, the current balance of account 3 is $10,
                         // so it is invalid to transfer $15 from it.
bank.withdraw(10, 50);   // return false, it is invalid because account 10 does not exist.
</pre>


## Constraints:

<ul>
  <li><code>n == balance.length</code></li>
  <li><code>1 &lt;= n, account, account1, account2 &lt;= 10<sup>5</sup></code></li>
  <li><code>0 &lt;= balance[i], money &lt;= 10<sup>12</sup></code></li>
  <li>At most <code>10<sup>4</sup></code> calls will be made to <strong>each</strong> function <code>transfer</code>, <code>deposit</code>, <code>withdraw</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Use a <strong>hash table</strong> to store the account information.</p>

 
<strong>C++</strong>

```
//  Topic   ：2043. Simple Bank System (https://leetcode.com/problems/simple-bank-system/)
//  Author  : YCX
//  Time    : O(1)
//  Space   : O(N)


class Bank {
public:
    Bank(vector<long long>& balance) {
        int n = balance.size();
        for (int i = 0; i < n; i++)
            accounts[i + 1] = balance[i];
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (accounts.count(account1) == 0 || accounts.count(account2) == 0)
            return false;
        if (accounts[account1] < money)
            return false;
        accounts[account1] -= money;
        accounts[account2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (accounts.count(account) == 0)
            return false;
        accounts[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (accounts.count(account) == 0)
            return false;
        if (accounts[account] < money)
            return false;
        accounts[account] -= money;
        return true;
    }
    
private: 
    unordered_map<int, long long> accounts;
};
```

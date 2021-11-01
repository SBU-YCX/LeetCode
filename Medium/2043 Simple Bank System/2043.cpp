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


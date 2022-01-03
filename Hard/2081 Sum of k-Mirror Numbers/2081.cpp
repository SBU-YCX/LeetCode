// Topic     : 2081. Sum of k-Mirror Numbers (https://leetcode.com/problems/sum-of-k-mirror-numbers/)
// Author    : YCX (https://github.com/SBU-YCX/LeetCode/tree/main/Hard/2081%20Sum%20of%20k-Mirror%20Numbers)
// Time      : O(F(N)) where F(N) is the number of all palindrome numbers of base 10 smaller than the nth k-mirror number
// Space     : O(F(N))


class Solution {
public:
    long long kMirror(int k, int n) {
        long long sum = 0;
        for (long long level = 1; n > 0; level *= 10)
        {
            for (long long num = level; n > 0 && num < level * 10; num++)
            {
                long long palindodd = genPalind(num, true);
                if (isPalind(palindodd, k))
                {
                    sum += palindodd;
                    n--;
                }
            }
            for (long long num = level; n > 0 && num < level * 10; num++)
            {
                long long palindeven = genPalind(num, false);
                if (isPalind(palindeven, k))
                {
                    sum += palindeven;
                    n--;
                }
            }
        }
        return sum;
    }
    
private: 
    long long genPalind(long long half, bool o2e)
    {
        long long ans = half;
        if (o2e)
            half /= 10;
        while (half)
        {
            ans = ans * 10 + half % 10;
            half /= 10;
        }
        return ans;
    }
    
    bool isPalind(long long& num, int& base)
    {
        string s = toBase(num, base);
        int l = 0, r = s.length() - 1;
        while (l < r)
            if (s[l++] != s[r--])
                return false;
        return true;
    }
    
    string toBase(long long num, int& base)
    {
        string ans = "";
        while (num)
        {
            ans += (num % base + '0');
            num /= base;
        }
        return ans;
    }
};

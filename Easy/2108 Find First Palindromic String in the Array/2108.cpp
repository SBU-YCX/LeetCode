//  Topic   : 2108. Find First Palindromic String in the Array (https://leetcode.com/problems/find-first-palindromic-string-in-the-array/)
//  Author  : YCX
//  Time    : O(N * M)
//  Space   : O(1)


class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto& w : words)
            if (isPalindrome(w))
                return w;
        return "";
    }
    
private: 
    bool isPalindrome(string& s)
    {
        int l = 0, r = s.length() - 1;
        while (l < r)
        {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};

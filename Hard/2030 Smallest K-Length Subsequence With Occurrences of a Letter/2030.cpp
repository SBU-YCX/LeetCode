// Topic     : 2030. Smallest K-Length Subsequence With Occurrences of a Letter (https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/)
// Author    : YCX (https://github.com/SBU-YCX/LeetCode/tree/main/Hard/2030%20Smallest%20K-Length%20Subsequence%20With%20Occurrences%20of%20a%20Letter)
// Time      : O(N)
// Space     : O(N)


class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int n = s.length(), m = count(s.begin(), s.end(), letter);
        string ans;
        for (int i = 0; i < n; i++)
        {
            int l = ans.length();
            while (l > 0 && ans.back() > s[i] && (n - i + l) > k)
            {
                if (ans.back() == letter && m <= repetition)
                    break;
                else if (ans.back() == letter)
                    repetition++;
                ans.pop_back();
                l = ans.length();
            }
            if (l < k)
                if (s[i] == letter || k - l > repetition)
                {
                    ans += s[i];
                    if (s[i] == letter)
                        repetition--;
                }
            if (s[i] == letter)
                m--;
        }
        return ans;
    }
};

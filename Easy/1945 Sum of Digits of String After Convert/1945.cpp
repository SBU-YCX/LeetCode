//  Topic   : 1945. Sum of Digits of String After Convert
//  Author  : YCX
//  Time    : O(N * K)
//  Space   : O(N)


class Solution {
public:
    int getLucky(string s, int k) {
        string ans = "";
        for (int i = 0; i < s.length(); i++)
            ans += to_string(s[i] - 'a' + 1);
        int sum;
        for (int i = 0; i < k; i++)
        {
            sum = 0;
            for (int j = 0; j < ans.length(); j++)
                sum += (ans[j] - '0');
            ans = to_string(sum);
        }
        return sum;
    }
};

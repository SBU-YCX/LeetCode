//  Topic   ：2024. Maximize the Confusion of an Exam (https://leetcode.com/problems/maximize-the-confusion-of-an-exam/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length(), l = -1, r = 0, m = 0, ans = 0;
        while (r < n)
        {
            if (answerKey[r] == 'F')
                m += 1;
            while (m > k)
            {
                l++;
                if (answerKey[l] == 'F')
                    m -= 1;
            }
            ans = max<int>(ans, r - l);
            r++;
        }
        l = -1, r = 0, m = 0;
        while (r < n)
        {
            if (answerKey[r] == 'T')
                m += 1;
            while (m > k)
            {
                l++;
                if (answerKey[l] == 'T')
                    m -= 1;
            }
            ans = max<int>(ans, r - l);
            r++;
        }
        return ans;
    }
};

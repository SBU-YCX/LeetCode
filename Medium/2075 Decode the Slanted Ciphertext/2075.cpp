//  Topic   ：2075. Decode the Slanted Ciphertext (https://leetcode.com/problems/decode-the-slanted-ciphertext/)
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(NN)


class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int l = encodedText.length(), m = rows, n = l / m, k = 0;
        string ans = "";
        for (int c = 0; c < n; c++)
            for (int r = c; r < l; r += (n + 1))
                ans += encodedText[r];
        int p = ans.length() - 1;
        while (p >= 0 && ans[p] == ' ')
            p--;
        return ans.substr(0, p + 1);
    }
};

// Topic     : 2117. Abbreviating the Product of a Range (https://leetcode.com/problems/abbreviating-the-product-of-a-range/)
// Author    : YCX
// Time      : O(N)
// Space     : O(1)


class Solution {
public:
    string abbreviateProduct(int left, int right) {
        int c = 0;
        long long pre = 1, suf = 1, mod = 1e12;
        for (int i = left; i <= right; i++)
        {
            long long cur(i);
            pre *= cur;
            while (pre > mod)
                pre /= 10;
            suf *= cur;
            while (suf % 10 == 0)
            {
                suf /= 10;
                c++;
            }
            suf %= mod;
        }
        string pres = to_string(pre), sufs = to_string(suf), ans = "";
        if (sufs.length() <= 10)
            ans = sufs + "e" + to_string(c);
        else
        {
            if (sufs.length() < 5)
                sufs = string(5 - sufs.length(), '0') + sufs;
            ans = pres.substr(0, 5) + "..." + sufs.substr(sufs.length() - 5) + "e" + to_string(c);
        }
        return ans;
    }
};

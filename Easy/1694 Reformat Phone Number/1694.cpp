//  Topic   : 1694. Reformat Phone Number
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class Solution {
public:
    string reformatNumber(string number) {
        string digits = "";
        for (int i = 0; i < number.length(); i++)
            if (number[i] <= '9' && number[i] >= '0')
                digits += number[i];
        string ans = "";
        int n = digits.length();
        switch(n % 3)
        {
            case 0:
                for (int i = 0; i < n - 3; i += 3)
                {
                    ans += digits[i];
                    ans += digits[i + 1];
                    ans += digits[i + 2];
                    ans += '-';
                }
                ans += digits[n - 3];
                ans += digits[n - 2];
                ans += digits[n - 1];  
                break;
            case 1:
                for (int i = 0; i < n - 4; i += 3)
                {
                    ans += digits[i];
                    ans += digits[i + 1];
                    ans += digits[i + 2];
                    ans += '-';
                }
                ans += digits[n - 4];
                ans += digits[n - 3];
                ans += '-';
                ans += digits[n - 2];
                ans += digits[n - 1];  
                break;
            case 2:
                for (int i = 0; i < n - 2; i += 3)
                {
                    ans += digits[i];
                    ans += digits[i + 1];
                    ans += digits[i + 2];
                    ans += '-';
                }
                ans += digits[n - 2];
                ans += digits[n - 1];  
                break;
        }
        return ans;
    }
};

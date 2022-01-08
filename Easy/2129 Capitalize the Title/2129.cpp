//  Topic   : 2129. Capitalize the Title
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    string capitalizeTitle(string title) {
        int r = title.length(), l = 0;
        while (l < r)
        {
            int p = title.find(' ', l);
            if (p == -1)
                p = r;
            int m = p - l;
            if (m <= 2)
            {
                while (l < p)
                {
                    if (title[l] <= 'Z' && title[l] >= 'A')
                        title[l] = (title[l] - 'A' + 'a');
                    l++;
                }
            }
            else
            {
                if (title[l] <= 'z' && title[l] >= 'a')
                    title[l] = (title[l] - 'a' + 'A');
                l++;
                while (l < p)
                {
                    if (title[l] <= 'Z' && title[l] >= 'A')
                        title[l] = (title[l] - 'A' + 'a');
                    l++;
                }
            }
            l = p + 1;
        }
        return title;
    }
};

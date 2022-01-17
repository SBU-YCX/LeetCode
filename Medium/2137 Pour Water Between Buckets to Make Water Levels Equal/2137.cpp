//  Topic   : 2137. Pour Water Between Buckets to Make Water Levels Equal
//  Author  : YCX
//  Time    : O(Nlog(M)) [M is the maximum element]
//  Space   : O(1)


class Solution {
public:
    double equalizeWater(vector<int>& buckets, int loss) {
        double l = 0, r = *max_element(buckets.begin(), buckets.end());
        while (r - l > 1e-8)
        {
            double m = (l + r) / 2;
            double need = 0, extra = 0;
            for (auto& i : buckets)
            {
                need += max<double>(0, m - i);
                extra += max<double>(0, i - m);
            }
            if (need <= extra * (100 - loss) / 100)
                l = m;
            else
                r = m;
        }
        return l;
    }
};

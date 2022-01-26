//  Topic   : 1629. Slowest Key
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(26)


class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        vector<int> duration(26, 0);
        int max_duration, n = releaseTimes.size(), prev = 0;
        char c;
        for (int i = 0; i < n; i++)
        {
            int idx = keysPressed[i] - 'a';
            duration[idx] = max<int>(duration[idx], releaseTimes[i] - prev);
            prev = releaseTimes[i];
        }
        max_duration = duration[0], c = 'a';
        for (int i = 1; i < 26; i++)
            if (duration[i] >= max_duration)
            {
                max_duration = duration[i];
                c = 'a' + i;
            }
        return c;
    }
};

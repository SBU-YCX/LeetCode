//  Topic   : 2037. Minimum Number of Moves to Seat Everyone (https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/)
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(N)


class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int n = seats.size(), ans = 0;
        for (int i = 0; i < n; i++)
            ans += abs(seats[i] - students[i]);
        return ans;
    }
};

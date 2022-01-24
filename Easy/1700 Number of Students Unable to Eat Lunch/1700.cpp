//  Topic   : 1700. Number of Students Unable to Eat Lunch
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int num_st = 0, num_sa = 0;
        for (int i = 0; i < students.size(); i++)
            if (students[i] == 1)
                num_st += 1;
        for (int j = 0; j < sandwiches.size(); j++)
            if (sandwiches[j] == 1)
                num_sa += 1;
        if (num_st > num_sa)
        {
            int num_0 = 0;
            for (int j = sandwiches.size() - 1; j >= 0; j--)
                if (sandwiches[j] == 0)
                {
                    num_0 += 1;
                    if (num_0 == num_st - num_sa)
                        return sandwiches.size() - j;
                }
        }
        else if (num_st < num_sa)
        {
            int num_1 = 0;
            for (int j = sandwiches.size() - 1; j >= 0; j--)
                if (sandwiches[j] == 1)
                {
                    num_1 += 1;
                    if (num_1 == num_sa - num_st)
                        return sandwiches.size() - j;
                }
        }
        return 0;
    }
};

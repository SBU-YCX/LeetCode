//  Topic   : 1826. Faulty Sensor
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(1)


class Solution {
public:
    int badSensor(vector<int>& sensor1, vector<int>& sensor2) {
        int m = sensor1.size(), n = sensor2.size(), i = 0, j = 0;
        while (i < m && j < n)
        {
            if (sensor1[i] == sensor2[j])
            {
                i++;
                j++;
            }
            else
            {
                if (i < m - 1 && j < n - 1 && sensor1[i + 1] == sensor2[j] && sensor1[i] == sensor2[j + 1])
                {
                    i++;
                    j++;
                }
                else if (i < m - 1 && sensor1[i + 1] == sensor2[j])
                    return 2;
                else if (j < n - 1 && sensor1[i] == sensor2[j + 1])
                    return 1;
                else
                {
                    i++;
                    j++;
                }
            }
        }
        return -1;
    }
};

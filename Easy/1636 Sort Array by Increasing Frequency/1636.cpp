//  Topic   : 1636. Sort Array by Increasing Frequency
//  Author  : YCX
//  Time    : O(NlogN)
//  Space   : O(N)


class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, vector<int>> freq;
        sort(nums.begin(), nums.end());
        int m = nums.size() - 1; 
        for (int i = m - 1; i >= 0; i--)
            if (nums[i] != nums[i + 1])
            {
                int f = m - i;
                freq[f].push_back(nums[i + 1]);
                m = i;
            }
        freq[m + 1].push_back(nums[0]);
        vector<int> ans;
        map<int, vector<int>>::iterator iter = freq.begin();
        while (iter != freq.end())
        {
            for (int j = 0; j < iter->second.size(); j++)
                for (int k = 0; k < iter->first; k++)
                    ans.push_back(iter->second[j]);
            iter++;
        }
        return ans;
    }
};

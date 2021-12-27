//  Topic   : 2080. Range Frequency Queries (https://leetcode.com/problems/range-frequency-queries/)
//  Author  : YCX
//  Time    : O(logN) for query()
//            O(N) for RangeFreqQuery()
//  Space   : O(N)


class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++)
            data[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
        int l = lower_bound(data[value].begin(), data[value].end(), left) - data[value].begin();
        int r = upper_bound(data[value].begin(), data[value].end(), right) - data[value].begin();
        return (r - l);
    }
    
private: 
    unordered_map<int, vector<int>> data;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */

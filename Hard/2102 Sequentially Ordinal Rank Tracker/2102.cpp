//  Topic   : 2102. Sequentially Ordinal Rank Tracker (https://leetcode.com/problems/sequentially-ordinal-rank-tracker/)
//  Author  : YCX
//  Time    : get - O(1), add - O(logN)
//  Space   : O(N)


class SORTracker {
public:
    SORTracker() {
        iter = s.begin();
    }
    
    void add(string name, int score) {
        auto newiter = s.insert({-score, name}).first;
        if (iter == s.end() || *newiter < *iter)
            iter--;
    }
    
    string get() {
        string ans = iter->second;
        iter++;
        return ans;
    }
    
private: 
    set<pair<int, string>> s;
    set<pair<int, string>>::iterator iter;
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */

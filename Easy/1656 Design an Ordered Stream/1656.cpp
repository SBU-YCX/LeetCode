//  Topic   : 1656. Design an Ordered Stream
//  Author  : YCX
//  Time    : O(N)
//  Space   : O(N)


class OrderedStream {
public:
    OrderedStream(int n) {
        for (int i = 0; i < n; i++)
            data.push_back("-");
        pos = 0;
    }
    
    vector<string> insert(int idKey, string value) {
        data[idKey - 1] = value;
        vector<string> ans;
        int i;
        if (idKey == pos + 1)
        {
            for (i = pos; i < data.size(); i++)
            {
                if (data[i] == "-")
                    break;
                else
                    ans.push_back(data[i]);
            }
            pos = i;
        }
        return ans;
    }
    
private: 
    vector<string> data;
    int pos;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */

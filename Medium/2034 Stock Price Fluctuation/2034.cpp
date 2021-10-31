//  Topic   ：2034. Stock Price Fluctuation (https://leetcode.com/problems/stock-price-fluctuation/)
//  Author  : YCX
//  Time    : O(logN) [for each operation]
//  Space   : O(N)


class StockPrice {
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (m.find(timestamp) != m.end())
        {
            int old = m[timestamp];
            s.erase(s.lower_bound(old));
        }
        m[timestamp] = price;
        s.insert(price);
    }
    
    int current() {
        return (*m.begin()).second;
    }
    
    int maximum() {
        return *s.rbegin();
    }
    
    int minimum() {
        return *s.begin();
    }
    
private: 
    map<int, int, greater<int>> m;
    multiset<int> s;
};

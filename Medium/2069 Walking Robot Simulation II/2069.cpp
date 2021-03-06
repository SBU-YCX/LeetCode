//  Topic   ：2069. Walking Robot Simulation II (https://leetcode.com/problems/walking-robot-simulation-ii/)
//  Author  : YCX
//  Time    : O(1) for each operation
//  Space   : O(1)


class Robot {
public:
    Robot(int width, int height) {
        n = 0;
        w = width;
        h = height;
        m = h + w - 2;
        d = 0;
    }
    
    void move(int num) {
        n += num;
    }
    
    vector<int> getPos() {
        int x, y, k = n % m;
        if ((n / m) % 2)
        {
            x = (k < w) ? w - 1 - k : 0;
            y = (k < w) ? h - 1 : h - 1 - k + w - 1;
        } 
        else
        {
            x = (k < w) ? k : w - 1;
            y = (k < w) ? 0 : k - w + 1;
        } 
        return {x, y};
    }
    
    string getDir() {
        if (n == 0)
            return "East";
        int k = n % m;
        if ((n / m) % 2)
            return (k == 0) ? "North" : ((k > w - 1) ? "South" : "West");
        else
            return (k == 0) ? "South" : ((k > w - 1) ? "North" : "East");
    }
    
private: 
    int n, w, h, m, d;
};

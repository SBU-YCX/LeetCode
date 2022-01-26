//  Topic   : 1603. Design Parking System
//  Author  : YCX
//  Time    : O(1)
//  Space   : O(1)


class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        b = big;
        m = medium; 
        s = small;
    }
    
    bool addCar(int carType) {
        switch (carType) {
            case 1:
                if (b > 0)
                {
                    b -= 1;
                    return true;
                }
                break;
            case 2:
                if (m > 0)
                {
                    m -= 1;
                    return true;
                }
                break;
            case 3:
                if (s > 0)
                {
                    s -= 1;
                    return true;
                }
                break;
        }
        return false;
    }
    
private: 
    int b;
    int m;
    int s;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

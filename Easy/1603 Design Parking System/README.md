# [1603. Design Parking System](https://leetcode.com/problems/design-parking-system/)


## Description:

<p>Design a parking system for a parking lot. The parking lot has three kinds of parking spaces: big, medium, and small, with a fixed number of slots for each size.</p>

<p>Implement the <code>ParkingSystem</code> class:</p>

<ul>
    <li><code>ParkingSystem(int big, int medium, int small)</code> Initializes object of the <code>ParkingSystem</code> class. The number of slots for each parking space are given as part of the constructor.</li>
    <li><code>bool addCar(int carType)</code> Checks whether there is a parking space of <code>carType</code> for the car that wants to get into the parking lot. <code>carType</code> can be of three kinds: big, medium, or small, which are represented by <code>1</code>, <code>2</code>, and <code>3</code> respectively. <strong>A car can only park in a parking space of its</strong> <code>carType</code>. If there is no space available, return <code>false</code>, else park the car in that size space and return <code>true</code>.</li>
</ul>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> ["ParkingSystem", "addCar", "addCar", "addCar", "addCar"]
[[1, 1, 0], [1], [2], [3], [1]]
<strong>Output:</strong> [null, true, true, false, false]
<strong>Explanation:</strong> ParkingSystem parkingSystem = new ParkingSystem(1, 1, 0);
parkingSystem.addCar(1); // return true because there is 1 available slot for a big car
parkingSystem.addCar(2); // return true because there is 1 available slot for a medium car
parkingSystem.addCar(3); // return false because there is no available slot for a small car
parkingSystem.addCar(1); // return false because there is no available slot for a big car. It is already occupied.
</pre>


## Constraints:

<ul>
    <li><code>0 &lt;= big, medium, small &lt;= 1000</code></li>
    <li><code>carType</code> is <code>1</code>, <code>2</code>, or <code>3</code></li>
    <li>At most <code>1000</code> calls will be made to <code>addCar</code></li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Use three variables <code>b</code>, <code>m</code> and <code>s</code> to store the number of remaining available slots of each type.</p>


<strong>C++</strong>

```
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
```
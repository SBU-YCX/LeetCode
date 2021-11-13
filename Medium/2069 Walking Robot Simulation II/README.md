# [2069. Walking Robot Simulation II](https://leetcode.com/problems/walking-robot-simulation-ii/)


## Description:

<p>A <code>width x height</code> grid is on an XY-plane with the <strong>bottom-left</strong> cell at <code>(0, 0)</code> and the <strong>top-right</strong> cell at <code>(width - 1, height - 1)</code>. The grid is aligned with the four cardinal directions (<code>"North"</code>, <code>"East"</code>, <code>"South"</code>, and <code>"West"</code>). A robot is <strong>initially</strong> at cell <code>(0, 0)</code> facing direction <code>"East"</code>.</p>

<p>The robot can be instructed to move for a specific number of <strong>steps</strong>. For each step, it does the following.</p>
<ol>
    <li>Attempts to move <strong>forward one</strong> cell in the direction it is facing.</li>
    <li>If the cell the robot is <strong>moving to</strong> is <strong>out of bounds</strong>, the robot instead <strong>turns</strong> 90 degrees <strong>counterclockwise</strong> and retries the step.</li>
</ol>

<p>After the robot finishes moving the number of steps required, it stops and awaits the next instruction.</p>

<p>Implement the <code>Robot</code> class:</p>
<ul>
    <li><code>Robot(int width, int height)</code> Initializes the <code>width x height</code> grid with the robot at <code>(0, 0)</code> facing <code>"East"</code>.</li>
    <li><code>void move(int num)</code> Instructs the robot to move forward <code>num</code> steps.</li>
    <li><code>int[] getPos()</code> Returns the current cell the robot is at, as an array of length 2, <code>[x, y]</code>.</li>
    <li><code>String getDir()</code> Returns the current direction of the robot, <code>"North"</code>, <code>"East"</code>, <code>"South"</code>, or <code>"West"</code>.</li>
</ul>


## Examples:

<strong>Example 1:</strong>
<br/>![ex1](https://assets.leetcode.com/uploads/2021/10/09/example-1.png)</br>
<pre>
<strong>Input:</strong> 
["Robot", "move", "move", "getPos", "getDir", "move", "move", "move", "getPos", "getDir"]
[[6, 3], [2], [2], [], [], [2], [1], [4], [], []]
<strong>Output:</strong> 
[null, null, null, [4, 0], "East", null, null, null, [1, 2], "West"]
<strong>Explanation:</strong> 
Robot robot = new Robot(6, 3); // Initialize the grid and the robot at (0, 0) facing East.
robot.move(2);  // It moves two steps East to (2, 0), and faces East.
robot.move(2);  // It moves two steps East to (4, 0), and faces East.
robot.getPos(); // return [4, 0]
robot.getDir(); // return "East"
robot.move(2);  // It moves one step East to (5, 0), and faces East.
                // Moving the next step East would be out of bounds, so it turns and faces North.
                // Then, it moves one step North to (5, 1), and faces North.
robot.move(1);  // It moves one step North to (5, 2), and faces North (not West).
robot.move(4);  // Moving the next step North would be out of bounds, so it turns and faces West.
                // Then, it moves four steps West to (1, 2), and faces West.
robot.getPos(); // return [1, 2]
robot.getDir(); // return "West"
</pre>


## Constraints:

<ul>
  <li><code>2 &lt;= width, height &lt;= 100</code></li>
  <li><code>1 &lt;= num &lt;= 10<sup>5</sup></code></li>
  <li>At most <code>10<sup>4</sup></code> calls <strong>in total</strong> will be made to <code>move</code>, <code>getPos</code>, and <code>getDir</code>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>We can see that the robot will repeatedly move along the boundaries of the grid, i.e. the position and direction will be the same every <code>2 * ((width - 1) + (height - 1))</code> steps. So, for the whole process, we only need to count the total number of steps <code>n</code> and decide the location and direction. Here, we divide the route into two part in further, left-top and right-bottom since they are symmetrical, and each half takes <code>m = width + height - 2</code> steps, if (n / m) is odd, the robot is on the left-top side, otherwise, right-bottom side. Then, we only need to compare <code>n % m</code> and <code>width</code> to see whether it is on the horizontal boundary or the vertical boundary. </p>

<p>Note: when the robot is at <code>(0, 0)</code>, there two cases for the direction: when it is the beginning, the direction is <code>"East"</code>; then when it comes back later, the direction is <code>"South"</code>.</p>

 
<strong>C++</strong>

```
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

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
```

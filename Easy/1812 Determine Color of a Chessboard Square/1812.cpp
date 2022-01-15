//  Topic   : 1812. Determine Color of a Chessboard Square
//  Author  : YCX
//  Time    : O(1)
//  Space   : O(1)


class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x = coordinates[0] - 'a';
        int y = coordinates[1] - '0';
        return ((x + y) % 2 == 0);
    }
};

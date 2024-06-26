#include <iostream>
#include <cmath>

/**
 * Collinearity
 *
 * You are given two vectors starting from the origin (x=0, y=0) with coordinates (x1,y1) and (x2,y2).
 * Your task is to find out if these vectors are collinear. Collinear vectors are vectors that lie on the same straight line.
 * They can be directed in the same or opposite directions. One vector can be obtained from another by multiplying it by a certain number.
 * In terms of coordinates, vectors (x1, y1) and (x2, y2) are collinear if (x1, y1) = (k*x2, k*y2) , where k is any number acting as a coefficient.
 *
 * (1,1,1,1) ➞ true
 * (1,2,2,4) ➞ true
 * (1,1,6,1) ➞ false
 * (1,2,-1,-2) ➞ true
 * (1,2,1,-2) ➞ false
 * (4,0,11,0) ➞ true
 * (0,1,6,0) ➞ false
 * (4,4,0,4) ➞ false
 * (0,0,0,0) ➞ true
 * (0,0,1,0) ➞ true
 * (5,7,0,0) ➞ true
 */

bool collinearity(int x1, int y1, int x2, int y2)
{
    if ((x1 == 0 && y1 == 0) || (x2 == 0 && y2 == 0)) {
        return true;
    }

    if ((x1== 0 && x2 == 0) || (y1 == 0 && y2 == 0)) {
        return true;
    }

    if ((x2 == 0 && y2 != 0) || (x2 != 0 && y2 == 0)) {
        return false;
    }

    return x1 / static_cast<double>(x2) == y1 / static_cast<double>(y2);
}

int main()
{
    std::cout << collinearity(1, 2, 1, -2) << std::endl;
    return 0;
}

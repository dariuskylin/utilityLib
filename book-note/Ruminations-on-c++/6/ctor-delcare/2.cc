/*
 * =====================================================================================
 *
 *       Filename:  1.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/29/2012 11:56:59 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<iostream>

class Point {
    public:
        Point( int x=0, int y=0 ) : xval(x), yval(y) {}
        int x() const {return xval;}
        int y() const {return yval;}
        Point& x( int xv ) {
            xval = xv;
            return *this;
        }
        Point& y( int yv ) {
            yval = yv;
            return *this;
        }
    private:
        int xval;
        int yval;
};

int main() {
    Point a[10];
    return 0;
}

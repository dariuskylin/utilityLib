/*
 * =====================================================================================
 *
 *       Filename:  pre.1.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/17/2012 01:09:24 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<iostream>

class Point{
    public:
        Point( int x = 0 ): _x(x){}
        int x() const {return _x; }
    private:
        int _x;
};

inline std::ostream&
operator<<(std::ostream &os, const Point &pt ){
    return os<<pt.x();
}

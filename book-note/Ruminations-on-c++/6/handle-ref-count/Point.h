/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *
 *       Filename:  Point.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/30/2012 01:07:53 AM
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 *
 * =====================================================================================
 */
#ifndef BOOK_NOTE_RUMINATIONS_ON_C++_6_HANDLE_REF_COUNT_POINT_H_
#define BOOK_NOTE_RUMINATIONS_ON_C++_6_HANDLE_REF_COUNT_POINT_H_
class Point {
    public:
        Point(): xval(0), yval(0) { }
        Point(int x, int y): xval(x), yval(y) { }
        int x() const { return xval; }
        int y() const { return yval; }
        Point& x(int xv) {
            xval = xv;
            return *this;
        }
        Point& y(int yv) {
            yval = yv;
            return *this;
        }
    private:
        int xval, yval;
};
#endif  // BOOK_NOTE_RUMINATIONS_ON_C++_6_HANDLE_REF_COUNT_POINT_H_

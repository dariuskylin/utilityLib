/*
 * =====================================================================================
 *
 *       Filename:  pow3.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/12/2012 05:10:47 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _POW3_HPP_
#define _POW3_HPP_

template<int N>
class Pow3 {
    public:
        enum { result = 3*Pow3<N-1>::result };
};
template<>
class Pow3<0> {
    public:
        enum { result = 1 };
};
#endif  // _POW3_HPP_

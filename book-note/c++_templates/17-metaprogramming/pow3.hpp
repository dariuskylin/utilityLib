/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  pow3.hpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/12/2012 09:00:39 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#ifndef _POW3_HPP_
#define _POW3_HPP_

template<int N>
class Pow3 {
    public:
        enum { result = 3*Pow3<N-1>::result; };
};

template<>
class Pow3<0> {
    public:
        enum { result = 1; };
};
#endif  // _POW3_HPP_

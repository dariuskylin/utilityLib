/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg2.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/14/2012 10:45:16 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<boost/static_assert.hpp>

template<typename T>
void accepts_values_between_1_and_10() {
    BOOST_STATIC_ASSERT(T>=1&&T<=10);
}

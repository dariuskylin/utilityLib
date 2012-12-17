/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg3.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/14/2012 10:47:02 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<boost/static_assert.hpp>

void expects_ints_to_be_4_bytes() {
    BOOST_STATIC_ASSERT(sizeof(int) == 4);
}

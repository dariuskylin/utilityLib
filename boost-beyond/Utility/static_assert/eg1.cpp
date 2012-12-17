/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/14/2012 10:42:34 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<boost/static_assert.hpp>
#include<boost/type_traits.hpp>

//该类要求实例化时所用的类型必须是int
template<typename T>
class only_compatible_with_integral_types {
    BOOST_STATIC_ASSERT(boost::is_integral<T>::value);
}

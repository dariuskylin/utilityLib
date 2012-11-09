/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  2.2.cc
 *    Description:  
 *        Version:  1.0
 *        Created:  11/06/2012 11:50:35 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>


template < typename T >
inline T const& max ( T const& a, T const& b){
    return a > b? a : b;
}

int main() {
    std::cout<<max(4, 7)<<std::endl;
    std::cout<<max(4.2, 5.6)<<std::endl;
    //std::cout<<max(4.2, 4)<<std::endl;  不匹配模板函数类型，必须显示声明，不然int型的4不会隐式变为double
    std::cout<<max(4.2, static_cast<double>(4))<<std::endl;
    std::cout<<max<double>(4.2, 4)<<std::endl;
    return 0;
}

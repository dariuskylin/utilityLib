/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  2.4.cc
 *    Description:  
 *        Version:  1.0
 *        Created:  11/06/2012 02:44:12 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>

inline int const& max( int const& a, int const& b){
    return a < b ? b : a;
}

template < typename T >
inline T const& max ( T const& a, T const& b) {
    return a < b ? b : a;
}

template < typename T >
inline T const& max ( T const& a, T const& b, T const& c ){
    return ::max ( ::max( a, b ), c );
}
int main(){
    ::max(7, 42, 68);
    ::max(7.0, 42.0);
    ::max('a', 'b');
    ::max(7,42);
    ::max<>(7,42);
    ::max<double>(7,42);
    ::max('a',42.7);
    return 0;
}

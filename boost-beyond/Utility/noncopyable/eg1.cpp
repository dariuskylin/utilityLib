/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/14/2012 07:14:11 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<boost/utility.hpp>

class please_dont_make_copies : boost::noncopyable { }

int main() {
    please_dont_make_copies d1;
    please_dont_make_copies d2(d1);
    please_dont_make_copies d3;
    d3 = d1;
    return 0;
}

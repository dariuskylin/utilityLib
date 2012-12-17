/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/14/2012 06:58:04 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include"deleter.hpp"
#include"to_be_deleted.hpp"

int main() {
    to_be_deleted* p = new to_be_deleted;
    deleter d;
    d.delete_it(p);
    return 0;
}

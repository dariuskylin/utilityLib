/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  deleter.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/14/2012 06:54:37 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include"deleter.hpp"
#include<boost/checked_delete.hpp>

void deleter::delete_it(to_be_deleted* p) {
    //delete p;
    boost::checked_delete(p);
}

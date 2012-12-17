/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  deleter.hpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/14/2012 06:52:59 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#ifndef DELETER_HPP_
#define DELETER_HPP_
class to_be_deleted;
class deleter {
    public:
        void delete_it(to_be_deleted* p);
};
#endif

/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  file.hpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/13/2012 05:36:06 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#ifndef _FILE_HPP_
#define _FILE_HPP_
class file {
    public:
        file(char const *name, char const *mode);
        void read(void* data, size_t size);
    private:
        class impl;
        shared_ptr<impl> pimpl_;
};
#endif  // _FILE_HPP_

/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  file.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/13/2012 05:38:26 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include"file.hpp"

class file::impl {
    private:
        impl(impl const &);
        impl& operator=(impl const &);
    public:
        impl(char const *name, char const* mode) { }
        ~impl() { }
        void read(void* data, size_t size) { }
};

file::file(char const* name, char const* mode) : 
    pimpl_(new impl(name,mode)) {
}
void file::read(void* data, size_t size){
    pimpl_->read(data, size);
}

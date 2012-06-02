/*
 * =====================================================================================
 *
 *       Filename:  noncopyable.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/31/2012 07:30:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _NONCOPYABLE_H_
#define _NONCOPYABLE_H_
namespace NDSL
{
    namespace noncopyable_
    {
    class noncopyable
        {
            protected:
                noncopyable() {}
                ~noncopyable() {}
            private:
                noncopyable(const noncopyable &);
                const noncopyable& operator=(const noncopyable &);
        };
    }
    typedef noncopyable_::noncopyable noncopyable;
}
#endif

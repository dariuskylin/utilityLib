/*
 * =====================================================================================
 *
 *       Filename:  objectCounter.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/07/2012 07:25:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _NDSL_OBJECTCOUNTER_HPP_
#define _NDSL_OBJECTCOUNTER_HPP_
namespace NDSL
{
    namespace simple
    {
        template<typename T>
        class ObjectCounter
        {
            public:
                inline ObjectCounter(int step = 1)
                {
                    m_step = step;
                    static_m_obj_cnt += m_step;
                }
                inline ~ObjectCounter()
                {
                    static_m_obj_cnt -= m_step;
                }
                inline static int getObjCnt()
                {
                    return static_m_obj_cnt;
                }
            private:
                static int static_m_obj_cnt;
                int m_step;
        };
        template<typename T>
        int ObjectCounter<T>::static_m_obj_cnt = 0;
    }
}
#endif

/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  reference_counter.hpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/13/2012 11:02:36 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#ifndef REFERENCE_COUNTER_HPP_
#define REFERENCE_COUNTER_HPP_
class reference_counter {
    public:
        reference_counter() : ref_count_(0) { }
        virtual ~reference_counter() { }
        void add_ref() {
            ref_count_++;
        }
        int release() {
            return --ref_count_;
        }
    protected:
        reference_counter& operator=(const reference_counter&) {
            return *this;
        }
    private:
        reference_counter(const reference_counter&);
    private:
        int ref_count_;
};
#endif  // REFERENCE_COUNTER_HPP_

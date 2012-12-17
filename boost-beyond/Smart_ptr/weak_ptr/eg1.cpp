/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/13/2012 11:25:36 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<boost/shared_ptr.hpp>
#include<boost/weak_ptr.hpp>
#include<iostream>
#include<cassert>

class A {};

int main() {
    boost::weak_ptr<A> w;
    assert(w.expired());
    {
        boost::shared_ptr<A> p(new A());
        assert(p.use_count() == 1);
        w = p;
        assert(p.use_count() == w.use_count());
        assert(p.use_count() == 1);

        boost::shared_ptr<A> p2(w);
        assert(p2 == p);
        std::cout<<p.use_count()<<std::endl;
    }
    assert(w.expired());
    boost::shared_ptr<A> p3 = w.lock();
    assert(!p3);
    return 0;
}

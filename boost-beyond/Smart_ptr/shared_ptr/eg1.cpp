/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/13/2012 07:35:39 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<boost/shared_ptr.hpp>
#include<cassert>

class A {
    private:
        boost::shared_ptr<int> no_;
    public:
        A(boost::shared_ptr<int> no) : no_(no) { }
        void value(int i) {
            *no_ = i;
        }
};

class B {
    private:
        boost::shared_ptr<int> no_;
    public:
        B(boost::shared_ptr<int> no) : no_(no) { }
        int value() const {
            return *no_;
        }
};

int main() {
    boost::shared_ptr<int> temp(new int(14));
    std::cout<<temp.use_count()<<std::endl;
    A a(temp);
    std::cout<<temp.use_count()<<std::endl;
    B b(temp);
    std::cout<<temp.use_count()<<std::endl;
    std::cout<<"b.value:"<<b.value()<<std::endl;
    a.value(28);
    assert(b.value() == 28);
    temp.reset();
    std::cout<<temp.use_count()<<std::endl;
    return 0;
}

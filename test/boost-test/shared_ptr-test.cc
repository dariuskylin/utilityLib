/*
 * =====================================================================================
 *
 *       Filename:  shared_ptr-test.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/04/2012 07:43:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<iostream>
#include<boost/shared_ptr.hpp>
using std::endl;
using std::cout;
using namespace boost;
class shared
{
    private:
        shared_ptr<int> p;
    public:
        shared(shared_ptr<int> p_):p(p_)
        {}
        void print()
        {
            cout<<"count:"<<p.use_count()
                <<" v = "<<*p<<endl;
        }
};
void print_func(shared_ptr<int> p)
{
    cout<<"count:"<<p.use_count()
        <<" v="<<*p<<endl;
}
int main()
{
    shared_ptr<int> p(new int(100));
    shared s1(p),s2(p);
    s1.print();
    s2.print();
    *p= 20;
    print_func(p);
    s1.print();
    print_func(p);
    return 0;
}

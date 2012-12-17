/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg2.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/16/2012 09:03:06 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
//bind可以绑定成员函数
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<boost/bind.hpp>

class status {
    public:
        status(const std::string& name) :
            name_(name), ok_(true) {}
        void break_it() {
            ok_ = false;
        }
        bool is_broken() const {
            return ok_;
        }
        void report() const {
            std::cout<< name_ << " is "
               <<(ok_?"working nominally":"terribly broken")
              <<std::endl; 
        }
    private:
        std::string name_;
        bool ok_;
};

int main() {
    std::vector<status> statuses;
    statuses.push_back(status("status 1"));
    statuses.push_back(status("status 2"));
    statuses.push_back(status("status 3"));
    statuses.push_back(status("status 4"));

    statuses[1].break_it();
    statuses[2].break_it();

    std::for_each(statuses.begin(),
            statuses.end(),
            boost::bind(&status::report,_1));
    return 0;
}

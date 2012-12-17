/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg2.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/15/2012 09:27:25 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<boost/any.hpp>

class property {
    public:
        property(
                const std::string& name,
                const boost::any& value)
            : name_(name), value_(value)  { }

        std::string name() const {
            return name_;
        }
        boost::any& value()  {
            return value_;
        }
        friend bool operator<
            (const property& lhs, const property& rhs) {
                return lhs.name_<rhs.name_;
            }
    private:
        boost::any value_;
        std::string name_;
};

void print_names(const property& p) {
    std::cout<< p.name() <<std::endl;
}

int main() {
    std::cout<< "Example of using any for storing properties." <<std::endl;

    std::vector<property> properties;
    properties.push_back(
            property("B",30));
    properties.push_back(
            property("A",std::string("Thirty something")));
    properties.push_back(
            property("C",3.1415));

    std::sort(properties.begin(), properties.end());
    std::for_each(
            properties.begin(),
            properties.end(),
            print_names);

    std::cout<<std::endl;

    std::cout<<
        boost::any_cast<std::string>(properties[0].value()) <<std::endl;
    std::cout<<
        boost::any_cast<int>(properties[1].value()) <<std::endl;
    std::cout<<
        boost::any_cast<double>(properties[2].value()) <<std::endl;
    return 0;
}

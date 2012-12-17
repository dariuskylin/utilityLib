/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg2.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/15/2012 12:52:23 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
//regex_search有另外一个重载，该函数可以接受表示所要查找的字符序列的
//两个迭代器。这是因为std::string是一个容器，它提供的是迭代器。现在，
//对于每一次匹配，必须把表示范围起点的迭代器更新为引用上一次匹配的
//结束点。最后，还需要增加两个变量来记录对new和delete调用的次数。
//这里需要注意的是，该程序总是把迭代器it设置为m[0].second。
//match_results[0]返回的是对匹配整个正则表达式的子匹配的引用，因此可以确定这个匹配的结束点通常就是下次运行regex_search函数的起始点。
#include<iostream>
#include<string>
#include<boost/regex.hpp>

int main() {
    boost::regex reg("(new)|(delete)");
    boost::smatch m;
    std::string s =
        "Calls to new must be followed by delete. \
        Calling simply new results in a leak";
    int new_counter = 0;
    int delete_counter = 0;
    std::string::const_iterator it = s.begin();
    std::string::const_iterator end = s.end();

    while(boost::regex_search(it, end, m, reg)){
        m[1].matched? ++new_counter : ++delete_counter;
        it = m[0].second; 
    }
    if(new_counter != delete_counter)
        std::cout<< "Leak detected!" <<std::endl;
    else
        std::cout<< "Seems ok..." <<std::endl;
    return 0;
}

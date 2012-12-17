/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/15/2012 12:42:53 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
//该程序在输入字符串中查找new或者delete，并报告先找到哪一个。
//通过传递一个类型为smatch的对象给regex_search函数，我们就可以得知
//算法如何成功执行的一些细节；
//在regex表达式中有两个子表达式（被小括号括住），因此可以通过match_results
//的索引1得到new的子表达式。这样我们就得到了一个sub_match的实例，它有一个
//布尔类型的成员matched，该成员可以表明这个子表达式是否参与了匹配。
#include<iostream>
#include<string>
#include<boost/regex.hpp>

int main() {
    boost::regex reg("(new)|(delete)");
    boost::smatch m;
    std::string s =
        "Calls to new must be followed by delete. \
        Calling simply new results in a leak";
    if(boost::regex_search(s,m,reg)) {
        if(m[1].matched)
            std::cout<< "The expression (new) matched!" <<std::endl;
        if(m[2].matched)
            std::cout<< "The expression (delete) matched!" <<std::endl;
    }
    return 0;
}

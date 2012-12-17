/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/15/2012 05:47:53 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
// 该例子将英式拼法的colour替换为美式拼法的color。
// 本例中的格式化字符串为"$1$3"，表示替换文本为第一个和
// 第三个子表达式
#include<iostream>
#include<string>
#include<boost/regex.hpp>

int main() {
    boost::regex reg("(Colo)(u)(r)",
            boost::regex::icase|boost::regex::perl);
    std::string s = "Colour, colours, color, colourize";
    s = boost::regex_replace(s, reg, "$1$3");
    std::cout<< s <<std::endl;
    return 0;
}

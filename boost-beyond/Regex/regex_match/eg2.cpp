/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg2.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/14/2012 09:24:55 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<cassert>
#include<string>
#include<boost/regex.hpp>

int main() {
    //3个数字，1个单词，1个任意的字符，2个数字或者字符串'N/A'，1个空格，
    //然后再重复第一个单词（开头3个数字结束后，紧跟1个单词）
    boost::regex reg("\\d{3}([a-zA-Z]+).(\\d{2}|N/A)\\s\\1");//最后的'\\1'表示第一个引用，即（第一个小括号([a-zA-Z]+)）

    std::string correct = "123Hello N/A Hello";
    std::string incorrect = "123Hello 12 hello";

    assert(boost::regex_match(correct,reg) == true);
    assert(boost::regex_match(incorrect,reg) == false);
    return 0;
}

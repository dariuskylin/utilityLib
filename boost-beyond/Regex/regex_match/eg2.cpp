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
    //3�����֣�1�����ʣ�1��������ַ���2�����ֻ����ַ���'N/A'��1���ո�
    //Ȼ�����ظ���һ�����ʣ���ͷ3�����ֽ����󣬽���1�����ʣ�
    boost::regex reg("\\d{3}([a-zA-Z]+).(\\d{2}|N/A)\\s\\1");//����'\\1'��ʾ��һ�����ã�������һ��С����([a-zA-Z]+)��

    std::string correct = "123Hello N/A Hello";
    std::string incorrect = "123Hello 12 hello";

    assert(boost::regex_match(correct,reg) == true);
    assert(boost::regex_match(incorrect,reg) == false);
    return 0;
}

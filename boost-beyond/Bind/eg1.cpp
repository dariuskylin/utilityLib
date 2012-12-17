/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/16/2012 06:19:55 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<boost/bind.hpp>

//���������ҪΪ�˽���ռλ���ĸ���
//ռλ����ʾ�ṩ��������ɵĺ�������Ĳ��������֧��9��
//��һ���������滻_1,�ڶ��������滻_2,�Դ�����
//�ڱ�������Ҳ���ǣ�i1�滻_1,i2�滻_2......
void triple_arguments(
        int i1, int i2, int i3) {
    std::cout<< i1 << i2 << i3 <<std::endl;
}

int main() {
    int i1 = 1, i2 = 2, i3 = 3;
    (boost::bind(&triple_arguments,_3,_1,_2))
        (i1, i2, i3);
    return 0;
}

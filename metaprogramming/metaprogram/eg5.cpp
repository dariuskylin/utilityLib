/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg5.cpp
 *    Description:  �������͵�Ԫ����
 *                  �ڴ˱�дһ��Ԫ����demo_func<>����������Ԫ����T��ָ�������򷵻�
 *                  const T�����򷵻�const T*����ΪԪ����в���ʹ��if-else��֧��䣬
 *                  �������ǵ���Ҫʵ���ֶξ���ģ���ػ�����ͬ�������ػ���ͬ��ʵ�ִ���
 *        Version:  1.0
 *        Created:  11/19/2012 04:59:56 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */

template <typename T>
struct demo_func {
    typedef const T* type;
};

template <typename T>
struct demo_func<T*> {
    typedef const T type;
};

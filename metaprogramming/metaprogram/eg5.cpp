/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg5.cpp
 *    Description:  操作类型的元函数
 *                  在此编写一个元函数demo_func<>，如果输入的元数据T是指针类型则返回
 *                  const T，否则返回const T*。因为元编程中不能使用if-else分支语句，
 *                  所以我们的主要实现手段就是模板特化，不同的条件特化不同的实现代码
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

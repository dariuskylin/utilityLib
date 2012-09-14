/*
 * =====================================================================================
 *
 *       Filename:  test.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/01/2012 02:39:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"bst-demo.hpp"
int main(){
    BST<int> intbst;
    intbst.insert(9);
    intbst.insert(10);
    intbst.insert(11);
    intbst.insert(5);
    intbst.insert(7);
    intbst.traversal();
    return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  foreach.h
 *
 *    Description:  A foreach of c++ based on Macro
 *
 *        Version:  1.0
 *        Created:  05/18/2012 03:11:23 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darius-Kylin (DK), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */

/* 
 *@brief:  This Macro is used to traversal 'container',such as vector、
           set;but it can't be  used to traversal map,such as map<int,string>,
           because Macro is not support comma well.
 *@param  container: the container to be traversaled,such as vector、set
 *@param  it: Iterator
 *@param  type: the type of container
 * */
#define foreach(container,it,type)  \
    for(type::iterator it = (container).begin();   \
            it != (container).end();it++)

/*
 *@brief: This Macro is used to traversal 'container',such as vector、set、map;
 *        and it can be used to travelsal map,because it omits the third param 'type'.
 *@param  container: the container to be travesaled,such as vector、set、map
 *@param  it: Iterator
 * */
#define foreach2(container,it)   \
    for(typeof((container).begin()) it = (container).begin();  \
            it != (container).end();it++)

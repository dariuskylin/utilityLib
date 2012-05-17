/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/17/2012 03:21:23 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<stdio.h>
#include"list.h"
struct int_node
{
    int val;
    struct list_head list;
};
int main()
{
    struct list_head head,*plist;
    struct int_node a,b;
    a.val = 2;
    b.val = 3;
    INIT_LIST_HEAD(&head);
    list_add(&a.list,&head);
    list_add(&b.list,&head);

    list_for_each(plist,&head)
    {
        struct int_node *node = list_entry(plist, struct int_node,list);
        printf("val = %d\n",node->val);
    }
    return 0;
}


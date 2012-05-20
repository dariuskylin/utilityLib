/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年05月20日 14时26分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darius-Kylin (DK), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"except-error.h"
#include"fsmImpl.h"
#include<iostream>
using namespace std;
class ICarrier;
int init(ICarrier *)
{
    cout<<"init ...."<<endl;
    return 0;
}
int exit_final(ICarrier *)
{
    cout<<"exit..."<<endl;
}
int process_1(ICarrier *)
{
    cout<<"1 is process..."<<endl;
    return 2;
}
int process_2(ICarrier *)
{
    cout<<"2 is process..."<<endl;
    return 3;
}
int process_3(ICarrier *)
{
    cout<<"3 is process..."<<endl;
    return 0;
}
int main()
{
    FSM_INIT(fsm)
    FSM_STATE_ADD(fsm,state1,1,init,process_1,exit_final)
    //IState* state1 = new IState(init,process_1,exit_final);
    //(*(fsm_fsm->m_fsmMgr))[1] = state1;
    FSM_STATE_ADD(fsm,state2,2,init,process_2,exit_final)
    //IState* state2 = new IState(init,process_2,exit_final);
    //(*(fsm_fsm->m_fsmMgr))[2] = state2;
    FSM_STATE_ADD(fsm,state3,3,init,process_3,exit_final)
    //IState* state3 = new IState(init,process_3,exit_final);
    //(*(fsm_fsm->m_fsmMgr))[3] = state3;
    FSM_RUN(fsm);
    FSM_DESTROY(fsm);
    return 0;
}

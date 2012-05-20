/*
 * =====================================================================================
 *
 *       Filename:  fsmImpl.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/17/2012 08:51:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _FSMIMPL_HEAD_H
#define _FSMIMPL_HEAD_H

#include<string>
#include<memory>
#include<iostream>
#include<map>
#include"functions.h"
#include"interfaces.h"
#include"except-error.h"
using namespace std;

class CBaseCarrier : public ICarrier
{
    private:
          IState *m_state;
    public:
          map< int,IState* > *m_fsmMgr;
    public:
          CBaseCarrier()
          {
            m_state = NULL;
            m_fsmMgr = NULL;
          }
          virtual ~CBaseCarrier()
          {
            if(m_state != NULL)
                delete m_state;
            if(m_fsmMgr != NULL) //should delete items,free all IState*
                delete m_fsmMgr;
          }
         int attachToMgr(map<int,IState*> *mMgr)
         {
            this->m_fsmMgr = mMgr; 
            return 0;
         }
         int addState(int state,IState* aState)
         {
            (*m_fsmMgr)[state] = aState;
            return 0;
         }
         int switchState(int destState)
         {
            if(m_fsmMgr == NULL)
                return 0;
            if( destState <= 0 )
            {
                return destState;
            }
            IState *state = NULL;
            state = (*m_fsmMgr)[destState];
            if(state == 0 )
                return 0;
            if( state != m_state)
            {
                if( m_state != NULL)
                    m_state->exit_final(this);
                m_state = state;
                state->init(this);
            }
           return state->process(this);
         }
};
#define FSM_INIT(name)  \
    CBaseCarrier* fsm_##name = new CBaseCarrier();
#define FSM_STATE_ADD(name,state,seqnum,init,process,end) \
    IState* ##state = new IState((init),(process),(end));  \
    fsm_##name->addState((seqnum),static_cast<IState *>(##state));
    //(*(fsm_##name->m_fsmMgr))[seqnum] = ##state;
#define FSM_RUN(name) \
    fsm_##name->switchState(1);
#define FSM_DESTROY(name) \
    delete fsm_##name;
#endif

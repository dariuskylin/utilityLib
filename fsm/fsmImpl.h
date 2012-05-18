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
            if(m_fsmMgr != NULL)
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
            if( destState != m_state)
            {
                if( m_state != NULL)
                    m_state->exit(this);
                m_state = destState;
                destState->init(this);
            }
            return process(this);
         }
};
#endif

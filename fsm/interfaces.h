/*
 * =====================================================================================
 *
 *       Filename:  interfaces.h
 *
 *    Description:  Common interfaces
 *
 *        Version:  1.0
 *        Created:  05/17/2012 08:17:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _INTERFACES_HEAD_H
#define _INTERFACES_HEAD_H

#include<map>
class ICarrier;
typedef int  (*do_task)(ICarrier *);
/**
 * @brief: 
 */
class IState
{
    public:
        IState() {}
        IState(do_task ainit,do_task aprocess,
                do_task aexit)
        {
            init=ainit;
            process=aprocess;
            exit_final=aexit;
        }
        /**
         * @brief: 
         */
        virtual ~IState() {}
        /**
         * @brief: 
         *
         * @param: obj
         *
         * @return 
         */
    public:
        do_task  init;
        /**
         * @brief: 
         *
         * @param: obj
         *
         * @return 
         */
        do_task process;
        /**
         * @brief: 
         *
         * @param: obj
         *
         * @return 
         */
        do_task exit_final;
};

/**
 * @brief: 
 */
class ICarrier 
{ 
    public:
        ICarrier() {}
        virtual ~ICarrier() {}   
        /**
         * @brief: 
         *
         * @param: mMgr
         *
         * @return 
         */
        virtual int attachToMgr(std::map< int,IState* > *mMgr) = 0;
        /**
         * @brief: 
         *
         * @param: int
         * @param: IState
         *
         * @return 
         */
        virtual int addState(int , IState*) = 0;
        /**
         * @brief: 
         *
         * @param: destState
         *
         * @return 
         */
        virtual int switchState(int destState) = 0;
};
#endif

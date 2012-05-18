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
/**
 * @brief: 
 */
class IState
{
    public:
        IState() {}
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
        virtual int init(ICarrier* obj) = 0;
        /**
         * @brief: 
         *
         * @param: obj
         *
         * @return 
         */
        virtual int process(ICarrier* obj) = 0;
        /**
         * @brief: 
         *
         * @param: obj
         *
         * @return 
         */
        virtual int exit(ICarrier* obj) = 0;
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
        virtual int attachManager(std::map< int,IState* > *mMgr) = 0;
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

/*
 * =====================================================================================
 *
 *       Filename:  lru_cache.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/11/2012 06:48:34 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _MAP_LRU_CACHE_H_
#define _MAP_LRU_CACHE_H_
#include<string>
#include<iostream>
#include<list>
#include<map>

using namespace std;

namespace lru_cache{
    static const int DEF_CAPACITY = 1000;
    typedef unsigned long long virtual_time;
    typedef struct _HashKey{
        long long index_key_;
    }HashKey;
    typedef struct _HashValue{
        string value_;
        virtual_time access_;
    }HashValue;

    class CLRUCache{
        public:
            CLRUCache():lru_list_(),hash_table_(),now_(0){ }
            virtual ~CLRUCache(){}

            int set(const HashKey &key,const string &value);
            HashValue* get(const HashKey &key);

            unsigned get_lru_list_size(){
                return lru_list_.size();
            }
            unsigned get_hash_table_size(){
                return hash_table_.size();
            }
            virtual_time get_now(){
                return now_;
            }
        private:
            virtual_time get_virtual_time(){
                return ++now_;
            }
        private:
            map<virtual_time,HashKey>  lru_list_;
            map<HashKey,HashValue>  hash_table_;
            virtual_time  now_;
    };
}
#endif

/*
 * =====================================================================================
 *
 *       Filename:  lru_cache.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/11/2012 07:03:28 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"lru_cache.h"

using namespace lru_cache;

int CLRUCache::set(const HashKey &key,const string &value){
    HashValue hash_value;
    hash_value.value_ = value;
    hash_value.access_ = get_virtual_time();

    pair< map<HashKey,HashValue>::iterator,bool> ret = hash_table_.insert(make_pair(key,hash_value));
    if( !ret.second ){
        //key already exist
        virtual_time old_access = hash_table_[key].access_;
        map<virtual_time,HashKey>::iterator iter = lru_list_.find(old_access);
        if(iter != lru_list_.end()){
            lru_list_.erase(iter);
        }
        lru_list_.insert(make_pair(hash_value.access_,key));
        hash_table_[key] = hash_value;
    }else{
        lru_list_.insert(make_pair(hash_value.access_,key));
        if(hash_table_.size() > DEF_CAPACITY){
            //get the least used key
            map<virtual_time,HashKey>::iterator iter = lru_list_.begin();

            hash_table_.erase(iter->second);
            //remove last key from list
            lru_list_.erase(iter);
        }        
    }
    return 0;
}
HashValue* CLRUCache::get(const HashKey &key){
    map<HashKey,HashValue>::iterator iter = hash_table_.find(key);
    if(iter != hash_table_.end()){
        virtual_time old_access = iter->second.access_;
        iter->second.access_ = get_virtual_time();
        map<virtual_time,HashKey>::iterator it = lru_list_.find(old_access);
        if(it!=lru_list_.end()){
            lru_list_.erase(it);
        }
        lru_list_.insert(make_pair(iter->second.access_,key));
        return &(iter->second);
    }else{
        return NULL;
    }
}

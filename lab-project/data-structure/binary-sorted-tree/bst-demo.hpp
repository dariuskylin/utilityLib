/*
 * =====================================================================================
 *
 *       Filename:  bst-demo.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/30/2012 11:36:49 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<iostream>
using namespace std;
template<class T>
class TreeNode{
    public:
        TreeNode():lson(NULL),rson(NULL),freq(1){}
        T data;
        unsigned int freq;
        TreeNode* lson;
        TreeNode* rson;
};

template<class T>
class BST{
    private:
        TreeNode<T>* root;
        void insertpri(TreeNode<T>* &node,T x);
        TreeNode<T>* findpri(TreeNode<T>* node,T x);
        void insubtree(TreeNode<T>* node);
        void Deletepri(TreeNode<T>* &node,T x);
    public:
        BST():root(NULL){}
        void insert(T x);
        TreeNode<T>* find(T x);
        void Delete(T x);
        void traversal();
};

template<class T>
void BST<T>::insertpri(TreeNode<T>* &node,T x){
    if(node == NULL){
        node = new TreeNode<T>();
        node->data = x;
        return ;
    }
    if(node->data > x){
        insertpri(node->lson,x);
    }
    else if( node->data < x){
        insertpri(node->rson,x);
    }
    else
        (node->freq)++;
}

template<class T>
void BST<T>::insert(T x){
    insertpri(root,x);
}

template<class T>
TreeNode<T>* BST<T>::findpri(TreeNode<T>* node,T x){
    if(node == NULL){
        return NULL;
    }
    if(node->data > x){
        return findpri(node->lson,x);
    }
    else if(node->data < x){
        return findpri(node->rson,x);
    }
    else 
        return node;
}

template<class T>
TreeNode<T>* BST<T>::find(T x){
    return findpri(root,x);
}

template<class T>
void BST<T>::Deletepri(TreeNode<T>* &node,T x){
    if(node == NULL){
        return;
    }
    if( node->data > x){
        Deletepri(node->lson,x);
    }
    else if(node->data < x){
        Deletepri(node->rson,x);
    }
    else{
        if(node->lson&&node->rson){
            //case: has two sons
            TreeNode<T>* temp = node->rson;
            while(temp->lson)
                temp = temp->lson;
            node->data = temp->data;
            node->freq = temp->freq;
            Deletepri(node->rson,temp->data);
        }
        else{
            //case: only one son or has no son
            TreeNode<T>* temp = node;
            if(node->lson = NULL)
                node = node->rson;
            else if(node->rson = NULL)
                node = node->lson;
            delete(temp);
        }
    }
    return;
}
template<class T>
void BST<T>::Delete(T x){
    Deletepri(root,x);
}

template<class T>
void BST<T>::insubtree(TreeNode<T>* node){
    if(node == NULL)
        return ;
    insubtree(node->lson);
    cout<<node->data<<"    ";
    insubtree(node->rson);
}
template<class T>
void BST<T>::traversal(){
    insubtree(root);
}



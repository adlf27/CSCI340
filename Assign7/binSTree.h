#ifndef BINSTREE_H
#define BINSTREE_H

#include <algorithm>
#include "binTree.h"

template <class T>
class binSTree:public binTree <T>
{
public:
  void insert(const T& x)     //inserts node with valua x
  { insert(this->root, x); }

  void remove(const T& x)       //removes node with value x
  { remove(this->root, x); }

private:
  void insert(Node<T>*&, const T&);  //private version of insert
  void remove(Node<T>*&, const T&);  //private verison of remove
  Node<T>* pred(Node <T>*); //retruns predecessor of node
};

//this function inserts the values to the binSTree
template <class T>
void binSTree<T>::insert(Node<T>*& root, const T& x)
{
  //if tree empty make that the root
  if(root == nullptr)
    root = new Node<T>(x);

  //if x is greater than root - insert to the right
  if( x > root->data)
    insert(root->right, x);

  //else insert to the left
  else if(x < root->data)
    insert(root->left, x);

}

//function removes the given x from the tree
//takes in a pointer to a node
//and a refrence to a const type T
template <class T>
void binSTree<T>::remove(Node<T>*& root, const T& x)
{
    if(root == nullptr)
      return;

    if(x < root->data)  //node is in the left subtree
     remove(root->left, x);

    else if(x > root->data)  //node is in the right subtree
      remove(root->right, x);
    else
    {
      //if the tree has no children
      if(root->left == nullptr && root->right == nullptr)
      {
        delete(root);
        root = nullptr;
      }

      //if tree has one child - right
      else if(root->left == nullptr)
        {
          Node<T>* tmp = root;
          root = root->right;
          delete tmp;
        }
      //if tree has one child - left
      else if(root->right == nullptr)
        {
          Node<T>* tmp = root;
          root = root->left;
          delete tmp;
        }
        //if the subtree has two childs
        else
        {
          Node <T> *temp = pred(root->left);
          temp->data = root->data;
          remove(root->left, temp->data);
        }
    }
}
//return predecessor of node - largest value in
//left subtree
//takes in a node pointer
template <class T>
Node<T>* binSTree<T>::pred(Node<T>* root)
{
  Node<T>* tmp = root;
  while(tmp->right != nullptr)
    tmp = tmp->right;
  return tmp;
}

#endif

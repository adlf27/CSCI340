/*------------------------------------------------
Name: Luis Aguinaga
ZID: z1811673
Date: 10/24/2017
Assigmnet 6
---------------------------------------------------*/
#ifndef BINTREE_H
#define BINTREE_H
#include "/home/cs340/progs/17f/p6/Node.h"

//definition of the class for a binary tree(template)
template <class T> class binTree
{
public:
  binTree()                  //default constructor
  { root = NULL; }            //sets the root equal to null

  unsigned height() const     //returns height of the tree
  { return height(root); }    // returns the height from private funciton

  virtual void insert(const T& x)   //inserts a node in the tree
  {insert(root, x);}             //calls the private version of insert

 void inorder(void(*inPtr)(const T&))  //inorder traversal of the tree
  {inorder(root, inPtr);}            //calls the private version of inorder

protected:
  Node <T>* root;               //root of the tree(protected)

private:
  unsigned height(Node<T>*) const;     //private version of height
  void insert(Node<T>*&, const T&);     //private version of insert
  void inorder(Node<T>*, void(*)(const T&));  //private version of inorder
};

//this function get the height of the tree.
//takes in one parameter - a pointer to the root
template <class T>
unsigned binTree<T>::height(Node<T> *root) const
{
  if(root == NULL)  //if the tree is empty return 0
    return 0;

  //returns which ever side is bigger and adds 1(root)
  return 1 + max(height(root->left), height(root->right));
}
//decides randomly if it is a right side or left side
typedef enum{left_side, right_side} SIDE;
SIDE rnd() {return rand() % 2 ? right_side:left_side;}

//this function inserts a value into the tree.
//takes in two arguments-
//1. reference to the pointer of the root
//2. value that is going in the tree
template <class T>
void binTree<T>::insert(Node<T>*& root, const T& x)
{
  SIDE side = rnd(); //sets the left side or right side equal to "side"
  if(root == NULL)  //check if root is empty
  {
    root = new Node<T>(x); //if empty-sets the first value - root
    return;
  }
  //if tree not empty- then side(randomly) selects which side
  //the values gets inserted
  else if(side == left_side)
      insert(root->left, x);
  else if(side == right_side)
      insert(root->right, x);

}

//function that does a inorder transversal
//two arguments-
//1. pointer to the root 2. fuction pointer to print
template <class T>
void binTree<T>::inorder(Node<T>* root, void(*inPtr)(const T&))
{
  if(root != NULL) // checks if the tree is empty
  {
    inorder(root->left, inPtr);  //gets left side values
    inPtr(root->data);         //prints values
    inorder(root->right, inPtr); // gets right side values
  }
}
#endif

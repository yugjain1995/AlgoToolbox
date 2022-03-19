/************************************************************************************
Author - Yug Jain
***********************************************************************************/

/// [headers]
#include<iostream>
#include<my_data_structures.h>
/// [headers]


/******************************************************************/
int main()
{
  MyBinaryTree<int> t;
  MyQueueByList<binaryNode<int>*> q;
  std::cout << "====================Testing Binary Tree=====================\n";

// Add nodes
  for(int i = 0; i < 20; i++){
    t.addNodeLevel(i);
  }

// Delete nodes
  t.deleteNode(5);
  t.deleteNode(12);
  t.deleteNode(19);
  t.deleteNode(16);
  t.deleteNode(16);
  t.deleteNode(5);
  
// Print binary tree
  q.enQueue(t.root);
  binaryNode<int>* temp;
  while(!q.isEmpty()){
    temp = q.deQueue();
    std::cout << temp->data;
    
    if(temp->left != NULL){
      q.enQueue(temp->left);
      std::cout << " ,left child = " << temp->left->data;
    }

    if(temp->right != NULL){
      q.enQueue(temp->right);
      std::cout << " ,right child = "<< temp->right->data;
    }
    std::cout << "\n";
  }
  
  return 0;
}
/******************************************************************/
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
  MyBinaryTree<char> t;
  MyQueueByList<binaryNode<char>*> q;
  std::cout << "====================Testing Binary Tree=====================\n";
  t.addNodeLevel('A');
  t.addNodeLevel('B');
  t.addNodeLevel('C');
  t.addNodeLevel('D');

  q.enQueue(t.root);
  binaryNode<char>* temp;
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
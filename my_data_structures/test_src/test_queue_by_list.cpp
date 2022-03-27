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
  MyQueueByList<int> t;
  std::cout << "====================Testing Queue By List=====================\n";
  for(int i = 1; i <= 4; i++){
    t.enQueue(10*i);
    std::cout << t.getTail()->data
         << " is tail\n";
  }
 
  while(!t.isEmpty()){
    std::cout << t.getHead()->data
         << " dequeued from queue\n";
    t.deQueue();
  }

  t.enQueue(10);
  t.enQueue(20);
  t.~MyQueueByList();
  t.enQueue(30);
  t.enQueue(40);
 
  while(!t.isEmpty()){
    std::cout << t.getHead()->data
         << " dequeued from queue\n";
    t.deQueue();
  }
  
  return 0;
}
/******************************************************************/
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
    MyQueueByArray<int> t(10);
    std::cout << "====================Testing Queue By Array=====================\n";
    t.enQueue(10);
    t.enQueue(20);
    t.enQueue(30);
    t.enQueue(40);
 
 while(!t.isEmpty()){
    std::cout << t.deQueue()
         << " dequeued from queue\n";
 }

    t.enQueue(10);
    t.enQueue(20);
    t.enQueue(30);
    t.enQueue(40);
 
 while(!t.isEmpty()){
    std::cout << t.deQueue()
         << " dequeued from queue\n";
 }
    return 0;
}
/******************************************************************/
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
    MyQueueByArray<int> t(1);
 
    t.enQueue(10);
    t.enQueue(20);
    t.enQueue(30);
    t.enQueue(40);
 
 int i = 0;
 while(i < 1){
    std::cout << t.deQueue()
         << " dequeued from queue\n";
         i++;
 }

 t.enQueue(10);
    t.enQueue(20);
    t.enQueue(30);
    t.enQueue(40);
 
 i = 0;
 while(i < 1){
    std::cout << t.deQueue()
         << " dequeued from queue\n";
         i++;
 }
    return 0;
}
/******************************************************************/
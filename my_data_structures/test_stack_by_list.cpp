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
  MyStackByList<int> t;
  std::cout << "====================Testing Stack By List=====================\n";

  std::cout << "\n********Test getSize********\n";
  t.enStack(1);
  t.enStack(2);
  t.enStack(3);
  t.enStack(4);
  std::cout << "Stack Size = " << t.getSize() << "\n";

  if(t.getSize() == 4) std::cout << "Test Passed!!\n";
  else std::cout << "Test failed!!\n";

  t.~MyStackByList();
  std::cout << "\n********END Test getSize********\n";



  std::cout << "\n********Test enStack********\n";

  bool test = true;
  for(int i = 1; i <= 4; i++){
    t.enStack(i);
    if(t.getHead()->data != i) test = false;
  }

  t.printStack();

  if(test) std::cout << "Test Passed!!\n";
  else std::cout << "Test failed!!\n";

  t.~MyStackByList();
  std::cout << "\n********END Test enStack********\n";



  std::cout << "\n********Test getTail********\n";
  test = true;
  for(int i = 1; i <= 4; i++){
    t.enStack(10*i);
  }

  if(t.getTail()->data != 10) test = false;

  t.printStack();

  if(test) std::cout << "Test Passed!!\n";
  else std::cout << "Test failed!!\n";

  t.~MyStackByList();
  std::cout << "\n********END Test getTail********\n";



  std::cout << "\n********Test getHead********\n";
  test = true;
  for(int i = 1; i <= 4; i++){

    t.enStack(10*i);
    if(t.getHead()->data != 10*i) test = false;
  }

  t.printStack();

  if(test) std::cout << "Test Passed!!\n";
  else std::cout << "Test failed!!\n";
  
  t.~MyStackByList();
  std::cout << "\n********END Test getHead********\n";



  std::cout << "\n********Test destroy MyStackByList********\n";
  test = true;

  t.enStack(10);
  t.enStack(20);
  t.~MyStackByList();
  if(t.getHead() != NULL) test = false;

  t.enStack(30);
  t.enStack(40);
  for(int i = 4; i >= 3; i--){
    if(t.getHead()->data != 10*i) test = false;
    t.deStack();
  }

  if(test) std::cout << "Test Passed!!\n";
  else std::cout << "Test failed!!\n";

  t.~MyStackByList();
  std::cout << "\n********END Test destroy MyStackByList********\n";


  std::cout << "\n********Test isEmpty stack********\n";
  test = true;
  t.enStack(1);
  t.enStack(2);
  t.enStack(3);
  t.enStack(4);
  test = !t.isEmpty();
  
  t.~MyStackByList();
  test = t.isEmpty();

  if(test) std::cout << "Test Passed!!\n";
  else std::cout << "Test failed!!\n";

  std::cout << "\n********END Test isEmpty stack********\n";

  std::cout << "\n====================End Testing Stack By List=====================\n";
  return 0;
}
/******************************************************************/
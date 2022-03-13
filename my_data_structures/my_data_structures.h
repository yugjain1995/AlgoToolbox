/************************************************************************************
Author - Yug Jain
***********************************************************************************/

#ifndef MY_DATA_STRUCT
#define MY_DATA_STRUCT

/// [headers]
  #include <iostream>
/// [headers]

//===================================================================================
// ARRAY IMPLEMENTATION OF CIRCULAR QUEUE
//===================================================================================

/******************************************************************/
// Class template
/******************************************************************/
template<typename T>
class MyQueueByArray{
  private:
    T* data;
    int f, r;
    int size;

  // Utility function to check if rear index
  // is pointing at the end of array.
  // If it is pointing at the end of array then
  // increment of rear index "r" will set it to 0
  // else it will add +1 to increment "r" due to
  // circular nature of the queue
    void rplus();

  // Same fuctionality as rplus() for front index "f"
    void fplus();
  
  public:
    MyQueueByArray(unsigned int s = 2);
    void enQueue(T d);
    T deQueue();
    bool isEmpty() const;
    bool isFull() const;
    ~MyQueueByArray();
};
/******************************************************************/


/******************************************************************/
  template <typename T>
  MyQueueByArray<T>::MyQueueByArray(unsigned int s){
    this->size = s;
    this->data = new T [size];
    this->f = -1;
    this->r = -1;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  bool MyQueueByArray<T>::isEmpty() const {
  // After queue becomes empty, indexes
  // are reset to -1. This can be used
  // for queue empty check
    if(this->f == -1) return true;
    return false;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  bool MyQueueByArray<T>::isFull() const {
    int temp;
    if(this->r + 1 > this->size - 1) temp = 0;
    else temp = this->r + 1;

    if(temp == this->f){
      std::cout << "Queue is Full!!\n";
      return true;
    }
    else return false;
  }
/******************************************************************/


/******************************************************************/
template <typename T>
void MyQueueByArray<T>::rplus(){
  if(this->r + 1 > this->size - 1) this->r = 0;
  else this->r = this->r + 1;
}
/******************************************************************/

/******************************************************************/
template <typename T>
void MyQueueByArray<T>::fplus(){
  if(this->f + 1 > this->size - 1) this->f = 0;
  else this->f = this->f + 1;
}
/******************************************************************/


/******************************************************************/
  template <typename T>
  void MyQueueByArray<T>::enQueue(T d){
  // If queue is empty
      if(this->isEmpty()){
        this->f = 0;
        this->r = 0;
        this->data[this->r] = d;
      }
      
  // If queue not full add the element
      else if(this->isFull()) return;
      else{
        this->rplus();
        this->data[this->r] = d;
      }
    
    return;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  T MyQueueByArray<T>::deQueue(){
  // Check if queue is empty
    try{
      if(this->isEmpty()){
        throw "[ERROR] Queue is empty!! - Nothing to deQueue\n";
      }
    }
    catch(char const* s){
      std::cerr << s;
      std::terminate();
    }

    int temp;

  // Check if the front element is also the rear element
  // If it is rear element then reset f and r to -1
  // because queue will be empty after this removal/deQueue operation
    if(this->f == this->r){
      temp = this->f;
      this->f = -1;
      this->r = -1;
      std::cout << "Queue has been emptied!!\n";
      return this->data[temp];
    }
    else{
      temp = this->f;
      this->fplus();
      return this->data[temp];
    }
  }
/******************************************************************/


/******************************************************************/
template <typename T>
MyQueueByArray<T>::~MyQueueByArray(){
  delete this->data;
}
/******************************************************************/

//===================================================================================
// END
//===================================================================================



//===================================================================================
// LINKED LIST IMPLEMENTATION OF QUEUE
//===================================================================================

/******************************************************************/
// Class template
/******************************************************************/

//===================================================================================
// END
//===================================================================================



//===================================================================================
// BINARY TREE
//===================================================================================

/******************************************************************/
// Class template
/******************************************************************/

//===================================================================================
// END
//===================================================================================



//===================================================================================
// BINARY SEARCH TREE
//===================================================================================

/******************************************************************/
// Class template
/******************************************************************/

//===================================================================================
// END
//===================================================================================



//===================================================================================
// HEAP
//===================================================================================

/******************************************************************/
// Class template
/******************************************************************/

//===================================================================================
// END
//===================================================================================



//===================================================================================
// HASHING
//===================================================================================

/******************************************************************/
// Class template
/******************************************************************/

//===================================================================================
// END
//===================================================================================



//===================================================================================
// GRAPH
//===================================================================================

/******************************************************************/
// Class template
/******************************************************************/

//===================================================================================
// END
//===================================================================================



//===================================================================================
// MAP
//===================================================================================

/******************************************************************/
// Class template
/******************************************************************/

//===================================================================================
// END
//===================================================================================

#endif
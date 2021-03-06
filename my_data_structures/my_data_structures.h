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
    unsigned int cap;
    unsigned int size;

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
    unsigned int getSize() const;
    ~MyQueueByArray();
};
/******************************************************************/


/******************************************************************/
  template <typename T>
  unsigned int MyQueueByArray<T>::getSize() const{
    return this->size;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  MyQueueByArray<T>::MyQueueByArray(unsigned int s){
    this->cap = s;
    this->size = 0;
    this->data = new T [this->cap];
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
    if(this->r + 1 > this->cap - 1) temp = 0;
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
  if(this->r + 1 > this->cap - 1) this->r = 0;
  else this->r = this->r + 1;
}
/******************************************************************/

/******************************************************************/
template <typename T>
void MyQueueByArray<T>::fplus(){
  if(this->f + 1 > this->cap - 1) this->f = 0;
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
        this->size++;
      }
      
  // If queue not full add the element
      else if(this->isFull()) return;
      else{
        this->rplus();
        this->data[this->r] = d;
        this->size++;
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
      this->size--;
      return this->data[temp];
    }
    else{
      temp = this->f;
      this->fplus();
      this->size--;
      return this->data[temp];
    }
  }
/******************************************************************/


/******************************************************************/
template <typename T>
MyQueueByArray<T>::~MyQueueByArray(){
  delete this->data;
  std::cout << "Queue by Array deleted\n";
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
template<typename T>
struct Node{
  T data;
  Node<T>* next;
};

template<typename T>
class MyQueueByList{
  private:
    Node<T>* head;
    Node<T>* tail;
    unsigned int size;
  
  public:
    MyQueueByList();
    void enQueue(T d);
    T deQueue();
    unsigned int getSize() const;
    bool isEmpty() const;
    ~MyQueueByList();
};
/******************************************************************/


/******************************************************************/
  template <typename T>
  unsigned int MyQueueByList<T>::getSize() const{
    return this->size;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  MyQueueByList<T>::MyQueueByList(){
    this->size = 0;
    this->head = NULL;
    this->tail = NULL;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  bool MyQueueByList<T>::isEmpty() const {
  // After queue becomes empty, indexes
  // are reset to -1. This can be used
  // for queue empty check
    if(this->head == NULL) return true;
    return false;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  void MyQueueByList<T>::enQueue(T d){
  // If queue is empty
      if(this->isEmpty()){
        this->head = new Node<T>;
        this->tail = this->head;
        this->tail->data = d;
        this->tail->next = NULL;
        this->size++;
      }
      else{
        this->tail->next = new Node<T>; // Create a new node after the current tail
        this->tail = this->tail->next; // Move tail to newly created node
        this->tail->next = NULL; // Next for newly created tail node will be NULL
        this->tail->data = d; // Add the data to new tail node
        this->size++;
      }
    
    return;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  T MyQueueByList<T>::deQueue(){
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

  // If not empty then extract head node data and move the head pointer to next node
    T data = this->head->data;
    Node<T>* temp = this->head;
    this->head = this->head->next;
    delete temp;
    this->size--;
    if(this->head == NULL){
      this->tail = NULL;
      std::cout << "Queue has been emptied!!\n";
    }
    return data;
  }
/******************************************************************/


/******************************************************************/
template <typename T>
MyQueueByList<T>::~MyQueueByList(){
  Node<T>* temp;
  while(this->head != NULL){
    temp = this->head;
    this->head = this->head->next;
    delete temp;
  }
  std::cout << "Queue by List deleted\n";
}
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
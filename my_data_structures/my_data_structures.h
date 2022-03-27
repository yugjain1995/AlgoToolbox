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
    return size;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  MyQueueByArray<T>::MyQueueByArray(unsigned int s){
    cap = s;
    size = 0;
    data = new T [cap];
    f = -1;
    r = -1;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  bool MyQueueByArray<T>::isEmpty() const {
  // After queue becomes empty, indexes
  // are reset to -1. This can be used
  // for queue empty check
    if(f == -1) return true;
    return false;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  bool MyQueueByArray<T>::isFull() const {
    int temp;
    if(r + 1 > cap - 1) temp = 0;
    else temp = r + 1;

    if(temp == f){
      std::cout << "Queue is Full!!\n";
      return true;
    }
    else return false;
  }
/******************************************************************/


/******************************************************************/
template <typename T>
void MyQueueByArray<T>::rplus(){
  if(r + 1 > cap - 1) r = 0;
  else r = r + 1;
}
/******************************************************************/

/******************************************************************/
template <typename T>
void MyQueueByArray<T>::fplus(){
  if(f + 1 > cap - 1) f = 0;
  else f = f + 1;
}
/******************************************************************/


/******************************************************************/
  template <typename T>
  void MyQueueByArray<T>::enQueue(T d){
  // If queue is empty
      if(isEmpty()){
        f = 0;
        r = 0;
        data[r] = d;
        size++;
      }
      
  // If queue not full add the element
      else if(isFull()) return;
      else{
        rplus();
        data[r] = d;
        size++;
      }
    
    return;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  T MyQueueByArray<T>::deQueue(){
  // Check if queue is empty
    try{
      if(isEmpty()){
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
    if(f == r){
      temp = f;
      f = -1;
      r = -1;
      std::cout << "Queue has been emptied!!\n";
      size--;
      return data[temp];
    }
    else{
      temp = f;
      fplus();
      size--;
      return data[temp];
    }
  }
/******************************************************************/


/******************************************************************/
template <typename T>
MyQueueByArray<T>::~MyQueueByArray(){
  delete data;
  std::cout << "Queue by Array deleted\n";
}
/******************************************************************/

//===================================================================================
// END
//===================================================================================



//===================================================================================
// Singly LINKED LIST NODE
//===================================================================================

/******************************************************************/
// Templated struct
/******************************************************************/
template<typename T>
struct Node{
  T data;
  Node<T>* next;
};
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
class MyQueueByList{
  private:
    Node<T>* head;
    Node<T>* tail;
    unsigned int size;
  
  public:
    MyQueueByList();

  // Add nodes
    void enQueue(T d);
  // Remove nodes
    T deQueue();

  // Search queue
    bool findQueue(T d) const;

  // Get queue info
    Node<T>* getHead() const;
    Node<T>* getTail() const;  
    unsigned int getSize() const;
    bool isEmpty() const;

  // Destroy queue
    ~MyQueueByList();
};
/******************************************************************/


/******************************************************************/
  template <typename T>
  unsigned int MyQueueByList<T>::getSize() const{
    return size;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  bool MyQueueByList<T>::findQueue(T d) const{
    Node<T>* current = head;
    while(current != NULL){
      if(current->data == d) return true;
      current = current->next;
    }
    return false;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  MyQueueByList<T>::MyQueueByList(){
    size = 0;
    head = NULL;
    tail = NULL;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  Node<T>* MyQueueByList<T>::getHead() const{
    return head;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  Node<T>* MyQueueByList<T>::getTail() const{
    return tail;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  bool MyQueueByList<T>::isEmpty() const {
  // After queue becomes empty, head is
  // is reset to NULL. This can be used
  // for queue empty check
    return (head == NULL);
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  void MyQueueByList<T>::enQueue(T d){
  // If queue is empty
      if(isEmpty()){
        head = new Node<T>;
        tail = head;
        tail->data = d;
        tail->next = NULL;
        size++;
      }
      else{
        tail->next = new Node<T>; // Create a new node after the current tail
        tail = tail->next; // Move tail to newly created node
        tail->next = NULL; // Next for newly created tail node will be NULL
        tail->data = d; // Add the data to new tail node
        size++;
      }
    
    return;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  T MyQueueByList<T>::deQueue(){
  // Check if queue is empty
    try{
      if(isEmpty()){
        throw "[ERROR] Queue is empty!! - Nothing to deQueue\n";
      }
    }
    catch(char const* s){
      std::cerr << s;
      std::terminate();
    }

  // If not empty then extract head node data and move the head pointer to next node
    T data = head->data;
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    size--;
    if(head == NULL){
      tail = NULL;
      std::cout << "Queue has been emptied!!\n";
    }
    return data;
  }
/******************************************************************/


/******************************************************************/
template <typename T>
MyQueueByList<T>::~MyQueueByList(){
  Node<T>* temp;
  while(head != NULL){
    temp = head;
    head = head->next;
    delete temp;
  }
  std::cout << "Queue by List deleted\n";
}
/******************************************************************/

//===================================================================================
// END
//===================================================================================




//===================================================================================
// LINKED LIST IMPLEMENTATION OF STACK
//===================================================================================

/******************************************************************/
// Class template
/******************************************************************/
template<typename T>
class MyStackByList{
  private:
    Node<T>* head;
    Node<T>* tail;
    unsigned int size;
  
  public:
    MyStackByList();

  // Add nodes
    void enStack(T d);

  // Search stack
    bool findStack(T d) const;

  // Get stack info
    Node<T>* getHead() const;
    Node<T>* getTail() const;  
    unsigned int getSize() const;
    bool isEmpty() const;

  // Print stack
    void printStack() const;

  // Remove nodes
    T deStack();
    
  // Destroy stack
    ~MyStackByList();
};
/******************************************************************/


/******************************************************************/
  template <typename T>
  unsigned int MyStackByList<T>::getSize() const{
    return size;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  bool MyStackByList<T>::findStack(T d) const{
    Node<T>* current = head;
    while(current != NULL){
      if(current->data == d) return true;
      current = current->next;
    }
    return false;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  MyStackByList<T>::MyStackByList(){
    size = 0;
    head = NULL;
    tail = NULL;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  Node<T>* MyStackByList<T>::getHead() const{
    return head;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  Node<T>* MyStackByList<T>::getTail() const{
    return tail;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  bool MyStackByList<T>::isEmpty() const {
  // After stack becomes empty, head
  // is reset to NULL. This can be used
  // for queue empty check
    return (head == NULL);
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  void MyStackByList<T>::enStack(T d){
  // If queue is empty
      if(isEmpty()){
        head = new Node<T>;
        tail = head;
        tail->data = d;
        tail->next = NULL;
        size++;
      }
      else{
        Node<T>* temp = new Node<T>; // Create a new node above the current head
        temp->next = head; // Set next node of new node as current head
        head = temp; // Move head to new node
        head->data = d; // Add the data to new head node
        size++;
      }
    
    return;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  T MyStackByList<T>::deStack(){
  // Check if queue is empty
    try{
      if(isEmpty()){
        throw "[ERROR] Queue is empty!! - Nothing to deStack\n";
      }
    }
    catch(char const* s){
      std::cerr << s;
      std::terminate();
    }

  // If not empty then extract head node data and move the head pointer to next node
    T data = head->data;
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    size--;
    if(head == NULL){
      tail = NULL;
      std::cout << "Queue has been emptied!!\n";
    }
    return data;
  }
/******************************************************************/


/******************************************************************/
  template <typename T>
  void MyStackByList<T>::printStack() const{
    Node<T>* current;

  // Check that stack not empty
    if(!isEmpty()){
      current = head;
      std::cout << current->data << " <--head\n";
      current = current->next;
    }
    else{
      std::cout << "Stack is empty!!\n";
      return;
    }

  // Loop if current not NULL
    if (current != NULL){
      while(true){
        if(current->next == NULL){
          std::cout << current->data << " <--tail\n";
          break;
        }
        else std::cout << current->data << "\n";
        current = current->next;
      }
    }
    else std::cout << "<--tail\n";
  }
/******************************************************************/


/******************************************************************/
template <typename T>
MyStackByList<T>::~MyStackByList(){
  Node<T>* temp;
  while(head != NULL){
    temp = head;
    head = head->next;
    delete temp;
  }
  std::cout << "Stack by List deleted\n";
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
template<typename T>
struct binaryNode{
  T data;
  binaryNode<T>* left;
  binaryNode<T>* right;
};

template<typename T>
class MyBinaryTree{
  public:
    binaryNode<T>* root;

  // Constructor  
    MyBinaryTree();

  // Adds node to the closest level to root with available vacancy form left to right
  // Duplicates allowed
    void addNodeLevel(T d);

  // Add not below the seleted node from tree
    void addNodeBelow(T d, T selectNode);

  // Delete the given node and put the deepest and far right node at deletion location
  // Incase of duplicates in the tree only the deepeset and farthest right node will be
  // deleted 
    void deleteNode(T d);

  // Search
    // Return the pointer to the node which had required data
    // Only returnsthe pointer to first found node
      binaryNode<T>* breadthSearch(T d);
      binaryNode<T>* depthSearch(T d);

    ~MyBinaryTree();
};
/******************************************************************/


/******************************************************************/
template<typename T>
MyBinaryTree<T>::MyBinaryTree(){
  root = NULL;
}
/******************************************************************/


/******************************************************************/
template<typename T>
void MyBinaryTree<T>::addNodeLevel(T d){
  if(root == NULL){
    root = new binaryNode<T>;
    root->data = d;
  }

  else{
    MyQueueByList<binaryNode<T>*> q;
    q.enQueue(root);
    binaryNode<T>* temp;

    while(!q.isEmpty()){
      temp = q.deQueue();

    // If left of node vacant put a node there
      if(temp->left == NULL){
        temp->left = new binaryNode<T>;
        temp->left->data = d;
        temp->left->left = NULL;
        temp->left->right = NULL;
        break;
      }
    // If left not vacant check if right vacant and put a node there
      else if(temp->right == NULL){
        temp->right = new binaryNode<T>;
        temp->right->data = d;
        temp->right->left = NULL;
        temp->right->right = NULL;
        break;
      }
    // Else put left and right node in queue to further explore
      else{
        q.enQueue(temp->left);
        q.enQueue(temp->right);
      }
    }
  }
  
}
/******************************************************************/


/******************************************************************/
template<typename T>
void MyBinaryTree<T>::addNodeBelow(T d, T selectNode){
  ;
}
/******************************************************************/


/******************************************************************/
template<typename T>
void MyBinaryTree<T>::deleteNode(T d){
  MyQueueByList<binaryNode<T>*> q;
  q.enQueue(root);
  binaryNode<T>* temp = NULL;
  binaryNode<T>* last = NULL; // Parent of deepest far node
  binaryNode<T>* search_node = NULL;

  while(!q.isEmpty()){
    temp = q.deQueue();

  // Check if node key is the key to be searched
    if(temp->data == d) search_node = temp;

    if(temp->left != NULL){
      last = temp;
      q.enQueue(temp->left);
    }

    if(temp->right != NULL){
      last = temp;
      q.enQueue(temp->right);
    }
  }
  
  if(search_node != NULL){
    search_node->data = temp->data;

    if(last->right == temp) last->right = NULL;
    else last->left = NULL;
    
    delete temp;
  }
  else std::cout << "Node with requested key not found!!\n";
}
/******************************************************************/


/******************************************************************/
template<typename T>
binaryNode<T>* MyBinaryTree<T>::breadthSearch(T d){
  ;
}
/******************************************************************/


/******************************************************************/
template<typename T>
 binaryNode<T>* MyBinaryTree<T>::depthSearch(T d){
  MyQueueByList<binaryNode<T>*> L; // Queue of Expanded nodes of binary tree
  MyQueueByList<binaryNode<T>*> S; // Queue of to be expanded nodes of binary tree
  binaryNode<T>* current; // Cuurent node to be expanded
// Initialize to be expanded list
  S.enQueue(root);

// Expand in depth first manner
  while(!S.isEmpty){
  // Get the first in queue
    current = S.deQueue();

  // If current node data == search data then return
    if(current->data == d){
      std::cout << "Node found!!\n";
      return current;
    }
  // Else expand the current node
    else{
      if(current->left != NULL && !L.findQueue(current->left->data)){
        S.enQueue(current->left);
      }
      else if(current->right != NULL && !L.findQueue(current->right->data)){
        S.enQueue(current->right);
      }
      else L.enQueue(current);
    }
  }
}
/******************************************************************/


/******************************************************************/
template<typename T>
MyBinaryTree<T>::~MyBinaryTree(){
  ;
}
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
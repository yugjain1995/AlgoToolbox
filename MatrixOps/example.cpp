#include"myMatrix.h"
#include<tgmath.h> 

// This fuction generates random, linealy memory contigous matrix of r x c
double* randMat(unsigned int r, unsigned int c){
  static bool t = false;
  double* a = new double [r*c];
  if(a == NULL){throw std::runtime_error("Memeory was not allocated successfully\n");}
  if(t){srand(time(NULL)/std::pow(10,4)); t = false;}
  else{srand(time(NULL)/10); t = true;}
  for(unsigned int i = 0; i < r; i++){
    for(unsigned int j = 0; j < c; j++){
      double LO = -1000;
      double HI = 1000;
      a[c*i+j] = LO + static_cast <double> (rand()) /( static_cast <double> (RAND_MAX/(HI-LO)));
    }
  }
  return a;
}


int main(){
  double* a = randMat(3,2);
  double* b = randMat(2,3);
  
  myMat<double> A(3, 2, a);
  myMat<double> B(2, 3, b);

  delete a;
  delete b;

  myMat<double> C(3, 3);
  myMat<double> D(2, 3);

  C = A * B;
  D = A.transpose();

  std::cout << "A =";
  A.display();
  std::cout << "B =";
  B.display();
  std::cout << "C = A * B =";
  C.display();
  std::cout << "D = A' =";
  D.display();

  return 0;
}
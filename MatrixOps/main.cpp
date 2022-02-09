#include"myMatrix.h"
#include <Eigen/Dense>
#include<limits>

// TODO:
// Add matrix multiplication library
// Think on boundary conditions and mitigate them
// Eg -Exceeding float size, exceeding uint, Using template to allow double and long double
// Create function to get random matrix for random tests and compare the multiplication results with library
// Write descructor
// Write various improvement avenues

float* randMat(unsigned int r, unsigned int c){
  float* a = new float [r*c];
  srand(time(NULL));
  for(unsigned int i = 0; i < r; i++){
    for(unsigned int j = 0; j < c; j++){
      float LO = -900;//std::numeric_limits<float>::min()/pow(10.0,-20);
      float HI = 900;//std::numeric_limits<float>::max()/pow(10.0,20);
      a[c*i+j] = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
    }
  }
  return a;
}

int main(){
    float* a = randMat(2,3);
    float* b = randMat(3,3);
    myMat A(2, 3, a);
    std::cout << "A = ";
    A.display();
    std::cout << "\n";

    myMat B(3, 3, b);
    std::cout << "B = ";
    B.display();
    std::cout << "\n";

    delete a;
    delete b;

    myMat C = A * B;
    std::cout << "C = ";
    C.display();
    std::cout << "\n";

    myMat D = A.transpose();
    std::cout << "D = ";
    D.display();
    std::cout << "\n";

    return 0;
}
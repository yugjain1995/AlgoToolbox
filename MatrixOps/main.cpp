#include"myMatrix.h"
#include <Eigen/Dense>
#include<limits>
#include <string> 

template<typename T>
using MatrixX = Eigen::Matrix <T, Eigen::Dynamic, Eigen::Dynamic>;

// TODO:
// Add matrix multiplication library
// Think on boundary conditions and mitigate them
// Eg -Exceeding double size, exceeding uint, Using template to allow double and long double
// Create function to get random matrix for random tests and compare the multiplication results with library
// Write descructor
// Write various improvement avenues

unsigned int r = 2, k = 3, c = 3;

int str2int(char* c){
    int i = 0;
    std::string s;
    while(c[i] != '\0'){
        s.push_back(c[i]);
        i++;
    }
    return std::stoi(s);
}

void initEigen(MatrixX<double> &A, const double* a){
  for(int i = 0; i < A.rows(); i++){
    for(int j = 0; j < A.cols(); j++){
      A(i, j) = a[A.cols()*i+j];
    }
  }
}

void compareMat(myMat<double> &mulResult, MatrixX<double> &emulResult){
  for(unsigned int i = 0; i < r; i++){
    for(unsigned int j = 0; j < c; j++){
      if(abs(mulResult.data[c*i+j] - emulResult(i,j)) > 1e-6){
        std::cout << "Mismatch at (" << i << ", " << j << ")\n"
                  << "myMat value = " << mulResult.data[c*i+j] << "\n"
                  << "Eigen mat value = " << emulResult(i,j) << "\n"
                  << "Difference = " << (mulResult.data[c*i+j] - emulResult(i,j)) << "\n";
        throw std::runtime_error("Matrices do not match\n"); 
      }
    }
  }
  std::cout << "----------Matrices match-----------\n";
}

double* randMat(unsigned int r, unsigned int c){
  static bool t = false;
  double* a = new double [r*c];
  if(t){srand(time(NULL)/pow(10,4)); t = false;}
  else{srand(time(NULL)/10); t = true;}
  for(unsigned int i = 0; i < r; i++){
    for(unsigned int j = 0; j < c; j++){
      double LO = -10;//std::numeric_limits<double>::min()/pow(10.0,-20);
      double HI = 10;//std::numeric_limits<double>::max()/pow(10.0,20);
      a[c*i+j] = LO + static_cast <double> (rand()) /( static_cast <double> (RAND_MAX/(HI-LO)));
    }
  }
  return a;
}


void myMatMulTest(myMat<double> &A, myMat<double> &B, myMat<double> &result){
  std::cout << "====================================\n";
  std::cout << "myMat\n";
  std::cout << "====================================\n";
  std::cout << "A = ";
  A.display();
  std::cout << "\n";

  std::cout << "B = ";
  B.display();
  std::cout << "\n";

  result = A * B;
  std::cout << "result = ";
  result.display();
  std::cout << "\n";
  std::cout << "====================================\n\n";
}

void eMatMulTest( MatrixX<double> &result, const double* a, const double* b){
  MatrixX<double> A(r, k);
  MatrixX<double> B(k, c);
  initEigen(A, a);
  initEigen(B, b);
  std::cout << "====================================\n";
  std::cout << "Eigen Mat\n";
  std::cout << "====================================\n";
  std::cout << "A = ";
  std::cout << A;
  std::cout << "\n\n";

  std::cout << "B = ";
  std::cout << B;
  std::cout << "\n\n";

  result = A * B;
  std::cout << "result = \n";
  std::cout << result;
  std::cout << "\n\n";
  std::cout << "====================================\n\n";
}

int main(int argc, char** argv){
  bool rowInput = false;
  bool colInput = false;
  bool commonInput = false;

  for(int i = 0; i < argc; i++){
    if(rowInput){r = str2int(argv[i]); rowInput = false;}
    if(strcmp(argv[i], "-r") == 0){rowInput = true;}

    if(colInput){c = str2int(argv[i]); colInput = false;}
    if(strcmp(argv[i], "-c") == 0){colInput = true;}

    if(commonInput){k = str2int(argv[i]); commonInput = false;}
    if(strcmp(argv[i], "-k") == 0){commonInput = true;}
    
  }

  double* a = randMat(r,k);
  double* b = randMat(k,c);
  
  myMat<double> A(r, k, a);
  myMat<double> B(k, c, b);

  myMat<double> mulResult(r, c);
  MatrixX<double> emulResult(r, c);

  myMatMulTest(A, B, mulResult);
  eMatMulTest(emulResult, a, b);

  delete a;
  delete b;

  compareMat(mulResult, emulResult);

    return 0;
}
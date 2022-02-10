# Build instructions to run test against Eigen library and run example 
For seperating build files from source it is advisable to create a seperate build folder.

1) Go to the source folder you have recieved

2) Create build directory
    mkdir build

3) cd to build directory
    cd build

4) camke ..

5) make

6) To run test
    ./test -r "number of rows" -c "number of columns" -k "number of cols of 1st mat and rows of 2nd mat"

Eg- ./test -r "2" -c "2" -k "3"

This implies multiply a 2 * 3 matrix with 3 * 2 matrix to give 2 * 2 matrix

7) To run example
    ./example

# Explaination of example code

int main(){

  //Randomly create two linearly memory contigous matrix// 
  double* a = randMat(3,2);
  double* b = randMat(2,3);
  
  // Create two myMat matrices (of double data type) which will be later multiplied//
  myMat<double> A(3, 2, a);
  myMat<double> B(2, 3, b);

  delete a;
  delete b;

  // Create two myMat matrices which will store result of multiplication and transpose//
  myMat<double> C(3, 3);
  myMat<double> D(2, 3);

  // Use overloaded * operator to multiply matrices and store the result in matrix C//
  C = A * B;

  //Store Transpose of matrix A in D;
  D = A.transpose();

  // Print the matrices//
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


# TODO:

Matrix multiplication can be further improved by concept of blocking for cache effiient operations

Another way to greatly improve performance is to use vectorization to exploit SIMD(Single-Instruction-Multiple-Data) feature in mordern processors


#include<iostream>

template<typename T>
class myMat{
  public:
    T* data;
    unsigned int row, col;

    myMat(unsigned int r, unsigned int c){
      row = r;
      col = c;
      data = new T[row*col];
    }

    myMat(unsigned int r, unsigned int c, T* a){
      row = r;
      col = c;

      data = new T[row*col];
      for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
          data[col*i + j] = a[col*i + j];
        }
      }
      return;
    }

    myMat operator * (myMat const &obj){
      myMat result(row, obj.col);
      if(col != obj.row){
        throw std::runtime_error("Matrix dim incompatible\n");
      }
      for(int i = 0; i < row; i++){
        for(int j = 0; j < obj.col; j++){
          for(int k = 0; k < col; k++){
            result.data[obj.col*i+j] += data[col*i + k] * obj.data[obj.col*k + j];
          }
        }
      }
      return result;
    }

    myMat transpose(){
      myMat result(col, row);

      for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            result.data[row*j+i] += data[col*i + j];
        }
      }
      return result;
    }

    void display(){
      std::cout << "\n";
      for(int i = 0; i < row; i++){
          for(int j = 0; j < col; j++){
              std::cout << data[col*i + j] << "  ";
          }
          std::cout << "\n";
      }
    }

};
#include <iostream>
#include <string.h>

using namespace std;

void print_matrix(int **Matrix, int x, int y) {
  if (Matrix == nullptr)
    cout << "Матрица пуста" << endl;
  else {
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) 
      cout << Matrix[i][j] << " ";
      cout << endl;
    }
  }
}

void Menu(int **&Matrix, int &x, int &y) {
  cout << "Выберите одну из операций:" << endl;
  cout << "1. Вывести матрицу" << endl;
  cout << "2. Сложить матрицу" << endl;
  cout << "3. Умножить матрицу" << endl;
  cout << "4. Транспонировать матрицу" << endl;
  cout << "5. Сохранить в файл" << endl;
  cout << "6. Загрузить из файла" << endl;
  cout << "7. Сортировать матрицу" << endl;
  cout << "8. Выход" << endl;
  cout << endl;
}

void Main(int **&Matrix, int &x, int &y, int argc, char *argv[]) {
  string str_x, str_y;
  int str_int;
  int k = 0;
  if (argc == 1) {
    x = y = 0;
    Matrix = nullptr;
  } else {
    while (argv[1][k] != 'x') {
      str_x = str_x + argv[1][k];
      k++;
    }
    k++;
    while (k != strlen(argv[1])) {
      str_y = str_y + argv[1][k];
      k++;
    }
    k = 0;
    x = atoi(str_x.c_str());
    y = atoi(str_y.c_str());
    Matrix = new int *[x];
    for (int i = 0; i < x; i++) Matrix[i] = new int[y];
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) Matrix[i][j] = 0;
    }
    if (argc == 2) { } 
    else {
        int z = 2;
        for (int i = 0; i < x; i++) {
          for (int j = 0; j < y; j++) {
            if (z < argc) {
              str_int = atoi(argv[z]);
              Matrix[i][j] = str_int;
              z++;
            }
          }
        }
    }
    }
}

void summ_matrix(int **&Matrix, int &x, int &y) {
        cout << "Введите матрицу размера "<< x<<"x"<<y<<":"<<endl;
        int **summ_matrix;
        summ_matrix = new int *[x];
        for (int i=0; i<x; i++) 
        summ_matrix[i]= new int [y];
        for (int i=0; i<x; i++) {
            for (int j=0; j<y; j++)
                cin >> summ_matrix[j];
        }
        cout<<endl;
        for (int i=0; i<x; i++) {
            for (int j=0; j<y; j++) 
            Matrix[i][j]= Matrix[i][j]+ summ_matrix[i][j];
        }
        if (Matrix == nullptr)
    cout << "Матрица пуста" << endl;
  else {
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) 
      cout << Matrix[i][j] << " ";
      cout << endl;
    }
  }
        for (int i = 0; i < x; i++) 
        delete[] Matrix[i];
    delete[] Matrix;
    }

int main(int argc, char *argv[]) {
  int **Matrix = nullptr;
  int x = 0;
  int y = 0;
  Menu(Matrix, x, y);
  Main(Matrix, x, y, argc, argv);
  while (true) {
    int choice;
    cin >> choice;
    switch (choice) {
      case 1:
        cout << endl;
        Main(Matrix, x, y, argc, argv);
        print_matrix(Matrix, x, y);
        cout << endl;
        Menu(Matrix, x, y);
        break;
      case 2:
        cout << endl;
        summ_matrix(Matrix, x, y);
        cout << endl;
        Menu(Matrix, x, y);
        break;
      case 8:
        return 0;
    }
  }
  if (Matrix == nullptr) {
    for (int i = 0; i < x; i++) delete[] Matrix[i];
    delete[] Matrix;
  }
}


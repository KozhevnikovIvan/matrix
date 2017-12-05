#include <iostream>
#include <string.h>

using namespace std;

void print_matrix(int **Matrix, int m, int n) {
  if (Matrix == nullptr)
    cout << "Matrix is empty" << endl;
  else {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) cout << Matrix[i][j] << " ";
      cout << endl;
    }
  }
}

void Menu(int **&Matrix, int &m, int &n) {
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

void Main(int **&Matrix, int &m, int &n, int argc, char *argv[]) {
  string m_str, n_str;
  int integer1;
  int k = 0;
  if (argc == 1) {
    m = n = 0;
    Matrix = nullptr;
  } else {
    while (argv[1][k] != 'x') {
      m_str = m_str + argv[1][k];
      k++;
    }
    k++;
    while (k != strlen(argv[1])) {
      n_str = n_str + argv[1][k];
      k++;
    }
    k = 0;
    m = atoi(m_str.c_str());
    n = atoi(n_str.c_str());
    Matrix = new int *[m];
    for (int i = 0; i < m; i++) Matrix[i] = new int[n];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) Matrix[i][j] = 0;
    }
    if (argc == 2) {
    } else {
      if (argc == 3) {
        string matrix_array;
        matrix_array = argv[2];
        string integer_str;
        for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++) {
            if (k < matrix_array.length()) {
              for (int z = k; z < matrix_array.length(); z++) {
                if (matrix_array[z] == ',') {
                  k++;
                  break;
                }
                integer_str = integer_str + matrix_array[z];
                k++;
              }
              if (integer_str != "") {
                integer1 = atoi(integer_str.c_str());
                Matrix[i][j] = integer1;
              }
              integer_str = "";
            }
          }
        }
      } else {
        int z = 2;
        for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++) {
            if (z < argc) {
              integer1 = atoi(argv[z]);
              Matrix[i][j] = integer1;
              z++;
            }
          }
        }
      }
    }
  }
}

int main(int argc, char *argv[]) {
  int **Matrix = nullptr;
  int m = 0;
  int n = 0;
  Menu(Matrix, m, n);
  Main(Matrix, m, n, argc, argv);
  while (true) {
    int choice;
    cin >> choice;
    switch (choice) {
      case 1:
        cout << endl;
        print_matrix(Matrix, m, n);
        cout << endl;
        Menu(Matrix, m, n);
        break;
      case 8:
        return 0;
    }
  }
  if (Matrix == nullptr) {
    for (int i = 0; i < m; i++) delete[] Matrix[i];
    delete[] Matrix;
  }
}

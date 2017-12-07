#include <iostream>
#include <string.h>

using namespace std;

void print_matrix(int **Matrix, int x, int y) {
  if (Matrix == nullptr)
    cout << "Матрица пуста" << endl;
  else {
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) cout << Matrix[i][j] << " ";
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
    if (argc == 2) {
    } else {
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
  if (Matrix == nullptr)
    cout << "Матрица пуста" << endl;
  else {
    int **summ_matrix;
    summ_matrix = new int *[x];
    for (int i = 0; i < x; i++) summ_matrix[i] = new int[y];
    cout << "Введите матрицу размера " << x << "x" << y << ":" << endl;
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) cin >> summ_matrix[i][j];
    }
    cout << endl;
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++)
        Matrix[i][j] = Matrix[i][j] + summ_matrix[i][j];
    }
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) cout << Matrix[i][j] << " ";
      cout << endl;
    }
    for (int i = 0; i < x; i++) delete[] summ_matrix[i];
    delete[] summ_matrix;
  }
}

void multiplication_matrix(int **&Matrix, int x, int y, int argc,
                           char *argv[]) {
  if (Matrix == nullptr) {
    cout << "Матрица пуста" << endl;
  } else {
    int a, b;
    string amount;
    cout << "Введите размер второй матрицы: ";
    cin >> amount;
    int g = 0;
    string amount_a, amount_b;
    while (argv[1][g] != 'x') {
      amount_a = amount_a + argv[1][g];
      g++;
    }
    g++;
    while (g != strlen(argv[1])) {
      amount_b = amount_b + argv[1][g];
      g++;
    }
    a = atoi(amount_a.c_str());
    b = atoi(amount_b.c_str());
    if (a != y) {
      cout << "Количество столбцов этой матрицы должно быть равно количеству "
              "строк первой матрицы\nОшибка!"
           << endl;
    } else {
      int **multi_matrix;
      multi_matrix = new int *[a];
      for (int i = 0; i < a; i++) multi_matrix[i] = new int[b];
      cout << "\nВведите элементы второй матрицы:" << endl;
      for (int j = 0; j < a; j++) {
        for (int q = 0; q < b; q++) cin >> multi_matrix[j][q];
      }
      cout << endl;
      int **multiplication_matrix_2;
      multiplication_matrix_2 = new int *[x];
      for (int i = 0; i < a; i++) multiplication_matrix_2[i] = new int[b];
      for (int i = 0; i < x; i++) {
        for (int q = 0; q < b; q++) multiplication_matrix_2[i][q] = 0;
      }
      for (int i = 0; i < x; i++) {
        for (int j = 0; j < b; j++) {
          for (int q = 0; q < a; q++)
            multiplication_matrix_2[i][q] = Matrix[i][j] * multi_matrix[j][q] +
                                            multiplication_matrix_2[i][q];
        }
      }
      for (int i = 0; i < x; i++) {
        for (int q = 0; q < b; q++)
          cout << multiplication_matrix_2[i][q] << " ";
        cout << endl;
      }
      for (int i = 0; i < x; i++) delete multiplication_matrix_2[i];
      delete multiplication_matrix_2;
      for (int i = 0; i < a; i++) delete multi_matrix[i];
      delete multi_matrix;
    }
  }
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
      case 3:
        cout << endl;
        multiplication_matrix(Matrix, x, y, argc, argv);
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

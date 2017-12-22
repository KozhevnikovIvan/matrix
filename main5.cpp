#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

struct Matrix
{
    int** matrix=nullptr;
    int x;
    int y;
};

void print_matrix(Matrix &matrix) {
  if (matrix.matrix == nullptr)
    cout << "Матрица пуста" << endl;
  else {
    for (int i = 0; i < matrix.x; i++) {
      for (int j = 0; j < matrix.y; j++) cout << matrix.matrix[i][j] << " ";
      cout << endl;
    }
  }
}

void Menu() {
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

void Main(Matrix &matrix, int argc, char *argv[]) {
  string str_x, str_y;
  int k = 0;
  if (argc == 1) {
    matrix.x = matrix.y = 0;
    matrix.matrix = nullptr;
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
    matrix.x = atoi(str_x.c_str());
    matrix.y = atoi(str_y.c_str());
    matrix.matrix = new int *[matrix.x];
    for (int i = 0; i < matrix.x; i++) matrix.matrix[i] = new int[matrix.y];
    for (int i = 0; i < matrix.x; i++) {
      for (int j = 0; j < matrix.y; j++) matrix.matrix[i][j] = 0;
    }
    if (argc == 2) {
    } else {
      int z = 2;
      int str_el;
      for (int i = 0; i < matrix.x; i++) {
        for (int j = 0; j < matrix.y; j++) {
          if (z < argc) {
            str_el = atoi(argv[z]);
            matrix.matrix[i][j] = str_el;
            z++;
          }
        }
      }
    }
  }
}

void summ_matrix(Matrix &matrix) {
  if (matrix.matrix == nullptr)
    cout << "Матрица пуста" << endl;
  else {
    int **summ_matrix;
    summ_matrix = new int *[matrix.x];
    for (int i = 0; i < matrix.x; i++) summ_matrix[i] = new int[matrix.y];
    cout << "Введите матрицу размера " << matrix.x << "x" << matrix.y << ":" << endl;
    for (int i = 0; i < matrix.x; i++) {
      for (int j = 0; j < matrix.y; j++) cin >> summ_matrix[i][j];
    }
    cout << endl;
    for (int i = 0; i < matrix.x; i++) {
      for (int j = 0; j < matrix.y; j++)
        matrix.matrix[i][j] = matrix.matrix[i][j] + summ_matrix[i][j];
    }
    for (int i = 0; i < matrix.x; i++) delete[] summ_matrix[i];
    delete[] summ_matrix;
  }
}

void multiplication_matrix(Matrix &matrix) {
  if (matrix.matrix == nullptr) {
    cout << "Матрица пуста" << endl;
  } else {
    int a, b;
    cout << "Введите количество строк: ";
    cin >> a;
    cout << "Введите количество столбцов: ";
    cin >> b;
    if (a != matrix.y) {
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
      multiplication_matrix_2 = new int *[matrix.x];
      for (int i = 0; i < a; i++) multiplication_matrix_2[i] = new int[b];
      for (int i = 0; i < matrix.x; i++) {
        for (int q = 0; q < b; q++) multiplication_matrix_2[i][q] = 0;
      }
      for (int i = 0; i < matrix.x; i++) {
        for (int j = 0; j < matrix.y; j++) {
          for (int q = 0; q < b; q++)
            multiplication_matrix_2[i][q] = matrix.matrix[i][j] * multi_matrix[j][q] +
                                            multiplication_matrix_2[i][q];
        }
      }
      for (int i = 0; i < matrix.x; i++) {
        for (int q = 0; q < b; q++)
          cout << multiplication_matrix_2[i][q] << " ";
        cout << endl;
      }
      for (int i = 0; i < matrix.x; i++) delete[] multiplication_matrix_2[i];
      delete[] multiplication_matrix_2;
      for (int i = 0; i < a; i++) delete[] multi_matrix[i];
      delete[] multi_matrix;
    }
  }
}

void transpose_matrix(Matrix &matrix) {
  if (matrix.matrix == nullptr)
    cout << "Матрица пуста" << endl;
  else {
    int **Matrix_tr;
    Matrix_tr = new int *[matrix.x];
    for (int i = 0; i < matrix.x; i++) Matrix_tr[i] = new int[matrix.y];
    for (int i = 0; i < matrix.x; i++) {
      for (int j = 0; j < matrix.y; j++) Matrix_tr[i][j] = matrix.matrix[i][j];
    }
    int x_tr = matrix.x;
    int y_tr = matrix.y;
    for (int i = 0; i < matrix.x; i++) delete[] matrix.matrix[i];
    delete[] matrix.matrix;
    swap(matrix.x, matrix.y);
    matrix.matrix = new int *[matrix.x];
    for (int i = 0; i < matrix.x; i++) matrix.matrix[i] = new int[matrix.y];
    for (int i = 0; i < matrix.x; i++) {
      for (int j = 0; j < matrix.y; j++) matrix.matrix[i][j] = Matrix_tr[j][i];
    }
    for (int i = 0; i < matrix.x; i++) delete[] Matrix_tr[i];
    delete[] Matrix_tr;
  }
}

void matrix_v_file(Matrix &matrix, int argc, char *argv[]) {
  Main(Matrix &matrix, argc, argv);
  if (matrix.matrix == nullptr)
    cout << "Матрица пуста";
  else {
    string name_file, rewrite;
    cout << "Введите название файла: ";
    cin >> name_file;
    ifstream file(name_file, ios::in);
    if (file != nullptr) {
      cout << endl << "Перезаписать файл? (yes/ no)" << endl;
      cin >> rewrite;
      cout << endl;
      file.close();
      if (rewrite == "yes") {
        ofstream file2(name_file, ios::out);
        for (int i = 0; i < matrix.x; i++) {
          for (int j = 0; j < matrix.y; j++) file2 << matrix.matrix[i][j] << " ";
          file2 << endl;
        }
        cout << "Матрица записанна в файл " << name_file << endl;
        file2.close();
      } else if (rewrite == "no") {
      }
    } else {
      file.close();
      ofstream file3(name_file, ios::out);
      for (int i = 0; i < matrix.x; i++) {
        for (int j = 0; j < matrix.y; j++) file3 << matrix.matrix[i][j] << " ";
        file3 << endl;
      }
      cout << "Матрица записанна в файл " << name_file << endl;
      file3.close();
    }
  }
}

void matrix_iz_file(Matrix &matrix) {
  char matrix_ch;
  string name_file;
  cout << "Введите название файла: ";
  cin >> name_file;
  cout << endl;
  ifstream file(name_file, ios::in);
  if (file == nullptr)
    cout << "Матрица пуста" << endl;
  else {
    while (file.get(matrix_ch)) cout << matrix_ch;
  }
}

void sorting(Matrix &matrix, int argc, char *argv[]) {
  Main(Matrix &matrix, argc, argv);
  if (matrix.matrix == nullptr)
    cout << "Матрица пуста";
  else {
    string method;
    cout << endl
         << "Выберите порядок сортировки:\nЗмея(s);\nУлитка(e);\nМуравей(a);"
         << endl;
    cin >> method;
    if (method == "s") {
      int z = matrix.x * matrix.y;
      int k = 0;
      int *matrix_string = new int[z];
      for (int i = 0; i < matrix.x; i++) {
        for (int j = 0; j < matrix.y; j++) {
          matrix_string[k] = matrix.matrix[i][j];
          k++;
        }
      }
      k = 0;
      for (int j = 0; j < matrix.y; j++) {
        if ((j + 1) % 2 == 1) {
          for (int i = 0; i < matrix.x; i++) {
            matrix.matrix[i][j] = matrix_string[k];
            k++;
          }
        } else if ((j + 1) % 2 == 0) {
          for (int i = matrix.x - 1; i > -1; i--) {
            matrix.matrix[i][j] = matrix_string[k];
            k++;
          }
        }
      }
      print_matrix(Matrix &matrix);
      delete[] matrix_string;
    }
    if (method == "e") {
      int z = matrix.x * matrix.y;
      int k = 0;
      int *matrix_string = new int[z];
      for (int i = 0; i < matrix.x; i++) {
        for (int j = 0; j < matrix.y; j++) {
          matrix_string[k] = matrix.matrix[i][j];
          k++;
        }
      }
      k = 0;
      int kvadr = 0;
      int str_int = 0;
      if (matrix.x < matrix.y)
        str_int = matrix.x;
      else
        str_int = matrix.y;
      if ((str_int % 2) == 0) {
        kvadr = str_int / 2;
      } else
        kvadr = (str_int / 2) + 1;
      int curr_kvadr = 1;
      while (curr_kvadr != (kvadr + 1)) {
        for (int i = (curr_kvadr - 1); i < (matrix.y - curr_kvadr + 1); i++) {
          matrix.matrix[curr_kvadr - 1][i] = matrix_string[k];
          k++;
        }
        for (int i = curr_kvadr; i < (matrix.x - curr_kvadr + 1); i++) {
          matrix.matrix[i][matrix.y - curr_kvadr] = matrix_string[k];
          k++;
        }
        for (int i = (matrix.y - curr_kvadr - 1); i > (curr_kvadr - 2); i--) {
          matrix.matrix[matrix.x - curr_kvadr][i] = matrix_string[k];
          k++;
        }
        for (int i = (matrix.x - curr_kvadr - 1); i > (curr_kvadr - 1); i--) {
          matrix.matrix[i][curr_kvadr - 1] = matrix_string[k];
          k++;
        }
        curr_kvadr++;
      }
      print_matrix(Matrix &matrix);
      delete[] matrix_string;
    }
    if (method == "a") {
      int z = matrix.x * matrix.y;
      int k = 0;
      int *matrix_string = new int[z];
      for (int i = 0; i < matrix.x; i++) {
        for (int j = 0; j < matrix.y; j++) {
          matrix_string[k] = matrix.matrix[i][j];
          k++;
        }
      }
      k = 0;
      for (int k = 0; k < z / 2; k++)
        swap(matrix_string[k], matrix_string[z - k - 1]);
      for (int i = 0; i < matrix.x; i++) {
        for (int j = 0; j < matrix.y; j++) {
          matrix.matrix[i][j] = matrix_string[k];
          k++;
        }
      }
      print_matrix(Matrix &matrix);
      delete[] matrix_string;
    }
  }
}

int main(int argc, char *argv[]) {
  Matrix matrix;
  int matrix.x = 0;
  int matrix.y = 0;
  Menu();
  Main(Matrix &matrix, argc, argv);
  while (true) {
    int choice;
    cin >> choice;
    switch (choice) {
      case 1:
        cout << endl;
        Main(Matrix &matrix, argc, argv);
        print_matrix(Matrix &matrix);
        cout << endl;
        Menu();
        break;
      case 2:
        cout << endl;
        summ_matrix(Matrix &matrix);
        cout << endl;
        print_matrix(Matrix &matrix);
        cout << endl;
        Menu();
        break;
      case 3:
        cout << endl;
        Main(Matrix &matrix, argc, argv);
        multiplication_matrix(Matrix &matrix);
        cout << endl;
        Menu();
        break;
      case 4:
        cout << endl;
        Main(Matrix &matrix, argc, argv);
        transpose_matrix(Matrix &matrix);
        cout << endl;
        print_matrix(Matrix &matrix);
        cout << endl;
        Menu();
        break;
      case 5:
        cout << endl;
        matrix_v_file(Matrix &matrix, argc, argv);
        cout << endl;
        Menu();
        break;
      case 6:
        cout << endl;
        matrix_iz_file(Matrix &matrix);
        cout << endl;
        Menu();
        break;
      case 7:
        cout << endl;
        sorting(Matrix &matrix, argc, argv);
        cout << endl;
        Menu();
        break;
      case 8:
        return 0;
    }
  }
  if (matrix.matrix == nullptr) {
    for (int i = 0; i < matrix.x; i++) delete[] matrix.matrix[i];
    delete[] matrix.matrix;
  }
}

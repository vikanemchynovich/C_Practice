#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

void bfs(int city, const vector<vector<int>>& matrix, vector<bool>& visited) {
    queue<int> q;
    q.push(city);
    visited[city] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor = 0; neighbor < matrix.size(); ++neighbor) {
            if (matrix[current][neighbor] == 1 && !visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int countProvinces(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<bool> visited(n, false);
    int provinces = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            bfs(i, matrix, visited);
            provinces++;
        }
    }
    return provinces;
}

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    srand(time(0));

    for (int i = 0; i < n; ++i) {
        matrix[i][i] = 1;
        for (int j = i + 1; j < n; ++j) {
            matrix[i][j] = matrix[j][i] = rand() % 2;
        }
    }
    return matrix;
}

vector<vector<int>> inputMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Введите матрицу " << n << "x" << n << " (по строкам, 0/1):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    cout << "\nМатрица смежности:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    char choice;

    cout << "Введите количество городов: ";
    cin >> n;

    cout << "Сгенерировать матрицу случайно? (y/n): ";
    cin >> choice;

    vector<vector<int>> matrix;
    if (choice == 'y' || choice == 'Y') {
        matrix = generateMatrix(n);
    }
    else {
        matrix = inputMatrix(n);
    }

    printMatrix(matrix);
    int provinces = countProvinces(matrix);

    cout << "\nКоличество провинций: " << provinces << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    int N, step;
    cout << "Введите длину массива: ";
    cin >> N;
    cout << "Введите шаг: ";
    cin >> step;

    vector<int> arr;
    int jump_pos = rand() % (N - 2) + 1;

    for (int i = 0, val = 0; i < N; i++) {
        arr.push_back(val);
        val += (i == jump_pos) ? 2 * step : step;
    }

    cout << "Массив: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    int left = 0, right = N - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == arr[0] + mid * step) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    int missing = arr[0] + left * step;

    cout << "Недостающий элемент: " << missing << endl;
    cout << "Позиция прыжка: " << left << endl;

    return 0;
}
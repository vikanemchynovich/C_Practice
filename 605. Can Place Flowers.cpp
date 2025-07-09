#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int size = flowerbed.size();
    for (int i = 0; i < size && n > 0; ++i) {
        if (flowerbed[i] == 0) {
            bool prevEmpty = (i == 0) || (flowerbed[i - 1] == 0);
            bool nextEmpty = (i == size - 1) || (flowerbed[i + 1] == 0);
            if (prevEmpty && nextEmpty) {
                flowerbed[i] = 1;
                --n;
            }
        }
    }
    return n <= 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> flowerbed1 = { 1, 0, 0, 0, 1 };
    int n1 = 1;
    cout << "Количество цветков: " << n1 << "\n"
        << (canPlaceFlowers(flowerbed1, n1) ? "Можно посадить" : "Нельзя посадить") << endl;

    vector<int> flowerbed2 = { 1, 0, 0, 0, 1 };
    int n2 = 2;
    cout << "Количество цветков: " << n2 << "\n"
        << (canPlaceFlowers(flowerbed2, n2) ? "Можно посадить" : "Нельзя посадить") << endl;

    return 0;
}
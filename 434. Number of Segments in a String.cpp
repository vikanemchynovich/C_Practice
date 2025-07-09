#include <iostream>
#include <string>

using namespace std;

int countSegments(string s) {
    int segment_count = 0;
    bool in_segment = false;

    for (char c : s) {
        if (c != ' ') {
            if (!in_segment) {
                segment_count++;
                in_segment = true;
            }
        }
        else {
            in_segment = false;
        }
    }

    return segment_count;
}

int main() {
    setlocale(LC_ALL, "Russian");
    string test_string = "Hello, world! This is a test.";
    int result = countSegments(test_string);

    cout << "Строка: \"" << test_string << "\"" << endl;
    cout << "Количество сегментов: " << result << endl;

    return 0;
}
#include <stack>
#include <stdexcept>
#include <iostream>

template <typename T>
class Queue {
private:
    std::stack<T> input;
    std::stack<T> output;

    void shiftStacks() {
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
    }

public:
    void push(const T& value) {
        input.push(value);
    }

    void pop() {
        if (empty()) {
            throw std::runtime_error("Queue is empty");
        }

        if (output.empty()) {
            shiftStacks();
        }

        output.pop();
    }

    T front() {
        if (empty()) {
            throw std::runtime_error("Queue is empty");
        }

        if (output.empty()) {
            shiftStacks();
        }

        return output.top();
    }

    bool empty() const {
        return input.empty() && output.empty();
    }

    size_t size() const {
        return input.size() + output.size();
    }
};

int main() {
    Queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);  // input: [1, 2, 3], output: []

    std::cout << "Front: " << q.front() << std::endl; // input: [], output: [3, 2, 1]
    q.pop();  // output: [3, 2]

    q.push(4);  // input: [4]

    std::cout << "Front: " << q.front() << std::endl;
    q.pop();  // output: [4]

    std::cout << "Size: " << q.size() << std::endl;  // input: [4], output: [3]

    return 0;
}
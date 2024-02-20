#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class GenericStack {
protected:
    int capacity;
    vector<T> items;
public:
    GenericStack(int capacity) {
        this->capacity = capacity;

    }
    void push(const T& item) {
        items.push_back(item);
    }

    T pop() {
        if (items.empty()) {
            throw runtime_error("The stack is empty");
        }
        T item = items.back();
        items.pop_back();
        return item;
    }

    T& peek() {
        if (items.empty()) {
            throw runtime_error("The stack is empty");
        }
        return items.back();
    }

};

class StringStack : public GenericStack<string> {
public:
    StringStack(int capacity) : GenericStack(capacity) {
        this->capacity = capacity;
    }
    void push(string item) {
        if (item.empty()) {
            throw runtime_error("String is empty");
        }
        items.push_back(item);
    }

    void concatTopTwo() {
        if (this->capacity < 2) {
            throw runtime_error("Too less items in the stack");
        }
        string s = this->pop() + this->pop();
        this->push(s);

    }

};

int main() {
    GenericStack<double> doubles(5);
    doubles.push(4);
    doubles.pop();
//    doubles.pop(); throws an error
    StringStack strings(6);
    strings.push("Hello");
    strings.push(("wo"));
    strings.push("rld");
    strings.push("f");

    cout << strings.pop() << endl;
     strings.concatTopTwo();
     cout << strings.pop() << endl;


}
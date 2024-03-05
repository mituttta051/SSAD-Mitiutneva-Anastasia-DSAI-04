#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;
template <typename T>
class CircularBuffer {
private:
    vector<T> buffer;
    int front;
    int currentSize;
public:
    CircularBuffer(int size) : buffer(size), front(0), currentSize(0) {}

    void push(const T& value) {
        int end = (front + currentSize) % buffer.size();
        buffer[end] = value;
        if (currentSize == buffer.size()) {
            front = (front + 1) % buffer.size();
        } else {
            ++currentSize;
        }
    }
    T pop() {
        if (empty()) {
            throw std::runtime_error("Buffer is empty");
        }
        T value = buffer[front];
        front = (front + 1) % buffer.size();
        --currentSize;
        return value;
    }
    bool empty() const {
        return currentSize == 0;
    }

    int size() const {
        return currentSize;
    }
    class Iterator;
    friend class Iterator;
    class Iterator {
    private:
        CircularBuffer<T> &buffer;
        int index;
    public:
        Iterator(CircularBuffer &buffer, int index) : buffer(buffer), index(index) {};


        T &operator*() {
            return buffer.buffer[index];
        }

        Iterator &operator++() {
            index = (index + 1) % buffer.buffer.size();
            return *this;
        }

        bool operator!=(const Iterator &other) const {
            return index != other.index || &buffer != &other.buffer;
        }
    };
    Iterator begin() {
        return Iterator(*this, front);
    }
    Iterator end() {
        return Iterator(*this, (front + currentSize) % buffer.size());
    }




};


int main() {
    CircularBuffer<int> buffer(4);
    buffer.push(1);
    buffer.push(2);
    buffer.push(3);

    for (auto it = buffer.begin(); it != buffer.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}

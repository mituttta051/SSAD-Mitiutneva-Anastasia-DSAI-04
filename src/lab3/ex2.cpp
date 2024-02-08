#include <vector>
#include <string>
#include <iostream>
using namespace std;
template <typename T, typename E>
vector<E> customMap (vector<T> input, E (*func)(T)) {
    vector<E> result = vector<E>();
    for (T n : input) {
        result.push_back(func(n));
    }
    return result;

}

template <typename T>
vector<T> customFilter (vector<T> input, bool (*func)(T)) {
    vector<T> result = vector<T>();
    for (T n : input) {
        if (func(n)) {
            result.push_back(n);
        }
    }
    return result;

}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "Squared: ";
    auto squared = customMap<int, int>(nums, [](int x) { return x * x; });
    for (int n : squared) {
        cout << n << " ";
    }
    cout << endl << "Odds: ";
    auto odds = customFilter<int>(nums, [](int x) { return x % 2 != 0; });
    for (int n : odds) {
        cout << n << " ";
    }
    return 0;
}
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int ex() {
    auto map = [](vector<int>* v, int (*fun_ptr)(int)) -> vector<int>* {
        vector<int>* output;
        for(int n : *v) {
            output->push_back(fun_ptr(n));
        }
        return output;
    };
    vector<int> v = {1, 2, 3};
    auto increase = [](int x) {return x+1;};
    vector<int> output = map(v, increase);
    for (int o : output) {
        cout << o << endl;
    }
    return 0;

}
int main() {
    ex();
    return 0;
}
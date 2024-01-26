#include <iostream>
using namespace std;

int arraySolution() {
    int N;
    cin >> N;
    int array[N];
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }
    int result[N];
    for (int i = 0; i < N; i++) {
        result[i] = -1;
    }
    int k = 0;
    for (int i = 0; i < N; i++) {
        int flag = 0;
        for (int j = 0; j < N; j++) {
            if (array[i] == result[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            result[k] = array[i];
            k += 1;
        } 
    }
    for (int i = 0; i < k; i++) {
            cout << result[i] << " ";
    }
    
    return 0;
}

int vectorSolution() {
    int N;
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    vector<int> result;

    for (int i = 0; i < N; i++) {
        int flag = 0;
        for (int j = 0; j < result.size(); j++) {
            if (v[i] == result[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            result.push_back(v[i]);
        } 
    }

    for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
    }
    
    return 0;
}

int main() {
    vectorSolution();
    return 0;
}
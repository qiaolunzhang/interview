#include <iostream>
#include <vector>

using namespace std;

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if (k > input.size()) {
            return result;
        }
        
        for (int i=0; i<k; i++) {
            result.push_back(input[i]);
            int key = input[i];
            int j = i - 1;
            while (j>=0 && result[j] > key) {
                result[j+1] = result[j];
                j = j - 1;
            }
            result[j+1] = key;
        }
        
        for (int i=k; i<input.size(); i++) {
            if (result[k-1] > input[i]) {
                int key = input[i];
                int j = k - 2;
                while (j>=0 && result[j] > key) {
                    result[j+1] = result[j];
                    j = j - 1;
                }
                result[j+1] = key;
            }
        }
        return result;
    }

int main() {
    cout << "hello world" << endl;
    vector<int> test;
    test.push_back(9);
    test.push_back(3);
    test.push_back(1);
    test.push_back(11);
    test.push_back(4);
    GetLeastNumbers_Solution(test, 3);
    return 0;
}
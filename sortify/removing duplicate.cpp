#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter the value at index [" << i << "]: ";
        cin >> arr[i];
    }

    vector<int> unique;

    for (int i = 0; i < n; i++) {
        bool duplicate = false;
        for (int j = 0; j < unique.size(); j++) {
            if (arr[i] == unique[j]) {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            unique.push_back(arr[i]);
        }
    }

    cout << "\nArray after removing duplicate values: ";
    for (int i = 0; i < unique.size(); i++) {
        cout << unique[i];
        if (i < unique.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}

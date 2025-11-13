#include <iostream>
#include <vector>
using namespace std;

void selectionSort(int arr[], int n, bool ascending = true)
{
    for (int i = 0; i < n - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < n; j++) {
            if ((ascending && arr[j] < arr[idx]) || (!ascending && arr[j] > arr[idx])) 
            {
                idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
}

void printArray(const vector<int>& vec) 
{
    for (int x : vec)
        cout << x << " ";
    cout << endl;
}

int main() 
{
    int n;
    cout << "Enter the size of array: ";
    while (!(cin >> n) || n <= 0) {
        cout << "Invalid input! Enter a positive integer: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter value at index [" << i << "]: ";
        while (!(cin >> arr[i])) {
            cout << "Invalid input! Enter an integer: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    vector<int> even, odd;

    for (int i = 0; i < n; i++) 
    {
        if (arr[i] % 2 == 0)
            even.push_back(arr[i]);
        else
            odd.push_back(arr[i]);
    }

    if (!even.empty())
        selectionSort(&even[0], even.size(), true);

    if (!odd.empty())
        selectionSort(&odd[0], odd.size(), false);

    cout << "\nEven numbers sorted ascending: ";
    printArray(even);

    cout << "Odd numbers sorted descending: ";
    printArray(odd);

    vector<int> merged;
    for (int x : even) merged.push_back(x);
    for (int x : odd) merged.push_back(x);

    if (!merged.empty())
        selectionSort(&merged[0], merged.size(), true);

    cout << "Merged Magic Sorted Array: ";
    printArray(merged);

    return 0;
}

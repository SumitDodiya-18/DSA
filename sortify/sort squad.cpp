#include <iostream>
using namespace std;

void selectionSort(int arr[], int n, bool ascending = true) 
{
    for (int i = 0; i < n - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < n; j++) {
            if ((ascending && arr[j] < arr[idx]) || (!ascending && arr[j] > arr[idx])) {
                idx = j;
            }
        }
     
        int temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    while (!(cin >> n) || n <= 0) 
    {        
        cout << "Invalid input! Enter a positive integer: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter value at index [" << i << "]: ";
        while (!(cin >> arr[i]))
        {       
            cout << "Invalid input! Enter an integer: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    selectionSort(arr, n, true);
    cout << "Array in Ascending Order: ";
    printArray(arr, n);

    selectionSort(arr, n, false);
    cout << "Array in Descending Order: ";
    printArray(arr, n);

    return 0;
}



#include <iostream>
using namespace std;

int main() 
{
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

    int positiveCount = 0, negativeCount = 0, zeroCount = 0;

    for (int i = 0; i < n; i++) 
    {
        if (arr[i] > 0)
            positiveCount++;
        else if (arr[i] < 0)
            negativeCount++;
        else
            zeroCount++;
    }

    cout << "Count of Positive numbers: " << positiveCount << endl;
    cout << "Count of Negative numbers: " << negativeCount << endl;
    cout << "Count of Zero: " << zeroCount << endl;

    return 0;
}

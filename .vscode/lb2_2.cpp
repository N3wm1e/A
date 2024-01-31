#include<iostream>
using namespace std;
double average(int* arr, int size);
int main()
{
    int length = 0;
    cout << "Array length: ";
    cin >> length;
    int* arr = new int[length];
    for (int i = 0; i < length; i++)
    {
        cout << "arr[" << i << "] = ";
        cin >> *(arr + i);
    }
    cout << "Average number: " << average(arr, length);
    delete[] arr;
    arr = nullptr;
}


double average(int *arr, int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }


    return sum / size;
}

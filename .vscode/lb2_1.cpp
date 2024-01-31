#include<iostream>
using namespace std;


int min(int arr[], int size);
int max(int arr[], int size);


int main()
{
    const int SIZE = 10;
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
    cout << "min: " << min(arr, SIZE) << endl;
    cout << "max: " << max(arr, SIZE) << endl;
}


int min(int arr[],int size)
{
    int min = arr[0];
    for (int i = 0; i < size;i++)
    {
        if (min > arr[i]) {
            min = arr[i];
        }
    }
    return min;
}
int max(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size;i++)
    {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

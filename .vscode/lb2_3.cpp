#include<iostream>
using namespace std;


void fillMatrix(int **arr, int size);
void printMatrix(int **arr, int size);
int main()
{
    int size = 0;
    cout << "size = ";cin >> size;
    int** arr = new int*[size];
    for (int i = 0; i < size;i++)
    {
        arr[i] = new int[size];
    }
    fillMatrix(arr, size);
    printMatrix(arr, size);
    for (int i = 0; i < size;i++)
    {
        delete[]arr[i];
    }
    delete[]arr;
}


void fillMatrix(int** arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "arr[" << i << "][" << j << "] = ";
            cin >> *(*(arr+i)+j);
        }
    }
}


void printMatrix(int** arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl << endl;
    }

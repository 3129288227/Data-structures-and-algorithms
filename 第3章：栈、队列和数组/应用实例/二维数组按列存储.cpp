#include <iostream>
using namespace std;

//����ά���鰴�д洢��һά������
void TwoMapOneDim(int arr[][3], int array[], int row, int col)
{
    int k = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            array[k++] = arr[j][i];
        }
    }
}

//����������һά����ȡֵ
int OneDimIndex(int *array, int i, int j)
{
    return array[(j - 1) * 3 + i - 1];
}

//��ӡ��ά����
void PrintTwoDim(int arr[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
}

//��ӡһά����
void PrintOneDim(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << '\t';
    }
    cout << endl;
}

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int array[9];
    PrintTwoDim(arr, 3, 3);
    TwoMapOneDim(arr, array, 3, 3);
    PrintOneDim(array, 9);
    cout << OneDimIndex(array, 3, 2);
}
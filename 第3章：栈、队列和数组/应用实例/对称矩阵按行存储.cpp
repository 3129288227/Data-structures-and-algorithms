#include <iostream>
using namespace std;

//����ά���鰴�д洢��һά������
//���������Ǿ���
void TwoMapOneDim(int arr[][3], int array[], int row, int col)
{
    int k = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            array[k++] = arr[i][j];
        }
    }
}

//����������һά����ȡֵ
int OneDimIndex(int *array, int i, int j)
{
    if (i >= j)
    {
        return array[i * (i - 1) / 2 + j - 1];
    }
    else
    {
        return array[j * (j - 1) / 2 + i - 1];
    }
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
    int arr[3][3] = {{1, 4, 5}, {4, 2, 6}, {5, 6, 3}};
    int array[3 * (3 + 1) / 2];
    PrintTwoDim(arr, 3, 3);
    TwoMapOneDim(arr, array, 3, 3);
    PrintOneDim(array, 3 * (3 + 1) / 2);
    cout << OneDimIndex(array, 1, 3);
}
#include <iostream>
using namespace std;

//������Ԫ��
typedef struct
{
    int row;
    int col;
    int value;
} Triple[100];

//��ϡ������洢����Ԫ��
void ArrToTriple(int arr[][3], Triple t, int &len)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] != 0)
            {
                t[len].row = i;
                t[len].col = j;
                t[len].value = arr[i][j];
                len++;
            }
        }
    }
}

//����Ԫ��ָ���ϡ������
void TripleToArr(int arr[][3], Triple t, int len)
{
    for (int i = 0; i < len; i++)
    {
        arr[t[i].row][t[i].col] = t[i].value;
    }
}

//��ӡ��ά����
void Print(int arr[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
}

int main()
{
    int arr[3][3] = {{1, 0, 0}, {4, 0, 6}, {0, 8, 0}};
    Triple t;
    int len = 0;
    int new_arr[3][3] = {0};
    ArrToTriple(arr, t, len);
    TripleToArr(new_arr, t, len);
    Print(new_arr);
}
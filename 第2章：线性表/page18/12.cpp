#include <iostream>
using namespace std;
#define Maxsize 50

// ����˳���ṹ
typedef struct
{
    int data[Maxsize];
    int length = 0;
} SqList;

// �����������
void ListInsert(SqList &L)
{
    int val = 0;
    while (cin >> val)
    {
        L.data[L.length++] = val;

        if (cin.get() == '\n')
        {
            break;
        }
    }
}

// ��ӡ˳���
void PrintList(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << '\t';
    }
    cout << endl;
}

// ��Ŀ���ܺ���
int MainValue(SqList &L, int n)
{
    int i, c, count = 1;
    c = L.data[0];
    for (i = 1; i < n; i++)
    {
        if (L.data[i] == c)
        {
            count++;
        }
        else
        {
            if (count > 0)
            {
                count--;
            }
            else
            {
                c = L.data[i];
                count = 1;
            }
        }
    }
    if (count > 0)
    {
        for (i = count = 0; i < n; i++)
        {
            if (L.data[i] == c)
            {
                count++;
            }
        }
    }
    if (count > n / 2)
    {
        return c;
    }
    else
    {
        return -1;
    }
}

int main()
{
    SqList L;      // ����һ��˳���
    ListInsert(L); // ����д��������

    cout << MainValue(L, 5);
}
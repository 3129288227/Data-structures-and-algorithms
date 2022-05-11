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
void MergeList(SqList &L1, SqList &L2, SqList &L3)
{
    int i = 0, j = 0, k = 0;
    while (i < L1.length && j < L2.length)
    {
        if (L1.data[i] < L2.data[j])
        {
            L3.data[k++] = L1.data[i++];
        }
        else
        {
            L3.data[k++] = L2.data[j++];
        }
    }

    while (i < L1.length)
    {
        L3.data[k++] = L1.data[i++];
    }
    while (j < L2.length)
    {
        L3.data[k++] = L2.data[j++];
    }

    L3.length = L1.length + L2.length;
}

int main()
{
    SqList L1, L2, L3; // ����һ��˳���
    ListInsert(L1);    // ����д��������
    ListInsert(L2);

    MergeList(L1, L2, L3);
    cout << L3.length;

    PrintList(L3);
}
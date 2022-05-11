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
void DelValue(SqList &L)
{
    if (L.length == 0)
    {
        return;
    }
    int k = 0;
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[k] != L.data[i])
        {
            L.data[++k] = L.data[i];
        }
    }

    L.length = k + 1;
}

int main()
{
    SqList L;      // ����һ��˳���
    ListInsert(L); // ����д��������
    PrintList(L);

    DelValue(L);
    PrintList(L);
}
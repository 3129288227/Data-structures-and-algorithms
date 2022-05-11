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
void ReverseList(SqList &L)
{
    int temp = 0;
    for (int i = 0; i < L.length / 2; i++)
    {
        temp = L.data[i]; // ������ʱ�������浱ǰλ�õ�ֵ
        // ����β��Ӧλ�ý��н���
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}

int main()
{
    SqList L;      // ����һ��˳���
    ListInsert(L); // ����д��������
    PrintList(L);

    ReverseList(L);
    PrintList(L);
}
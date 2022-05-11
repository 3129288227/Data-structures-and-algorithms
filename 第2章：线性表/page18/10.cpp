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
void Reverse(SqList &L, int left, int right)
{
    // ����Ӧλ��Ԫ�ؽ���ʵ��������ת
    for (int i = 0; i < (right - left + 1) / 2; i++)
    {
        int temp = L.data[i + left];
        L.data[i + left] = L.data[right - i];
        L.data[right - i] = temp;
    }
}

void ReverseList(SqList &L, int p)
{
    Reverse(L, 0, p - 1);        // ��תǰm��Ԫ��
    Reverse(L, p, L.length - 1); // ��ת��n��Ԫ��
    Reverse(L, 0, L.length - 1); // ��ת��������
}

int main()
{
    SqList L;      // ����һ��˳���
    ListInsert(L); // ����д��������

    ReverseList(L, 3);
    PrintList(L);
}
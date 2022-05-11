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
void DelValue(SqList &L, int s, int t)
{
    // �жϺ�����
    if (s >= t || L.length == 0)
    {
        cout << "Error";
        return;
    }

    int i = 0, j = 0; // ���屣���һ�����ڵ���s��Ԫ�ص��±꣬��һ������t��Ԫ�ص��±�
    // Ѱ�ҵ�һ�����ڵ���s��Ԫ�ص��±�
    for (; i < L.length && L.data[i] < s; i++)
        ;
    // ���û�д���s�Ľ�������
    if (i == L.length)
    {
        return;
    }
    // Ѱ�ҵ�һ������t��Ԫ�ص��±�
    for (; j < L.length && L.data[j] <= t; j++)
        ;
    // ������t��Ԫ��ǰ��
    for (; j < L.length; i++, j++)
    {
        L.data[i] = L.data[j];
    }
    L.length = i;
}

int main()
{
    SqList L;      // ����һ��˳���
    ListInsert(L); // ����д��������
    PrintList(L);

    DelValue(L, 3, 6);
    PrintList(L);
}
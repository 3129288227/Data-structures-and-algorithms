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
void DelValue(SqList &L, int x)
{
    int k = 0; //���治����x��Ԫ�ص�λ���±�
    int length = L.length;
    for (int i = 0; i < length; i++)
    {
        // ���������x�����丳ֵ��kλ��
        if (L.data[i] != x)
        {
            L.data[k++] = L.data[i];
        }
        // ����x����ɾ�������ǽ����ȼ�һ
        else
        {
            L.length--;
        }
    }
}

int main()
{
    SqList L;      // ����һ��˳���
    ListInsert(L); // ����д��������
    PrintList(L);

    int x = 5;
    DelValue(L, x);
    PrintList(L);
}
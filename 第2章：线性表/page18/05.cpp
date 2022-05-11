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

    // ����k���ڼ�¼����֮���Ԫ�ظ���
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (!(L.data[i] >= s && L.data[i] <= t)) // ������ֲ���֮�䣬����ǰ��
        {
            L.data[k++] = L.data[i];
        }
    }

    L.length = k;
}

int main()
{
    SqList L;      // ����һ��˳���
    ListInsert(L); // ����д��������
    PrintList(L);

    DelValue(L, 3, 6);
    PrintList(L);
}
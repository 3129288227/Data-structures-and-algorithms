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
bool DelMin(SqList &L, int &value)
{
    if (L.length == 0)
    {
        cout << "��ǰ˳���Ϊ�գ�";
        return false;
    }

    value = L.data[0];
    int pos = 0;

    // ѭ������Ѱ����Сֵ����Сֵ�����±�
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[i] < value)
        {
            value = L.data[i];
            pos = i;
        }
    }

    // ʹ�����һ��λ���ɾ��Ԫ��
    L.data[pos] = L.data[L.length - 1];
    L.length--;

    return true;
}

int main()
{
    SqList L;      // ����һ��˳���
    ListInsert(L); // ����д��������
    PrintList(L);

    int value = 0;
    DelMin(L, value);
    PrintList(L);
    cout << "��С��Ԫ��Ϊ��" << value;
}
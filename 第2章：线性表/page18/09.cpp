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
void SearchList(SqList &L, int x)
{
    // ʹ�ö��ֲ��Ҳ���x
    int low = 0, high = L.length - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (L.data[mid] < x)
        {
            low = mid + 1;
        }
        else if (L.data[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            break;
        }
    }

    // ����ҵ�x���Ҳ������һ��Ԫ�ؽ��н���
    if (L.data[mid] == x && mid != L.length - 1)
    {
        int temp = L.data[mid];
        L.data[mid] = L.data[mid + 1];
        L.data[mid + 1] = temp;
    }

    // ���û���ҵ������в���
    if (low > high)
    {
        int i = 0;
        for (i = L.length - 1; i > high; i--)
        {
            L.data[i + 1] = L.data[i];
        }
        L.data[i + 1] = x;
        L.length++;
    }
}

int main()
{
    SqList L;      // ����һ��˳���
    ListInsert(L); // ����д��������

    SearchList(L, 3);
    PrintList(L);
}
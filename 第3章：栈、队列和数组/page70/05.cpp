#include <iostream>
using namespace std;
#define MAXSIZE 100

// ��������
typedef struct
{
    int data[MAXSIZE];
    int top1 = -1;
    int top2 = MAXSIZE;
} stk;

void Push(stk &s, int top, int value)
{
    if (top != 1 && top != 2)
    {
        cout << "ջ���������" << endl;
        return;
    }

    if (s.top2 - s.top1 == 1)
    {
        cout << "��ǰջ����" << endl;
        return;
    }

    if (top == 1)
    {
        s.data[++s.top1] = value;
    }
    else
    {
        s.data[--s.top2] = value;
    }
}

int Pop(stk &s, int top)
{
    if (top != 1 && top != 2)
    {
        cout << "ջ���������" << endl;
        return -1;
    }

    if (top == 1)
    {
        if (s.top1 == -1)
        {
            cout << "��ǰջ�ѿ�" << endl;
            return -1;
        }
        else
        {
            return s.data[s.top1--];
        }
    }
    else
    {
        if (s.top2 == MAXSIZE)
        {
            cout << "��ǰջ�ѿ�" << endl;
            return -1;
        }
        else
        {
            return s.data[s.top2++];
        }
    }
}

int main()
{
    stk s;

    Push(s, 1, 2);
    Push(s, 1, 4);
    Push(s, 1, 6);
    Push(s, 2, 3);
    Push(s, 2, 7);

    cout << Pop(s, 1) << endl;
    cout << Pop(s, 2) << endl;
    cout << Pop(s, 2) << endl;
    cout << Pop(s, 2) << endl;
    cout << Pop(s, 1) << endl;
}
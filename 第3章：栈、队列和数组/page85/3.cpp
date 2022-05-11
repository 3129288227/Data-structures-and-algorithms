#include <iostream>
using namespace std;
#define MAXSIZE 3

//����ѭ������
typedef struct
{
    int data[MAXSIZE];
    int front = 0, rear = 0;
} SqQueue;

//����ջ
typedef struct
{
    int data[MAXSIZE];
    int top1 = -1;
} Stack;

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(Stack s)
{
    if (s.top1 == -1)
    {
        return true;
    }
    return false;
}

//�ж�ջ�Ƿ����
bool StackOverflow(Stack s)
{
    if (s.top1 >= MAXSIZE)
    {
        return true;
    }
    return false;
}

//ѹջ
void Push(Stack &s, int x)
{
    if (!StackOverflow(s))
    {
        s.data[++s.top1] = x;
    }
    else
    {
        cout << "��ǰջ����" << endl;
    }
}

//��ջ
void Pop(Stack &s, int &x)
{

    if (StackEmpty(s))
    {
        cout << "��ǰջ�ѿ�" << endl;
        return;
    }
    else
    {
        x = s.data[s.top1--];
    }
}

//���
void Enqueue(Stack &s1, Stack &s2, int x)
{
    //���ջs1û��������xѹ��x1
    if (!StackOverflow(s1))
    {
        Push(s1, x);
        return;
    }
    //���s1���ˣ�ͬʱs2���ǿյģ�������ʱ��������
    else if (StackOverflow(s1) && !StackEmpty(s2))
    {
        cout << "��ǰ��������" << endl;
        return;
    }
    //���s1������ʱs2Ϊ�գ����в�������s1��Ԫ��ѹ��s2
    else if (StackOverflow(s1) && StackEmpty(s2))
    {
        int value;
        while (!StackEmpty(s1))
        {
            Pop(s1, value);
            Push(s2, value);
        }
        Push(s1, x);
    }
}

//����
void Dequeue(Stack &s1, Stack &s2, int &x)
{
    //���ջs2���գ�ֱ�ӳ���
    if (!StackEmpty(s2))
    {
        Pop(s2, x);
    }
    //���ջs2����s1Ϊ�գ���������Ϊ��
    else if (StackEmpty(s1))
    {
        cout << "��ǰ����Ϊ��" << endl;
        return;
    }
    //���ջs2����s1���գ���s1��Ԫ�ص���ѹ��s2��
    else
    {
        int value;
        while (!StackEmpty(s1))
        {
            Pop(s1, value);
            Push(s2, value);
        }
        Pop(s2, x);
    }
}

//�ж϶����Ƿ�Ϊ��
void QueueEmpty(Stack s1, Stack s2)
{
    if (StackEmpty(s1) && StackEmpty(s2))
    {
        cout << "��ǰ����Ϊ��" << endl;
    }
}

int main()
{
    Stack s1, s2;
    int x = 0;
    QueueEmpty(s1, s2);
    Enqueue(s1, s2, 1);
    Enqueue(s1, s2, 2);
    Dequeue(s1, s2, x);
    cout << x << endl;
    Enqueue(s1, s2, 3);
    Dequeue(s1, s2, x);
    cout << x << endl;
    Dequeue(s1, s2, x);
    cout << x << endl;
    QueueEmpty(s1, s2);
}
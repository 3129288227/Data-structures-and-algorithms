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

//�ж϶����Ƿ�Ϊ��
bool IsEmpty(SqQueue Q)
{
    if (Q.front == Q.rear)
    {
        return true;
    }
    return false;
}

//�ж϶����Ƿ���
bool IsFull(SqQueue Q)
{
    if (Q.rear == MAXSIZE)
    {
        return true;
    }
    return false;
}

//����
bool EnQueue(SqQueue &Q, int x)
{
    if (IsFull(Q))
    {
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear++;
    return true;
}

//����
bool DeQueue(SqQueue &Q, int &x)
{
    if (IsEmpty(Q))
    {
        return false;
    }
    x = Q.data[Q.front];
    Q.front++;
    return true;
}

void Push(Stack &s, int value)
{
    s.data[++s.top1] = value;
}

int Pop(Stack &s)
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

//�������Ԫ��
void Print(SqQueue Q)
{
    for (int i = Q.front; i < Q.rear; i++)
    {
        cout << Q.data[i] << '\t';
    }
    cout << endl;
}

void ReverseQueue(SqQueue &Q, Stack &s)
{
    //�������е�Ԫ�س���ѹ��ջ��
    while (Q.front != Q.rear)
    {
        int value;
        DeQueue(Q, value);
        Push(s, value);
    }

    Q.front = Q.rear = 0;

    //��ջ��Ԫ�ص������
    while (s.top1 != -1)
    {
        int value = Pop(s);
        EnQueue(Q, value);
    }
}

int main()
{
    SqQueue Q;
    Stack s;
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);

    Print(Q);
    ReverseQueue(Q, s);
    Print(Q);
}
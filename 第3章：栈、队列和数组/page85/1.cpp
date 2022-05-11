#include <iostream>
using namespace std;
#define MAXSIZE 3

//����ѭ������ṹ
typedef struct
{
    int data[MAXSIZE];
    int front = 0, rear = 0;
    int tag = 0;
} SqQueue;

//�ж϶����Ƿ�Ϊ��
bool IsEmpty(SqQueue Q)
{
    if (Q.front == Q.rear && Q.tag == 0)
    {
        return true;
    }
    return false;
}

//�ж϶����Ƿ���
bool IsFull(SqQueue Q)
{
    if (Q.front == Q.rear && Q.tag == 1)
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
    Q.tag = 1;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return true;
}

//����
bool DeQueue(SqQueue &Q, int &x)
{
    if (IsEmpty(Q))
    {
        return false;
    }
    Q.tag = 0;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return true;
}

//�������Ԫ��
void Print(SqQueue Q)
{
    int length = 0;
    if (IsFull(Q))
    {
        length = MAXSIZE;
    }
    else
    {
        length = (Q.rear + MAXSIZE - Q.front) % MAXSIZE;
    }
    for (int i = Q.front; i < Q.front + length; i++)
    {
        cout << Q.data[i] << '\t';
    }
}

int main()
{
    SqQueue Q;
    EnQueue(Q, 1);
    EnQueue(Q, 1);

    Print(Q);
}
#include <iostream>
using namespace std;
#define MAXSIZE 100

//����ջ
typedef struct
{
    double data[MAXSIZE];
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
void Push(Stack &s, double x)
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
double Pop(Stack &s)
{

    if (StackEmpty(s))
    {
        cout << "��ǰջ�ѿ�" << endl;
        return '\0';
    }
    else
    {
        return s.data[s.top1--];
    }
}

//����ջʵ�ֵݹ�
double RecursionToStack(int n, double x)
{
    Stack s; //��ʼ��һ��ջ�����ڱ����Ӧ���n

    double fv1 = 1, fv2 = 2 * x; //n=0,n=1�ĳ�ʼֵ

    //n=0���
    if (n == 0)
    {
        return fv1;
    }

    //n=1���
    else if (n == 1)
    {
        return fv2;
    }

    //n>1�ݹ����
    for (int i = n; i >= 2; i--)
    {
        Push(s, i); //����Ӧ���ѹ��ջ�У�Խ����Խ���㣬ջ��Ϊ2
    }

    //����p2��ѹ��ջ�У��ټ���p3ѹ��ջ��
    while (!StackEmpty(s))
    {
        double no = Pop(s); //������Ӧ���n
        //������õ�Pn�ٴ�ѹ��ջ��
        Push(s, 2 * x * fv2 - 2 * (no - 1) * fv1);
        fv1 = fv2; //fv2��ֵ����fv1
        fv2 = Pop(s); //fv2��ֵ��Ϊ�ղ��¼����ѹ��ջ����ֵ
    } 

    return fv2;
}

int main()
{
    int n = 5;
    double x = 4;
    cout << RecursionToStack(n, x) << endl;
}
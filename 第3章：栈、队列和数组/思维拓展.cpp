#include <iostream>
using namespace std;
#define MAXSIZE 100

//����ջ�ṹ
typedef struct
{
    int data[MAXSIZE]; //������ͨԪ��
    int data_min[MAXSIZE]; //���浱ǰջ��Сֵ
    int top = -1; //ջ��
    int top_min = -1;
} Stack;

//�ж�ջ�Ƿ�Ϊ��
bool EmptyStack(Stack s)
{
    if (s.top == -1)
    {
        return true;
    }
    return false;
}

//�ж�ջ�Ƿ����
bool FullEmpty(Stack s)
{
    if (s.top == MAXSIZE)
    {
        return true;
    }
    return false;
}

//ѹջ
void Push(Stack &s, int x)
{
    if (!FullEmpty(s))
    {
        //�����СֵջΪ�գ�ֱ�ӽ���ǰԪ��ѹջ
        if (s.top_min == -1)
        {
            s.data_min[++s.top_min] = x;
        }
        //�����ǰֵС�ڸ���ջ��ջ��Ԫ�أ�����ѹ�븨��ջ
        else if (x < s.data_min[s.top_min])
        {
            s.data_min[++s.top_min] = x;
        }
        //����ǰֵѹ����ջ
        s.data[++s.top] = x;
    }
}

//��ջ
int Pop(Stack &s)
{
    if (!EmptyStack(s))
    {
        //�������ջ��ջ��Ԫ�ص�����ջ��ջ��Ԫ�أ�����ȫ������
        if (s.data[s.top] == s.data_min[s.top_min])
        {
            s.top--;
            s.top_min--;
            return s.data[s.top];
        }
        //������ջԪ�ص���
        else
        {
            return s.data[s.top--];
        }
    }
    exit(0);
}

//���ջ����Сֵ
int min(Stack s)
{
    if (s.top_min == -1)
    {
        cout << "��ǰջΪ��" << endl;
        exit(0);
    }
    //���ظ���ջ��ջ��Ԫ��
    return s.data_min[s.top_min];
}
int main()
{
    Stack s;
    Push(s, 2);
    Push(s, 3);
    cout << min(s) << endl;
    Push(s, 1);
    cout << min(s) << endl;
    Pop(s);
    cout << min(s) << endl;
    Pop(s);
    cout << min(s) << endl;
}
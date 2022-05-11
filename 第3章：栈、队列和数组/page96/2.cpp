#include <iostream>
using namespace std;
#define MAXSIZE 100

//����ջ
typedef struct
{
    char data[MAXSIZE];
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
void Push(Stack &s, char x)
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
char Pop(Stack &s)
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

//ʵ�ֻ𳵵���
void TrainSchedule(char *str)
{
    Stack s;          //��ʼջ�����ڱ���H
    int i = 0, k = 0; //��������������i���ڱ�����k���ڵ���S

    while (str[i] != '\0')
    {
        //�����H��������ջ���ȴ�����
        if (str[i] == 'H')
        {
            Push(s, str[i]);
        }
        //�����S��ֱ�ӽ������ǰ��
        else
        {
            str[k++] = str[i];
        }
        i++;
    }

    //������Hƴ��S����
    while (!StackEmpty(s))
    {
        str[k++] = Pop(s);
    }
}

int main()
{
    char str[] = "HSHHSSHHHS";
    TrainSchedule(str);
    cout << str << endl;
}
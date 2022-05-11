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

//ʵ������ƥ��
void BracketMatch(Stack &s, char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        cout << str[i] << endl;
        //����������Ž���ѹ��ջ��
        if (str[i] == '[' || str[i] == '{' || str[i] == '(')
        {
            Push(s, str[i]);
        }
        else
        {
            //�����ʱ�������ţ���ջΪ�գ������Ų�ƥ��
            if (StackEmpty(s))
            {
                cout << "���Ų�ƥ��" << endl;
                return;
            }
            else
            {
                char chr = Pop(s);
                //���ջ��Ϊ�գ�����ջ��Ԫ���뵱ǰ�����Ų�ƥ��
                if (!((str[i] == ']' && chr == '[') || (str[i] == '}' && chr == '{') || (str[i] == ')' && chr == '(')))
                {
                    cout << "���Ų�ƥ��" << endl;
                    return;
                }
            }
        }
        i++;
    }
    //���ȫ��ƥ���ջΪ�ձ�ʾ����ƥ��
    if (StackEmpty(s))
    {
        cout << "����ƥ��" << endl;
        return;
    }
    //ջ���ж������ţ���ƥ��
    cout << "���Ų�ƥ��" << endl;
}

int main()
{
    Stack s;
    char str[] = "[(){}]";

    BracketMatch(s, str);
}
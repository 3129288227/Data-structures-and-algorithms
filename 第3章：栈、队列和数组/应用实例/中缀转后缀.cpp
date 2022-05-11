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
        // cout << "��ǰջ�ѿ�" << endl;
        return '\0';
    }
    else
    {
        return s.data[s.top1--];
    }
}

//����׺���ʽתΪ��׺���ʽ
string InfixToSuffix(string infix)
{
    Stack s;
    string suffix = "";
    char op;

    for (int i = 0; i < infix.length(); i++)
    {
        //����������ֱ�Ӽ����׺���ʽ
        if (infix[i] >= 'A' && infix[i] <= 'Z')
        {
            suffix += infix[i];
        }
        //����������ֱ����ջ
        else if (infix[i] == '(')
        {
            Push(s, infix[i]);
        }
        //�������������ε��������������������׺���ʽ
        else if (infix[i] == ')')
        {
            while (!StackEmpty(s))
            {
                op = Pop(s);
                if (op != '(')
                {
                    suffix += op;
                }
                else
                {
                    break;
                }
            }
        }

        else
        {
            //����ǳ˺Ż��߳���ֻ�����˺Ż��߳���
            if (infix[i] == '*' || infix[i] == '/')
            {

                while (!StackEmpty(s))
                {
                    op = Pop(s);
                    if (op == '(')
                    {
                        break;
                    }
                    else
                    {
                        //�����ͼ������������ѹ��ȥ
                        if (op == '+' || op == '-')
                        {
                            Push(s, op);
                            break;
                        }
                        else
                        {
                            suffix += op;
                        }
                    }
                }
            }
            //����+-����������������������
            else if (infix[i] == '+' || infix[i] == '-')
            {
                while (!StackEmpty(s))
                {
                    op = Pop(s);
                    if (op == '(')
                    {
                        break;
                    }
                    else
                    {
                        suffix += op;
                    }
                }
            }
            //����ǰ�����ѹ��ջ��
            Push(s, infix[i]);
        }
    }

    //��ջ��ʣ����������ε���
    while (!StackEmpty(s))
    {
        suffix += Pop(s);
    }

    return suffix;
}

int main()
{
    string infix = "A+B*(C-D)-E/F";
    cout << InfixToSuffix(infix);
}
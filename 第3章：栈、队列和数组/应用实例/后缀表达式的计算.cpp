#include <iostream>
using namespace std;
#define MAXSIZE 100

//����ջ
typedef struct
{
    double data[MAXSIZE] = {0.0};
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
        // cout << "��ǰջ�ѿ�" << endl;
        return '\0';
    }
    else
    {
        return s.data[s.top1--];
    }
}

//�����׺���ʽ
void CalSuffix(string suffix[])
{
    Stack s; //����ջ�����ڱ��������

    for (int i = 0; i < 15; i++)
    {
        //���������������ѹ��ջ
        if (suffix[i] != "+" && suffix[i] != "-" && suffix[i] != "*" && suffix[i] != "/")
        {
            Push(s, atoi(suffix[i].c_str()));
        }
        //����ǲ��������ε�������������
        else
        {
            double oper1 = Pop(s); //�Ҳ�����
            double oper2 = Pop(s); //�������

            //ִ����Ӧ���㣬��������ѹ��ջ��
            if (suffix[i] == "+")
            {
                Push(s, oper1 + oper2);
            }
            else if (suffix[i] == "-")
            {
                Push(s, oper2 - oper1);
            }
            else if (suffix[i] == "*")
            {
                Push(s, oper1 * oper2);
            }
            else if (suffix[i] == "/")
            {
                Push(s, oper2 / oper1);
            }
        }
    }
    //����ջ��Ԫ�ؼ�Ϊ���
    cout << "���ս��Ϊ��" << Pop(s) << endl;
}

int main()
{
    string suffix[] = {"15",
                       "7",
                       "1",
                       "1",
                       "+",
                       "-",
                       "/",
                       "3",
                       "*",
                       "2",
                       "1",
                       "1",
                       "+",
                       "+",
                       "-"};

    CalSuffix(suffix);
}
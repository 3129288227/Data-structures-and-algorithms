#include <iostream>
using namespace std;
#define MAXSIZE 100

//���崮�Ľṹ
typedef struct
{
    char ch[MAXSIZE];
    int length = 0;
} String;

//Ϊ�ַ�����ֵ
void InitString(String &s, char *chars)
{
    int i = 0, k = 1;
    while (chars[i] != '\0')
    {
        s.ch[k++] = chars[i++];
        s.length++;
    }
}

//��ӡ�ַ���
void Print(String s)
{
    for (int i = 0; i < s.length; i++)
    {
        cout << s.ch[i + 1];
    }
    cout << endl;
}

//���ģʽ����next����
void GetNextVal(String T, int nextval[])
{
    int j = 1, k = 0;
    nextval[1] = 0; //��ʼ����һ��λ��
    while (j < T.length)
    {
        //���pj==pk����ƥ��ʧ��
        if (k == 0 || T.ch[j] == T.ch[k])
        {
            j++;
            k++;
            //�������������ֵ
            if (T.ch[j] != T.ch[k])
            {
                nextval[j] = k;
            }
            //����ݹ���ڵ�һ�γ��ֵ�ֵ
            else
            {
                nextval[j] = nextval[k];
            }
        }
        else
        {
            k = nextval[k]; //ƥ��ʧ�ܣ���������
        }
    }
}

//�ַ�������ƥ���㷨
int KMPMatch(String &S, String &T, int nextval[])
{
    int i = 1, j = 1; //�����ʼ�ַ���ָ��
    while (i <= S.length && j <= T.length)
    {
        //���ƥ��ɹ������ߵ�һ���ַ�ƥ��ʧ�ܣ�������ָ�����
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            j = nextval[j]; //ƥ��ʧ�ܣ��ƶ�ģ�崮ָ��Ϊ��󹫹�ǰ��׺�ĺ�һλ
        }
    }
    //���j��ֵ���ڵ�ǰģʽ���ĳ���˵����ȫ��ƥ��ɹ�
    if (j > T.length)
    {
        return i - T.length;
    }

    return -1;
}

//��ӡnextval����ֵ
void PrintArray(int nextval[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << nextval[i] << '\t';
    }
    cout << endl;
}

int main()
{
    String S, T;
    int n = 12;
    int nextval[n + 1];
    char s[] = "aabaabaabaacdss";
    char t[] = "ababaaababaa";
    InitString(S, s);
    InitString(T, t);

    GetNextVal(T, nextval);
    
    PrintArray(nextval, n);
}
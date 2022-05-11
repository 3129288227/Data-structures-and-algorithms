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
void GetNext(String T, int next[])
{
    int j = 1, k = 0;
    next[1] = 0; //��ʼ����һ��λ��
    while (j < T.length)
    {
        //���pj==pk����ƥ��ʧ��
        if (k == 0 || T.ch[j] == T.ch[k])
        {
            j++;
            k++;
            next[j] = k; // p[j+1]=p[j]+1
        }
        else
        {
            k = next[k]; //ƥ��ʧ�ܣ���������
        }
    }
}

//�ַ�������ƥ���㷨
int KMPMatch(String &S, String &T, int next[])
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
            j = next[j]; //ƥ��ʧ�ܣ��ƶ�ģ�崮ָ��Ϊ��󹫹�ǰ��׺�ĺ�һλ
        }
    }
    //���j��ֵ���ڵ�ǰģʽ���ĳ���˵����ȫ��ƥ��ɹ�
    if (j > T.length)
    {
        return i - T.length;
    }

    return -1;
}

//��ӡnext����ֵ
void PrintArray(int next[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << next[i] << '\t';
    }
    cout << endl;
}

//ͳ��ģʽ���������ж��ٸ���ȫƥ����Ӵ�
int CountSub(String S, String T, int next[], int n, int m)
{
    int count = 0;
    int i = 1, j = 1;
    while (i <= (n - m + 1))
    {
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
                j = next[j]; //ƥ��ʧ�ܣ��ƶ�ģ�崮ָ��Ϊ��󹫹�ǰ��׺�ĺ�һλ
            }
        }
        //���j��ֵ���ڵ�ǰģʽ���ĳ���˵����ȫ��ƥ��ɹ�
        if (j > T.length)
        {
            count++;
            i = i - T.length + 1;
            j = 1;
        }
        else
        {
            return count;
        }
    }

    return count;
}
int main()
{
    String S, T;
    int n = 14;
    int next[n + 1];
    char s[] = "ababaabaababab";
    char t[] = "ab";
    InitString(S, s);
    InitString(T, t);
    GetNext(T, next);
    cout << CountSub(S, T, next, n, 2);
}
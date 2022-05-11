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

//�ַ�������ƥ���㷨
int NaiveMatch(String &S, String &T)
{
    int i = 1, j = 1; //��ʼ��ָ�룬ͬʱָ��������ģʽ���ĵ�һ��λ��
    while (i <= S.length && j <= T.length)
    {
        //�����Ӧ�ַ���ȣ�ָ�����ƫ��һλ
        if (S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }
        //����ʧ��
        else
        {
            //i-j��ָ��ǰƥ�俪ʼ��ǰһ��λ�ã�+1�����ο�ʼƥ��λ�ã�+2�����ο�ʼƥ�����һ��λ��
            i = i - j + 2; //����ָ��ָ��ǰ�ȽϿ�ʼ����һ��λ��
            j = 1; //ģʽ��ָ���һλ�����¿�ʼ
        }
    }
    //���j��ֵ���ڵ�ǰģʽ���ĳ���˵����ȫ��ƥ��ɹ�
    if (j > T.length)
    {
        return i - T.length;
    }
    
    return -1;
}

int main()
{
    String S, T;
    char s[] = "googlegooalgelgoole";
    char t[] = "goole";
    InitString(S, s);
    InitString(T, t);
    cout << NaiveMatch(S, T);
}
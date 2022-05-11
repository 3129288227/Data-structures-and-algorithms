#include <iostream>
using namespace std;
#define MAXSIZE 100

//˳��洢�ṹ
typedef struct BiTNode
{
    char data[MAXSIZE];
    int length = 0;
} BiTNode, *BiTree;

//����������
BiTree CreateTree(string s)
{
    BiTree T = new BiTNode;
    for (int i = 0; i < s.length(); i++)
    {
        T->data[i + 1] = s[i];
        T->length++;
    }
    return T;
}

//Ѱ�ҹ������Ƚ��
void CommonAncestor(BiTree T, int i, int j)
{
    //�������Ϊ�գ���ָ��������㲻Ϊ��
    if (T && T->data[i] != '#' && T->data[j] != '#')
    {
        //�ݹ�Ѱ�ҹ������
        while (i != j)
        {
            //���i>j����i��Ϊ�丸���
            if (i > j)
            {
                i = i / 2;
            }
            //����j��Ϊ�����
            else
            {
                j = j / 2;
            }
        }
        //������������ʱ
        cout << T->data[i] << endl;
    }
}

int main()
{
    string s = "123456###78";
    BiTree T = CreateTree(s);
    CommonAncestor(T, 10, 11);
}
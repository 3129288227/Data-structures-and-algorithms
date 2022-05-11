#include <iostream>
using namespace std;

//���������
typedef struct BiTNode
{
    char data;
    struct BiTNode *left, *right;
} BiTNode, *BiTree;

//ͨ�������������������
void CreateTree(BiTree &T)
{
    char ch;
    cin >> ch;
    //������Ϊ#��˵���ýڵ�Ϊ��
    if (ch == '#')
    {
        T = NULL;
    }
    else
    {
        if (!(T = new BiTNode)) //�����½��ռ�
        {
            exit(0);
        }
        T->data = ch;
        //�ݹ齨����������
        CreateTree(T->left);
        CreateTree(T->right);
    }
}

//���������������
void CountTNode(BiTree &T, int &count)
{
    if (T)
    {
        count++; //��ǰ������+1
        //�ݹ���������
        CountTNode(T->left, count);
        CountTNode(T->right, count);
    }
}

int main()
{
    int count = 0;
    BiTree T;
    // 124635
    // string chr = "12#46###3#5##";
    CreateTree(T);
    CountTNode(T, count);
    cout << count << endl;
}
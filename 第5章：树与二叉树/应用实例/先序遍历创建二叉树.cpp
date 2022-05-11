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

//�������
void PreOrderTraversal(BiTree &T)
{
    if (T)
    {
        cout << T->data << '\t';
        //�ݹ������������
        PreOrderTraversal(T->left);
        PreOrderTraversal(T->right);
    }
}

int main()
{
    BiTree T;
    // 124635
    string chr = "12#46###3#5##";
    CreateTree(T);
    PreOrderTraversal(T);
}
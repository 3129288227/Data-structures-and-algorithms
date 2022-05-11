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

//����������߶�
int TreeHeight(BiTree &T)
{
    if (T)
    {
        int left_height = TreeHeight(T->left);                                //�������߶�
        int right_height = TreeHeight(T->right);                              //�������߶�
        return (left_height > right_height ? left_height : right_height) + 1; //�������������߶����ֵ+1
    }

    return 0;
}

int main()
{
    int count = 0;
    BiTree T;
    // 124635
    // string chr = "12#46###3#5##";
    CreateTree(T);

    cout << TreeHeight(T);
}
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

//����ȫ�ֱ����������ۼ�ÿ������·������
int path_length = 0;

//����������߶�
void PathLength(BiTree &T, int count)
{
    if (T)
    {
        path_length += count;            //�ۼӵ�ǰ����·������
        PathLength(T->left, count + 1);  //�ݹ���ڵ�
        PathLength(T->right, count + 1); //�ݹ��ҽ��
    }
}

int main()
{
    int count = 0;
    BiTree T;
    // 124635
    // string chr = "12#46###3#5##";
    CreateTree(T);

    PathLength(T, 0);

    cout << path_length;
}
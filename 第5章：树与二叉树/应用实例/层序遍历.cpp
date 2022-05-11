#include <iostream>
#include <queue>
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
void LevelOrderTraversal(BiTree &T)
{
    queue<BiTNode *> queue; //��ʼ��һ������
    BiTNode *p; //����һ���������
    queue.push(T); //�����ڵ����

    while (!queue.empty())
    {
        //��ö���Ԫ��
        p = queue.front();
        cout << p->data << '\t';
        queue.pop(); //������Ԫ�س���

        //���������
        if (p->left)
        {
            queue.push(p->left);
        }
        //�Һ������
        if (p->right)
        {
            queue.push(p->right);
        }
    }
}

int main()
{
    BiTree T;
    // 124635
    string chr = "12#46###3#5##";
    CreateTree(T);
    LevelOrderTraversal(T);
}
#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *prior;
    struct LNode *next;
} LNode, *LinkList;

// β�巨
void TailInsert(LinkList &L)
{
    int val = 0;
    LNode *r = L;
    while (cin >> val)
    {
        LNode *s = new LNode;
        s->data = val;
        r->next = s;
        s->prior = r;
        r = s;

        if (cin.get() == '\n')
        {
            break;
        }
    }

    r->next = L;
    L->prior = r;
}

// �����������Ԫ��
void Print(LinkList L)
{
    LNode *p = L->next;
    while (p != L)
    {
        cout << p->data << '\t';
        p = p->next;
    }
    cout << endl;
}

void JudgeSymmetry(LinkList &L)
{
    LNode *p, *q; //���幤����㣬�ֱ𱣴��Ӧ��ǰ���ͺ��
    p = L->next;
    q = L->prior;

    //���߲��غϼ����ж�
    while (p != q)
    {
        //ż��Ԫ�����
        if (p->next == q && p->data == q->data)
        {
            cout << "��ѭ������Գ�" << endl;
            return;
        }

        //�������
        if (p->data != q->data)
        {
            cout << "��ѭ�������Գ�" << endl;
            return;
        }
        else
        {
            p = p->next;
            q = q->prior;
        }
    }
    cout << "��ѭ������Գ�" << endl;
}

int main()
{
    LinkList L = new LNode;

    TailInsert(L);
    Print(L);

    JudgeSymmetry(L);
}
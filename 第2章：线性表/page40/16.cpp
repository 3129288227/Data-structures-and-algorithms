#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// ͷ�巨
void HeadInsert(LinkList &L)
{
    int val = 0;
    while (cin >> val)
    {
        LNode *s = new LNode;
        s->data = val;
        s->next = L->next;
        L->next = s;

        if (cin.get() == '\n')
        {
            break;
        }
    }
}

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
        r = s;
        r->next = NULL;

        if (cin.get() == '\n')
        {
            break;
        }
    }
}

// �����������Ԫ��
void Print(LinkList L)
{
    LNode *p = L->next;
    while (p)
    {
        cout << p->data << '\t';
        p = p->next;
    }
    cout << endl;
}

void SubNode(LinkList &LA, LinkList &LB)
{
    LNode *p, *q, *pre; // LA��LB�Ĺ�����㣬��ÿ�ο�ʼ�ıȽϽ��
    p = LA->next;
    q = LB->next;
    pre = p;

    while (p && q)
    {
        //���������ȣ�ָ����Ƽ���ƥ��
        if (p->data == q->data)
        {
            p = p->next;
            q = q->next;
        }
        //���ȣ���pre��ʼָ�����ƫ��һλ��q���¿�ʼ
        else
        {
            pre = pre->next;
            p = pre;
            q = LB->next;
        }
    }

    if (q)
    {
        cout << "B����A��������" << endl;
        return;
    }

    cout << "B��A��������" << endl;
}

int main()
{
    LinkList LA = new LNode;
    LinkList LB = new LNode;

    TailInsert(LA);
    TailInsert(LB);

    SubNode(LA, LB);
}
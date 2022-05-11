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

void DelValue(LinkList &L, int x)
{
    LNode *p, *pre;
    p = L->next, pre = L;

    while (p)
    {
        if (p->data == x)
        {
            LNode *q = p;
            pre->next = p->next;
            p = p->next;
            delete q;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}

int main()
{
    LinkList L = new LNode;
    TailInsert(L);

    DelValue(L, 2);
    Print(L);
}
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

void Duplicate(LinkList &L)
{
    LNode *p, *pre; //�ֱ𱣴湤�����ʹ�ɾ�����ǰ��
    p = L->next, pre = L;

    while (p)
    {
        if (p->next && p->data == p->next->data) //�жϵ�ǰ������һ�ڵ�ֵ�Ƿ���ͬ��Ҫ��֤��̽�����
        {
            LNode *q = p;
            p = p->next;
            pre->next = p;
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

    Duplicate(L);

    Print(L);
}
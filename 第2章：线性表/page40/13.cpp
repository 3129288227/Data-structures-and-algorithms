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

void MergeList(LinkList &LA, LinkList &LB)
{
    LNode *pa, *pb, *r; //�ֱ𱣴�LA��LB����ָ���������ʱ������ָ��
    pa = LA->next;
    pb = LB->next;
    LA->next = NULL; //��LA��Ϊ�ձ�

    while (pa && pb)
    {
        if (pa->data < pb->data)
        {
            r = pa->next;
            pa->next = LA->next;
            LA->next = pa;

            pa = r;
        }
        else
        {
            r = pb->next;
            pb->next = LA->next;
            LA->next = pb;

            pb = r;
        }
    }

    //������ʣ��Ԫ�����β���
    while (pa)
    {
        r = pa->next;
        pa->next = LA->next;
        LA->next = pa;

        pa = r;
    }

    while (pb)
    {
        r = pb->next;
        pb->next = LA->next;
        LA->next = pb;

        pb = r;
    }

    delete LB;
}

int main()
{
    LinkList LA = new LNode;
    LinkList LB = new LNode;
    TailInsert(LA);
    TailInsert(LB);

    MergeList(LA, LB);

    Print(LA);
}
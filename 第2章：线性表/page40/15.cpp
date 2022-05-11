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

void PublicNode(LinkList &LA, LinkList &LB)
{
    LNode *pa, *pb, *r, *q; //������������Ĺ�������β��ָ��
    pa = LA->next;
    pb = LB->next;
    r = LA;

    while (pa && pb)
    {
        //���paС��pb������ɾ����ͬʱָ�����
        if (pa->data < pb->data)
        {
            q = pa;
            pa = pa->next;
            delete q;
        }
        else if (pa->data > pb->data)
        {
            q = pb;
            pb = pb->next;
            delete q;
        }
        //�����Ƚ�paβ�壬ɾ��pb
        else
        {
            r->next = pa;
            r = pa;
            pa = pa->next;
            q = pb;
            pb = pb->next;
            delete q;
        }
    }

    //��ʣ�����н��ȫ���ͷ�
    while (pa)
    {
        q = pa;
        pa = pa->next;
        delete q;
    }

    while (pb)
    {
        q = pb;
        pb = pb->next;
        delete q;
    }

    r->next = NULL;
    delete LB;
}

int main()
{
    LinkList LA = new LNode;
    LinkList LB = new LNode;

    TailInsert(LA);
    TailInsert(LB);

    PublicNode(LA, LB);
    Print(LA);
}
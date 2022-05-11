#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
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
        r = s;

        if (cin.get() == '\n')
        {
            break;
        }
    }

    r->next = L;
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

void ConnectList(LinkList &LA, LinkList &LB)
{
    LNode *pa, *pb; //������������ָ��
    pa = LA->next;
    pb = LB->next;

    //�ҵ�LA��βָ��
    while (pa->next != LA)
    {
        pa = pa->next;
    }

    //�ҵ�LB��βָ��
    while (pb->next != LB)
    {
        pb = pb->next;
    }

    //�޸�ָ��ָ��
    pa->next = LB->next;
    pb->next = LA;
}

int main()
{
    LinkList LA = new LNode;
    LinkList LB = new LNode;

    TailInsert(LA);
    TailInsert(LB);

    ConnectList(LA, LB);

    Print(LA);
}
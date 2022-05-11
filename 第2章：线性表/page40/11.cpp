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

void BreakList(LinkList &LA, LinkList &LB)
{
    LNode *p, *q, *ra; //����ָ�롢������ָ�롢LAβָ��
    LB->next = NULL;   //��LB�����ÿ�
    p = LA->next;
    ra = LA; //��ʼ��βָ��
    while (p)
    {
        // LAβ��
        ra->next = p;
        ra = p;
        p = p->next;

        //���p��Ϊ�գ���������ǰ�嵽B
        if (p)
        {
            q = p->next; //����p�ĺ�̣���ֹ����
            p->next = LB->next;
            LB->next = p;
            p = q;
        }
    }
    ra->next = NULL; //��A��β����ָ������Ϊ��
}

int main()
{
    LinkList LA = new LNode;
    LinkList LB = new LNode;
    TailInsert(LA);

    BreakList(LA, LB);

    Print(LA);
    Print(LB);
}
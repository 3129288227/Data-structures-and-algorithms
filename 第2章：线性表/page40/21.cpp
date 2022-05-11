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

void LoopNode(LinkList &L)
{
    LNode *fast, *slow;    //������������ָ��
    fast = slow = L->next; //�ֱ�ָ���׽��

    //ͬʱ����
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;       //ÿ����һ��
        fast = fast->next->next; //ÿ��������

        //����
        if (fast == slow)
        {
            break;
        }
    }

    if (fast == NULL || fast->next == NULL)
    {
        cout << "�����޻�" << endl;
        return;
    }

    cout << "�����л�" << endl;
}

int main()
{
    LinkList L1 = new LNode;
    LinkList L2 = new LNode;
    LinkList L3 = new LNode;
    LinkList L4 = new LNode;

    L1->next = L2;
    L2->next = L3;
    L3->next = L4;
    L4->next = L2;

    LoopNode(L1);
}
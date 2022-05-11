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

void DelValue(LinkList &L)
{
    LNode *p, *pre, *minP, *minPre; //���幤�����ͱ�����Сֵ��ǰ����ָ��

    //ֻҪL��Ϊ�վ�������Сֵ
    while (L->next != L)
    {
        //����ָ��
        p = minP = L->next;
        pre = minPre = L;

        while (p != L)
        {
            if (p->data < minP->data)
            {
                minP = p;
                minPre = pre;
            }
            pre = p;
            p = p->next;
        }

        cout << minP->data << '\t';
        minPre->next = minP->next; //ɾ����Сֵ
        delete minP;
    }
    delete L;
}

int main()
{
    LinkList L = new LNode;

    TailInsert(L);

    DelValue(L);
}
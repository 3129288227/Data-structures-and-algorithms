#include <iostream>
#include <string.h>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// ͷ�巨
void HeadInsert(LinkList &L)
{
    int val = '\0';
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

void DelValue(LinkList &L, int n)
{
    LNode *p, *r, *pre;   //���幤��ָ�롢ǰ��ָ��
    int x = 0;            //�������ֵ
    int arr[n + 1] = {0}; //���帨�������ʼֵ��ֵΪ0

    p = L->next;
    pre = L;

    while (p)
    {
        x = p->data > 0 ? p->data : -p->data; //�������ֵ

        //������Ȳ����ڣ�����Ӧλ�ø�ֵΪ1
        if (arr[x] == 0)
        {
            arr[x] = 1;
            pre = p;
            p = p->next;
        }
        //���֮ǰ���ڣ��򽫵�ǰ���ɾ��
        else
        {
            r = p->next;
            pre->next = p->next;
            delete p;
            p = r;
        }
    }
}

int main()
{
    LinkList L = new LNode;
    TailInsert(L);
    Print(L);

    DelValue(L, 30);
    Print(L);
}
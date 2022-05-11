#include <iostream>
using namespace std;

// ��������
typedef struct LNode
{
    char data;
    struct LNode *next;
} LNode, *LinkList;

// ����β�巨����Ԫ��
void TailInsert(LinkList &L)
{
    char val = '0';
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

void fn(LinkList L, int n)
{
    char *s = new char[n / 2];
    LNode *p = L->next;
    for (int i = 0; i < n / 2; i++)
    {
        s[i] = p->data;
        p = p->next;
    }
    if (n % 2 == 1)
    {
        p = p->next;
    }
    int k = n / 2 - 1;
    while (p && s[k] == p->data)
    {
        k--;
        p = p->next;
    }
    if (k == -1)
    {
        cout << "����Ԫ�����ĶԳ�";
        return;
    }
    else
    {
        cout << "����Ԫ�ز����ĶԳ�";
    }
    delete[] s;
}

int main()
{
    LinkList L = new LNode;
    L->next = NULL;
    TailInsert(L);
    Print(L);
    fn(L, 4);
}
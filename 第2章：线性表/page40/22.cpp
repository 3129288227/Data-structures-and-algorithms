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

void SearchK(LinkList &L, int k)
{
    LNode *p, *q; //��������ָ�룬�ֱ��ǿ졢��ָ��
    p = q = L->next; //ͬʱָ���һ�����

    int count = 0;
    while (p)
    {
        //���������ҵ���k�����
        if (count < k)
        {
            count++;
        }
        //����k��֮��q��ʼ����
        else
        {
            q = q->next;
        }
        p = p->next;
    }

    //��p��β����ʱ��q��ָ����ǵ�����k��
    if (count < k)
    {
        cout << "����ʧ��" << endl;
        return;
    }

    cout << q->data << endl;
}

int main()
{
    LinkList L = new LNode;
    TailInsert(L);

    SearchK(L, 3);
}
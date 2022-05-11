#include <iostream>
using namespace std;
#define MAXSIZE 100

//�������
typedef struct
{
    char data[MAXSIZE];
    int front = 0, rear = 0;
} Queue;

//�ж϶����Ƿ�Ϊ��
bool EmptyQueue(Queue Q)
{
    if (Q.front == Q.rear)
    {
        return true;
    }
    return false;
}

//�ж϶����Ƿ�����
bool FullQueue(Queue Q)
{
    if (Q.rear == MAXSIZE)
    {
        return true;
    }
    return false;
}

//���
void EnQueue(Queue &Q, char x)
{
    if (!FullQueue(Q))
    {
        Q.data[Q.rear++] = x;
    }
}

//����
char DeQueue(Queue &Q)
{
    if (!EmptyQueue(Q))
    {
        return Q.data[Q.front++];
    }
    return '\0';
}

void Manager(Queue &ship, Queue &car, Queue &truck)
{
    int vehicles_num = 0, car_num = 0; //�����ϴ��������ͳ�����
    char ch;                           //���泵�����

    while (vehicles_num < 10)
    {
        //����ͳ�δ�գ��һ�û����4��
        if (!EmptyQueue(car) && car_num < 4)
        {
            ch = DeQueue(car);
            EnQueue(ship, ch);
            car_num++;
            vehicles_num++;
        }
        //����ͳ���4����ͬʱ����δ�գ���һ������
        else if (car_num == 4 && !(EmptyQueue(truck)))
        {
            ch = DeQueue(truck);
            EnQueue(ship, ch);
            car_num = 0;
            vehicles_num++;
        }
        //����ͳ����ˣ��Ҳ���4����ʹ�û�����ȫ
        else if (EmptyQueue(car) && car_num < 4)
        {
            while (vehicles_num < 10 && car_num < 4 && !EmptyQueue(truck))
            {
                ch = DeQueue(truck);
                EnQueue(ship, ch);
                car_num++;
                vehicles_num++;
            }
        }
        //�������ˣ�ȫ���Ͽͳ�
        else if (!EmptyQueue(car) && EmptyQueue(truck))
        {
            while (vehicles_num < 10 && car_num < 4 && !EmptyQueue(truck))
            {
                ch = DeQueue(truck);
                EnQueue(ship, ch);
                car_num++;
                vehicles_num++;
            }
        }
        //������
        if (EmptyQueue(car) && EmptyQueue(truck) && vehicles_num < 10)
        {
            cout << "�ͳ��������������10" << endl;
            return;
        }
    }
}

//�������
void Print(Queue Q)
{
    while (!EmptyQueue(Q))
    {
        cout << DeQueue(Q) << '\t';
    }
    cout << endl;
}

int main()
{
    Queue ship, car, truck;
    EnQueue(car, 'C');
    EnQueue(car, 'C');
    EnQueue(car, 'C');
    EnQueue(car, 'C');
    EnQueue(car, 'C');
    EnQueue(car, 'C');
    EnQueue(truck, 'T');
    EnQueue(truck, 'T');
    EnQueue(truck, 'T');
    EnQueue(car, 'C');
    Manager(ship, car, truck);
    Print(ship);
}
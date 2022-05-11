#include <iostream>
using namespace std;

//��������
void swap(int *a, int i, int j)
{
    int temp = *(a + i);
    *(a + i) = *(a + j);
    *(a + j) = temp;
}

int sort(int *a, int i, int j)
{
    int pivot = *(a + i);
    int left = i + 1;
    int right = j;

    while (left <= right)
    {
        if (*(a + left) <= pivot)
        {
            left++;
        }
        else
        {
            swap(a, left, right);
            right--;
        }
    }

    swap(a, i, right);
    return right;
}

void quickSort(int *a, int left, int right)
{
    if (left < right)
    {
        int mid = sort(a, left, right);
        quickSort(a, left, mid - 1);
        quickSort(a, mid + 1, right);
    }
}

//�ҵ������ֺ�Ϊx��������
void Find(int *arr, int x, int n)
{
    int i = 0, j = n - 1; //��������ָ�룬�ֱ�ָ��ͷ����β��

    //ֻҪ����ָ��û������������
    while (i < j)
    {
        //����ײ�+β��Ԫ��С��x����i++
        if (arr[i] + arr[j] < x)
        {
            i++;
        }
        //������ڣ���j--
        else if (arr[i] + arr[j] > x)
        {
            j--;
        }
        //�����ȣ������ӡ��Ȼ������ָ��ֱ������ǰƫ��һλ
        else
        {
            cout << arr[i] << " + " << arr[j] << " = " << x << endl;
            i++;
            j--;
        }
    }
}

int main()
{
    int arr[] = {1, 5, 3, 6, 2, 8, 3, 1, 4, 7, 9, 3, 2, 0, 2};
    quickSort(arr, 0, 14);
    Find(arr, 6, 15);
}
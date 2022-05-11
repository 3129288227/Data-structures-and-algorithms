#include <iostream>
using namespace std;

void Judge(string s)
{
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] == 'I')
        {
            sum += 1;
        }
        else
        {
            sum -= 1;
        }
        if (sum < 0)
        {
            cout << "���Ϸ�����" << endl;
            return;
        }
    }

    if (sum == 0)
    {
        cout << "�Ϸ�����" << endl;
        return;
    }

    cout << "���Ϸ�����" << endl;
}

int main()
{
    string s1 = "IOIIOIOO";
    string s2 = "IOOIOIIO";
    string s3 = "IIIOIOIO";
    string s4 = "IIIOOIOO";
    Judge(s1);
    Judge(s2);
    Judge(s3);
    Judge(s4);
}
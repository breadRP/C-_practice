#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> self_num;
    for (int i=1; i<=10000; i++)
    {
        bool isSelf_num = true;
        for (int a=0; a<10; a++)
        {
            for (int b=0; b<10; b++)
            {
                for (int c=0; c<10; c++)
                {
                    for (int d=0; d<10; d++)
                    {
                        if (1001*a + 101*b + 11*c + 2*d == i)
                        {
                            isSelf_num = false;
                            break;
                        }
                    }
                }
            }
        }
        if (isSelf_num)
        {
            self_num.push_back(i);
        }
    }

    for (int i : self_num)
    {
        cout << i << '\n';
    }

    return 0;
}
#include <iostream>
using namespace std;

int d(int n)
{
    int sum = n;

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main()
{
    bool generated[10001] = {false};

    for (int i = 1; i <= 10000; i++)
    {
        int num = d(i);

        if (num <= 10000)
            generated[num] = true;
    }

    for (int i = 1; i <= 10000; i++)
    {
        if (!generated[i])
            cout << i << '\n';
    }
}
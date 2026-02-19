#include <iostream>

int main()
{
    using namespace std;
    int a, b;

    cin >> a;
    cin >> b;
    if (a > b)
    {
        cout << '>';
    }
    else if (a < b)
    {
        cout << '<';
    }
    else
    {
        cout << "==";
    }
    return 0;
}
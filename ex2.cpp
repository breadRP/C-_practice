#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float a, b;
    cin >> a >> b;
    
    cout << fixed << setprecision(2) << a << " + " << fixed << setprecision(2) << b << " = " << fixed << setprecision(2) << a+b << endl;
    cout << fixed << setprecision(2) << a << " - " << fixed << setprecision(2) << b << " = " << fixed << setprecision(2) << a-b << endl;
    cout << fixed << setprecision(2) << a << " * " << fixed << setprecision(2) << b << " = " << fixed << setprecision(2) << a*b << endl;
    cout << fixed << setprecision(2) << a << " / " << fixed << setprecision(2) << b << " = " << fixed << setprecision(2) << a/b << endl;
    return 0;
}

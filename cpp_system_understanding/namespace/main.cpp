#include <iostream>

namespace A {int f();}
namespace B {int f();}

int main() {
    using namespace std;

    cout << A::f() << B::f();
}
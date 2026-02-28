#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
    using namespace std;
    vector<int> v;

    int size; // v에 들어갈 값 개수

    cin >> size;
    for (int i=0; i<size; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    } // v 벡터에 값 모두 저장 완료

    sort(v.begin(), v.end()); // 오름차순으로 정렬
    for (int i=0; i<size; i++) 
    {
        cout << v[i] << '\n';
    }
    
    return 0;
}
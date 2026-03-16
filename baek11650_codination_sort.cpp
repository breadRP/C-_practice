#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 좌표값 저장
    int N;
    cin >> N;
    vector<pair<int,int>> co;
    // **vector.reserve(N)로 먼저 메모리 할당하는게 효율적
    for (int i=0; i<N; i++)
    {
        int first, second;
        cin >> first >> second;
        co.push_back({first, second});
        // **emplace_back을 쓰면 복사해서 삽입이 아니라 바로 vector 내부에 pair를 생성하므로 더 효율적
    }
    
    // 좌표 정렬
    sort(co.begin(), co.end());

    //
    for (auto& i : co)
    {
        cout << i.first << ' ' << i.second << '\n';
    }
    
    return 0;
}
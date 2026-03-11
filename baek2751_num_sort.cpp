// 수 오름차순 정렬 + 중복 제거
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // cin 속도 개선
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // 숫자 입력 배열 구하기
    int N;
    cin >> N;
    vector<int> v(N); // 숫자 모아둘 배열
    for (int i=0; i<N; i++)
    {
        int num;
        cin >> v[i];
    }

    // 오름차순 정렬
    sort(v.begin(), v.end());

    // 배열 출력
    for (auto x : v)
    {
        cout << x << '\n';
    }

    return 0;
}
// 2525번: 오븐 시계
// 시작 시간과 필요한 시간이 주어질 때, 끝나는 시각 구하기
// 풀이 - 시계산술 1440 사용.
#include <iostream>

int main()
{
    using namespace std;
    int A, B; // A는 시작 시, B는 시작 분
    int C; // C는 필요한 시간(분단위)

    cin >> A; // 입력 받기 cin은 scanf와 동작원리가 비슷한걸로 추정
    cin >> B;
    cin >> C;

    int sum_of_time = A*60 + B; // 하루 중에 몇분이 지난 상태인지 저장
    int time_of_end = (sum_of_time + C) % 1440; // 하루는 1440분이고, 몇일이 지났는지는 중요하지 않고 지났을때 해당 일의 시각이 중요.
    cout << time_of_end/60 << " "; // 종료 시 출력
    cout << time_of_end%60; // 종료 분 출력
    return 0;
}
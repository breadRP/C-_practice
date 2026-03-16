//Review: 이 문제는 재귀로 풀면 2개를 분기되는 점 - 시간복잡도가 2^n. 그래서 그냥 반복문으로 시간복잡도를 n으로
#include <iostream>
using namespace std;
static int count_0 = 0; // 0 호출되는 횟수
static int count_1 = 0; // 1 호출되는 횟수

/*
int fibonacci(const int& n)
{
    // 초기식
    if (n == 0)
    {
        count_0++;
        return 0;
    }
    else if (n == 1)
    {
        count_1++;
        return 1;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    /* int n = 0;
    cin >> n;
    fibonacci(n);

    cout << count_0 << ' ' << count_1 << '\n';
    return 0;
    */

    int dp[41][2] = {0,}; // 40까지 피보나치를 구하는데 0과 1이 호출된 횟수

    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    // 시간복잡도 n / 40까지 피보나치 수 배열에 모두 저장.
    for (int i=2; i<= 40; i++)
    {
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }
    
    int T;
    cin >> T;
    for (int i=0; i<T; i++)
    {
        int n;
        cin >> n;
        cout << dp[n][0] << ' ' << dp[n][1] << '\n';
    }
}
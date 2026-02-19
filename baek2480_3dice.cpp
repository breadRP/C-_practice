// 2480번: 주사위 세개
// 같은 눈의 주사위가 몇개냐에 따라서 출력이 달라지는 문제
// 풀이 - 조건이 쉬운 같은 눈이 세 개, 한 개를 먼저 조건문으로 쓰고 나머지를 두 개로 고려
// + std에서 max()(algorithm 라이브러리) 공부하면 굳이 조건 나눌 필요 없음** ex. max(dice[0], dice[1], dice[2])

#include <iostream>
// #include <algorithm>

int main()
{
    using namespace std;
    
    int dice[3];
    for (int i=0; i<3; i++) 
    {
        cin >> dice[i];
    }

    if (dice[0] == dice[1] && dice[1] == dice[2]) // 같은 눈이 세 개
    {
        cout << 10000 + dice[0]*1000;
    }
    else if (dice[0] != dice[1] && dice[1] != dice[2] && dice[2] != dice[0]) // 같은 눈이 한 개
    {
        // 반복문으로 배열을 오름차순으로 정렬하는 방법 or max()도 있지만 조건문 문제이므로 조건으로 풀이
        // 아래 조건문을 max({dice[0], dice[1], dice[2]})로 축약가능
        if (dice[0] > dice[1] && dice[0] > dice[2]) // dice[0]이 제일 클 때
        {
            cout << dice[0]*100;
        }
        
        else if (dice[1] > dice[0] && dice[1] > dice[2]) // dice[1]이 제일 클 때
        {
            cout << dice[1]*100;
        }
        else // dice[2]이 제일 클 때
        {
            cout << dice[2]*100;
        }
    }
    else // 같은 눈이 두 개
    {
        // 같은 눈이 무엇인지 찾기
        if (dice[0] == dice[1]) // 0, 1 동일일 때
        {
            cout << 1000 + dice[0]*100;
        }
        else if (dice[1] == dice[2]) // 1, 2 동일일 때
        {
            cout << 1000 + dice[1]*100;
        }
        else // 0, 2 동일일 때
        {
            cout << 1000 + dice[2]*100;
        }
    }
    return 0;
}


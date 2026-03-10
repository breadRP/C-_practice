#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    queue<pair<int, int>> c; // 좌표값 저장용
    int N, M; // 공간의 크기 (각각 행과 열)

    // 미로공간 입력받기
    cin >> N >> M;
    vector<vector<int>> space(N, vector<int>(M)); // 미로 공간
    for (int i=0; i<N; i++)
    {
        string s;
        cin >> s;

        for (int j=0; j<M; j++)
        {
            space[i][j] = s[j] - '0';
        }
    }

    // 탐색하는 순서 만들기
    /*
    vector<int> dx = {1, -1, 0, 0}; // 오른쪽, 왼쪽
    vector<int> dy = {0, 0, 1, -1}; // 위쪽, 아래쪽
    */ // vector가 무거워서 사용 X
    int dx[4] = {1, -1, 0, 0}; // 오른쪽, 왼쪽
    int dy[4] = {0, 0, 1, -1}; // 위쪽, 아래쪽
    c.push({0, 0});
    while (!c.empty())
    {
        // 현재 공간 좌표 저장
        int x = c.front().first;
        int y = c.front().second;
        c.pop();

        for (int i=0; i<4; i++)
        {
            // 다음 탐색할 공간 좌표 구하기
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 만약에 배열을 벗어나거나 벽이면 버림
            if ((nx < 0 || ny < 0) || (nx >= N || ny >= M)) continue;
            // if (space[nx][ny] == 0) continue; // 아래 1만 검사하면 사실 의미가 없음

            // 갈 수 있는 길일때 처리 (1인 이유는 우리가 온 길은 거리 증가식으로 2, 3, 4...)
            if (space[nx][ny] == 1)
            {   
                space[nx][ny] = space[x][y] + 1;
                c.push({nx, ny});
            }
        }
    }

    cout << space[N-1][M-1];
}
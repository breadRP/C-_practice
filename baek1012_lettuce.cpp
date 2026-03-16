#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 테스트 케이스에 대해서 각각 처리
    int T;
    cin >> T;
    for (int i=0; i<T; i++)
    {
        int count = 0;
        int M, N, K;
        cin >> M >> N >> K;
        vector<vector<int>> pos(N, vector<int>(M, 0)); // 밭 좌표 / 일단 모든 좌표에 대해서 0으로 초기화
        vector<pair<int,int>> pos_1; // 배추 좌표 <- 탐색 초기 위치를 구하기 위함
        // 배추 있는 위치를 0 -> 1로
        for (int j=0; j<K; j++)
        {
            int pos_x, pos_y;
            cin >> pos_x >> pos_y;
            pos[pos_y][pos_x] = 1;
            pos_1.emplace_back(pos_y, pos_x);
        }
        for (int idx=0; idx<pos_1.size(); idx++) // 1인 위치 원소에 대해서 각각 실행
        {
            // 탐색준비
            queue<pair<int, int>> c; // 탐색할 좌표값 저장용
            int dx[] = {-1, 1, 0, 0}; // 왼쪽, 오른쪽
            int dy[] = {0, 0, -1, 1}; // 아래쪽, 위쪽
            // ** for문 밖에 두는게 효율적
            if (pos[pos_1[idx].first][pos_1[idx].second] == 1)
            {
                c.push(pos_1[idx]); // pos_1에서 값이 1인 좌표를 초기값으로 설정
            }
            else
            {
                continue;
            }
            while (!c.empty())
            {
                // 현재 좌표 공간 저장
                int x = c.front().second;
                int y = c.front().first;
                pos[y][x] += 1;
                c.pop();

                for (int k=0; k<4; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if ((nx < 0 || ny < 0) || (nx > M-1 || ny > N-1))
                    {
                        continue;
                    }
                    else
                    {
                        // 그 좌표로 갈 수 있는지 검사
                        if (pos[ny][nx] == 1)
                        {
                            pos[ny][nx] += 1;  // 또는 pos[ny][nx] = 0
                            c.push({ny,nx});
                        }
                    }
                }
            }
            // 한 구역에 대해서 탐색끝
            count++;
        }
        cout << count << '\n';
    }

    return 0;
}

/*
========================================
BFS + 2차원 배열 구현하면서 발생했던 문제 정리
========================================

1. 좌표 (x, y) 와 배열 [row][col] 혼동

문제 입력 좌표는 보통
    (x, y)

하지만 C++ 2차원 배열은
    array[row][col]

즉
    pos[y][x]
형태로 접근해야 한다.

----------------------------------------

2. 배열 생성 크기와 좌표 접근 불일치

배열 생성

    vector<vector<int>> pos(N, vector<int>(M));

의 의미

    pos[0 ~ N-1][0 ~ M-1]
    pos[row][col]

따라서 입력이 (x, y)라면

    pos[y][x]

로 저장해야 한다.

처음에

    pos[x][y]

로 접근해서 vector 범위를 벗어나는 오류가 발생했다.

----------------------------------------

3. queue에 잘못된 타입 push

queue 선언

    queue<pair<int,int>>

즉 큐에는 좌표 (row, col) 쌍이 들어가야 한다.

처음 코드

    c.push(pos[pos_1[idx].first][pos_1[idx].second]);

이렇게 하면 int 값을 넣는 것이므로 타입 오류가 발생한다.

올바른 코드

    c.push(pos_1[idx]);

----------------------------------------

4. emplace_back 사용 문제

초기 코드

    pos_1.emplace_back({pos_x, pos_y});

일부 컴파일러에서 initializer list 문제 발생 가능

안전한 방식

    pos_1.emplace_back(pos_x, pos_y);

----------------------------------------

5. BFS 범위 체크 조건 오류

초기 코드

    if ((nx < 0 || ny < 0) && (nx > M-1 || ny > N-1))

이 조건은 거의 항상 false가 되어
범위 밖 좌표가 필터링되지 않는다.

올바른 조건

    if (nx < 0 || ny < 0 || nx >= M || ny >= N)
        continue;

----------------------------------------

6. 방문 처리 방식

방문 처리는 두 가지 방법이 있다.

방법 1 (일반적인 방식)

    pos[ny][nx] = 0;

방법 2 (현재 코드 방식)

    pos[ny][nx] += 1;

즉

    1 = 방문 전 배추
    2 이상 = 이미 방문한 배추

이 방식도 논리적으로 문제 없음.

----------------------------------------

7. BFS 탐색 조건 필요

BFS에서는 반드시 다음 조건이 필요하다.

    if (pos[ny][nx] == 1)

그래야 배추가 있는 칸만 탐색한다.

조건이 없으면 BFS가 밭 전체로 퍼질 수 있다.

----------------------------------------

핵심 정리

BFS + 2차원 배열 문제에서는 반드시 다음 4가지를
일관되게 유지해야 한다.

1) 배열 생성 크기
2) 좌표 의미 (x, y)
3) 배열 접근 방식 pos[y][x]
4) 범위 체크 조건

이 네 가지가 맞으면 대부분의 BFS 문제는 정상 동작한다.

-------------------------------------------

개선점 : pos_1을 쓰지 않아도 현재 문제에 대해서는 전체탐색이 비용적으로 그렇게 크지 않다.
        그러므로 깔끔하게 코드를 쓰려면 전체탐색을 하는게 좋다. 그리고 왠만한 bfs문제\에서는
        실제로 전체탐색을 주로 쓴다.
*/
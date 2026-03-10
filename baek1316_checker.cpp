// 바로 이전 문자랑 다른가 + 이미 사용되었던 문자인가
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int count = 0; // 그룹단어 개수
    bool is_group = true; 
    // REVIEW: is_group은 각 단어마다 상태가 초기화되어야 하는 변수라
    // for문 안에서 선언/초기화하는 것이 더 안전한 구조

    int N; // 받을 단어 개수
    cin >> N;

    for (int i=0; i<N; i++)
    {
        string s;
        cin >> s;

        // 각 단어에 대해 그룹단어 검사 실시
        // 알파벳에 사용횟수에 대응하는 집합만들기
        int alpha[26] = {0,}; 
        // REVIEW: 알파벳 등장 여부만 필요하므로
        // 실제로는 사용횟수보다 "사용 여부" 배열로 쓰이고 있음

        if (s.size() != 1) {
        // REVIEW: 길이가 1인 경우는 자동으로 그룹 단어
        // 하지만 아래 로직에서도 자연스럽게 처리됨. 즉, 필요없는 코드

            alpha[s[0]-'a'] += 1;

            for (int j=1; j<s.size(); j++)
            {
                if (s[j] != s[j-1]) // 새로운 단어가 시작할 때
                {
                    if (alpha[s[j]-'a'] != 0)
                    {
                            is_group = false;
                            // REVIEW: 이미 사용된 문자가 다시 등장
                            // -> 그룹 단어 아님
                            // 여기서 break로 반복문 종료하면 불필요한 검사 줄일 수 있음
                    }
                    else {
                        alpha[s[j]-'a'] += 1; // 처음 등장한 문자일 때
                    }
                }
            }

            if (is_group == false)
            {
                is_group = true;
                // REVIEW: 상태 복구 로직
                // 하지만 검사 시작 전에 is_group을 초기화하면
                // 이 코드는 필요 없어짐
            }
            else
            {
                count += 1;
            }
        }
        else
        {
            count += 1;
        }
    }

    cout << count;
}
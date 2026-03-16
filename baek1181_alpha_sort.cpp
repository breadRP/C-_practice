/*
백준 1181
알파벳 소문자로 이루어진 N개의 단어가 들어오면 
아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.
*/
// 길이가 짧은 것부터
// 길이가 같으면 사전 순으로
// 단, 중복된 단어는 하나만 남기고 제거해야 한다.

// 1. 입력받을 때 cctype 이용해서 숫자제거 / set을 이용해서 중복제거
// 2. vector에 크기 1부터 정렬
#include <iostream>
#include <string>
#include <set>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

// ** 새로운 학습 **
bool cmp(const string& a, const string& b)
{
    if (a.size() == b.size()) // 사이즈가 같으면 작은게 사전순
        return a < b;
    return a.size() < b.size(); // 사이즈가 다르면 크기순
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 1.
    int N;
    cin >> N;
    set<string> s_alpha;
    for (int i=0; i<N; i++)
    {
        string s;
        cin >> s;
        bool is_alpha = true;
        for (char i : s)
        {
            if (!isalpha(i))
            {
                is_alpha = false;
            }
        }
        if (is_alpha)
        {
            s_alpha.insert(s);
        }
    }

    // 2.
    vector<string> vAlpha(s_alpha.begin(), s_alpha.end());
    sort(vAlpha.begin(), vAlpha.end(), cmp);

    for (string s : vAlpha)
    {
        cout << s << '\n';
    }
}
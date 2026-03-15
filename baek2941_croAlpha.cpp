// 앞에서 조건 세우면 c, d, l, n, s, z 6개
// 뒤에서 조건 세우면 =, -, j 3개
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int count = 0;

    string s; // 입력받을 문자열
    cin >> s;
    int n = s.size();

    // 맨뒷자리가 =, -, j로 끝난다는 것을 이용
    for (int i=0; i<n; i++)
    {
        count += 1;
        if (s[i] == '=' && i >= 1) // 뒷자리가 =인 글자 처리
        {
            if (s[i-1] == 'c' || s[i-1] == 's') count -= 1;
            else if (s[i-1] == 'z')
            {
                if (i >= 2 && s[i-2] == 'd') count -= 2;
                else count -= 1;
            }
        }
        else if (s[i] == '-' && i >= 1) // 뒷자리가 -인 글자 처리
        {
            if (s[i-1] == 'd' || s[i-1] == 'c') count -= 1;
        }
        else if (s[i] == 'j' && i >= 1) // 뒷자리가 j인 글자 처리
        {
            if (s[i-1] == 'l' || s[i-1] == 'n') count -= 1;
        }
    }

    cout << count << '\n';
}
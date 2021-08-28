#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

ll solve(string s1)
{
    ll n, m, a, l, r, b, x, y, k, c = mod, m1, m2, rr, cc;

    map<char, ll> mp;
    for (auto xx : s1)
        mp[xx]++;
    char vow = 'A', con = 'B';
    c = 0;
    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            if (mp[ch] >= mp[vow])
            {
                vow = ch;
                c++;
            }
        }
        else
        {
            if (mp[ch] >= mp[con])
                con = ch;
        }
    }
    a = b = 0;
    for (auto ch : s1)
    {
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            a += 2;
            b++;
            if (c > 0 && ch == vow)
            {
                a -= 2;
            }
        }
        else
        {
            a++;
            b += 2;
            if (s1.size() - c > 0 && ch == con)
            {
                b -= 2;
            }
        }
    }

    return min(a, b);
}
int main()
{
    // ifstream myfile("input1_1.txt");
    // ofstream ansfile("chapter1_1.txt");
    ll t = 1;
    string s1;
    cin >> t;
    for (int t0 = 1; t0 <= t; t0++)
    {
        cin >> s1;
        ll ans = solve(s1);
        cout << "Case #" << t0 << ": " << ans << "\n";
    }
    return 0;
}

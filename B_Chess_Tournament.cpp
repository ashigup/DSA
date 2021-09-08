
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
ll modpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b % 2 == 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans % mod;
}
void solve()
{
    ll n, a, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2 = "YES";
    cin >> n >> s1;
    vector<vector<char>> dp(n, vector<char>(n, 'X'));
    // -1-notDecided | 1-i-win |  2-j-win |3 draw
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '1')
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (dp[j][i] == '+')
                {
                    dp[i][j] = dp[j][i] = '=';
                }
                else
                {
                    dp[i][j] = '+';
                    dp[j][i] = '-';
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '2')
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (dp[i][j] == '+')
                {
                    break;
                }
                else if (dp[j][i] == 'X')
                {
                    dp[i][j] = '+';
                    dp[j][i] - '-';
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (dp[i][j] == 'X' && dp[j][i] == 'X')
            {
                dp[i][j] = '+';
                dp[j][i] - '-';
            }
        }
    }
    s2 = "YES";
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '1')
        {

            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (dp[i][j] == '-')
                {
                    s2 = "NO";
                    break;
                }
            }
        }
        else if (s1[i] == '2')
        {
            c = 0;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (dp[i][j] == '+')
                {
                    c++;
                    break;
                }
            }
            if (c == 0)
            {
                s2 = "NO";
                break;
            }
        }
    }
    cout << s2 << "\n";
    if (s2 == "NO")
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == 'X' && dp[j][i] == '+')
                dp[i][j] = '-';
            cout << dp[i][j];
        }
        cout << "\n";
    }
    return;
}
int main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        //cout << "\n";
    }
    return 0;
}
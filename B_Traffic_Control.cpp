#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
// #define infile cin
// #define outfile cout

vector<vector<ll>> solve(ll n, ll m, ll a, ll b, string &ans)
{
    ll x, y, k, c = mod, m1, m2, rr, cc;
    c = 0;
    x = a;
    y = b;
    ans = "Possible";
    vector<vector<ll>> cost(n, vector<ll>(m, 1000));
    if (a < n + m - 1 || b < m + n - 1)
    {
        ans = "Impossible";
        return cost;
    }
    for (int i = 0; i < n; i++)
        cost[i][m - 1] = cost[i][0] = 1;
    for (int i = 0; i < m; i++)
        cost[0][i] = cost[n - 1][i] = 1;
    a -= (n - 1 + m - 1);
    b -= (m + n - 1 - 1);
    cost[0][0] = a;
    cost[n - 1][0] = b;
    c = 0;
    for (int i = 0; i < m; i++)
        c += cost[0][i];
    for (int i = 1; i < n; i++)
        c += cost[i][m - 1];
    if (c > x)
    {
        ans = "Impossible";
        return cost;
    }
    c = 0;
    for (int i = 0; i < m; i++)
        c += cost[n - 1][i];
    for (int i = 0; i < n - 1; i++)
        c += cost[i][m - 1];
    if (c > y)
    {
        ans = "Impossible";
        return cost;
    }
    return cost;
}
int main()
{
    ifstream infile("traffic_control_input.txt");
    ofstream outfile("traffic_control_output.txt");
    ll t = 1, n, m, a, b;
    string s1;
    infile >> t;
    for (int t0 = 1; t0 <= t; t0++)
    {
        infile >> n >> m >> a >> b;
        vector<vector<ll>> cost = solve(n, m, a, b, s1);
        outfile << "Case #" << t0 << ": " << s1 << "\n";
        if (s1 == "Impossible")
            continue;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                outfile << cost[i][j] << " ";
            }
            outfile << "\n";
        }
    }
    return 0;
}

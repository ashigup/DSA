
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vch vector<char>
ll bfs(ll src, ll des, vector<vll> &egg)
{
    if (src == des)
        return 0;
    queue<ll> qq;
    qq.push(src);
    bool vis[26] = {false};
    vis[src] = 1;
    ll cost = 0;
    while (!qq.empty())
    {
        ll siz = qq.size();
        cost++;
        for (int i = 0; i < siz; i++)
        {
            ll u = qq.front();
            qq.pop();
            for (auto v : egg[u])
            {
                if (!vis[v])
                {
                    if (des == v)
                        return cost;
                    vis[v] = 1;
                    qq.push(v);
                }
            }
        }
    }
    return mod;
}
ll solve(string s1, vector<string> edges)
{
    ll n, m, a, l, r, b, x, k, y, c, d, m1, m2, rr, cc;
    //string s1, s2;
    ll freq[26];
    k = edges.size();
    for (int i = 0; i < 26; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < s1.size(); i++)
    {
        freq[s1[i] - 'A']++;
    }
    vector<vll> egg(26);
    for (int i = 0; i < k; i++)
    {
        egg[edges[i][0] - 'A'].push_back(edges[i][1] - 'A');
    }
    ll ans = INT_MAX;
    for (ll des = 0; des < 26; des++)
    {
        ll tempAns = 0;
        ll flag = 0;
        for (ll src = 0; src < 26; src++)
        {
            if (freq[src] > 0)
            {
                ll indiCost = bfs(src, des, egg);
                if (indiCost == mod)
                {
                    flag = 1;
                    break;
                }
                tempAns += (freq[src] * indiCost);
            }
        }
        if (flag == 0)
        {
            ans = min(ans, tempAns);
        }
    }
    if (ans == INT_MAX)
        ans = -1;

    return ans;
}
int main()
{
    // ifstream cin("consistency_chapter_2_input.txt");
    // ofstream cout("consistency_chapter_2_output.txt");
    ll t = 1, k;
    cin >> t;
    string s1, s2;
    for (int i = 0; i < t; i++)
    {
        cin >> s1 >> k;
        vector<string> edges(k);
        for (int i = 0; i < k; i++)
        {
            cin >> edges[i];
        }
        cout << "Case #" << i + 1 << ": ";
        cout << solve(s1, edges);
        cout << "\n";
    }
    // while (t--)
    // {
    //     solve();
    //     cout << "\n";
    // }
    return 0;
}
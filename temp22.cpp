#include <bits/stdc++.h>
using namespace std;
#define ll long long
// mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
// #define deb(...) [](const auto &...x) {            \
//     char c = '=';                                  \
//     cout << #_VA_ARGS << " ";                      \
//     ((cout << exchange(c, ',') << " " << x), ...); \
//     cout << endl;                                  \
// }(VA_ARGS_);
int main()
{
    ll n, q;
    cin >> n >> q;
    ll a[n], pre[n + 1]{};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
    }
    while (q--)
    {
        ll k, x, y;
        cin >> y >> k >> x;
        ll ans = x;
        vector<int> v;
        for (int i = 0; i <= n - y; i++)
            v.push_back(pre[i + y] - pre[i]);
        for (int i = 30; i >= 0; i--)
        {
            if (x & (1 << i))
                continue;
            vector<int> pos;
            for (auto u : v)
            {
                if (u & (1 << i))
                    pos.push_back(u);
            }
            if (pos.size() >= k)
            {
                swap(pos, v);
                ans |= 1 << i;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
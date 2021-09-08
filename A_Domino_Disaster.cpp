
#define ll long long int
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define pbds tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
// using namespace __gnu_pbds;
#define mod 1000000007
using namespace std;
#define vll vector<ll>

void solve()
{
    ll n, a, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1;
    cin >> n >> s1;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == 'D')
            s1[i] = 'U';
        else if (s1[i] == 'U')
            s1[i] = 'D';
    }
    cout << s1;
    return;
}
int main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}
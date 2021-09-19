
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
map<char, int> cpppp;
bool comp1(string &s1, string &s2)
{
    int n = min(s1.size(), s2.size());
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
            return cpppp[s1[i]] < cpppp[s2[i]];
    }
    return (s1.size() <= s2.size());
}
void solve()
{
    ll n, a, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1;
    cin >> s1 >> n;
    for (int i = 0; i < s1.size(); i++)
        cpppp[s1[i]] = i + 1;

    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), comp1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\n";
    return;
}
int main()
{
    ll t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}
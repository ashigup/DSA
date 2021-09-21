
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
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

bool comp1(vector<ll> a1, vector<ll> a2)
{
    if (a1[1] == a2[1])
        return a1[0] <= a2[0];
    return a1[1] <= a2[1];
}
ll getSum(multiset<ll> &mss, ll k)
{

    ll sum = 0;
    multiset<ll>::iterator it = mss.begin();
    for (ll i = 0; i < k; i++)
    {
        sum += (*it);
        ++it;
    }
    return sum;
}
bool fun(vll &arr, ll assumedSize, ll x, ll y)
{
    // if(assumedSize<=y) return 1;
    ll n = arr.size();
    ll k = assumedSize - y; //  number of elements whose top sum has to be compare with x
    priority_queue<ll> pq;
    ll sum = 0;
    multiset<ll> mss;
    for (int i = 0; i < assumedSize; i++)
    {
        mss.insert(arr[i]);
    }
    if (getSum(mss, k) <= x)
        return true;

    for (int i = assumedSize; i < n; i++)
    {
        mss.erase(mss.find(arr[i - assumedSize]));
        mss.insert(arr[i]);
        if (getSum(mss, k) <= x)
            return true;
    }
    return 0;
}
void solve()
{
    ll a, b, n, x, s, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n >> x >> y;
    vll arr(n);
    s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s += arr[i];
    }
    if (y >= n || s <= x)
    {
        cout << n;
        return;
    }
    ll ss = y;
    ll ee = n;
    ll ans = y;
    while (ss < ee - 1)
    {
        ll mm = ss + (ee - ss) / 2;
        if (fun(arr, mm, x, y))
        {
            ss = mm;
            ans = max(ans, mm);
        }
        else
        {
            ee = mm - 1;
        }
    }
    cout << ans;
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
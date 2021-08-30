
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
bool isAnagram(vll s1, vll s2)
{
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}
int CountSteps(vll s1, vll s2, int size)
{
    int i = 0, j = 0;
    int result = 0;
    while (i < size)
    {
        j = i;
        while (s1[j] != s2[i])
        {
            j += 1;
        }
        while (i < j)
        {
            char temp = s1[j];
            s1[j] = s1[j - 1];
            s1[j - 1] = temp;
            j -= 1;
            result += 1;
        }
        i += 1;
    }
    return result;
}
ll starter(vector<ll> &arr, ll st)
{
    vector<ll> cpps = arr;
    ll n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cpps[i] = st;
        st = 1 - st;
    }
    if (!isAnagram(arr, cpps))
    {
        return -1;
    }
    return CountSteps(arr, cpps, arr.size());
}
void solve()
{
    ll n, m, a, l, r, b, x, y, k, c, d, m1, m2, rr, cc;
    string s1;
    cin >> n;
    vll arr(n);
    c = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<ll> open;
    vector<ll> st;
    c = 0;
    a = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            open.push_back(arr[i]);
            a++;
        }
        else
        {
            if (open.size() == 0)
            {
                st.clear();
                a = 0;
            }
            else if (open.back() == arr[i])
            {
                int op = open.back();
                open.pop_back();
                c += arr[i];
                d = st.size();
                c += d;
                st.push_back(--a);
            }
            else if (open.back() > arr[i])
            {
                int op = open.back();
                open.pop_back();
                c += arr[i];
                op -= arr[i];
                d = 0;
                for (int k = st.size() - 1; k >= 0 && st[k] == a; k--)
                {
                    d++;
                    st.pop_back();
                }
                st.push_back(--a);
                if (op > 0)
                {
                    open.push_back(op);
                }
            }
            else if (open.back() < arr[i])
            {

                int op = open.back();
                open.pop_back();
                c += op;
                d = 0;
                for (int k = st.size() - 1; k >= 0 && st[k] == a; k--)
                {
                    d++;
                    st.pop_back();
                }
                c += d;
                arr[i] -= op;
                i--;
            }
        }
        cout << i << "--index--" << open.size() << "-" << st.size() << "=" << c << "\n";
    }
    cout << c;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}
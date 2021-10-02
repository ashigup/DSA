
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define pll pair<ll, ll>

vector<double> combine2(double a, double b)
{
    return {a / b, b / a, a + b, a - b, b - a, a * b};
}
double eps = 1e-5;
bool judgePoint24(vector<int> &nums)
{
    vector<int> id({3, 2, 1, 0});
    vector<double> v1, v2, v3;
    do
    {
        int a = nums[id[0]], b = nums[id[1]], c = nums[id[2]], d = nums[id[3]];
        v1 = combine2(a, b);
        for (auto x : v1)
        {
            v2 = combine2(c, d);
            for (auto y : v2)
            {
                v3 = combine2(x, y);
                for (auto z : v3)
                {
                    if (abs(z - 24) < eps)
                        return true;
                }
            }
        }
    } while (prev_permutation(id.begin(), id.end()));
    sort(id.rbegin(), id.rend());
    do
    {
        int a = nums[id[0]], b = nums[id[1]], c = nums[id[2]], d = nums[id[3]];
        v1 = combine2(a, b);
        for (auto x : v1)
        {
            v2 = combine2(c, x);
            for (auto y : v2)
            {
                v3 = combine2(d, y);
                for (auto z : v3)
                {
                    if (abs(z - 24) < eps)
                        return true;
                }
            }
        }
    } while (prev_permutation(id.begin(), id.end()));
    return false;
}
vector<int> c1;
vector<int> dp(11);
string CalculateProb(vector<int> arr)
{
    int num = 0, d = 1, dino = 0, flag;
    for (int i = 1; i <= 10; i++)
        dp[i] = 4;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            for (int k = 1; k <= 10; k++)
            {
                for (int kk = 1; kk <= 10; kk++)
                {
                    c1 = {i, j, k, kk};
                    flag = 0;
                    while (flag < arr.size())
                    {
                        if (arr[flag] != c1[flag])
                            break;
                        flag++;
                    }
                    if (flag == arr.size())
                    {
                        d = 1;
                        for (int jj = 0; jj < 4; jj++)
                        {
                            if (jj >= flag)
                                d *= dp[c1[jj]];
                            dp[c1[jj]]--;
                        }
                        for (int jj = 0; jj < 4; jj++)
                        {
                            dp[c1[jj]]++;
                        }
                        if (judgePoint24(c1))
                            num += d;
                        dino += d;
                    }
                }
            }
        }
    }
    string ans = "";
    if (0 == num || num == dino)
    {
        ans = to_string(num);
    }
    else
    {
        int f = __gcd(num, dino);
        ans = to_string(num / f) + "/" + to_string(dino / f);
    }
    return ans;
}
void solve()
{
    ll a, b, n, q, m, p, x, s, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    s1 = CalculateProb(arr);

    cout << s1;
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
        // cout << "\n";
    }
    return 0;
}
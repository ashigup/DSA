#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
const ll INF = 1e15;
#define pll pair<ll, ll>
#define vll vector<ll>
#define mod 1000000007

int main()
{
    IOS;
    ll a, b, c, d, e, f, n, m, q, t, s;
    t = 1;
    //cin>>t;
    while (t--)
    {
        cin >> n >> e;
        vector<vector<pll>> egg(n);
        for (int i = 0; i < e; i++)
        {
            cin >> a >> b >> c;
            a--;
            b--;
            egg[a].push_back({c, b});
        }
        //dijk
        vll dismn(n, INF);
        vll waysmn(n, 0);
        vll mnEmnP(n, INF);
        vll mxEmnP(n, 0);
        waysmn[0] = 1;
        dismn[0] = 0;
        mnEmnP[0] = 0;
        mxEmnP[0] = 0;
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0, 0});
        while (pq.size() > 0)
        {
            pll u = pq.top();
            pq.pop();
            ll ind = u.second;
            if (dismn[ind] < u.first)
                continue;
            for (auto v : egg[ind])
            {
                ll vx = v.second;
                ll vw = v.first;
                if (dismn[vx] > dismn[ind] + vw)
                {
                    dismn[vx] = dismn[ind] + vw;
                    waysmn[vx] = waysmn[ind];
                    mnEmnP[vx] = (mnEmnP[ind] + 1);
                    mxEmnP[vx] = (mxEmnP[ind] + 1);
                    pq.push({dismn[vx], vx});
                }
                else if (dismn[vx] == dismn[ind] + vw)
                {
                    waysmn[vx] += waysmn[ind];
                    waysmn[vx] %= mod;
                    mnEmnP[vx] = min(mnEmnP[vx], mnEmnP[ind] + 1);
                    mxEmnP[vx] = max(mxEmnP[vx], mxEmnP[ind] + 1);
                }
            }
        }

        cout << dismn[n - 1] << " " << waysmn[n - 1] << " " << mnEmnP[n - 1] << " " << mxEmnP[n - 1];
        cout << "\n";
    }
    return 0;
}
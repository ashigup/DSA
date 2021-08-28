/*
Subset queries

ASSume that you have an empty array am.
You have to process Q independent queries of three different types:

type = 0 and value = X: Insert element X to array arr
type 1 and value X: Remove the element X(it always exists) from array arr
type = 2 and value = X: Count all the subsets having the sum of elements equal to X. Since this count can be large print t mod 19-7

Task
Determine the count of subsets for each type 2 query in the gven order

Example
Assumptions
Q-4
query [0 3][0 5], [0, 8], [2 8]

Approach
Initially, arrl =/ (an empty array)
*After processing the t query, arnil 13
After processing the 2 query, arrl]=13, 5
After processing the 3 query. arfl=[3, 5, 8
In the 4 query, the total number of subsets having sum cquals 8 is 2 which means subset= 35, 18


Function description
Complete the soive function provided in the editor This function takes the following 2 parameters and returns an artay of the answe
&Represents the size of the query array
query Represents the queries

Input format
Note: This is the input format you must use to provide custom input (available above the Compile and Test button).
The first line contains a single integer Q which denotes the number of queries in the query array.
The next Q lines cotain the queries.

Output format
Print an integer array representing the answer to type 2 query mod 10 ++ 7, Each value that is printed must be space separated.

Constraints
1<Q<=7x 10^3
1<=X<=7*10^3
There is at least one query of type 2, and the aray will be non-empty.


Sample input 1
6
0 2
0 3
2 5
1 3
0 2
2 2

Sample output 1
1 2

Explanation

Approach
Initially. arrdD (an empty aroy)
After processing the 1 and 2 query, the artay is arrl 123
In the 3query. the number of subsets having a sum equal to 5 is 1, the subset is 2, 3
In the 4 query, we remove element 3 from the array, So the array 15 arl 2
In the 5t query, we introduce a new element 2 to the array, hence aril =12. 2
.in the 6h query, the umber of subsets having sum equals 21s 2, the siubsets are 2, 2

*/

#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
vll solveQueries(vpll queries)
{
    vll ans;
    ll x;
    map<ll, ll> mp;
    vll sums(7001, 0);
    for (int i = 0; i < queries.size(); i++)
    {
        switch (queries[i].first)
        {
        case 0:
            x = queries[i].second;
            for (auto xx : mp)
            {
                if (xx.first + x < 7001)
                    sums[xx.first + x] = sums[xx.first + x] + sums[xx.first];
            }
            mp[x]++;
            sums[x]++;
            break;
        case 1:
            x = queries[i].second;
            mp[x]--;
            sums[x]--;
            for (auto xx : mp)
            {
                if (xx.first - x > 0)
                    sums[xx.first - x] -= sums[xx.first];
            }

            break;
        case 2:
            x = queries[i].second;
            ans.push_back(sums[x]);
            break;
        }
        // for (int i = 0; i <= 15; i++)
        // {
        //     cout << sums[i] << " ";
        // }
        // cout << "\n";
        //cout << sums[queries[i].second];
    }

    return ans;
}
void solve()
{
    ll n, m, a, l, r, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n;
    vpll queries(n);
    for (int i = 0; i < n; i++)
        cin >> queries[i].first >> queries[i].second;
    vll ans = solveQueries(queries);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
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
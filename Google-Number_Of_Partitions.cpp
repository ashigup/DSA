/*
Number of partition
YOu are given an array of N elements. You can perform the below operation at most one time.
Operation
You can pick any element of the array and change it to O.
You are required to maximize the number of the partition of the given array such that after the partition sum of the
first subarray is equal to the sum of another subarray.
Note: In this problem, the patition of the array is defined as dividing the given array into two contiguous subarrays
Any of the two subarrays in the partition can't be empty.

Input Format:
First-line will contain the number of test cases(7)
For each test case:
The first line will contain N, denoting the size of the array.
The next line will contain N space-separated integers a. denoting the elements of the array

Output Format
For each test case print a single integer in a new line.

Constralnts:
1STS 10
1<=N<=10^5
-10^9 <=Ai <= 10^9

Sample Input 1
-1 5 0 0 5 0

Sample output 1
3

Explanation
For the above sample
Change-1 to O.
New array wil be [0, 5, 0, 0, 5, 0]
All possilble partitions:
[O,5] [0, 0, 5, 0]
[O, 5, 0] [o, 5, 0]
[o,5, 0, 0] [5, 0]
Therefore answer is 3.
*/

#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
void solve()
{
    ll n, m, a, l, r, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n;
    vll arr(n);
    ll rsum = 0, lsum = 0;
    map<ll, ll> mp1, mp2;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        rsum += arr[i];
        mp2[arr[i]]++;
    }
    mp1[arr[0]]++;
    mp2[arr[0]]--;
    lsum += arr[0];
    c = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        if (lsum == rsum)
        {
            c++;
        }
        else if (mp1[lsum - rsum] > 0 || mp1[-lsum + rsum] > 0)
        {
            c++;
        }

        else if (mp2[lsum - rsum] > 0 || mp2[-lsum + rsum] > 0)
        {
            c++;
        }

        lsum += arr[i];
        rsum -= arr[i];
        mp1[arr[i]]++;
        mp2[arr[i]]--;
    }
    cout << c;
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
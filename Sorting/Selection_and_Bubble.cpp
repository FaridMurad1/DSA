/*
8
1 4 2 6 3 8 4 9
*/

#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
// searching min value and swap first and this min value
void selection_sort(ll arr[], ll n)
{
    ll mn = 0;
    for (ll i = 0; i < n - 2; i++)
    {
        mn = i;
        for (ll j = i; j < n - 1; j++)
        {
            if (arr[j] < arr[mn])
                mn = j;
        }
        // swap(arr[mn], arr[i]);
        ll temp = arr[mn];
        arr[mn] = arr[i];
        arr[i] = temp;
    }
    for (ll i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
/*
push the max to the last by adjecnt swaps

TC: O(n^2)
*/
void bubble_sort(ll arr[], ll n)
{
    for (ll i = n - 1; i >= 0; i--)
    {
        for (ll j = 0; j < i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                ll temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (ll i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
/*
optimization code
if the array is already sorted then no need to check the array
TC: O(n)
*/
void optimization_bubble_sort(ll arr[], ll n)
{
    for (ll i = n - 1; i >= 0; i--)
    {
        ll isswap = 0;
        for (ll j = 0; j < i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                ll temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                isswap = 1;
            }
        }
        if (isswap == 0)
        {
            break;
        }
    }
    for (ll i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void solve()
{
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    selection_sort(arr, n);
    cout << nl;
    bubble_sort(arr, n);
    cout << nl;
    optimization_bubble_sort(arr, n);
}
int main()
{
    int tc = 1;
    // cin>>tc;
    for (int i = 1; i <= tc; i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}

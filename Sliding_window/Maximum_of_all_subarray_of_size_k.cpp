/*

Input:
        9 3
        2 3 7 9 5 1 6 4 3

Output:
        7 9 9 9 6 6 6

*/

#include <bits/stdc++.h>
using namespace std;
void usingPriorityQueue(vector<int> &arr, int k, int n)
{
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i < k; i++)
    {
        pq.push({arr[i], i});       // push value and position  k-1 
        //cout << arr[i] << " " << i << endl;
    }
   // cout << endl;
    for (int i = k; i <= n; i++)
    {
        pq.push({arr[i], i});
        while (pq.top().second <= i - k)    // check it between the slide or not ,if not then pop
            pq.pop();
        cout << pq.top().first << endl;      
    }
}
void UsingMultiSet(vector<int> &arr, int k, int n)
{
    multiset<int, greater<int>> st;     // according to greater wise
    for (int i = 1; i < k; i++)
    {
        st.insert(arr[i]);
    }
    for (int i = k; i <= n; i++)
    {
        st.insert(arr[i]);
        cout << *st.begin() << endl;
        st.erase(st.find(arr[i - k + 1]));    // if value is not present the slide then find this value and errase this 
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
     UsingMultiSet(arr, k, n);
    usingPriorityQueue(arr, k, n);
    return 0;
}

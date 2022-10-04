#include <bits/stdc++.h>
#define int long long 
using namespace std;
int getSum(int BITree[], int index)
{
    int sum = 0; 
    index = index + 1;
  
    while (index>0)
    {
        sum += BITree[index];
  
        index -= index & (-index);
    }
    return sum;
}
void updateBIT(int BITree[], int n, int index, int val)
{
    index = index + 1;
  
    while (index <= n)
    {
    BITree[index] += val;
  
    index += index & (-index);
    }
}
  
int *constructBITree(int arr[], int n)
{
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;
  
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
  
    return BITree;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int freq[n];
    for(int i=0;i<n;i++){
        cin>>freq[i];
    }
    int *BITree = constructBITree(freq, n);
    cout << "Sum of elements in arr[0..5] is "
        << getSum(BITree, 5);
    freq[3] += 6;
    updateBIT(BITree, n, 3, 6);
  
    cout << "\nSum of elements in arr[0..5] after update is "
        << getSum(BITree, 5);
    }
    return 0;
}
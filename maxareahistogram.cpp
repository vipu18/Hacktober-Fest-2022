#include<bits/stdc++.h>
using namespace std;
long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long> nsl;
        vector<long long>nsr;
        
        stack<long long> k;
        int j=0;
        while(j<n)
        {
            
            if(k.empty())
            {
                nsl.push_back(-1);
                k.push(j);
                j++;
            }
            else
            {
                
                if(!k.empty() && arr[j]<=arr[k.top()])
                {
                    k.pop();
                }
                else
                {
                    
                    nsl.push_back(k.top());
                    k.push(j);
                    j++;
                }
            }
        }
        // cout<<"Nearest smaller left: ";
        
        // for(int i=0;i<n;i++)
        // {
        //     cout<<nsl[i]<<" ";
        // }
        
        //cout<<"\n\n Nearest smaller right: ";
        j = n-1;
        stack<long long>st;
        while(j>=0)
        {
            if(st.empty())
            {
                nsr.push_back(n);
                st.push(j);
                j--;
            }
            else
            {
                //cout<<"Top of the stack is "<<st.top()<<endl;
                if(!st.empty() && arr[j]<=arr[st.top()])
                {
                    st.pop();
                }
                else
                {
                    nsr.push_back(st.top());
                    st.push(j);
                    j--;
                }
            }
        }
        reverse(nsr.begin(),nsr.end());
        // for(int i=0;i<n;i++)
        // {
        //     cout<<nsr[i]<<" ";
        // }
        vector<long long> width;
        //cout<<"\n\n\n";
        for(int i = 0 ; i<n;i++)
        {
            width.push_back(nsr[i] - nsl[i] - 1);
            //cout<<"Width for "<<arr[i]<<" is equal to "<<width.back()<<endl;
            
        }
        long long g=0;
        for(int i=0;i<n;i++)
        {
            long long temp = width[i] * arr[i];
            g = max(g,temp);
        }
        return g;
    }
int main(){

    long long height[] = {6,2,5,4,5,1,6};
    long long area =getMaxArea(height, 7);

    cout<<"Total area for largest rectanle possible is "<<area;
}
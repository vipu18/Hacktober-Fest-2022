#include<bits/stdc++.h>
using namespace std;
int findComplement_bitManipulation(int num) {
        unsigned int mask = ~0;
        while (num & mask) 
            mask = mask<<1;
        return ~mask & ~num;
    }
int findComplement_queue(int num) {
        queue <int> q;
        int ans = 0,count = 0;
        while(num!=0){
            q.push(num%2);
            num=num/2;
        }
        while(!q.empty()){
            ans += !q.front()*pow(2,count);
            q.pop();
            count++;
        }
        return ans;
    }
int main() {
    cout<<findComplement_bitManipulation(2)<<endl;
    cout<<findComplement_queue(2)<<endl;
return 0; 
}
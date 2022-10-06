#include <bits/stdc++.h> 
using namespace std;

class TwoStack {
    int *arr;
    int size;
    int top1;
    int top2;

public:

    // Initialize TwoStack.
    TwoStack(int s) {
        this->size=s;
        top1=-1;
        top2= s;
        arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(top2-top1>1){
            top1++;
            arr[top1]=num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if(top2-top1>1){
            top2--;
            arr[top2]=num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1>=0){
            int ans = arr[top1];
            top1--;
            return ans;
        }else{
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2<size){
            int ans = arr[top2];
            top2++;
            return ans;
        }else{
            return -1;
        }
    }
};

int main(){
//take input 
/*
3 5
1 1 3
1 2 4
1 1 5
2 1
2 2
*/
    int n, q;
    cin >> n >> q;

    TwoStack *ts = new TwoStack(n);

    while (q--) {
        int qt;
        cin >> qt;

        if (qt == 1) {
            int stack_no;
            cin >> stack_no;

            int x;
            cin >> x;

            if (stack_no == 1) {
                ts->push1(x);
            } else if (stack_no == 2) {
                ts->push2(x);
            }

        } else if (qt == 2) {
            int stack_no;
            cin >> stack_no;
            
            if (stack_no == 1) {
                cout << ts->pop1() << endl;
            } else if (stack_no == 2) {
                cout << ts->pop2() << endl;
            }
        }
    }
}
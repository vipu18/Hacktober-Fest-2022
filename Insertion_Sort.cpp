#include<iostream>
#include<vector>
using namespace std;

int main(){
    int size{};
    vector<int> arr;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter the array elements separated with space: ";
    for(int i{0}; i<size; ++i){
        int num{};
        cin >> num;
        arr.push_back(num);
    }
    for(int i{1}; i<size; ++i){
        int j{i-1};
        int flag{arr.at(i)};
        while(j >= 0 && arr.at(j) > flag){
            arr.at(j+1) = arr.at(j);
            j--;
        }
        arr.at(j+1) = flag;
    }
    cout << "Sorted array: ";
    for(int i{0}; i<size; ++i){
        cout << arr.at(i) << " ";
    }
    return 0;
}

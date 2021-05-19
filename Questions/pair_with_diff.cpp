#include<bits/stdc++.h>
using namespace std;

bool findPair(int arr[],int n,int diff){
    sort(arr,arr+n);
    int i = 0;
    int j = 1;
    while(j<n){
        if(arr[j]-arr[i] == diff)
        return true;
        else if(arr[j]-arr[i] < diff)
        j++;
        else
        i++;
    }

    return false;
}
int main(){
    int arr[] = {1,2,3,4,5};
   cout << findPair(arr,5,3);
}
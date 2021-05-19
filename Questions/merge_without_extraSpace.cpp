#include<bits/stdc++.h>
using namespace std;
//T.C of this in O(n*m) worst case is if all the elements in arr1 are greater than all the elements of arr2
void mergeWithoutSpace(int arr1[],int arr2[],int n,int m){
    int i =0;
    int j = 0;
    while(i<n){
        if(arr1[i]<=arr2[j]){
            i++;
        }else{
            int tmp = arr1[i];
            arr1[i] = arr2[j];
            int x = j;
            while(x<m-1 && arr2[x+1] < tmp){
                arr2[x] = arr2[x+1];
            }
            arr2[x] = tmp;
            i++;
        }
    }
}
int main(){
    
}
#include<bits/stdc++.h>
using namespace std;
//Swap USing selection sort T.C = O(N^2) , S.C = O(1)
int selectionSort(vector<int>& arr,int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        int tmp = i;
        for(int j=i;j<n;j++){
            if(arr[j] < arr[tmp]){
                tmp = j;
            }
        }

        if(tmp!=i){
            ans++;
            swap(arr[tmp],arr[i]);
        }
    }

    return ans;
    
}
//Using Cycle Detection method of graph T.C = O(nlogn) , S.C = O(n);
int minSwapGraph(vector<int>& arr,int n){
    vector<pair<int,int>> vec(n);
    long long int ans = 0;
    for(int i=0;i<n;i++){
        vec[i] = {arr[i],i};
    }
    sort(vec.begin(),vec.end());
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if(vis[i]){
            continue;
        }
        int x = vec[i].second;
        int cnt = 0;
        while(!vis[x]){
            vis[x] = true;
            cnt++;
            x = vec[x].second;
        }
        ans+=cnt-1;

    }
    return ans;
}
int main(){

}
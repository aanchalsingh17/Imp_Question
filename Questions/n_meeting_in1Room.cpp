//Max no of meetings we can conduct with only one room available given start ans end time of different meeting
#include<bits/stdc++.h>
using namespace std;
int maxMeeting(int start[],int end[],int n){
    vector<pair<int,int>> vec(n);
    for(int i=0;i<n;i++){
        vec[i] = {end[i],start[i]};
    }
    sort(vec.begin(),vec.end());
    int x = vec[0].first;
    int count = 0;
    for(int i=0;i<n;i++){
        if(vec[i].first > x){
            x = vec[i].first;
            count++;
        }
    }

    return count;
}
int main(){

}

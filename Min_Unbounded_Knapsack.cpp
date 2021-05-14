#include<bits/stdc++.h>
using namespace std;

int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        vector<int> length;
        vector<int> price;
        for(int i=0;i<N;i++){
            if(cost[i]!=-1){
                length.push_back(i+1);
                price.push_back(cost[i]);
            }
        }
        
        int n = length.size();
        int dp[n+1][W+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=W;j++){
                dp[i][j] = 1000000000;
            }
        }
        
        for(int i=1;i<=n;i++){
            dp[i][0] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=W;j++){
                if(length[i-1] <= j){
                    dp[i][j] = min(dp[i-1][j],dp[i][j-length[i-1]]+price[i-1]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        if(dp[n][W] == 1000000000)
         return -1;
        return dp[n][W];
  
	} 
int main(){
    int cost[] = {20,10,4,50,100};
    cout << minimumCost(cost,5,5) << "\n";
}

//Problem Statement 
//Given an array cost[] of positive integers of size N and an integer W, cost[i]
//represents the cost of ‘i’ kg packet of oranges, the task is to find the minimum 
//cost to buy W kgs of oranges. If it is not possible to buy exactly W kg oranges then the output will be -1

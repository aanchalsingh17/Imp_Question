//Gfg Question Link
//https://www.geeksforgeeks.org/optimum-location-point-minimize-total-distance/#:~:text=We%20need%20to%20find%20a,set%20of%20points%20is%20minimum.&text=In%20above%20figure%20optimum%20location,is%20minimum%20obtainable%20total%20distance.


#include<bits/stdc++.h>
using namespace std;
double distance(pair<double,double> point,double x,double y){
    return (sqrt( (x-point.first)*(x-point.first) + (y-point.second)*(y-point.second)));
}
double compute(vector<pair<double,double>>& points,vector<int>& line,double x){
    double res = 0;
    double y = -(line[0]*x+line[2])/line[1];
    for(int i=0;i<points.size();i++){
        res+=distance(points[i],x,y);
    }

    return res;
}
double optimumLocation(vector<pair<double,double>>& points,vector<int>& line){
    double left = -1000000;
    double right = 1000000;
    //To be precise till 0.000001;
    while(right -left > 1e-6){
       double mid1 = left + (right-left)/3;
       double mid2 = right - (right-left)/3;
       double dis1 = compute(points,line,mid1);
       double dis2 = compute(points,line,mid2);
       if(dis1<dis2){
           right = mid2;
       }else{
           left = mid1;
       }
    }

    return compute(points,line,(left+right)/2);
}
int main(){
    
}
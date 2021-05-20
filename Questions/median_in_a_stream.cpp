#include<bits/stdc++.h>
using namespace std;
class MedianFinder{
    priority_queue<int> minpq;
    priority_queue<int> maxpq;
    MedianFinder(){

    }

    void addNumber(int val){
        if(maxpq.empty()){
            maxpq.push(val);
            return;
        }
       
        if(maxpq.size() > minpq.size()){
           if(maxpq.top() <= val){
               minpq.push(val);
           }else{
               minpq.push(maxpq.top());
               maxpq.pop();
               maxpq.push(val);
           }
        }else{
            if(maxpq.top() >= val){
                maxpq.push(val);
            }else{
                maxpq.push(minpq.top());
                minpq.pop();
                minpq.push(val);
            }
        }
    }


    double getMedian(){
        if(minpq.empty() && maxpq.empty()){
            return 0.0;
        }

        if(maxpq.size() > minpq.size()){
            return maxpq.top();
        }

      return (double)(maxpq.top() + minpq.top())/2.0;
    }
};

int main(){

}
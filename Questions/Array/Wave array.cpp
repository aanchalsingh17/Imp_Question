// Given an array of integers A, sort the array into a wave like array and return it, In other words, arrange the elements into a sequence such that 
// a1 >= a2 <= a3 >= a4 <= a5.....


vector<int> Solution::wave(vector<int> &A) {
    vector<int> a;
    int n = A.size(),temp;
    for(int i=0; i<n;i++)
        a.push_back(A[i]);
    sort(a.begin(),a.end());
    for(int i = 0; i<n-1; i +=2){
        if(i+1==n)  break;
        temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
    }
    return a;
}

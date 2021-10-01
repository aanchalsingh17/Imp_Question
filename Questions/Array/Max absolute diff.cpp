// You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
// f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

int maxAbsDiff(vector<int> &A) {
    int n= A.size();
    int res = INT_MIN;
    int a = INT_MIN,b=INT_MAX,c=INT_MIN,d=INT_MAX;
    for(int i=0; i<n; i++){
        a = max(a,A[i] +i);
        b = min(b,A[i] +i);
        c = max(c,A[i] -i);
        d = min(d,A[i] -i);
    }
    res = max(abs(a-b), abs(c-d));
    return res;
}

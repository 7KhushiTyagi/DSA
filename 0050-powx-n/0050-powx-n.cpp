double helper(double x,int n){
    if(n==0) return 1.00;
    
    double half=helper(x,n/2);
    if(n%2==0){
        return half*half;
    }
    return x*half*half;
}


class Solution {
public:
    double myPow(double x, int n) {
        long N=n;
        if(n<0) {
        x=1/x;
        N=-N;
    }
        return helper(x,n);
    }
};
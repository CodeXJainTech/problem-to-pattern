class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1.0000;
        }
        return (n >0) ? x*pow(x,n-1) : 1.0000/x*pow(x,n+1);
    }
};
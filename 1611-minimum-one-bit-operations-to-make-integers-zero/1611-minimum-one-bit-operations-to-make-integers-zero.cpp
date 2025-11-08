class Solution {
public:
    //exhausted editorial
    int minimumOneBitOperations(int n) {
        int ans = 0;
        int k = 0;
        int i = 1;
        
        while ( i<= n) {
            if ((n & i) != 0) {
                ans = (1 << (k + 1)) - 1 - ans;
            }
            i<<= 1;
            k++;
        }
        return ans;
    }
};
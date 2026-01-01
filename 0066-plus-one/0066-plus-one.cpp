class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry = 1;
        for(int i = digits.size()-1; i>=0; i--){
            int v = digits[i]+carry;
            carry = 0;
            if(v == 10){
                carry = 1;
                v = 0;
            }
            ans.push_back(v);
        }
        if(carry == 1){
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
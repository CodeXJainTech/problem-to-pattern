class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        vector<int> a;
        for(int i: nums){
            sum += i;
            a.push_back(sum);
        }
        return a;
    }
};
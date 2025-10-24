class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> a(nums.begin(), nums.end());
        for(int i : nums){
            a.push_back(i);
        }
        return a;
    }
};
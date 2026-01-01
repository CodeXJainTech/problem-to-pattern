class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> mp;
        for(int i : bills){
            if(i == 5){
                mp[5]++;
            }
            else{
                if(mp[5] == 0){
                    return false;
                }
                mp[5]--;
                if(i == 10){
                    mp[10]++;
                }
                else{
                    if(mp[10] > 0){
                        mp[10]--;
                    }
                    else if(mp[5]>=2){
                        mp[5]-=2;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
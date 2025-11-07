#define ull long long
class Solution {
public:
    bool helper(vector<ull> v, ull k, ull x, ull m){
        ull n = v.size();
        vector<ull> a(n,0);
        ull extra = 0;
        for(int i =0; i<n; i++){
            extra += a[i];
            if(v[i]+extra <= m){
                ull much = m-v[i]-extra;
                if(much > k){
                    return false;
                }
                k-=much;
                extra += much;
                if(i+x*2+1 <= n-1){
                    a[i+x*2+1] = -much;
                }
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int x, int k) {
        vector<ull> pre(stations.begin(), stations.end());
        ull n = stations.size();
        for(int i = 1; i<n; i++){
            pre[i] += pre[i-1];
        }
        vector<ull> a(n,0);
        for(int i =0; i<n; i++){
            ull l = 0,r = pre[n-1];
            if(i-x-1 >= 0){
                l = pre[i-x-1];
            }
            if(i+x <= n-1){
                r = pre[i+x];
            }
            a[i] = r-l;
        }

        ull l = 0, r = accumulate(stations.begin(), stations.end(), 0ull) + k;
        ull ans = 0;
        while(l <= r){
            ull mid = l+(r-l)/2;
            // cout << mid << endl;
            if(helper(a,k,x,mid)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};
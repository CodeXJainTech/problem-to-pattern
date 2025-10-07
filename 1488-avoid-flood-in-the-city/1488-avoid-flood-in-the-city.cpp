class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> mp;
        set<int> st;
        int n = rains.size();
        vector<int> ans(n, 1);

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                if (!mp.empty())
                    st.insert(i);
                continue;
            }

            if (mp.find(rains[i]) == mp.end()) {
                mp[rains[i]] = i;
                ans[i] = -1;
                continue;
            }

            if (st.empty()) return {};

            auto it = st.begin();
            while (it != st.end() && *it < mp[rains[i]]) ++it;

            if (it == st.end()) return {};

            ans[*it] = rains[i];
            ans[i] = -1;
            mp[rains[i]] = i;
            st.erase(it);
        }

        return ans;
    }
};

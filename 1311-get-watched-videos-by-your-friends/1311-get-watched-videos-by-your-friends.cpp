class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                          vector<vector<int>>& friends,
                                          int id,
                                          int level) {

        int n = friends.size();

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(id);
        vis[id] = true;

        int currLevel = 0;

        while (!q.empty() && currLevel < level) {
            int sz = q.size();

            while (sz--) {
                int person = q.front();
                q.pop();

                for (int fr : friends[person]) {
                    if (!vis[fr]) {
                        vis[fr] = true;
                        q.push(fr);
                    }
                }
            }

            currLevel++;
        }

        unordered_map<string, int> freq;

        while (!q.empty()) {
            int person = q.front();
            q.pop();

            for (string &video : watchedVideos[person])
                freq[video]++;
        }

        vector<pair<string, int>> arr;

        for (auto &it : freq)
            arr.push_back(it);

        sort(arr.begin(), arr.end(),
             [](auto &a, auto &b) {
                 if (a.second == b.second)
                     return a.first < b.first;
                 return a.second < b.second;
             });

        vector<string> ans;

        for (auto &it : arr)
            ans.push_back(it.first);

        return ans;
    }
};
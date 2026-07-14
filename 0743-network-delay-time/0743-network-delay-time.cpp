class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times,
                         int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &it : times){

            int u=it[0];
            int v=it[1];
            int t=it[2];

            adj[u].push_back({v,t});
        }

        vector<int> dist(n+1,INT_MAX);

        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        > pq;

        pq.push({0,k});
        dist[k]=0;

        while(!pq.empty()){

            auto top=pq.top();
            pq.pop();

            int wgt=top.first;
            int node=top.second;

            if(wgt > dist[node])
                continue;

            for(auto &it : adj[node]){

                int nbr=it.first;
                int time=it.second;

                if(wgt+time < dist[nbr]){

                    dist[nbr]=wgt+time;

                    pq.push({dist[nbr],nbr});
                }
            }
        }

        int ans=INT_MIN;

        for(int i=1;i<=n;i++){

            if(dist[i]==INT_MAX)
                return -1;

            ans=max(ans,dist[i]);
        }

        return ans;
    }
};
class Solution {
public:
    double maxProbability(int n,
                          vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start_node,
                          int end_node) {

        vector<vector<pair<int,double>>> adj(n);

        for(int i=0;i<edges.size();i++) {
            int u=edges[i][0];
            int v=edges[i][1];
            double p=succProb[i];

            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }

        vector<double> prob(n,0.0);

        priority_queue<pair<double,int>> pq;

        pq.push({1.0,start_node});
        prob[start_node]=1.0;

        while(!pq.empty()) {

            auto curr=pq.top();
            pq.pop();

            double pro=curr.first;
            int node=curr.second;

            if(pro<prob[node])
                continue;

            for(auto &it:adj[node]) {

                int nbr=it.first;
                double edgeProb=it.second;

                if(pro*edgeProb > prob[nbr]) {

                    prob[nbr]=pro*edgeProb;

                    pq.push({prob[nbr],nbr});
                }
            }
        }

        return prob[end_node];
    }
};
class Solution {
public:
    double findvalue(string src, string dst,
                 unordered_map<string, vector<pair<string,double>>> &graph,
                 unordered_set<string> &vis) {

    if (src == dst)
        return 1.0;

    vis.insert(src);

    for (auto it : graph[src]) {
        string nbr = it.first;
        double wt = it.second;

        if (!vis.count(nbr)) {
            double ans = findvalue(nbr, dst, graph, vis);

            if (ans != -1.0)
                return wt * ans;
        }
    }

    return -1.0;
}
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        unordered_map<string,vector<pair<string,double>>>graph;
        int i=0;
        for(auto it: equations){
            string src=it[0];
            string dst=it[1];
            double val=values[i++];
            graph[src].push_back({dst,val});
            graph[dst].push_back({src,1/val});
        }
        vector<double> ans;
        for(auto it:queries){
            string src=it[0];
            string dst=it[1];
           unordered_set<string> vis;

          if (!graph.count(src) || !graph.count(dst))
                 ans.push_back(-1.0);
          else
             ans.push_back(findvalue(src, dst, graph, vis));
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
         vector<int> ans(n);
         if(n==0) return ans;
        vector<pair<int,int>>list;
        for(int i=0;i<n;i++){
            list.push_back({arr[i],i});
        }
        sort(list.begin(),list.end());
        int rank=1;
        for(int i=0;i<n-1;i++){
           auto p=list[i];
           int ele=p.first;
           int idx=p.second;
           ans[idx]=rank;
           if(list[i].first==list[i+1].first)
               rank--;
           rank++;

        }
        ans[list[n-1].second]=rank;
        return ans;
    }
};
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str="123456789";
        string st1=to_string(low);
        string st2=to_string(high);
        int l1=st1.length();
        int l2=st2.length();
        vector<int>ans;
        int k=l1;
        while(k<=l2){
            for(int i=0;i<10-k;i++){
              string sub=str.substr(i,k);
              int num=stoi(sub);
              if(num>=low && num<=high){
                ans.push_back(num);
              }
            }
            k++;
        }
        return ans;
    }
};
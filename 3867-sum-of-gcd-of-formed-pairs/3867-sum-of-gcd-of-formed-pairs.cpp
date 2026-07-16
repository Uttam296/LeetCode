class Solution {
public:
    int gcd(int a, int b){
        if(b==0)
          return a;
        else
          return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        vector<int>prefixgcd(n);
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
           prefixgcd[i]=gcd(nums[i],maxi);
        }
        sort(prefixgcd.begin(),prefixgcd.end());
        int i=0;
        int j=n-1;
        long long sum=0;
        while(i<j){
         int ele=gcd(prefixgcd[i],prefixgcd[j]);
         sum +=ele;
         i++;
         j--;
        }
        return sum;   
    }
};
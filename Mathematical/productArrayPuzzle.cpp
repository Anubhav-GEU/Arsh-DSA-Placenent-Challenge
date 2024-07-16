class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here    
        if (n == 1) return {1};
        vector<long long int> suffix(n);
        suffix[n-1] = nums[n-1];
        for (int i=n-2; i>=0; i--) {
            suffix[i] = (nums[i]*suffix[i+1]);
        }
        long long int currProd = 1;
        for (int i=0; i<n; i++) {
            long long int temp=nums[i];
            if (i==0) nums[i] = suffix[i+1];
            else if (i==n-1) nums[i] = currProd;
            else nums[i] = currProd*suffix[i+1];
            currProd*=temp;
        }
        return nums;
    }
};

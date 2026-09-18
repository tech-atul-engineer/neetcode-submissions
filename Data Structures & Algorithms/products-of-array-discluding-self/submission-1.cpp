class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return nums;
        vector<int> ans(n);
        if(n == 2){
            ans[1] = nums[0];
            ans[0] = nums[1];
            return ans;
        }
        vector<int> sample(n);
        sample[0] = nums[0];
        for(int i=1;i<n-1;i++){
            sample[i] = nums[i]*sample[i-1];
        }
        sample[n-1] = nums[n-1];
        ans[n-1] = sample[n-2];
        for(int j=n-2;j>=0;j--){
            if(j == n-2) ans[j] = nums[j+1]*sample[j-1];
            else{
                nums[j+1] = nums[j+1]*nums[j+2];
                if(j!=0) ans[j] = sample[j-1]*nums[j+1];
                else ans[j] = nums[j+1];
            }
        }
        return ans;
    }
};

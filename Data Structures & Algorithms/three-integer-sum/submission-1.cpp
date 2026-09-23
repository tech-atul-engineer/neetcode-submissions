class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n < 2 or nums[n-1] < 0 or nums[0] > 0) return ans;
        for(int i=0;i<n-2;i++){
            if(nums[i]<=0){
                if(i!=0 && nums[i] == nums[i-1]) continue;
                int k = i+1, j = n-1;
                while(k<j){
                    while(k<j && nums[k] + nums[i] + nums[j] > 0){
                        j--;
                    }
                    while(k<j && nums[k] + nums[i] + nums[j] < 0){
                        k++;
                    }
                    while(k<j && nums[k] + nums[i] + nums[j] == 0){
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[k]);
                        tmp.push_back(nums[j]);
                        ans.push_back(tmp);
                        int k_1 = k,j_1 = j;
                        k++;j--;
                        while(k < j && nums[k_1] == nums[k]) k++;
                        while(k < j && nums[j_1] == nums[j]) j--;
                    }
                }
            }
        }
        return ans;
    }
};

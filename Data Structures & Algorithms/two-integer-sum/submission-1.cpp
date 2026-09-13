class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> numInd;
        vector<int> ans;
        for(int i=0;i<nums.size();i++) numInd[nums[i]].push_back(i);
        for(int i=0;i<nums.size();i++){
            int val = target - nums[i];
            if(numInd.contains(val)){
                for(int j=0;j<numInd[val].size();j++){
                    if(i != numInd[val][j]){
                        ans.push_back(i);
                        ans.push_back(numInd[val][j]);
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};

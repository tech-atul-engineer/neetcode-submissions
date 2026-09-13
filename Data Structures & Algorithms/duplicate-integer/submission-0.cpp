class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> check;
        for(int i =0;i<nums.size(); i++){
            if(check[nums[i]]) return true;
            check[nums[i]] = true;
        }
        return false;
    }
};
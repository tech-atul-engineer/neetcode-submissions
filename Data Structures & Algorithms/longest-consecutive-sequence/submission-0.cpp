class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> tmp(nums.begin(), nums.end());
        for(int num: tmp){
            if(tmp.find(num-1) == tmp.end()){
                int len = 1;
                while(tmp.find(num+len) != tmp.end()){
                    len++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};

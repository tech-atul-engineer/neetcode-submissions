class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]+=1;
        }
        map<int,vector<int>> mp2;
        for(const auto&[key,value] : mp){
            mp2[value].push_back(key);
        }
        for(auto i = mp2.rbegin();i!=mp2.rend();i++){
            int key = i->first;
            vector<int> value = i->second;
            while(k>0 && value.size() > 0){
                ans.push_back(value.back());
                value.pop_back();
                k--;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for(const auto& s:strs){
            vector<int> count(26,0);
            for(char c: s){
                count[c-'a']++;
            }
            string k = to_string(count[0]);
            for(int i=1;i<26;i++){
                k += ',' + to_string(count[i]); 
            }
            mp[k].push_back(s);
        }
        for(const auto& pair : mp){
            ans.push_back(pair.second);
        }
        return ans;
    }
};

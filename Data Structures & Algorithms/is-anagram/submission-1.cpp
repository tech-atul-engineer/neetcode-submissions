class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> checkAnagram;
        for(int i=0;i<s.length();i++){
            checkAnagram[s[i]] += 1; 
            checkAnagram[t[i]] -= 1; 
        }
        for (const auto& [key, value] : checkAnagram) {
            if (value!=0) return false;
        }
        return true;
    }
};

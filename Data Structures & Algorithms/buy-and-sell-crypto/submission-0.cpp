class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        if(prices.size() < 2) return ans;
        int minLeft=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i] > minLeft){
                ans = max(ans, prices[i]-minLeft);
            }else{
                minLeft = prices[i];
            }
        }
        return ans;
    }
};

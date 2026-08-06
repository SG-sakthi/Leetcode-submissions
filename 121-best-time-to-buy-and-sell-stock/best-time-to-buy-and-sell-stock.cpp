class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy =INT_MAX;
        int sell = 0;

        for(int i =0; i<prices.size();i++){
            buy = min(buy, prices[i]);
            int profit = prices[i] - buy;
            sell = max(sell, profit);
        }
        return sell;
    }
};
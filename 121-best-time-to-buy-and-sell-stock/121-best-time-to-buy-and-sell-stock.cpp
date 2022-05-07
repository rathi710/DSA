class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int mini=INT_MAX;
        int profit=0;
        for(int i=0;i<prices.size();i++){
            mini=min(mini,prices[i]);
            profit=max(profit,prices[i]-mini);
             
        }
        return profit;
    }
};

// EXPLANATION:
//   1. Find minimum price
//   2. Caclculate profit between minimum price and next prices
//   3. But store only maximum profit
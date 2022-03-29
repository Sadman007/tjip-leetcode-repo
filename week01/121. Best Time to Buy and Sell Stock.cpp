// T - O(n), M - O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> aux(len+1);
        aux[len-1] = prices[len-1];
        for(int i=len-2;i>=0;i--){
            aux[i]=max(prices[i],aux[i+1]);
        }
        int maxElement = INT_MIN;
        for(int i=0;i<len;i++){
            maxElement = max(maxElement,aux[i]-prices[i]);
        }
        return maxElement;
    }
};
/**....................................................................**/

// T - O(n), M - O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int maxValue = prices[len-1];
        int maxProfit = maxValue-prices[len-1];
        for(int i=len-2;i>=0;i--){
            maxValue = max(prices[i],maxValue);
            maxProfit = max(maxProfit,maxValue-prices[i]);
        }
        return maxProfit;
    }
};
/**....................................................................**/

// T - O(n), M - O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int maxValue = prices[0];
        int maxProfit = prices[0]-maxValue;
        for(int i=1;i<len;i++){
            maxValue = min(prices[i],maxValue);
            maxProfit = max(maxProfit,prices[i]-maxValue);
        }
        return maxProfit;
    }
};

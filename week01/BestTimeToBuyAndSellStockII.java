public int maxProfit(int[] prices) {
        int totalProfit = 0;
        
        for(int i = 0; i < prices.length -1; i++)
            if(prices[i] < prices[i+1]) totalProfit = totalProfit + (prices[i+1] - prices[i]);
        
        return totalProfit;
    }

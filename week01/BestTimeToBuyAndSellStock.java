public int maxProfit(int[] prices) {
        int maximumProfit = 0;
        int buyingValue = Integer.MAX_VALUE;
        int potentialProfit = 0;
        
        for(int i = 0; i<prices.length; i++){
            
            if(prices[i] < buyingValue) buyingValue = prices[i];
            
            potentialProfit = prices[i] - buyingValue;
            
            if(maximumProfit < potentialProfit) maximumProfit = potentialProfit;
        }
        
        return maximumProfit;
    }

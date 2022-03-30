Solution:

class Solution {
    public int maxProfit(int[] prices) {
        // int maxiumProfit = prices[prices.length -1];        
        int maxiumProfit = 0;

        int buyPrice = prices[0]; 
        int todaysProfit = 0;
        
        for(int i = 0; i<prices.length -1; ++ i){
            if(buyPrice > prices[i+1] ) {
                buyPrice = (buyPrice > prices[i+1]) ?  prices[i+1] : buyPrice;
            }else{
                maxiumProfit =  maxiumProfit < prices[i+1] ?
                    prices[i+1] : maxiumProfit;
            }
        }
        
//          for(int i = 0; i<prices.length && k<prices.length ; ++ i){
//             if(prices[i] > prices[k]) {
//                 maxiumProfit = k;
//             }
//         }
        System.out.println(maxiumProfit);       
        System.out.println(buyPrice);

        return maxiumProfit > buyPrice ? maxiumProfit - buyPrice : 0;
    }
}
***Learning
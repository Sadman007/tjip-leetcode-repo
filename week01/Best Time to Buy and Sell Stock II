class Solution {
public:
    int maxProfit(vector<int>& prices) {
int minPriceForNow=INT_MAX, maxPriceSoFar=0;
int totalProfit=0;
bool foundBreakPoint=false;

for(int i=1;i<prices.size();i++)
{
	if(prices[i]>prices[i-1]){
		minPriceForNow= min(minPriceForNow, prices[i-1]);
		maxPriceSoFar= max(maxPriceSoFar, prices[i]);
		foundBreakPoint=true;    	
}else{
        	if(foundBreakPoint){
		totalProfit+= (maxPriceSoFar-minPriceForNow);
		minPriceForNow= prices[i];
		maxPriceSoFar= prices[i];            
        	}

}

}   
if(foundBreakPoint)
        		totalProfit+= (maxPriceSoFar-minPriceForNow);
return totalProfit;
    }
};



/* Solution
	Finding the lowest price of the sock so far
	Maximizing the profit by retracting the lowest value from the cur price and update the profit if the condition is fulfilled
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
	int mn=INT_MAX;
	int mx=0;
    for(int price : prices){
		if(price < mn) {
			mn=price;
        }	
        if(price - mn > mx){
            mx=price-mn;
        }
    }
    return mx;    
    }
};


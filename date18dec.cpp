//1475. Final Prices With a Special Discount in a Shop

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        int n=prices.size();
        vector<int>result(n);
       
        for(int i=0;i<n;i++){

            result[i]=prices[i];
            int j=i+1;

            while(j<n){
                if(prices[i]>=prices[j]){
                    result[i]= prices[i]-prices[j];
                    break;
                }
                j++;
            }
        }
        return result;
    }
};

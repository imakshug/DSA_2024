//  Water Bottles

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drink=numBottles;
        while(numBottles>0){
            int temp = numBottles;
            numBottles = numBottles/numExchange;
            drink+=numBottles;
            if(temp%numExchange && numBottles)
                numBottles+=temp%numExchange;
        }
        return drink;
    }
};

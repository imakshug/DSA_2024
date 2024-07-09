// Average waiting time

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cust) {
        double ans=0;
        int time=cust[0][0];
        for(int i=0;i<cust.size();i++){
            auto& it = cust[i];
            if(time>=it[0]){
                time+=it[1];
                ans+=(time-it[0]);
            }
            else{
                time++;
                i--;
            }
        }
        double res = ans/(double)cust.size();
        return res;
    }
};

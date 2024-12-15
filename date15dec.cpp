// maximum average pass ratio 

typedef pair<int,int> pr;
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int k) {
        auto compare=[](pr& a,pr& b){
            double temp1=(double)a.first/a.second;
            double temp2=(double)(a.first+1)/(a.second+1);
            double temp3=(double)b.first/b.second;
            double temp4=(double)(b.first+1)/(b.second+1);
            return temp2-temp1 <temp4-temp3;
        };
        priority_queue<pr,vector<pr>,decltype(compare)>heap(compare);
        double res=0;
        for(auto& vec:classes){
            heap.push({vec[0],vec[1]});
        }
        while(k--){
            auto [a,b]=heap.top();
            heap.pop();
            heap.push({a+1,b+1});
        }
        while(!heap.empty()){
            auto [a,b]=heap.top();
            res+= (double)a/b;
            heap.pop();
        }
        cout<<res;
        return (double)res/classes.size();
    }
};

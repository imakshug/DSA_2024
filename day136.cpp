// Crawler log folder

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<strings>s;
        for (auto it: logs){
            if(it=="./")continue;
            else if (it=="../"){
                if (!s.empty())s.pop();

            } 
            else s.push(it);

   
        }
        return s.size();
        
    }
};

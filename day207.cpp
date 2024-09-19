//241. Different Ways to Add Parentheses

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {

        return dfs(expression);

        
    }


private:
    bool isNumber(const string& s){
        for(char c:s){
            if(!isdigit(c)) return false;
        }
        return true;
    }

    unordered_map<string, vector<int>> memo;

    vector<int> dfs(const string& exp){
        vector<int> result;

        if(memo.count(exp)) return memo[exp];

        if(isNumber(exp)){
            result.push_back(stoi(exp));
            return result;
        }

        int n =exp.size();

        for(int i=0; i<n; i++){
            char c =exp[i];

            if(c =='+' || c=='-' || c=='*'){
                vector<int> leftResult =dfs(exp.substr(0,i));
                vector<int> rightResult =dfs(exp.substr(i+1));

                for(int left :leftResult){
                    for(int right: rightResult){
                        if(c=='+')result.push_back(left+right);
                        else if(c=='-') result.push_back(left-right);
                        else result.push_back(left*right);
                    }
                }

                
            }
        }
        memo[exp] =result;
        return result;




    }
};

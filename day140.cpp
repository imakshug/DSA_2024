// Number of atoms

class Solution {
public:
    string formula;
    bool isUpperCase(char c) {
        return (c>='A' && c<='Z');
    }
    bool isLowerCase(char c) {
        return (c>='a' && c<='z');
    }
    bool isDigit(char c) {
        return (c>='0' && c<='9');
    }
    map<string, int> solve(int& idx) {
        map<string, int> hm;
        while (idx < formula.length() && formula[idx]!=')') {
            if (isUpperCase(formula[idx])) {
                string element = "";
                element += formula[idx]; idx++;
                int count = 0;
                while (idx < formula.length() && isLowerCase(formula[idx])) {
                    element += formula[idx]; idx++;
                }
                while (idx < formula.length() && isDigit(formula[idx])) {
                    count = count*10 + (formula[idx]-'0');
                    idx++;
                }
                hm[element] += max(1,count);
            } else if (formula[idx] == '(') {
                idx++;
                map<string,int> subRes = solve(idx);
                idx++;
                int count = 0;
                while (idx < formula.length() && isDigit(formula[idx])) {
                    count = count*10 + (formula[idx]-'0'); idx++;
                }
                for(auto& pair : subRes) {
                    hm[pair.first] += max(1,count)*pair.second;
                }
            }
        }
        // for(auto& pair : hm) {
        //     cout<<"{"<<pair.first<<", "<<pair.second<<"} ";
        // }cout<<endl;
        return hm;
    }
    string countOfAtoms(string formula_) {
        formula = formula_;
        int i = 0;
        map<string, int> hm = solve(i);
        string res;
        for (auto& pair : hm) {
            res += pair.first;
            if (pair.second>1) res += to_string(pair.second);
        }
        return res;
    }
};

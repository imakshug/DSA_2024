// 624. Maximum Distance in Arrays

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minele = INT_MAX;
        int maxele = INT_MIN;
        int minind = -1;
        int maxind = -1;
        for(int i=0; i<arrays.size(); i++){
            if(arrays[i][0] < minele){
                minele = arrays[i][0];
                minind = i;
            }
            int n = arrays[i].size();
            if(arrays[i][n-1] > maxele){
                maxele = arrays[i][n-1];
                maxind = i;
            }
        }

        if(minind != maxind)
            return maxele - minele;
        else{
            int secmaxele=INT_MIN, secminele = INT_MAX;
            int secminind = -1, secmaxind = -1;
            for(int i=0; i<arrays.size(); i++){
                if(arrays[i][0]<secminele && minind != i){
                    secminele = arrays[i][0];
                    secminind = i;
                }
                int n = arrays[i].size();
                if(arrays[i][n-1] >secmaxele && maxind != i){
                    secmaxele = arrays[i][n-1];
                    secmaxind = i;
                }
            }
            return max(secmaxele-minele, maxele - secminele);
        }
        return 0;
    }
    
};

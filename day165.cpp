// spiral matrix iii

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rSt, int cSt) {
         vector<vector<int>> dir = {{0,1} , {1,0}, {0,-1}, {-1,0}};
                                  // east,  south,  west,  north
            vector<vector<int>> res;
            int steps = 0, d=0; //start with east dir
            
            res.push_back({rSt, cSt}); //initial corrdinates

            while(res.size() < rows*cols){
            if(d== 0 || d==2) steps++;  //d==0 -> east, d==2 -> west
            //we obs from Q that each time we move to east or west steps inceeases by 1

            for(int i=0; i<steps; i++){
                //d means which direction
                rSt += dir[d][0];
                cSt += dir[d][1];
                if(rSt >= 0 && rSt< rows && cSt>=0 && cSt < cols){ //lies in range
                     res.push_back({rSt, cSt}); //the coordinates
                }
            }
                d = (d+1)%4; //change direction
       }
        return res;
    }
};

// sliding puzzle

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>>req={{1,2,3},{4,5,0}};
        queue<pair<vector<vector<int>>,int>>q;
        q.push({board,0});
        string s="";
        for(int i=0; i<2; i++)
            for(int j=0; j<3; j++) s+=board[i][j];
        unordered_set<string>vis;
        int drow[]={-1,0,1,0},dcol[]={0,1,0,-1};
        vis.insert(s);
        while(q.empty()==false){
            vector<vector<int>>curr=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(curr==req) return steps;
            for(int i=0; i<2; i++){
                for(int j=0; j<3; j++){
                    if(curr[i][j]==0){
                        for(int k=0; k<4; k++){
                            int nrow=i+drow[k],ncol=j+dcol[k];
                            if(nrow>=0 && nrow<2 && ncol>=0 && ncol<3){
                                string cur="";
                                swap(curr[i][j],curr[nrow][ncol]);
                                for(int a=0; a<2; a++){
                                    for(int b=0; b<3; b++) cur+=curr[a][b];
                                }
                                if(vis.find(cur)==vis.end()){
                                    q.push({curr,steps+1});
                                    vis.insert(cur);
                                }
                                swap(curr[i][j],curr[nrow][ncol]);
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};

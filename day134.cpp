// 1823. Find the Winner of the Circular Game

class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n==1) return 1;
        if (k==1) return n;// special case

        queue<int> q;

        for(int i=1; i<=n; i++){
            //if (i%k==0) continue;
            q.push(i);
        }
        while( q.size() >1){
            for(int i=1;i < k;++i){ 
                q.push(q.front());
                q.pop();
            }
            q.pop();    
        }

    return q.front();
    }
};

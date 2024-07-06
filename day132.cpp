//  ass the Pillow

class Solution {
public:
    int passThePillow(int n, int time) {
        if(time <= n-1)return time + 1;
        n = n-1;
        int cnt = 0;
        while(time > n){
            time -= n;
            cnt++;
        }
        if(cnt % 2 == 0){
           return 1 + time;
        }
        return n - time + 1;
    }
};

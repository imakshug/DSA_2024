//1405. Longest Happy String

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
     string ans="";
     int limit_a=min(2,a),limit_b=min(b,2),limit_c=min(2,c);
     while(limit_a || limit_b || limit_c){
        int mx=max({limit_a,limit_b,limit_c});
        priority_queue<pair<int,char>>pq;
        char i;
        if(mx==limit_a)pq.push({a,'a'});
        if(mx==limit_b)pq.push({b,'b'});
        if(mx==limit_c)pq.push({c,'c'});
        i=pq.top().second;
        if(i=='a'){
            ans+='a';
            limit_a--;
            limit_b=min(b,2),limit_c=min(2,c);
            a--;
            if(a>b+c && limit_a){ans+='a';limit_a--;a--;}//push the limit to 0 if we know element is going 
            //to be wasted
        }
        else if(i=='b'){
            ans+='b';
            limit_b--;
            limit_a=min(a,2),limit_c=min(2,c);
            b--;
            if(b>a+c && limit_b){ans+='b';limit_b--;b--;}
        }
        else{
            ans+='c';
            limit_c--;
            limit_a=min(a,2),limit_b=min(2,b);
            c--;
            if(c>b+a && limit_c){ans+='c';limit_c--;c--;}
        }
     }
     return ans;
    }
};

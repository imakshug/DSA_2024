// 2406. Divide Intervals Into Minimum Number of Groups

class Solution {
public:
typedef pair<int,int> pt;
typedef pair<pt,int> ptt;

    bool checkOverlap(pt& a,vector<int>& b)
    {
        return (max(a.first,b[0])<=min(a.second,b[1]));
    }
    pt findOverLap(pt& a,vector<int>& b)
    {
        return {max(a.first,b[0]),min(a.second,b[1])};
    }
    int minGroups(vector<vector<int>>& itl) {
        int n=itl.size();
        sort(itl.begin(),itl.end());
        priority_queue<ptt,vector<ptt>,greater<ptt>>pq;

        pq.push({{itl[0][0],itl[0][1]},1});
        int res=0;
        for(int i=1;i<n;i++)
        {
            //2 possibilities the ith interval would be overlapping or not
            //if overlapping thenupdate the count
            // if not pop the previous interval store its value(how manhy times it overlapped)
            //and push the new interval
            ptt topV=pq.top();
            pq.pop();
            if(checkOverlap(topV.first,itl[i]))
            {
                pt overLap=findOverLap(topV.first,itl[i]);
                pq.push({overLap,topV.second+1});
                res=max(res,pq.top().second);
            }
            else 
            {
                res=max(res,topV.second);
                pq.push({{itl[i][0],itl[i][1]},1});
            }
        }
        return res;
    }
};

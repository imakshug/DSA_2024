//1942. The Number of the Smallest Unoccupied Chair
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size() ;
        map<int,int>m;
        vector<pair<pair<int,int> , int>>v ;
        for(int i=0 ; i<n ; i++){
            v.push_back({{times[i][0] , times[i][1]} , i});
        }
        sort(v.begin() , v.end());
        priority_queue<pair<pair<int,int> , int>, vector<pair<pair<int,int> , int>>, greater<pair<pair<int,int> , int>>>pq ;
        priority_queue<int, vector<int>, greater<int>>seats;

        for(int i=0 ; i<n ; i++){
            seats.push(i);
        }

        pair<pair<int , int> , int> pre = v[0] ;

        for(int i=0 ; i<n ; i++){

            while(!pq.empty() && pq.top().first.first <= v[i].first.first){
                seats.push(pq.top().second);
                pq.pop();
            }
            
            m[v[i].second] = seats.top();
            pq.push({{v[i].first.second , v[i].first.first} , seats.top()});
            seats.pop();
        }

        return m[targetFriend] ;
    }
};

//2054. Two Best Non-Overlapping Events

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        stack<vector<int>> st;
        int n = events.size(), currMA;
        int ans = 0;
        // using stack to implement upper bound for start time
        //i.e. for time >= t what is the max v we can use
        for(int i= n-1; i>=0; i--){
            auto event = events[i];
            if(st.empty() || event[2] > st.top()[1]){
                st.push({event[0], event[2]});
            }
            ans = max(ans, event[2]);
        }

        auto comparator = [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; 
        };
        // sorting according to ending time
        sort(events.begin(), events.end(), comparator);
        for(auto event : events){
            // remove the stack event which started before event started 
            while(!st.empty() && st.top()[0] <= event[1]){
                st.pop();
            }
            if(!st.empty())
                ans = max(ans, st.top()[1] + event[2]);
        }
        return ans;
    }
};

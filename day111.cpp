// ipo

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        // Priority queue to store the maximum profits available with current capital
        priority_queue<int> pq;

        // Vector to store pairs of (capital required, profit) for each project
        vector<pair<int, int>> projects;

        // Populate the projects vector
        for(int i = 0; i < n; i++) 
            projects.push_back({capital[i], profits[i]});

        // Sort the projects based on the capital required in ascending order
        sort(projects.begin(), projects.end());

        int i = 0;

        // Perform at most k selections
        while(k--) {
            // Add all projects that can be started with the current capital to the priority queue
            while(i < n && projects[i].first <= w) {
                pq.push(projects[i].second);
                i++;
            }

            // If no projects can be started, break out of the loop
            if(pq.empty()) break;

            // Select the project with the maximum profit available and increase the capital
            w += pq.top();
            pq.pop();
        }

        // Return the maximized capital after at most k selections
        return w;
    }
};

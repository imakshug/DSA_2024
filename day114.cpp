// Most Profit Assigning Work


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); ++i) {
            jobs.push_back({difficulty[i], profit[i]});
        }

        // Sort jobs by difficulty, and if difficulties are the same, sort by profit descending
        sort(jobs.begin(), jobs.end());

        // Sort workers
        sort(worker.begin(), worker.end());

        int maxProfit = 0;
        int jobIndex = 0;
        int bestProfit = 0;
        
        for (int i = 0; i < worker.size(); ++i) {
            while (jobIndex < jobs.size() && worker[i] >= jobs[jobIndex].first) {
                bestProfit = max(bestProfit, jobs[jobIndex].second);
                jobIndex++;
            }
            maxProfit += bestProfit;
        }

        return maxProfit;
    }
};


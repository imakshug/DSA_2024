// mimium time diffrence

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        
        // Convert all timePoints into minutes
        for (const string& time : timePoints) {
            int hours = stoi(time.substr(0, 2));
            int mins = stoi(time.substr(3, 2));
            minutes.push_back(hours * 60 + mins);
        }
        
        // Sort the time points in minutes
        sort(minutes.begin(), minutes.end());
        
        // Find the minimum difference between consecutive time points
        int minDiff = INT_MAX;
        for (int i = 1; i < minutes.size(); ++i) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        
        // Also check the difference between the first and last time point (across midnight)
        int lastDiff = (1440 - minutes.back()) + minutes[0];
        minDiff = min(minDiff, lastDiff);
        
        return minDiff;
    }
};
 

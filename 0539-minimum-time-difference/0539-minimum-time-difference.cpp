class Solution {
public:


    int timeToMinutes(const string& time) 
    {
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        return hours * 60 + minutes;
    }
    int findMinDifference(vector<string>& timePoints) {

        vector<int> minutes;

        // Convert each time point to minutes and store it in the vector
        for (const string& time : timePoints) {
            minutes.push_back(timeToMinutes(time));
        }

        // Sort the vector of minutes
        sort(minutes.begin(), minutes.end());

        int minDiff = INT_MAX;

        // Calculate the difference between consecutive time points
        for (int i = 1; i < minutes.size(); ++i) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }

        // Special case: the difference between the first and last time point, accounting for wrap-around midnight
        int wrapAroundDiff = (1440 + minutes[0]) - minutes.back();
        minDiff = min(minDiff, wrapAroundDiff);

        return minDiff;
        
    }
};
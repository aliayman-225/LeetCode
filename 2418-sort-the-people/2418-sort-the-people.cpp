class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> people;
        
        // Create a vector of pairs (height, name)
        for (int i = 0; i < n; ++i) {
            people.push_back({heights[i], names[i]});
        }
        
        // Sort the vector based on heights in descending order
        sort(people.begin(), people.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first > b.first;
        });
        
        // Extract the names in the sorted order
        vector<string> sortedNames;
        for (const auto& person : people) {
            sortedNames.push_back(person.second);
        }
        
        return sortedNames;
    }
};
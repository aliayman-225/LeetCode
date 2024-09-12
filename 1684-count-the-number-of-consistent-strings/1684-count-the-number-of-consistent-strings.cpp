class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {

        // for fast lookup
        unordered_set<char> allowed_set(allowed.begin(), allowed.end());  
        int consistent_count = 0;

        for (const string& word : words) 
        {
            bool is_consistent = true;
            
            for (char c : word) {
                if (allowed_set.find(c) == allowed_set.end()) 
                {
                    is_consistent = false;
                    break;
                }
            }
            
            if (is_consistent) 
                consistent_count++;
        }

        return consistent_count;
            
    }
};
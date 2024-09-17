class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
    
    unordered_map<string, int> wordCount;
    string word;

    // Combine both sentences into one stream
    stringstream ss(s1 + " " + s2);

    // Count the frequency of each word
    while (ss >> word) {
        wordCount[word]++;
    }

    // Collect the uncommon words
    vector<string> result;
    for (const auto& entry : wordCount) {
        if (entry.second == 1) {
            result.push_back(entry.first);
        }
    }

    return result;
        
    }
};
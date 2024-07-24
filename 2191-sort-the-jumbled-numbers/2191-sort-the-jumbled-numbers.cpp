class Solution {
public:
    std::vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto getMappedValue = [&](int num) -> long long {
            string numStr = std::to_string(num);
            string mappedStr;
            for (char digit : numStr) {
                mappedStr += to_string(mapping[digit - '0']);
            }
            return std::stoll(mappedStr);
        };
        
        vector<pair<int, long long>> mappedNums;
        for (int num : nums) {
            mappedNums.emplace_back(num, getMappedValue(num));
        }

        stable_sort(mappedNums.begin(), mappedNums.end(), [](const pair<int, long long>& a, const pair<int, long long>& b) {
            return a.second < b.second;
        });
        
        vector<int> sortedNums;
        for (const auto& pair : mappedNums) {
            sortedNums.push_back(pair.first);
        }
        
        return sortedNums;
    }
};
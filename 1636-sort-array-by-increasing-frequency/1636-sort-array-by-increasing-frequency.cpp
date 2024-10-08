class Solution {
public:
    std::vector<int> frequencySort(std::vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        sort(nums.begin(), nums.end(), [&freq](int a, int b) {
            if (freq[a] != freq[b]) {
                return freq[a] < freq[b];
            }
            return a > b;
        });
        
        return nums;
    }
};
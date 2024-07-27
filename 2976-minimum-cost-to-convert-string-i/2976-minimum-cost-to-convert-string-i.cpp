class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.length();
        const int ALPHABET_SIZE = 26;
        const int INF = INT_MAX;
        
        // Create a cost matrix to store the minimum cost to change from one char to another
        vector<vector<int>> costMatrix(ALPHABET_SIZE, vector<int>(ALPHABET_SIZE, INF));
        
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            costMatrix[i][i] = 0;
        }
        
        for (int i = 0; i < cost.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            costMatrix[u][v] = min(costMatrix[u][v], cost[i]);
        }
        
        // Use Floyd-Warshall algorithm to find the shortest paths between all pairs of nodes
        for (int k = 0; k < ALPHABET_SIZE; ++k) {
            for (int i = 0; i < ALPHABET_SIZE; ++i) {
                for (int j = 0; j < ALPHABET_SIZE; ++j) {
                    if (costMatrix[i][k] != INF && costMatrix[k][j] != INF) {
                        costMatrix[i][j] = min(costMatrix[i][j], costMatrix[i][k] + costMatrix[k][j]);
                    }
                }
            }
        }
        
        long long totalCost = 0;
        
        for (int i = 0; i < n; ++i) {
            int srcChar = source[i] - 'a';
            int tgtChar = target[i] - 'a';
            
            if (costMatrix[srcChar][tgtChar] == INF) {
                return -1;  // Impossible to transform source[i] to target[i]
            } else {
                totalCost += costMatrix[srcChar][tgtChar];
            }
        }
        
        return totalCost;
    }
};
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Helper function for topological sorting
        auto topologicalSort = [&](const vector<vector<int>>& conditions, int k) {
            vector<vector<int>> adj(k + 1); // adjacency list for the graph
            vector<int> inDegree(k + 1, 0); // in-degree count for each node
            
            for (const auto& condition : conditions) {
                int u = condition[0];
                int v = condition[1];
                adj[u].push_back(v);
                inDegree[v]++;
            }
            
            queue<int> q;
            vector<int> sorted;
            
            for (int i = 1; i <= k; ++i) {
                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                sorted.push_back(node);
                
                for (int neighbor : adj[node]) {
                    if (--inDegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
            
            if (sorted.size() != k) return vector<int>(); // Cycle detected
            
            return sorted;
        };
        
        // Topological sorting for rows and columns
        vector<int> rowOrder = topologicalSort(rowConditions, k);
        vector<int> colOrder = topologicalSort(colConditions, k);
        
        if (rowOrder.empty() || colOrder.empty()) return {}; // No valid sorting
        
        // Construct the matrix
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        unordered_map<int, int> rowIndex, colIndex;
        
        for (int i = 0; i < k; ++i) {
            rowIndex[rowOrder[i]] = i;
            colIndex[colOrder[i]] = i;
        }
        
        for (int num = 1; num <= k; ++num) {
            matrix[rowIndex[num]][colIndex[num]] = num;
        }
        
        return matrix;
    }
};
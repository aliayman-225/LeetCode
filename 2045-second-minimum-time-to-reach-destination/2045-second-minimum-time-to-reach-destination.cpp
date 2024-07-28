class Solution {
public:
    using int2 = pair<int, int>;

    // Function to calculate the total waiting time given the number of steps, traversal time, and signal change duration
    inline static int calculateWaitingTime(int steps, int time, int change) {
        int totalTime = 0;
        for (int i = 0; i < steps; ++i) {
            int greenRedCycles = totalTime / change;
            // Check if the current cycle is red
            if (greenRedCycles % 2 == 1) {
                totalTime = (greenRedCycles + 1) * change;  // Wait for the next green signal
            }
            totalTime += time;
        }
        return totalTime;
    }

    // Main function to find the second minimum time to reach the destination
    static int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // Create adjacency list for the graph
        vector<vector<int>> adjacencyList(n + 1);
        for (const auto& edge : edges) {
            int v = edge[0], w = edge[1];
            adjacencyList[v].push_back(w);
            adjacencyList[w].push_back(v);
        }

        // Initialize distances arrays
        vector<int> minDist(n + 1, INT_MAX), secondMinDist(n + 1, INT_MAX);
        queue<int2> q;  // Queue to perform BFS {node, distance}
        q.emplace(1, 0);
        minDist[1] = 0;

        // Perform BFS to determine the minimum and second minimum distances
        while (!q.empty()) {
            auto [currentNode, currentDist] = q.front();
            q.pop();
            for (int neighbor : adjacencyList[currentNode]) {
                int newDist = currentDist + 1;
                if (newDist < minDist[neighbor]) {
                    secondMinDist[neighbor] = minDist[neighbor];
                    minDist[neighbor] = newDist;
                    q.emplace(neighbor, newDist);
                } 
                else if (newDist > minDist[neighbor] && newDist < secondMinDist[neighbor]) {
                    secondMinDist[neighbor] = newDist;
                    q.emplace(neighbor, newDist);
                }
            }
        }

        int steps = secondMinDist[n];
        if (steps == INT_MAX) return -1;  // Return -1 if the second minimum distance is not found
        return calculateWaitingTime(steps, time, change);  // Calculate the total time considering traffic signals
    }
};
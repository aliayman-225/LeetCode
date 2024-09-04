class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        // Convert obstacles into a set of strings for O(1) lookup
        unordered_set<string> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
        }

        // Define the directions for movement: North, East, South, West
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0, direction = 0; // Start at (0, 0) facing North
        int maxDistanceSquared = 0;

        for (int command : commands) 
        {
            if (command == -2) 
            { 
                direction = (direction + 3) % 4; // Equivalent to (direction - 1 + 4) % 4
            } 
            else if (command == -1) 
            { 
                direction = (direction + 1) % 4;
            } 
            else 
            { // Move forward by 'command' steps
                for (int step = 0; step < command; ++step) 
                {
                    int newX = x + directions[direction].first;
                    int newY = y + directions[direction].second;

                    // Check if the next position is an obstacle
                    if (obstacleSet.find(to_string(newX) + "," + to_string(newY)) == obstacleSet.end()) 
                    {
                        x = newX;
                        y = newY;
                        maxDistanceSquared = max(maxDistanceSquared, x * x + y * y);
                    } 
                    else 
                    {
                        // Obstacle encountered, stop moving in this direction
                        break;
                    }
                }
            }
        }
        return maxDistanceSquared;     
    }
};
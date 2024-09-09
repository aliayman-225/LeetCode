/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

    // Initialize the matrix with -1
    std::vector<std::vector<int>> matrix(m, std::vector<int>(n, -1));
    
    // Directions for spiral traversal: right, down, left, up
    std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int x = 0, y = 0;  // Start position
    int directionIndex = 0;  // Direction index
    
    while (head) {
        matrix[x][y] = head->val;
        head = head->next;
        
        // Move to the next cell
        int next_x = x + directions[directionIndex].first;
        int next_y = y + directions[directionIndex].second;
        
        // Check if the next cell is out of bounds or already filled
        if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && matrix[next_x][next_y] == -1) {
            x = next_x;
            y = next_y;
        } else {
            // Change direction
            directionIndex = (directionIndex + 1) % 4;
            x = x + directions[directionIndex].first;
            y = y + directions[directionIndex].second;
        }
    }
    
    return matrix;
        
    }
};
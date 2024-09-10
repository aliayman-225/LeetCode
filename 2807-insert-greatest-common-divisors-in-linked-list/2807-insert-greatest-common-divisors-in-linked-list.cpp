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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        if (!head || !head->next) 
            return head; // No pairs of adjacent nodes

        ListNode* current = head;
        // Traverse through the linked list
        while (current && current->next) {
            int gcdValue = std::gcd(current->val, current->next->val); // Calculate GCD
            ListNode* newNode = new ListNode(gcdValue); // Create a new node with GCD value

            // Insert the new node between current and current->next
            newNode->next = current->next;
            current->next = newNode;

            // Move to the next pair
            current = newNode->next;
        }

        return head;      
    }
};
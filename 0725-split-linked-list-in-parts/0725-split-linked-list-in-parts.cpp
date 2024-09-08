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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
         vector<ListNode*> result(k, nullptr);

        int totalNodes = 0;
        ListNode* current = head;
        while (current) 
        {
            totalNodes++;
            current = current->next;
        }

        int partSize = totalNodes / k;
        int extraNodes = totalNodes % k;  

        current = head;
        for (int i = 0; i < k && current; i++) 
        {
            result[i] = current;  // The head of the i-th part
            int currentPartSize = partSize + (extraNodes > 0 ? 1 : 0); 
            extraNodes--;  

            // Move current to the end of the current part
            for (int j = 1; j < currentPartSize; j++) 
            {
                if (current) 
                {
                    current = current->next;
                }
            }

            if (current) {
                ListNode* nextPartHead = current->next;
                current->next = nullptr;
                current = nextPartHead;
            }
        }

        return result;
    }
};
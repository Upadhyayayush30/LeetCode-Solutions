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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result;
        ListNode* current = head;

        while (current) {
            int nextGreater = findNextGreater(current->next, current->val);
            result.push_back(nextGreater);
            current = current->next;
        }

        return result;
    }

private:
    int findNextGreater(ListNode* start, int target) {
        while (start) {
            if (start->val > target) {
                return start->val;
            }
            start = start->next;
        }
        return 0; // No greater node found
    }
};

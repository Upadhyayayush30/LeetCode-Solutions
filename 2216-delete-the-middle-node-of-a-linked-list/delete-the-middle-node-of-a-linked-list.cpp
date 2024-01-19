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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) {
            
            return nullptr;
        }

        int length = 0;
        ListNode* temp = head;

       
        while (temp) {
            length++;
            temp = temp->next;
        }

        int middleIndex = length / 2;
        temp = head;

      
        for (int i = 0; i < middleIndex - 1; ++i) {
            temp = temp->next;
        }

        ListNode* middle = temp->next;
        temp->next = middle->next;

        delete middle;

        return head;
    }
};

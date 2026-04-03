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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr = head;
        ListNode* dummyNode = new ListNode(-1,head);
        ListNode* prev = dummyNode;
        if ( head == NULL ) {
            return NULL;
        }
        while( curr ) {
            ListNode* front = curr->next;
            if ( curr->val == val ) {
                prev->next = front;
            } else {
                prev = curr;
            }
            curr = front;
        }
        return dummyNode->next;
    }};

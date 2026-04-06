//brute
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
    ListNode* deleteDuplicates(ListNode* head) {
        set<int>s;
        ListNode* temp = head;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        while ( temp ) {
            s.insert(temp->val);
            temp = temp->next;
        }
        for ( auto it = s.begin(); it != s.end(); it++ ) {
            ListNode* newNode = new ListNode(*it);
            curr->next = newNode;
            curr = curr->next;
        }
        return dummyNode->next;
    }
};

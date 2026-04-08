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
        if ( head == NULL ) return NULL;
        map<int, int>mpp;
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        ListNode* temp = head;
        while( temp ) {
            mpp[temp->val]++;
            temp = temp->next;
        }
        for ( auto& p : mpp ) {
            if ( p.second == 1 ) {
                ListNode* newNode = new ListNode(p.first);
                curr->next = newNode;
                curr = curr->next;
            }
        }
        return dummyHead->next;
    }
};

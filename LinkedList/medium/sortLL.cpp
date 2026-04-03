//brute -> store vals in vector -> sort -> put back in LL
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
    ListNode* sortList(ListNode* head) {
        vector<int>v;
        ListNode* temp = head;
        if ( head == NULL || head->next == NULL ) {
            return head;
        }
        while ( temp ) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        sort(v.begin(), v.end());
        temp = head;
        int idx = 0;
        while ( temp ) {
            temp->val = v[idx];
            temp = temp->next;
            idx++; 
        }
        return head;
    }
};




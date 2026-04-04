//brute
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*>v1;
        vector<ListNode*>v2;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        if ( headA == NULL || headB == NULL ) {
            return NULL;
        }
        while ( temp1 ) {
            v1.push_back(temp1);
            temp1 = temp1->next;
        }
        while ( temp2 ) {
            v2.push_back(temp2);
            temp2 = temp2->next;
        }
        temp1 = headA;
        while ( temp1 ) {
            if ( find(v2.begin(), v2.end(), temp1) != v2.end() ) {
                return temp1;
            }
            temp1 = temp1->next;
        }
        return NULL;
    }
};

//optimal

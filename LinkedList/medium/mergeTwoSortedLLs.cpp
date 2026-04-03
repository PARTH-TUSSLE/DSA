// brute -> LLs -> vector -> sort vector -> newLL
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

    ListNode* convertVectotoLL ( vector<int>v ) {
        ListNode* head = new ListNode(v[0]);
        ListNode* temp = head;
        for ( int i = 1; i < v.size(); i++ ) {
        ListNode* newNode = new ListNode(v[i]);
        temp->next = newNode;
        temp = temp->next;
        }
        return head;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if ( list1 == NULL ) {
            return list2;
        }
        if ( list2 == NULL ) {
            return list1;
        }
        if ( list1 == NULL && list2 == NULL ) {
            return NULL;
        }
        vector<int>v;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while( temp1 ) {
            v.push_back(temp1->val);
            temp1 = temp1->next;
        }
        while ( temp2 ) {
            v.push_back(temp2->val);
            temp2 = temp2->next;
        }
        sort(v.begin(), v.end());
        return convertVectotoLL(v);
    }
};
// optimal -> just change the links using dummyNode
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        ListNode* dummyNode = new ListNode(-1) ;
        ListNode* temp = dummyNode;
        while ( ptr1 && ptr2 ) {
            if ( ptr1->val < ptr2->val ) {
                temp->next = ptr1;
                temp = temp->next;
                ptr1 = ptr1->next;
            } else {
                temp->next = ptr2;
                temp = temp->next;
                ptr2 = ptr2->next;
            }
        }
        if ( ptr1 ) {
            temp->next = ptr1;
        } else {
            temp->next = ptr2;
        }
        return dummyNode->next;
    }
};

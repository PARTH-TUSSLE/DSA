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

//brute-2 -> hashmap
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
        map<ListNode*, int>mpp;
        ListNode* temp = headA;
        while ( temp ) {
            mpp[temp] = 1;
            temp = temp->next;
        }
        temp = headB;
        while ( temp ) {
            if ( mpp.find(temp) != mpp.end() ) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
};

//optimal 1
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
        int l1 = 0;
        int l2 = 0;
        ListNode* temp = headA;
        if ( headA == NULL || headB == NULL ) {
            return NULL;
        }
        while ( temp ) {
            l1++;
            temp = temp->next;
        }
        temp = headB;
        while ( temp ) {
            l2++;
            temp = temp->next;
        }
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        int diff = max(l1,l2) - min(l1,l2);
        if (l1 > l2) {
            for (int i = 0; i < l1 - l2; i++) {
                ptr1 = ptr1->next;
            }
        } else {
            for (int i = 0; i < l2 - l1; i++) {
            ptr2 = ptr2->next;
            }
        }
        while ( ptr1 && ptr2 ) {
            if ( ptr1 == ptr2 ) {
                return ptr1;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return NULL;
    }
};
// optimal 2
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
        if ( headA == NULL || headB == NULL ) {
            return NULL;
        }
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while ( temp1 != temp2 ) {
            temp1 = temp1->next;
            temp2 = temp2->next;
            if ( temp1 == temp2 ) {
                return temp1;
            }
            if ( temp1 == NULL ) temp1 = headB;
            if ( temp2 == NULL ) temp2 = headA;
        }
        return temp1;
    }
};

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

//optimal -> MergeSort in LLs

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
    ListNode* findMiddle ( ListNode* head ) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while ( fast != NULL && fast->next != NULL ) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
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
    ListNode* sortList(ListNode* head) {
        if ( head == NULL || head->next == NULL ) {
            return head;
        }
        ListNode* middle = findMiddle(head);
        ListNode* rightHead = middle->next;
        ListNode* leftHead = head;
        middle->next = nullptr;
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);
        return mergeTwoLists(leftHead, rightHead);
    }
};



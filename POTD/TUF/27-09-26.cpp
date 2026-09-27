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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        map<int, int>m;
        ListNode* temp = head;
        while( temp != nullptr ) {
            m[temp->val]++;
            temp = temp->next;
        }
        for (auto &it: m) {
            if ( it.second > 1 ) {
                ListNode* prev = head;
                ListNode* temp = head;
                
                 while (temp != nullptr) {
                    if ( temp->val == it.first && temp == head ) {
                        ListNode* toDel = head;
                        head = head->next;
                        delete toDel;
                        prev = head;
                        temp = head;
                    } else if (temp->val == it.first && temp != head) {
                        prev->next = temp->next;
                        ListNode* toDel = temp;
                        temp = temp->next;
                        delete toDel;
                    } else {
                        prev = temp;
                        temp = temp->next;
                    }
                 }
            }
        }
        return head;
    }
};

//OPTIMAL 

class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {

        unordered_map<int, int> freq;

        ListNode* temp = head;

        // Pass 1: Count frequencies
        while (temp != nullptr) {
            freq[temp->val]++;
            temp = temp->next;
        }

        // Pass 2: Remove all duplicate values
        temp = head;
        ListNode* prev = nullptr;

        while (temp != nullptr) {

            if (freq[temp->val] > 1) {

                ListNode* toDel = temp;

                // If deleting head
                if (temp == head) {
                    head = head->next;
                    temp = head;
                }

                // If deleting any other node
                else {
                    prev->next = temp->next;
                    temp = temp->next;
                }

                delete toDel;
            }

            else {
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};

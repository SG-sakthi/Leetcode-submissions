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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* lessDummy = new ListNode(0);
        ListNode* greaterDummy = new ListNode(0);

        ListNode* less = lessDummy;
        ListNode* great = greaterDummy;

        ListNode* current = head;

        while(current!= nullptr){
            ListNode* next = current->next ;

            current->next = nullptr;

            if(current->val<x){
                less->next = current;
                less = less->next;
            }
            else{
                great->next = current;
                great= great->next;
            }
            current = next;
        }

        less->next = greaterDummy->next;

        ListNode* result = lessDummy->next;

        delete greaterDummy;
        delete lessDummy;

        return result;
    }
};
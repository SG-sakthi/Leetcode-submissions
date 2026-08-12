
class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){
            ListNode* next = curr-> next;
            curr-> next = prev;
            prev = curr;
            curr =next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* dummy = new ListNode(0);
            dummy->next = head;

            ListNode* prevTail = dummy;
            ListNode* curr = head;

            while(curr){
                //find kth node
                ListNode* kth =curr;
                for(int i =1; i<k && kth ; i++){
                    kth = kth->next;
                }
                //If less than k node break
                if(!kth){
                    break;
                }
                //save next group
                ListNode* nextGroup = kth->next;
                //break the list
                kth->next = nullptr;
                //reverse the list
                ListNode* newHead = reverseLinkedList(curr);
                //connect with previous group
                prevTail->next = newHead;
                //current becomes the tail after reverse
                curr->next = nextGroup;
                //move the pointer
                prevTail = curr;
                curr = nextGroup;

            }
            return dummy->next;
    }
};
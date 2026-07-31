/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //create a hash map to store original and copied 
        /*hash map 
        [1->1`]
        [10->10`]
        [11->11`]
        [13->13']
        [7->7`]
        */
        unordered_map<Node*, Node*> mp;
        //create a dummy node
        Node*curr = head;
        //store all the copied nodes to hashmap until the head ends which curr
        while(curr){
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }
        //again start with head node to connect all the next and random nodes
        curr = head;

        while(curr){
            mp[curr]->next = mp[curr->next]; //next node of curr in hashmap is to next node of curr [1`->2`]
            mp[curr]->random = mp[curr->random]; //next node of random noed in hasmap is to next node random node pointing 
            curr = curr->next;
        }
        return mp[head]; // return the copied list 

    }
};
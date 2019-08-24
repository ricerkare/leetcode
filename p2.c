/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int a, b, sum, carry;
    struct ListNode *curNode1 = l1, *curNode2 = l2, \
		*result = malloc(sizeof(struct ListNode)), \
		*curResult = result;
    
    for (a = b = carry = 0; curNode1 || curNode2; a = b = 0) {
        if (curNode1) {
            a = curNode1->val;
            curNode1 = curNode1->next;
        }
        if (curNode2) {
            b = curNode->val;
            curNode2 = curNode2->next;
        }
		
		curResult->val = (a + b + carry) % 10;
		curResult->next = malloc(sizeof(struct ListNode));
		carry += (a + b) / 10;

    }
    return result;
}


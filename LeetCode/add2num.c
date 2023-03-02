/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = NULL, *tail = NULL;
    int carry = 0, sum = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int l1Val = l1 ? l1->val : 0;
        int l2Val = l2 ? l2->val : 0;
        sum = l1Val + l2Val + carry;
        carry = sum / 10;
        sum %= 10;

        struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
        node->val = sum;
        node->next = NULL;

        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }

        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }

    return head;
}
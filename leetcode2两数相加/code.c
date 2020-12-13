/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL && l2 == NULL) {
        return NULL;
    }
    struct ListNode* list1 = l1;
    struct ListNode* list2 = l2;
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    struct ListNode* node = NULL;
    int sum_sw = 0;
    int sum_gw = 0;
    int data1 = 0;
    int data2 = 0;
    while (list1 != NULL || list2 != NULL) {
        if (list1 != NULL) {
            data1 = list1->val;
            list1 = list1->next;
        } else {
            data1 = 0;
        }
        if (list2 != NULL) {
            data2 = list2->val;
            list2 = list2->next;
        } else {
            data2 = 0;
        }
        sum_gw = (data1 + data2 + sum_sw) % 10;
        sum_sw = (data1 + data2 + sum_sw) / 10;
        node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = sum_gw;
        node->next = NULL;
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    if (sum_sw > 0) {
        node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = sum_sw;
        node->next = NULL;
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}
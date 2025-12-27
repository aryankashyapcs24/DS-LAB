struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *temp = head, *rev = NULL, *temp1 = NULL;

    if (head == NULL) {
        return head;
    } else {
        while (temp != NULL) {
            temp1 = temp->next;
            temp->next = rev;
            rev = temp;
            temp = temp1;
        }
    }

    return rev;
}

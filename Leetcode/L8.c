struct ListNode* mergeInBetween(
    struct ListNode* list1,
    int a,
    int b,
    struct ListNode* list2
) {
    struct ListNode *temp = list1, *temp1 = list2, *temp3 = NULL;

    for (int i = 0; i <= b; i++) {
        if (i == a - 1) {
            temp3 = temp;
        }
        temp = temp->next;
    }

    temp3->next = list2;

    while (temp1->next != NULL) {
        temp1 = temp1->next;
    }

    temp1->next = temp;

    return list1;
}

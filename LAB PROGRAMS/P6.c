#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createList()
{
    struct Node *head = NULL, *ptr = NULL, *newNode;
    int val;

    printf("Enter elements (-1 to stop): ");
    scanf("%d", &val);

    while (val != -1)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            ptr = head;
        }
        else
        {
            ptr->next = newNode;
            ptr = newNode;
        }

        scanf("%d", &val);
    }

    return head;
}

void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* sortList(struct Node *head)
{
    struct Node *ptr, *ptr2;
    int t;

    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        for (ptr2 = ptr->next; ptr2 != NULL; ptr2 = ptr2->next)
        {
            if (ptr->data > ptr2->data)
            {
                t = ptr->data;
                ptr->data = ptr2->data;
                ptr2->data = t;
            }
        }
    }

    return head;
}

struct Node* concat(struct Node *head1, struct Node *head2)
{
    struct Node *ptr;

    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    ptr = head1;
    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = head2;
    return head1;
}

struct Node* reverse(struct Node *head)
{
    struct Node *prev = NULL, *curr = head, *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    return head;
}

int main()
{
    struct Node *head1 = NULL, *head2 = NULL, *head3 = NULL;

    printf("Create List 1\n");
    head1 = createList();

    printf("Create List 2\n");
    head2 = createList();

    printf("List 1: ");
    display(head1);

    printf("List 2: ");
    display(head2);

    head1 = sortList(head1);
    head2 = sortList(head2);

    printf("Sorted List 1: ");
    display(head1);

    printf("Sorted List 2: ");
    display(head2);

    head3 = concat(head1, head2);
    printf("After Concatenation: ");
    display(head3);

    head3 = reverse(head3);
    printf("After Reversal: ");
    display(head3);

    return 0;
}

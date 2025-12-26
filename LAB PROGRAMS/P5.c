#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* create(struct node *head)
{
    struct node *newnode, *ptr;
    int val;

    printf("Enter data (-1 to stop): ");
    scanf("%d", &val);

    while (val != -1)
    {
        newnode = malloc(sizeof(struct node));
        newnode->data = val;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            ptr = head;
        }
        else
        {
            ptr->next = newnode;
            ptr = newnode;
        }

        printf("Enter data (-1 to stop): ");
        scanf("%d", &val);
    }
    return head;
}

struct node* delete_beg(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    struct node *ptr = head;
    printf("Deleted: %d\n", ptr->data);

    head = head->next;
    free(ptr);

    return head;
}

struct node* delete_end(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    if (head->next == NULL)
    {
        printf("Deleted: %d\n", head->data);
        free(head);
        return NULL;
    }

    struct node *ptr = head, *preptr;

    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    printf("Deleted: %d\n", ptr->data);
    preptr->next = NULL;
    free(ptr);

    return head;
}

struct node* delete_pos(struct node *head, int pos)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    struct node *ptr = head, *preptr;

    if (pos == 1)
    {
        printf("Deleted: %d\n", ptr->data);
        head = ptr->next;
        free(ptr);
        return head;
    }

    int i = 1;
    while (i < pos && ptr != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
        i++;
    }

    if (ptr == NULL)
    {
        printf("Invalid position\n");
        return head;
    }

    printf("Deleted: %d\n", ptr->data);
    preptr->next = ptr->next;
    free(ptr);

    return head;
}

struct node* display(struct node *head)
{
    struct node *ptr = head;

    if (ptr == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
    return head;
}

int main()
{
    struct node *head = NULL;
    int choice, pos;

    while (1)
    {
        printf("\nSingle Linked List Operations");
        printf("\n1. Create");
        printf("\n2. Delete at Beginning");
        printf("\n3. Delete at End");
        printf("\n4. Delete at Position");
        printf("\n5. Display");
        printf("\n6. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                head = create(head);
                break;

            case 2:
                head = delete_beg(head);
                break;

            case 3:
                head = delete_end(head);
                break;

            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                head = delete_pos(head, pos);
                break;

            case 5:
                head = display(head);
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}

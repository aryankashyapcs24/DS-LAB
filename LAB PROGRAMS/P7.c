#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* create(struct Node *head)
{
    int item;
    struct Node *newnode, *ptr;

    printf("Enter elements (-1 to stop): ");
    scanf("%d", &item);

    while (item != -1)
    {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = item;
        newnode->prev = newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;

            ptr->next = newnode;
            newnode->prev = ptr;
        }

        scanf("%d", &item);
    }

    return head;
}

struct Node* insert_left(struct Node *head, int value, int item)
{
    struct Node *ptr = head, *newnode;

    while (ptr != NULL && ptr->data != value)
        ptr = ptr->next;

    if (ptr == NULL)
    {
        printf("Value not found\n");
        return head;
    }

    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = item;

    newnode->next = ptr;
    newnode->prev = ptr->prev;

    if (ptr->prev != NULL)
        ptr->prev->next = newnode;
    else
        head = newnode;

    ptr->prev = newnode;

    return head;
}

struct Node* delete_value(struct Node *head, int value)
{
    struct Node *ptr = head;

    while (ptr != NULL && ptr->data != value)
        ptr = ptr->next;

    if (ptr == NULL)
    {
        printf("Value not found\n");
        return head;
    }

    if (ptr->prev != NULL)
        ptr->prev->next = ptr->next;
    else
        head = ptr->next;

    if (ptr->next != NULL)
        ptr->next->prev = ptr->prev;

    free(ptr);
    return head;
}

void display(struct Node *head)
{
    struct Node *ptr = head;

    if (ptr == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (ptr != NULL)
    {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    int choice = 0, item, value;

    while (1)
    {
        printf("\n1. Create / Append Nodes");
        printf("\n2. Insert Left");
        printf("\n3. Delete");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                head = create(head);
                break;

            case 2:
                printf("Insert to LEFT of value: ");
                scanf("%d", &value);

                printf("Enter data to insert: ");
                scanf("%d", &item);

                head = insert_left(head, value, item);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);

                head = delete_value(head, value);
                break;

            case 4:
                display(head);
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

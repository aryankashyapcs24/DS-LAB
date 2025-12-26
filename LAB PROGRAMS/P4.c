#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* create(struct node *head)
{
    struct node *new_node, *ptr;
    int value;

    printf("Enter data (-1 to stop): ");
    scanf("%d", &value);

    while (value != -1)
    {
        new_node = malloc(sizeof(struct node));
        new_node->data = value;
        new_node->next = NULL;

        if (head == NULL)
        {
            head = new_node;
            ptr = head;
        }
        else
        {
            ptr->next = new_node;
            ptr = new_node;
        }

        printf("Enter data (-1 to stop): ");
        scanf("%d", &value);
    }
    return head;
}

struct node* insert_beg(struct node *head, int value)
{
    struct node *new_node = malloc(sizeof(struct node));

    new_node->data = value;
    new_node->next = head;
    head = new_node;

    return head;
}

struct node* insert_end(struct node *head, int value)
{
    struct node *new_node = malloc(sizeof(struct node));

    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        return head;
    }

    struct node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = new_node;
    return head;
}

struct node* insert_pos(struct node *head, int pos, int value)
{
    struct node *new_node = malloc(sizeof(struct node));

    new_node->data = value;
    new_node->next = NULL;

    if (pos == 1 || head == NULL)
    {
        new_node->next = head;
        head = new_node;
        return head;
    }

    struct node *ptr = head;
    int i = 1;

    while (i < pos - 1 && ptr->next != NULL)
    {
        ptr = ptr->next;
        i++;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;

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
    int choice, pos, value;

    printf("\nSingle Linked List operations");
    printf("\n1. Create");
    printf("\n2. Insert at Beginning");
    printf("\n3. Insert at End");
    printf("\n4. Insert at Position");
    printf("\n5. Display");
    printf("\n6. Exit\n");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                head = create(head);
                break;

            case 2:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                head = insert_beg(head, value);
                break;

            case 3:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                head = insert_end(head, value);
                break;

            case 4:
                printf("Enter position and value to insert: ");
                scanf("%d %d", &pos, &value);
                head = insert_pos(head, pos, value);
                break;

            case 5:
                head = display(head);
                break;

            case 6:
                return 0;

            default:
                printf("Invalid\n");
        }
    }
}

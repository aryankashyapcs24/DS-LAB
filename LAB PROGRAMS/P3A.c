#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void insert()
{
    int value;

    if (rear == SIZE - 1)
    {
        printf("\nQueue overflow");
    }
    else
    {
        printf("Enter value to insert: ");
        scanf("%d", &value);

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;

        printf("%d inserted into the queue", value);
    }
}

void delete()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue underflow");
    }
    else
    {
        printf("%d deleted from the linear queue", queue[front]);
        front++;
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("\nLinear queue is empty");
    }
    else
    {
        printf("\nQueue elements are:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;

    printf("Simple queue using array\n");

    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice");
        }
    }
}

#include <stdio.h>

#define SIZE 3

int top = -1;
int arr[SIZE];

int push();
int pop();
void display();

int main()
{
    while (1)
    {
        int choice;

        printf("\nMenu:");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        if (choice == 1)
        {
            push();
        }
        else if (choice == 2)
        {
            pop();
        }
        else if (choice == 3)
        {
            display();
        }
        else
        {
            return 0;
        }
    }
}

int push()
{
    int ele;

    if (top == SIZE - 1)
    {
        printf("\nStack overflow");
        return 0;
    }
    else
    {
        printf("\nEnter element to push into array: ");
        scanf("%d", &ele);

        top = top + 1;
        arr[top] = ele;

        printf("\n%d pushed", arr[top]);
    }

    return 0;
}

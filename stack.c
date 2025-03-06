//to perform stack operations
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct stack {
    int top;
    int items[MAX];
};

void initialize(struct stack *s) {
    s->top = -1;
}

int isempty(struct stack *s) {
    return s->top == -1;
}

int isfull(struct stack *s) {
    return s->top == MAX - 1;
}

void push(struct stack *s, int x) {
    if (isfull(s)) {
        printf("Stack overflow\n");
    } else {
        s->items[++s->top] = x;
        printf("Pushed element is %d\n", x);
    }
}

int pop(struct stack *s) {
    if (isempty(s)) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return s->items[s->top--];
    }
}

int peek(struct stack *s) {
    if (isempty(s)) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return s->items[s->top];
    }
}

void display(struct stack *s) {
    if (isempty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = 0; i <= s->top; i++) {
            printf("%d\n", s->items[i]);
        }
    }
}

int main() {
    struct stack s;
    initialize(&s);
    int choice, value;

    do {
        printf("\nStack operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the value to be pushed: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    // Clear the input buffer
                    while (getchar() != '\n');
                    continue;
                }
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("Popped element is %d\n", value);
                }
                break;
            case 3:
                value = peek(&s);
                if (value != -1) {
                    printf("Top element is %d\n", value);
                }
                break;
            case 4:
                display(&s);
                break;
            case 5:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
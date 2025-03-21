#include <stdio.h>
#define SIZE 5
int queue[SIZE], front = -1, rear = -1;
void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("\nQueue is full\n");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        printf("Inserted: %d\n", value);
    }
}
void dequeue() {
    if (front == -1) {
        printf("\nQueue is empty\n");
    } else {
        printf("Removed: %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}
void display() {
    if (front == -1) {
        printf("\nQueue is empty\n");
    } else {
        int i = front;
        printf("\nQueue elements: ");
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d\n", queue[rear]);
    }
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    dequeue();
    display();
    enqueue(60);
    display();
    return 0;
}

// Queue in C

#include <stdio.h>
#define SIZE 4

void display();
void enQueue(int);
void deQueue();

int items[SIZE], front = -1, rear = -1;

int main() {
  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(4);

  display();

  //deQueue removes element at first -->1
  deQueue();
  display();
  return 0;
}

void enQueue(int v) {
  if (rear == SIZE - 1)
    printf("\nQueue is full");
  else {
    if (front == -1)
      front = 0;
    rear++;
    items[rear] = v;
    printf("\nElement inserted= %d", v);
  }
}

void deQueue() {
  if (front == -1)
    printf("\nQueue is empty");
  else {
    printf("\nDeleted : %d", items[front]);
    front++;
    if (front > rear)
      front = rear = -1;
  }
}

void display() {
  if (rear == -1)
    printf("\nQueue is empty");
  else {
    int i;
    printf("\nQueue elements= ");
    for (i = front; i <= rear; i++)
      printf("%d  ", items[i]);
  }
  printf("\n");
}

#include<stdio.h>
#include<string.h>
#define SIZE 10001

int queue[SIZE];
int front = -1, rear = -1;

void push(int data) {
    queue[++rear] = data;
}

int pop() {
    if(front == rear) {
        return -1;
    } else {
        return queue[++front];
    }
}

int size() {
    return rear - front;
}

int empty() {
    if(front == rear) {
        return 1;
    } else {
        return 0;
    }
}

int frontCheck() {
    if(front == rear) {
        return -1;
    } else {
        return queue[front + 1];
    }
}

int rearCheck() {
    if(front == rear) {
        return -1;
    } else {
        return queue[rear];
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++) {
        char sel[6];
        scanf("%s", sel);

        if(!strcmp(sel, "push")) {
            int data;
            scanf("%d", &data);
            push(data);
        } else if(!strcmp(sel, "pop")) {
            printf("%d\n", pop());
        } else if(!strcmp(sel, "size")) {
            printf("%d\n", size());
        } else if(!strcmp(sel, "empty")) {
            printf("%d\n", empty());
        } else if(!strcmp(sel, "front")) {
            printf("%d\n", frontCheck());
        } else {
            printf("%d\n", rearCheck());
        }
    }

    return 0;
}
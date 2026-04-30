ppog.c
#include <stdio.h>
#include <string.h>

#define SIZE 10

typedef struct {
    char dataRing[SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

int isFull(CircularBuffer *cb) {
    if (cb->count == SIZE)
        return 1;
    else
        return 0;
}

int isEmpty(CircularBuffer *cb) {
    if (cb->count == 0)
        return 1;
    else
        return 0;
}

void write(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("Buffer Overflow\n");
        return;
    }

    cb->dataRing[cb->tail] = data;
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count++;
}

char read(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Buffer Underflow\n");
        return '\0';
    }

    char data = cb->dataRing[cb->head];
    cb->head = (cb->head + 1) % SIZE;
    cb->count--;

    return data;
}

int main() {
    CircularBuffer cb;
    init(&cb);

    char name[50];

    printf("Enter your name: ");
    scanf("%s", name);

    strcat(name, "CE-ESY");

    for (int i = 0; i < strlen(name); i++) {
        write(&cb, name[i]);
    }

    printf("Output: ");

    while (!isEmpty(&cb)) {
        char c = read(&cb);
        printf("%c", c);
    }

    printf("\n");

    return 0;
}

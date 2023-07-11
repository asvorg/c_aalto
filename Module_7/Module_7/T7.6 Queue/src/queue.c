#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"

int enqueue(struct studentqueue *q, const char *name) {
    struct studentqueue *newNode = (struct studentqueue *)malloc(sizeof(struct studentqueue));
    
    newNode->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
    strcpy(newNode->name, name);
    
    newNode->next = NULL;
    
    if (q->next == NULL) {
        q->next = newNode;
    } else {
        struct studentqueue *current = q->next;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    return 1;
}

int dequeue(struct studentqueue *q, char *buffer, unsigned int size) {
    if (q->next == NULL) {
        return 0;
    }

    struct studentqueue *temp = q->next;
    strncpy(buffer, temp->name, size);
    buffer[size - 1] = '\0'; 
    
    q->next = temp->next;
    
    free(temp->name);
    free(temp);
    
    return 1;
}

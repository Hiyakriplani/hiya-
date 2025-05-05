#include <stdio.h>

#include <stdlib.h>

#include <string.h>



typedef struct Node {

    char url[100];

    struct Node* prev;

    struct Node* next;

} Node;



Node* current = NULL;



void visit(char* url) {

    Node* newNode = (Node*)malloc(sizeof(Node));

    strcpy(newNode->url, url);

    newNode->next = NULL;



    if (current != NULL) {

        current->next = newNode;

        newNode->prev = current;

    } else {

        newNode->prev = NULL;

    }



    current = newNode;

    printf("Visited: %s\n", current->url);

}



void back() {

    if (current != NULL && current->prev != NULL) {

        current = current->prev;

        printf("Back to: %s\n", current->url);

    } else {

        printf("No previous page.\n");

    }

}



void forward() {

    if (current != NULL && current->next != NULL) {

        current = current->next;

        printf("Forward to: %s\n", current->url);

    } else {

        printf("No forward page.\n");

    }

}



int main() {

    visit("google.com");

    visit("youtube.com");

    visit("openai.com");



    back();

    back();

    forward();



    return 0;

}

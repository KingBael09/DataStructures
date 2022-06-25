#include<stdio.h>
#include<stdlib.h>

#define max 5

int stack[max];
int top = -1;

void enque(int item){
    if(top == max -1){
        printf("\nStack is Full\n");
    }
    else{
        top++;
        stack[top] = item;
        printf("\nElement Added\n");
    }
}

void deque(){
    if(top == -1){
        printf("\nStack is Empty\n");
    }
    else{
        printf("\nElement Removed\n");
        top--;
    }
}

void peek(){
    printf("Topmost Element of Stack is %d", stack[top]);
}

void display(){
    int i = top;

    if(i == -1){
        printf("\nStack Empty\n");
    }
    else{
        printf("\nDisplaying: ");
        while(i != -1){
            printf("%d ", stack[i]);
            i--;
        }
    }
}

void main(){
    int choice, item;

    while(1){
        printf("\n\nMain Menu\n\n");
        printf("\n1. Insert from Top\n2. Delete form Top\n3. Peek Top\n4. Display\n\n0. Exit\n");
        printf("\nYour Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter Data: ");
                scanf("%d", &item);
                enque(item);
                break;
            case 2:
                deque();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("\nInvalid Choice\n");
        }
    }
}
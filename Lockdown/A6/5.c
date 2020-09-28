# include <stdio.h>
# include <stdlib.h>

struct node {
    int data;
    struct node* next;
} ;

typedef struct node* list;

list addBegin(list, int, int*);
list addEnd(list, int, int*);
void traverse(list);
list addMiddle(list, int, int*);
list delete(list, int, int*);

int main(){
    list head;
    head = (list)malloc(sizeof(struct node));
    head -> data = -1;
    head -> next = NULL;
    int size = 0;
    int op;
    printf("Enter the num of operations to perform : ");
    scanf("%d", &op);
    printf("Insert : \n1 to add at begin\n2 to add at end\n3 to add at middle\n4 to delete\n5 to traverse\n");
    while(op!= 0){
        printf("Enter operation number : ");
        int opNum, data;
        scanf("%d", &opNum);
        if(opNum != 5){
            printf("Enter data : ");
            scanf("%d", &data);
        }

        switch(opNum){
            case 1 : {
                head = addBegin(head, data, &size);
                break;
            }
            case 3 : {
                head = addMiddle(head, data, &size);
                break;
            }
            case 2 : {
                head = addEnd(head, data, &size);
                break;
            }
            case 4 : {
                head = delete(head, data, &size);
                break;
            }
            case 5 : {
                traverse(head);
                break;
            }
            default : {
                printf("wrong operation number entered\n");
            }
        }
        op --;

    }
    
    return 0;
}

list addBegin(list head, int d, int *size){
    if(*size == 0){
        head -> data = d;
        head -> next = NULL;
    }
    else{
        list temp = (list)malloc(sizeof(struct node));
        temp->next = head;
        temp -> data = d;
        head = temp;
    }

    (*size) ++;
    return head;
}

void traverse(list head){
    list temp = (list)malloc(sizeof(struct node));
    temp = head;
    do{
        printf("%d ", temp->data);      
        temp = temp->next;
    }
    while(temp  != NULL);
    printf("\n");
}
list addEnd(list head, int d, int *size){
    if(*size == 0){
        head->data = d;
        head->next = NULL;
    }
    else{
    list temp = (list) malloc(sizeof(struct node));
    temp = head;
    list newNode = (list) malloc(sizeof(struct node));
    newNode->data = d;
    newNode->next = NULL;
    while(head->next != NULL){
        head = head->next;
    }
    head->next = newNode;
    head = temp;
    }
    (*size)++;
    return head;
}

list addMiddle(list head, int d, int* size){
    if(*size == 0){
        head->data = d;
        head->next = NULL;
    }
    else{
       int k = (*size) /2;
       int i = 0;
       list temp = (list)malloc(sizeof(struct node));
       temp = head;
       while(i != k-1){
           head = head->next;
           i ++;
       } 
       list newNode = (list)malloc(sizeof(struct node));
       newNode->data = d;
       newNode->next = head->next;
       head->next = newNode;
       head = temp;
    }
    (*size) ++;
    return head;
}

list delete(list head, int d, int *size){
    list temp = (list)malloc(sizeof(struct node));
    temp = head;
    while(head->next != NULL){
        if(head->data == d || head->next->data == d){
            break;
        }
        head = head->next;
    }
    if(head -> data == d){
        head = head->next;
        return head;
    }
    else if(head->next->data == d){
        head->next = head->next->next;
    }
    head = temp;
    (*size) --;
    return head; 
    
}
/*
Name: Rakshit Agrawal
Github: Rakshit-26
*/

#include <stdio.h>
#include <stdlib.h>
//LL using *last
struct Node{
    int data;
    struct Node *next;
    struct Node *back;
} *start=NULL, *last=NULL;

void input();

void create(int x){//inst_end
    struct Node *ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->back = NULL;
    ptr->data = x;
    ptr->next = NULL;
    if(start==NULL){
        start = ptr;
        last = ptr;
    }
    else{
        last->next = ptr;
        ptr->back = last;
        last = ptr;
    } 
}

void traverse(){
    struct Node *temp = start;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next; 
    }
    printf("\n");
}

void inst_beg(int x){
    struct Node *ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->back = NULL;
    ptr->data = x;
    ptr->next = NULL;
    if(start==NULL){
        start = ptr;
        last = ptr;
    }
    else{
        ptr->next = start;
        start->back = ptr;
        start = ptr;

    } 
}

void inst_loc(int x, int loc){//maybe drawback that cant insert at 0th index: can use an if statement to change start and insert an element at 0th location
    struct Node *ptr, *temp;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->back = NULL;
    ptr->data = x;
    ptr->next = NULL;
    if(start==NULL){
        printf("List is empty");
    }
    else{
        temp = start;
        for(int i=0;i<loc-1;i++){
            temp = temp->next;
        }
        if(temp!=NULL){
            ptr->next = temp ->next;
            ptr->next->back = ptr;
            ptr->back = temp;
            temp->next = ptr;
        }
        else{
            printf("Location not available");
        }
    } 
}//if inserting at 0th position i.e., creating a list

void del_beg(){
    struct Node *temp;
    if(start==NULL){
        printf("List is empty");
    }
    else{
        temp = start;
        start = start->next;
        start->back = NULL;
        free(temp);
    } //try printing value of temp after free()
}

void del_end(){//Do it using mam's method  //incomp
    struct Node *prev;
    if(start==NULL){
        printf("List is empty");
    }
    else{
        prev = start;
        while(prev->next != last && prev->next!=last){//1 condition added
            prev = prev->next;
        }
        free(last);
        last = prev;//What if only one node..? what happens to start..?
        last->next = NULL;
    } 
}

void del_loc(int loc){
    struct Node *temp, *prev;
    if(start==NULL){
        printf("List is empty");
    }
    else{//Location not available..?
        temp = start;
        for(int i=0;i<loc;i++){
            prev = temp;
            temp = temp->next;
        }
        if(temp!=NULL){//what if 1st node
            prev->next = temp ->next;
            temp->next->back = prev;
            free(temp);
        }
        else{//NULL->next what happens..?
            printf("Location not available");
        }
    } 
}

int main(){
    while(1){
        int ch;
        printf("MENU DRIVEN:\
        \n#1 Creation\
        \n#2 Insertion\
        \n#3 Deletion\
        \n#4 Traverse\
        \n#5 Exit\
        \nYour choice: ");
        scanf("%d", &ch);
        printf("\n");
        if(ch==1){
            input();
            printf("LL: ");
            traverse();
        }
        else if(ch==2){
            printf("MENU DRIVEN:\
            \n#1 At beginning\
            \n#2 At end\
            \n#3 At specific location\
            \n#4 Exit\
            \nYour choice: ");
            scanf("%d", &ch);

            if(ch==1){
                int x;
                printf("Enter element: ");
                scanf("%d", &x);
                inst_beg(x);
                printf("Updated LL: ");
                traverse();
            }
            else if(ch==2){
                int x;
                printf("Enter element: ");
                scanf("%d", &x);
                create(x);
                printf("Updated LL: ");
                traverse();
            }
            else if(ch==3){
                int x, loc;
                printf("Enter element, location: ");
                scanf("%d %d", &x, &loc);
                inst_loc(x, loc);
                printf("Updated LL: ");
                traverse();
            }
            else break;
            printf("\n");
        }
        else if(ch==3){
            printf("MENU DRIVEN:\
            \n#1 At beginning\
            \n#2 At end\
            \n#3 At specific location\
            \n#4 Exit\
            \nYour choice: ");
            scanf("%d", &ch);

            if(ch==1){
                del_beg();
                printf("Updated LL: ");
                traverse();
            }
            else if(ch==2){
                del_end();
                printf("Updated LL: ");
                traverse();
            }
            else if(ch==3){
                int loc;
                printf("Enter location: ");
                scanf("%d", &loc);
                del_loc(loc);
                printf("Updated LL: ");
                traverse();
            }
            else break;
            printf("\n");
        }
        else if(ch==4){
            printf("LL: ");
            traverse();
        }
        else break;
        printf("\n");

    }
    if(start!=NULL){
        printf("LL: ");
        traverse();
    }
    return 0;
}
//Rakshit Agrawal cse26

void input(){
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        create(x);
    }
}
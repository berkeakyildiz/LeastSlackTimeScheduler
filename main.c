#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Implement linked list
typedef struct node {
    struct Process p;
    struct node* next;
}node;
//initalize linked list
struct node *head;

node* create(struct Process, node* next) {//create node
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    if(new_node == NULL)
        printf("Error creating a new node");

    new_node->p = Process;
    new_node->next = next;
    return new_node;
}

node* add(struct Process) {// append node at end of the list
    if(head == NULL)
        return NULL;
    node *cursor = head;
    while(cursor->next != NULL)
        cursor = cursor->next;
    node* new_node = create(Process, NULL);
    cursor->next = new_node;
    retun head;
}




typedef struct Process {
    char identifier[50];
    int runtime;
}Process;

int main() {
    char request[10];
    int systemTime = 0;
    while(true) {
        scanf("%s", request);
        switch(request) {
            case "QUIT": //completed
                return 0;
            case "MRCT": // display most recently completed k tasks
                int k = 0;
                scanf("%d", k);
                break;
            case "ECTS": // empty completed tasks stack

                break;
            case "DFCTS": //dump completed tasks into a text file

                break;
            case "DECTCTS": //delete k earliest completed tasks from the stack

                break;
            case "DST": // display system time DONE!
                printf("Current System Time is: %d", systemTime);
                break;
            case "DIT": // display total(idle) time

                break;
            case "SNT": // start a new task DONE!
                char id[50];
                int runtime;
                scanf("%s", id);
                scanf("%d", runtime);
                struct Process *new_process = (struct Process*) malloc(sizeof(struct Process));
                new_process->identifier = id;
                new_process->runtime = runtime;
                add(new_process);
                break;
            case "S": // simulate k units
                int k = 0;
                scanf("%d", k);
                for(int i = 1; i <= k; i++) {
                    node *cursor = head;
                    int min = 999999999;
                    node *minimum;
                    if(head != NULL) {
                        while (cursor->next != NULL) {
                            if (cursor->p.runtime <= min) {
                                min = cursor->p.runtime;
                                minimum = cursor;
                            }
                            cursor = cursor->next;
                        }
                        systemTime++;
                        minimum->p.runtime--;
                    }else
                        break;
                }
                systemTime++;
                break;


        }
        return 0;
    }

}
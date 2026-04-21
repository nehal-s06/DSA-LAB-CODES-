#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODE;

// Create a new node with given data
NODE createNodeInCLL(int data) {
    NODE temp = (NODE) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Create CLL with n nodes
NODE createCLL(int n     ) {
	
if(n <= 0) return NULL;

    NODE head = NULL, temp, last;
    int i, val;
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        temp = createNodeInCLL(val);
        if (head == NULL) {
            head = temp;
            temp->next = head;
            last = temp;
        } else {
            last->next = temp;
            temp->next = head;
            last = temp;
        }
    }
    return head;

	


}

// Traverse CLL
void traverseListInCLL(NODE head      ) {

 if (head == NULL) {
        printf("CLL is empty\n");
        return;
    }
    NODE temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");



}

// Insert at given position in CLL
NODE insertAtPositionInCLL( NODE head ,int pos,int data               ) {
	
NODE temp = createNodeInCLL(data);
    if (pos == 1) {  // Insert at beginning
        if (head == NULL) {
            temp->next = temp;
            return temp;
        } else {
            NODE last = head;
            while (last->next != head) last = last->next;
            temp->next = head;
            last->next = temp;
            return temp;  // new head
        }
}

    NODE curr = head;
    int i;
    for (i = 1; i < pos - 1 && curr->next != head; i++) {
        curr = curr->next;
    }

    if (i != pos - 1) {
        printf("Position not found\n");
        free(temp);
        return head;
    }

    temp->next = curr->next;
    curr->next = temp;
    return head;
	


}

// Delete node at given position in CLL
NODE deleteAtPositionInCLL( NODE head,int pos           ) {
if (head == NULL) {
        printf("CLL is empty\n");
        return NULL;
    }

    NODE curr = head, prev = NULL;
    int i;

    if (pos == 1) {  // Delete head
        int deleted = head->data;
        if (head->next == head) {  // only one node
            free(head);
            printf("Deleted element: %d\n", deleted);
            return NULL;
        }
        NODE last = head;
        while (last->next != head) last = last->next;
        last->next = head->next;
        head = head->next;
        free(curr);
        printf("Deleted element: %d\n", deleted);
        return head;
    }

    for (i = 1; i < pos && curr->next != head; i++) {
        prev = curr;
        curr = curr->next;
    }

    if (i != pos) {
        printf("Position not found\n");
        return head;
    }

    prev->next = curr->next;
    printf("Deleted element: %d\n", curr->data);
    free(curr);
    return head;

	



	
 
}

// Reverse CLL
NODE reverseCLL(  NODE head             ) {
	
if (head == NULL || head->next == head) return head;

    NODE prev = NULL, curr = head, next;
    NODE first = head;

    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != head);

    head->next = prev;  // fix last node's next
    head = prev;        // new head
    return head;






	




}

// Concatenate two CLLs
NODE concatCLL( NODE first ,NODE second          ) {

if (first == NULL) return second;
    if (second == NULL) return first;

    NODE last1 = first;
    while (last1->next != first) last1 = last1->next;

    NODE last2 = second;
    while (last2->next != second) last2 = last2->next;

    last1->next = second;
    last2->next = first;

    return first;





	





}

int main() {
    NODE first = NULL, second = NULL;
    int x, pos, op, n;

    while (1) {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                first = createCLL(n);
                break;
            case 2:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos <= 0) {
                    printf("Position not found\n");
                } else {
                    printf("Element: ");
                    scanf("%d", &x);
                    first = insertAtPositionInCLL(first, pos, x);
                }
                break;
            case 3:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Position: ");
                    scanf("%d", &pos);
                    first = deleteAtPositionInCLL(first, pos);
                }
                break;
            case 4:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;
            case 5:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                    traverseListInCLL(first);   // <-- display reversed list
                }
                break;
            case 6:
                printf("Creating second CLL to concatenate...\n");
                printf("How many nodes in second CLL? ");
                scanf("%d", &n);
                second = createCLL(n);
                first = concatCLL(first, second);
                printf("Concatenated CLL:\n");
                traverseListInCLL(first);
                break;
            case 7:
                exit(0);
        }
    }
}

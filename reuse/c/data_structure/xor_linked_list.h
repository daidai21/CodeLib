typedef struct XorNode {
    char data;
    struct XorNode *LRPtr;
}
XorNode, *XorPointer;


typedef struct XorLinkedList {
    XorPointer left, right;
}
XorLinkedList;


XorPointer xor(XorPointer a, XorPointer b) {
    return (XorPointer)((unsigned long)(a) ^ (unsigned long)(b));
}


void createXorLinkedList(XorLinkedList *list) {
    char ch;
    XorPointer lastNode = NULL;
    int isFirstNode = 1;
    while ((ch = getchar()) != '\n') {
        XorPointer newNode = (XorPointer) malloc(sizeof(XorNode));
        newNode -> data = ch;
        newNode -> LRPtr = NULL;
        if (lastNode) {
            newNode -> LRPtr = xor(lastNode, NULL);
            lastNode -> LRPtr = xor(xor(lastNode -> LRPtr, NULL), newNode);
        }
        lastNode = newNode;
        if (isFirstNode) {
            isFirstNode = 0;
            list -> left = newNode;
        }
    }
    list -> right = lastNode;
}


void print(XorPointer a, XorPointer b) {
    XorPointer nullFirst = a == NULL ? a : b;
    XorPointer nonNullFirst = a != NULL ? a : b;
    XorPointer tmp = NULL;
    do {
        printf("%c ", nonNullFirst -> data);
        tmp = nonNullFirst;
        nonNullFirst = xor(nullFirst, nonNullFirst -> LRPtr);
        nullFirst = tmp;
    } while (nonNullFirst != NULL);
}


void XorLinkedListInsert(XorLinkedList *list, int pos, char data) {
    XorPointer node = list -> left, tmp = NULL;
    XorPointer last = NULL;
    XorPointer newNode = NULL;
    int i = 1;
    while (i < pos && node != NULL) {
        tmp = node;
        node = xor(last, node -> LRPtr);
        last = tmp;
        i++;
    }
    newNode = (XorPointer) malloc(sizeof(XorNode));
    newNode -> data = data;
    newNode -> LRPtr = xor(last, node);
    if (node != NULL) {
        node -> LRPtr = xor(newNode, xor(last, node -> LRPtr));
    }
    if (last != NULL) {
        last -> LRPtr = xor(xor(last -> LRPtr, node), newNode);
    }
    if (pos == 1) {
        list -> left = newNode;
    }
}


void XorLinkedListDelete(XorLinkedList *list, int pos) {
    XorPointer node = list -> left, last = NULL, next = NULL, tmp = NULL;
    int i = 1;
    while (i < pos && node != NULL) {
        i++;
        tmp = node;
        node = xor(last, node -> LRPtr);
        last = tmp;
    }
    next = xor(last, node -> LRPtr);
    if (last != NULL) {
        last -> LRPtr = xor(xor(last -> LRPtr, node), next);
    }
    if (next != NULL) {
        next -> LRPtr = xor(last, xor(node, next -> LRPtr));
    } else {
        list -> right = last; //删除了最后一个结点
    }
    if (pos == 1) {
        list -> left = next;
    }
    free(node);
}




#include "list.hpp"
#include <cstdlib>


// Aufgabe 2.1
ListNode_t* NewListNode(void){
    ListNode_t* node = (ListNode_t*)malloc(sizeof(ListNode_t));
    node->data = 0;
    node->pNext = NULL;
    return node;
}

void FreeListNode(ListNode_t* elem){
    free(elem);
}

// Aufgabe 2.2
List_t* NewList(void){
    List_t* list = (List_t*)malloc(sizeof(List_t));
    list->pHead = NULL;
    list->pTail = NULL;
    list->size = 0;
    return list;
}

void FreeList(List_t* list){
    ListNode_t* current = list->pHead;
    ListNode_t* next = NULL;
    while (current != NULL){
        next = current->pNext;
        FreeListNode(current);
        current = next;
    }
    free(list);
}

// Aufgabe 2.3
int InsertIntoLinkedList(List_t* list, ListNode_t* elem){
    if(!list or !elem) return -1;
    ListNode_t* current = list->pHead;
    if(list->pHead == NULL){
        list->pHead = elem;
        list->pTail = elem;
        list->size++;
        elem->pNext = NULL;
    }
    else{
        while(current->pNext != NULL){
            current = current->pNext;
        }
        current->pNext = elem;
        list->pTail = elem;
        list->size++;
        elem->pNext = NULL;
    }
    return 0;
}
int InsertIntoLinkedListAfterNode(List_t* list, ListNode_t* node /* the node we insert the element into */, ListNode_t* elem){
    if(!node or !elem or !list) return -1;
    if(node->pNext == NULL){
        list->pTail = elem;
    };
    elem->pNext = node->pNext;
    node->pNext = elem;
    list->size++;
    return 0;
}

// Aufgabe 2.4
int RemoveFromList(List_t* list, ListNode_t* elem){
    if(!elem or !list) return -1;
    if(list->pHead == elem){
        list->pHead = elem->pNext;
    };
    ListNode_t* current = list->pHead;
    ListNode_t* last == NULL;
    while(current!=elem && current != NULL){
        last = current;
        current = last->pNext;
    };
    last->pNext = current->pNext;
    if(current->pNext == NULL){
        list->pTail = last;
    };
    FreeListNode(elem);
    list->size--;
}

// Aufgabe 2.5
ListNode_t* GetNext(const List_t* list, ListNode_t* elem){
    if(elem==NULL){
        return list->pHead;
    }
    else{
        return elem->pNext;
    };
};
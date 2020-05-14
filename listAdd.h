//
// Created by so_go on 2020/5/8.
//

#ifndef UNTITLED_LISTADD_H
#define UNTITLED_LISTADD_H
struct ListNode {
    int val;
    ListNode *next;
};

ListNode *listAdd(ListNode *a, ListNode *b){
    ListNode *aCur = a, *bCur = b;
    ListNode *resFirst = NULL, *last = NULL;
    int jw = 0, sum, tmp;
    ListNode *cur;
    while(aCur != NULL and bCur != NULL){
        sum = aCur->val + bCur->val + jw;
        tmp = sum % 10;
        jw = sum / 10;
        cur = new ListNode{tmp, NULL};
        if(last != NULL){
            last->next= cur;
            last = cur;
        }
        else{
            resFirst = cur;
            last = resFirst;
        }
        aCur = aCur->next;
        bCur = bCur->next;
    }
    while(aCur != NULL){
        sum = aCur->val + jw;
        tmp = sum % 10;
        jw = sum / 10;
        cur = new ListNode{tmp, NULL};
        last->next= cur;
        last = cur;
        aCur = aCur->next;
    }
    while(bCur != NULL){
        sum = bCur->val + jw;
        tmp = sum % 10;
        jw = sum / 10;
        cur = new ListNode{tmp, NULL};
        last->next = cur;
        last = cur;
        bCur = bCur->next;
    }
    if(jw != 0){
        cur = new ListNode{jw, NULL};
        last->next = cur;
        last = cur;
    }
    return resFirst;
}
#endif //UNTITLED_LISTADD_H

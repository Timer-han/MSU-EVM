#include <iostream>

using namespace std;

struct ListNode {
    int value;
    ListNode *next;
};

ListNode *Process(ListNode *head) {
    ListNode *a = nullptr, *b = a, *oldhead = head;
    if (head == nullptr){
        return nullptr;
    }
    while (head->next != nullptr and head->next->next != nullptr) {
        if (a == nullptr) {
            a = head->next;
            b = a;
        } else {
            a->next = head->next;
            a = a->next;
        }


        head->next = head->next->next;
        head = head->next;
        if (head == head->next) {

            head->next = b;
            return head;

        }
    }

    while (head->next != nullptr){
        head = head->next;
    }
    if (oldhead->next == nullptr or a == nullptr){

        head->next = b;
        return oldhead;
    }

    a->next = oldhead->next;
    oldhead->next = b;
    return oldhead;
}

int main() {
    for (int t = 2; t < 10; ++t) {
        cout << t << " ";
        ListNode *a = nullptr, *b, *c;

        for (int i = 0; i < t; ++i) {
            b = new ListNode;
            b->value = i;
            if (!a) {
                a = b;
                c = b;
                c->next = nullptr;
            } else {
                c->next = b;
                c = c->next;
                c->next = nullptr;
            }
        }
        c->next = a->next->next;

        cout << Process(a)->value << " ";

        b = a;
        for (int i = 0; i < t; ++i) {
            cout << b->value;
            b = b->next;
        }
        cout << endl;
    }

    return 0;
}
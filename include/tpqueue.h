// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
 private:
    struct Node {
        T v;
        Node* n;
    };
    Node* header;
 public:
    TPQueue() : header(nullptr) {}
    T pop();
    void push(const T& r);
};
template<typename T>
void TPQueue<T>::push(const T& r) {
    if (header == NULL) {
        Node* str = new Node;
        str->v = r;
        str->n = NULL;
        header = str;
    } else {
        Node* c1 = header;
        Node* c2 = new Node;
        int q = 0;
        while (c1) {
            if (c1->v.prior < r.prior) {
                break;
            } else {
                c1 = c1->n;
                q++;
            }
        }
        if (q == 0) {
            c2->n = header;
            c2->v = r;
            header = c2;
        } else {
            c1 = header;
            for (int i = 1; i < q; i++) {
                c1 = c1->n;
            }
            c2->n = c1->n;
            c2->v = r;
            c1->n = c2;
        }
    }
}
template<typename T>
T TPQueue<T>::pop() {
    if (header == NULL) {
        throw std::string("!!!");
    } else {
        T r = header->v;
        Node* c = header->n;
        delete header;
        header = c;
        return r;
    }
}

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_

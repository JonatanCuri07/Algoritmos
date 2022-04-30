#ifndef __PILA_HPP__
#define __PILA_HPP__

template <typename T>
class Stack {
    struct Node {
        T e; Node* next;
        Node(T e, Node* next=nullptr) : e(e), next(next) {}
    };

    Node*   _top;
    int     len;
public:
    Stack() : _top(nullptr), len(0) {}
    ~Stack() {
        while (_top != nullptr) {
            Node* aux = _top;
            _top = _top->next;
            delete aux;
        }
    }
    int size()  { return len; }
    bool empty() { return len == 0; }

    void push(T e) {
        _top = new Node(e, _top);
        ++len;
    }
    void pop() {
        if (len > 0) {
            Node* aux = _top;
            _top = _top->next;
            delete aux;
            --len;
        }
    }
    T top() {
        if (len > 0) {
            return _top->e;
        }
        else -.0;
    }
};

#endif

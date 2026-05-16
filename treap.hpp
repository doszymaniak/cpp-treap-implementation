#ifndef TREAP_HPP
#define TREAP_HPP

#include <utility>

namespace data_structures {

template <typename T>
class Treap {
    class Node {
        T key;
        int priority;
        Node *left, *right;
        Node(const T &key);
        static std::pair<Node *, Node *> split(Node *t, const T &piv);
        static Node *merge(Node *l, Node *r);
        static Node *insert(const T &el, Node *n);
        static Node *remove(const T &k, Node *n);
        static Node *find(const T &el, Node *n);
        static Node *find_minimum(Node *n);
        static Node *find_maximum(Node *n);
        static Node *remove_minimum(Node *n);
        static Node *remove_maximum(Node *n);
    };
    Node *root;
public:
    Treap();
    Treap(std::initializer_list<T> init);
    Treap(const Treap &other);
    Treap(Treap &&other);
    ~Treap();
    Treap &operator=(const Treap &other);
    Treap &operator=(Treap &&other);
    void insert(const T &el);
    void remove(const T &k);
    bool find(const T &el) const;
    T find_minimum() const;
    T find_maximum() const;
    void remove_minimum();
    void remove_maximum();
};

}

namespace ds = data_structures;

#include "treap.tpp"

#endif
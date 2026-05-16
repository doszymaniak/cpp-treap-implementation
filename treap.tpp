#include <cstdlib>

namespace data_structures {

template <typename T>
Treap<T>::Node::Node(const T &k) : key(k), priority(rand()), 
left(nullptr), right(nullptr)
{}

template <typename T>
std::pair<typename Treap<T>::Node *, typename Treap<T>::Node *> Treap<T>::Node::split(Node *t, const T &el)
{
    if (t == nullptr) return {nullptr, nullptr};
    if (t->key >= el)
    {
        std::pair<Node *, Node *> left_split = split(t->left, el);
        // t contains elements >= piv
        t->left = left_split.second;
        return {left_split.first, t};
    }
    std::pair<Node *, Node *> right_split = split(t->right, el);
    // t contains elements < piv
    t->right = right_split.first;
    return {t, right_split.second};
}

template <typename T>
Treap<T>::Node *Treap<T>::Node::merge(Treap<T>::Node *l, Treap<T>::Node *r)
{
    if (l == nullptr) return r;
    if (r == nullptr) return l;
    // Invariants:
    // - keys(left) < keys(right)
    // - node with higher priority becomes root 
    if (l->priority > r->priority)
    {
        l->right = merge(l->right, r);
        return l;
    }
    r->left = merge(l, r->left);
    return r;
}

}
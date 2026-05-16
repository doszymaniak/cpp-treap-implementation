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

template <typename T>
Treap<T>::Node *Treap<T>::Node::insert(const T &el, Treap<T>::Node *n)
{
    Node *new_node = new Node(el);
    std::pair<Node *, Node *> parts = split(n, el);
    return merge(merge(parts.first, new_node), parts.second);
}

template <typename T>
Treap<T>::Node *Treap<T>::Node::remove(const T &el, Treap<T>::Node *n)
{
    if (n == nullptr) return n;
    if (n->key > el) 
    {
        n->left = remove(el, n->left);
        return n;
    }
    else if (n->key < el) 
    {
        n->right = remove(el, n->right);
        return n;
    }
    Node *merged = merge(n->left, n->right);
    delete n;
    return merged;
}

template <typename T>
Treap<T>::Node *Treap<T>::Node::find(const T &el, Treap<T>::Node *n)
{
    if (n == nullptr) return n;
    if (n->key > el) return find(el, n->left);
    else if (n->key < el) return find(el, n->right);
    return n;
}

template <typename T>
Treap<T>::Node *Treap<T>::Node::find_minimum(Treap<T>::Node *n)
{
    if (n == nullptr) return n;
    if (n->left == nullptr) return n;
    return find_minimum(n->left);
}

template <typename T>
Treap<T>::Node *Treap<T>::Node::find_maximum(Treap<T>::Node *n)
{
    if (n == nullptr) return n;
    if (n->right == nullptr) return n;
    return find_maximum(n->right);
}

template <typename T>
Treap<T>::Node *Treap<T>::Node::remove_minimum(Treap<T>::Node *n)
{
    if (n == nullptr) return n;
    if (n->left == nullptr)
    {
        Node *r = n->right;
        delete n;
        return r;
    }
    n->left = remove_minimum(n->left);
    return n;
}

template <typename T>
Treap<T>::Node *Treap<T>::Node::remove_maximum(Treap<T>::Node *n)
{
    if (n == nullptr) return n;
    if (n->right == nullptr)
    {
        Node *l = n->left;
        delete n;
        return l;
    }
    n->right = remove_maximum(n->right);
    return n;
}

template <typename T>
Treap<T>::Treap() : root(nullptr) {};

template <typename T>
Treap<T>::Treap(std::initializer_list<T> l) : root(nullptr)
{
    for (const T &el: l) root = Node::insert(el, root);
}

template <typename T>
Treap<T>::Node *Treap<T>::Node::copy(const Treap<T>::Node *n)
{
    if (n == nullptr) return nullptr;
    Node *new_node = new Node(n->key);
    new_node->priority = n->priority;
    new_node->left = copy(n->left);
    new_node->right = copy(n->right);
    return new_node;
}

template <typename T>
Treap<T>::Treap(const Treap<T> &other) : root(Node::copy(other.root)) {}

template <typename T>
Treap<T>::Treap(Treap<T> &&other) : root(other.root)
{
    other.root = nullptr;
}

template <typename T>
void Treap<T>::Node::destroy(Treap<T>::Node *n)
{
    if (n == nullptr) return;
    destroy(n->left);
    destroy(n->right);
    delete n;
}

template <typename T>
Treap<T>::~Treap()
{
    Node::destroy(root);
    root = nullptr;
}

}
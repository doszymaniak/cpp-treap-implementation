#include <cstdlib>

namespace data_structures {

template <typename T>
Treap<T>::Node::Node(const T &k) : key(k), priority(rand()), 
left(nullptr), right(nullptr)
{}

}
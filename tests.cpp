#include <gtest/gtest.h>

#include "treap.hpp"

TEST(TreapTest, InsertAndFind) {
  ds::Treap<int> tree;
  tree.insert(5);
  tree.insert(3);
  tree.insert(7);

  EXPECT_TRUE(tree.find(5));
  EXPECT_TRUE(tree.find(3));
  EXPECT_TRUE(tree.find(7));
  EXPECT_FALSE(tree.find(99));
}

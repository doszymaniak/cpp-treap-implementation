#include "treap.hpp"
#include <gtest/gtest.h>
#include <vector>

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

TEST(TreapTest, DuplicateValuesAreSupported) {
  ds::Treap<int> tree;
  tree.insert(4);
  tree.insert(4);
  tree.insert(2);

  std::vector<int> expected{2, 4, 4};

  EXPECT_TRUE(tree.find(4));
  EXPECT_EQ(tree.to_vector(), expected);
}

TEST(TreapTest, EmptyTreeBehavior) {
  ds::Treap<int> empty;

  EXPECT_TRUE(empty.to_vector().empty());
  EXPECT_THROW(empty.find_minimum(), std::invalid_argument);
  EXPECT_THROW(empty.find_maximum(), std::invalid_argument);
}

TEST(TreapTest, MinAndMaxAcrossInsertionOrder) {
  ds::Treap<int> tree{10, 2, 8, 4, 6};

  EXPECT_EQ(tree.find_minimum(), 2);
  EXPECT_EQ(tree.find_maximum(), 10);
}

TEST(TreapTest, RemoveMinimumAndMaximum) {
  ds::Treap<int> tree{10, 2, 8, 4, 6};
  tree.remove_minimum();
  tree.remove_maximum();

  std::vector<int> expected{4, 6, 8};
  EXPECT_EQ(tree.to_vector(), expected);
}

TEST(TreapTest, CopySemanticsProduceEquivalentTree) {
  ds::Treap<int> original{5, 2, 9, 1};
  ds::Treap<int> copy(original);

  EXPECT_EQ(copy.to_vector(), original.to_vector());
  EXPECT_TRUE(copy.find(5));
  EXPECT_TRUE(copy.find(1));
}

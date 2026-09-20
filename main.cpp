#include "treap.hpp"
#include <iostream>
#include <limits>
#include <string>
#include <utility>

using ds::Treap;

void print_options() {
  std::cout << "\n1. Insert element\n";
  std::cout << "2. Remove element\n";
  std::cout << "3. Find element\n";
  std::cout << "4. Find minimum\n";
  std::cout << "5. Find maximum\n";
  std::cout << "6. Remove minimum\n";
  std::cout << "7. Remove maximum\n";
  std::cout << "8. Print (inorder)\n";
  std::cout << "9. Test copy constructor\n";
  std::cout << "10. Test move constructor\n";
  std::cout << "11. Exit\n\n";
  std::cout << "CHOOSE: ";
}

bool read_value(int &value) {
  if (std::cin >> value)
    return true;

  if (std::cin.eof())
    return false;

  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "INVALID VALUE. TRY AGAIN.\n";
  return false;
}

int main() {
  std::cout << "-- WELCOME TO THE TREAP DEMO --\n";
  Treap<int> treap;

  while (true) {
    print_options();
    std::string option;
    if (!(std::cin >> option))
      break;

    if (option == "1") {
      int val;
      std::cout << "ENTER VALUE: ";
      if (read_value(val))
        treap.insert(val);
    }

    else if (option == "2") {
      int val;
      std::cout << "ENTER VALUE: ";
      if (read_value(val))
        treap.remove(val);
    }

    else if (option == "3") {
      int val;
      std::cout << "ENTER VALUE: ";
      if (read_value(val)) {
        std::cout << "ELEMENT " << val;
        if (treap.find(val))
          std::cout << " FOUND!\n";
        else
          std::cout << " NOT FOUND!\n";
      }
    }

    else if (option == "4") {
      try {
        std::cout << treap.find_minimum() << '\n';
      } catch (const std::invalid_argument &) {
        std::cout << "EMPTY TREE!\n";
      }
    }

    else if (option == "5") {
      try {
        std::cout << treap.find_maximum() << '\n';
      } catch (const std::invalid_argument &) {
        std::cout << "EMPTY TREE!\n";
      }
    }

    else if (option == "6")
      treap.remove_minimum();

    else if (option == "7")
      treap.remove_maximum();

    else if (option == "8")
      std::cout << treap << '\n';

    else if (option == "9") {
      std::cout << "ORIGINAL: " << treap << '\n';
      Treap<int> copy_t(treap);
      std::cout << "COPY: " << copy_t << '\n';
    }

    else if (option == "10") {
      std::cout << "BEFORE MOVE: " << treap << '\n';
      Treap<int> moved(std::move(treap));
      std::cout << "MOVE CONSTRUCTOR: " << moved << '\n';
      std::cout << "ORIGINAL AFTER MOVE: " << treap << '\n';
    }

    else if (option == "11")
      break;

    else
      std::cout << "UNKNOWN OPTION. CHOOSE 1-11.\n";
  }

  return 0;
}
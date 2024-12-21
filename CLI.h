#include <iostream>
#include <string>
#include "Tree.h"  // Your Tree class
#include "Utils.h" // Helper functions for visualization
#include "OBST.h"  // Your OBST class
#include "TreeVisualization.h"

class CLI
{
private:
  Tree tree;
  int n;
  Vector<float> p;
  Vector<float> q;
  Vector<std::string> labels;
  std::string DOT_FILE = "tree.dot";
  std::string OUTPUT_IMAGE = "tree.png";

  void editTree();      // Option 1 in main menu
  void visualizeTree(); // Option 2 in main menu
  void analyzeTree();   // Option 3 in main menu

  // Submenu for editing the tree
  void createTreeFromScratch();
  void addNode();
  void deleteNode();
  void editNode();

public:
  CLI() {};
  // CLI(Tree &tree, int &n, Vector<float> &p,
  //     Vector<float> &q, Vector<std::string> &labels,
  //     std::string &DOT_FILE, std::string &OUTPUT_IMAGE)
  //     : tree(tree), n(n), p(p), q(q), labels(labels),
  //       DOT_FILE(DOT_FILE), OUTPUT_IMAGE(OUTPUT_IMAGE) {}

  void run(); // Main function to display the menu
};

void CLI::run()
{
  while (true)
  {
    Utils::clearTerminal();
    std::cout << "\n===== Optimal BST CLI =====\n";
    std::cout << "1. Edit Tree\n";
    std::cout << "2. Visualize Tree\n";
    std::cout << "3. Analyze Tree\n";
    std::cout << "4. Exit\n";
    std::cout << "Please select an option: ";

    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
      editTree();
      break;
    case 2:
      visualizeTree();
      break;
    case 3:
      analyzeTree();
      break;
    case 4:
      std::cout << "Exiting. Goodbye!\n";
      return;
    default:
      std::cout << "Invalid choice. Please try again.\n";
    }
  }
}

void CLI::editTree()
{
  while (true)
  {
    std::cout << "\n===== Edit Tree =====\n";
    std::cout << "1. Create a Tree from Scratch\n";
    std::cout << "2. Add a New Node\n";
    std::cout << "3. Delete a Node\n";
    std::cout << "4. Edit an Existing Node\n";
    std::cout << "5. Back to Main Menu\n";
    std::cout << "Please select an option: ";

    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
      Utils::getDataFromUser(labels, n, p, q);
      tree.assign(OBST::generateTheOBST(p, q, labels, true));
      break;
    case 2:
      addNode();
      break;
    case 3:
      deleteNode();
      break;
    case 4:
      editNode();
      break;
    case 5:
      return; // Go back to the main menu
    default:
      std::cout << "Invalid choice. Please try again.\n";
    }
  }
}

void CLI::createTreeFromScratch()
{
}

void CLI::addNode()
{
}

void CLI::deleteNode()
{
}

void CLI::editNode()
{
}

void CLI::visualizeTree()
{
  TreeVisualization::visualizeTree(tree, DOT_FILE, OUTPUT_IMAGE, true);
}

void CLI::analyzeTree()
{
}
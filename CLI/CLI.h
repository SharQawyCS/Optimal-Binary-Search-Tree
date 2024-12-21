#include <iostream>
#include <string>
#include "../Tree.h"  // Tree class
#include "../Utils.h" // Utility functions
#include "CLIHelper.h"
#include "../OBST.h" // Your OBST class
#include "../TreeVisualization.h"

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

  void editTree();             // Option 1 in main menu
  void displayTree() const;    // Option 2 in main menu
  void visualizeTree();        // Option 3 in main menu
  void analyzeTree();          // Option 4 in main menu
  void DisplayDerivedTables(); // Option 5 in main menu
  void DisplayEnteredData();   // Option 6 in main menu

  // Submenu for editing the tree
  void createTreeFromScratch();
  void addNode();    // Todo
  void deleteNode(); // Todo
  void editNode();   // Todo

public:
  CLI() {};
  // CLI(Tree &tree, int &n, Vector<float> &p,
  //     Vector<float> &q, Vector<std::string> &labels,
  //     std::string &DOT_FILE, std::string &OUTPUT_IMAGE)
  //     : tree(tree), n(n), p(p), q(q), labels(labels),
  //       DOT_FILE(DOT_FILE), OUTPUT_IMAGE(OUTPUT_IMAGE) {}

  void show(); // Main function to display the menu
};

void CLI::show()
{
  while (true)
  {
    Utils::clearTerminal();
    std::cout << "\n===== Optimal BST CLI =====\n";
    std::cout << "1. Edit Tree\n";
    std::cout << "2. Display Tree\n";
    std::cout << "3. Visualize Tree\n";
    std::cout << "4. Analyze Tree\n";
    std::cout << "5. Display Derived Tables\n";
    std::cout << "6. Display Entered Data\n";
    std::cout << "0. Exit\n";

    int choice = CLIHELPER::getChoice(6, "USE_DEFAULT");

    switch (choice)
    {
    case 1:
      editTree();
      break;
    case 2:
      displayTree();
      break;
    case 3:
      visualizeTree();
      break;
    case 4:
      analyzeTree();
      break;
    case 5:
      DisplayDerivedTables();
      break;
    case 6:
      DisplayEnteredData();
      break;
    case 0:
      Utils::clearTerminal();
      std::cout << "Exiting... As-Salamu Alaykum!\n";
      return;
    default:
      std::cout << "Invalid choice. (from default of while)\n";
    }
  }
}

void CLI::editTree()
{
  while (true)
  {
    Utils::clearTerminal();
    std::cout << "\n===== Edit Tree =====\n";
    std::cout << "1. Create a Tree from Scratch\n";
    std::cout << "2. Add a New Node\n";
    std::cout << "3. Delete a Node\n";
    std::cout << "4. Edit an Existing Node\n";
    std::cout << "0. Back to Main Menu\n";

    int choice = CLIHELPER::getChoice(4, "USE_DEFAULT");

    switch (choice)
    {
    case 1:
      createTreeFromScratch();
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
    case 0:
      return; // Go back to the main menu
    default:
      std::cout << "Invalid choice. (from default of while)\n";
    }
  }
}

void CLI::displayTree() const
{
  while (true)
  {
    Utils::clearTerminal();
    std::cout << "\n===== Displaying Tree =====\n";
    tree.displayTree();

    int choice = CLIHELPER::getChoice(0, "\nPress [0] to back to main menu\n");

    switch (choice)
    {
    case 0:
      return; // Go back to the main menu
      break;

    default:
      std::cout << "Invalid choice. (from default of while)\n";
      break;
    }
  }
}

void CLI::createTreeFromScratch()
{
  Utils::clearTerminal();

  Utils::getDataFromUser(labels, n, p, q);
  tree.assign(OBST::generateTheOBST(p, q, labels, false));
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
  Utils::clearTerminal();

  std::cout << "Visualizing the tree...\n";
  TreeVisualization::visualizeTree(tree, DOT_FILE, OUTPUT_IMAGE, true);
}

void CLI::analyzeTree()
{
  while (true)
  {
    Utils::clearTerminal();
    std::cout << "\n===== Tree Analysis =====\n";

    tree.analyzeTree();

    int choice = CLIHELPER::getChoice(0, "\nPress [0] to back to main menu\n");

    switch (choice)
    {
    case 0:
      return; // Go back to the main menu
    default:
      std::cout << "Invalid choice. (from default of while)\n";
    }
  }
}

void CLI::DisplayDerivedTables()
{
  while (true)
  {
    Utils::clearTerminal();
    std::cout << "\n===== Display Derived Tables =====\n";

    OBST::generateTheOBST(p, q, labels, true);

    int choice = CLIHELPER::getChoice(0, "\nPress [0] to back to main menu\n");

    switch (choice)
    {
    case 0:
      return; // Go back to the main menu
    default:
      std::cout << "Invalid choice. (from default of while)\n";
    }
  }
}

void CLI::DisplayEnteredData()
{
  while (true)
  {
    Utils::clearTerminal();
    std::cout << "\n===== Display Entered Data =====\n";

    std::cout << "Data labels      :  ";
    labels.display();
    std::cout << "Probabilities (p):  ";
    p.display(false);
    std::cout << "Probabilities (q): ";
    q.display();

    int choice = CLIHELPER::getChoice(0, "\nPress [0] to back to main menu\n");

    switch (choice)
    {
    case 0:
      return; // Go back to the main menu
    default:
      std::cout << "Invalid choice. (from default of while)\n";
    }
  }
}
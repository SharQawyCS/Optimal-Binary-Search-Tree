#pragma once

#include "CLI.h"
#include "CLIHelper.h"

#include "../Utils.h" // Utility functions
#include "../TreeVisualization.h"
#include "../OBST.h" // OBST class

void CLI::displayTree() const
{
  if (tree.isEmpty())
  {
    CLIHELPER::popAlert("The tree is empty! Please create a tree first.");
    return;
  }

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

void CLI::visualizeTree()
{
  Utils::clearTerminal();

  if (tree.isEmpty())
  {
    CLIHELPER::popAlert("The tree is empty! Please create a tree first.");
    return;
  }

  std::cout << "Visualizing the tree...\n";
  TreeVisualization::visualizeTree(tree, DOT_FILE, OUTPUT_IMAGE, true);
}

void CLI::analyzeTree()
{
  if (tree.isEmpty())
  {
    CLIHELPER::popAlert("The tree is empty! Please create a tree first.");
    return;
  }

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
  if (tree.isEmpty())
  {
    CLIHELPER::popAlert("The have not enter data yet! Please create data first.");
    return;
  }

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
  if (tree.isEmpty())
  {
    CLIHELPER::popAlert("The have not enter data yet! Please create data first.");
    return;
  }

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
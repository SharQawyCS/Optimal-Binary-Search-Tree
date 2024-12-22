#pragma once

#include "CLI.h"
#include "CLIHelper.h"

#include "../Utils.h" // Utility functions
#include "../TreeVisualization.h"
#include "../OBST.h" // OBST class

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
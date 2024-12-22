#pragma once

#include "CLI.h"
#include "CLIHelper.h"

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
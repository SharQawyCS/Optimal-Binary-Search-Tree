#pragma once

#include "CLI.h"
#include "CLIHelper.h"

#include "../OBST.h"  // OBST class
#include "../Utils.h" // Utility functions

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
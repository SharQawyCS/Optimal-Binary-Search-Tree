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
    // std::cout << "3. Delete a Node\n";
    // std::cout << "4. Edit an Existing Node\n";
    std::cout << "0. Back to Main Menu\n";

    int choice = CLIHELPER::getChoice(2, "USE_DEFAULT");

    switch (choice)
    {
    case 1:
      createTreeFromScratch();
      break;
    case 2:
      addNode();
    //   break;
    // case 3:
    //   deleteNode();
    //   break;
    // case 4:
    //   editNode();
    //   break;
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

  useQ = Utils::getDataFromUser(labels, n, p, q);
  tree.assign(OBST::generateTheOBST(p, q, labels, false));
}

void CLI::addNode()
{
  Utils::clearTerminal();
  std::cout << "\n===== Add New Node =====\n";

  if (useQ)
  {
    CLIHELPER::popAlert("You cannot edit a tree with un-successful search probabilities (q).");
    return;
  }

  std::string newNodeLabel = Utils::readLabel(labels, "Enter the label for the new node: ");
  float newNodeP = Utils::readFloatInput("Enter the probability of successful search (p): ", false);

  if (tree.isEmpty())
  {
    labels.resize(1);
    labels[0] = newNodeLabel;

    p.resize(2);
    p[0] = 0;
    p[1] = newNodeP;

    q.resize(2);
    q[0] = 0;
    q[1] = 0;
  }
  else
  {
    int size = labels.size();
    labels.resize(size + 1);
    labels[size] = newNodeLabel;

    p.resize(size + 2);
    p[size + 1] = newNodeP;

    q.resize(size + 2);
    q[size + 1] = 0;
  }

  Utils::sortInputs(labels, p);

  tree.assign(OBST::generateTheOBST(p, q, labels, false));

  CLIHELPER::popAlert("Node added successfully!");
}

void CLI::deleteNode()
{
  if (tree.isEmpty())
  {
    CLIHELPER::popAlert("The tree is empty! Please create a tree first.");
    return;
  }
}

void CLI::editNode()
{
  if (tree.isEmpty())
  {
    CLIHELPER::popAlert("The tree is empty! Please create a tree first.");
    return;
  }
}
#pragma once

#include <iostream>
#include <string>

class CLI
{
private:
  bool useQ;
  Settings settings;
  Tree tree;
  int n;
  Vector<float> p;
  Vector<float> q;
  Vector<std::string> labels;
  std::string DOT_FILE = Settings::getDotFile();
  std::string OUTPUT_IMAGE = Settings::getOutputImage();

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
  CLI()
  {
    useQ = false;
  }

  void show(); // Main function to display the menu
};

#include "MainScreen.cpp"
#include "TreeScreens.cpp"
#include "EditTreeScreen.cpp"
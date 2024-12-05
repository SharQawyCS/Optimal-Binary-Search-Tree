/**
 * @file main.cpp
 * @brief Entry point for the Optimal Binary Search Tree (OBST) project.
 *
 * This file initializes and runs the OBST application. It demonstrates how to compute
 * the OBST using given probabilities and labels using DP, providing an interactive educational
 * tool for understanding OBST concepts.
 */

#include <iostream>
#include "Vector.h" // Custom vector class used for dynamic arrays.
#include "OBST.h"   // Contains the OBST algorithm and related logic.
#include "Tree.h"   // Handles tree structure and visualization.

/**
 * @brief Main function for testing the Optimal Binary Search Tree (OBST) application.
 *
 * This function performs the following steps:
 * 1. Initializes data for probabilities and node labels.
 * 2. Calls the OBST algorithm to compute the tree structure and related metrics.
 * 3. Displays the resulting tree structure and outputs the execution results.
 *
 * @return int Exit code (0 for success).
 */
int main()
{
  std::cout << "==== Optimal Binary Search Tree Application ====" << std::endl;

  // **INPUT DATA SETUP**
  // Data to be input by the user (hardcoded for simplicity in this implementation).
  int n = 7;                                                          // Number of nodes in the tree.
  Vector<float> p = {0, 0.15, 0.10, 0.05, 0.10, 0.20, 0.10, 0.20};    // Probabilities of successful searches.
  Vector<float> q = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10, 0.05, 0.15}; // Probabilities of unsuccessful searches.

  // Labels for nodes (keys). These represent the values associated with the nodes in the OBST.
  Vector<std::string> labels = {
      "a",
      "b",
      "c",
      "d",
      "e",
      "f",
      "g",
  };

  // **OBST GENERATION**
  // The `OBST::generateTheOBST` function computes the OBST using:
  // - Probabilities of successful searches (`p`).
  // - Probabilities of unsuccessful searches (`q`).
  // - Node labels (`labels`).
  // The `true` parameter enables intermediate output (debugging or analysis purposes).
  Tree tree = OBST::generateTheOBST(p, q, labels, true);

  // **OUTPUT TREE**
  // Displays the generated tree structure in a readable format.
  std::cout << "MY TREE:" << std::endl;
  tree.displayTree();

  // Completion message to indicate successful execution.
  std::cout << "==== Execution Complete ====" << std::endl;

  return 0; // Exit code 0 indicates success.
}

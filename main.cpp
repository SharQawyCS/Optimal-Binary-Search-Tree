/**
 * @file main.cpp
 * @brief Entry point for the Optimal Binary Search Tree (OBST) project.
 *
 * This file initializes and runs the OBST application. It demonstrates how to compute
 * the OBST using given probabilities and labels using DP, providing an interactive educational
 * tool for understanding OBST concepts.
 */

#include <iostream>
#include "Vector.h"            // Custom vector class used for dynamic arrays.
#include "OBST.h"              // Contains the OBST algorithm and related logic.
#include "Tree.h"              // Handles tree structure and visualization.
#include "TreeVisualization.h" // Generates DOT files for tree visualization.

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
  Vector<float> p = {0, 0.15, 0.10, 0.05, 0.10, 0.20, 0.10, 0.20};    // Probabilities of successful searches. size = n+1
  Vector<float> q = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10, 0.05, 0.15}; // Probabilities of unsuccessful searches. size = n+1

  // Labels for nodes (keys). These represent the values associated with the nodes in the OBST. size = n
  Vector<std::string> labels = {
      "a",
      "b",
      "c",
      "d",
      "e",
      "f",
      "g",
  };

  // ? Test case 1
  // int n = 30;
  // Vector<float> p = {
  //     0.0, 0.10, 0.15, 0.10, 0.05, 0.20, 0.15, 0.05,
  //     0.10, 0.25, 0.20, 0.05, 0.30, 0.10, 0.15, 0.05,
  //     0.25, 0.10, 0.20, 0.15, 0.30, 0.05, 0.20, 0.10,
  //     0.25, 0.15, 0.10, 0.05, 0.15, 0.10, 0.20};
  // Vector<float> q = {
  //     0.05, 0.10, 0.15, 0.05, 0.10, 0.05, 0.20, 0.15,
  //     0.05, 0.10, 0.05, 0.15, 0.10, 0.20, 0.05, 0.15,
  //     0.05, 0.10, 0.15, 0.05, 0.30, 0.10, 0.20, 0.05,
  //     0.10, 0.15, 0.20, 0.10, 0.05, 0.15, 0.10};
  // Vector<std::string> labels = {
  //     "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
  //     "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
  //     "u", "v", "w", "x", "y", "z", "aa", "ab", "ac", "ad"};

  // ? Test case 2
  // int n = 4;
  // Vector<float> p = {0, 4, 2, 6, 3};
  // Vector<float> q = {0, 0, 0, 0, 0};
  // Vector<std::string> labels = {"10", "20", "30", "40"};

  // ? Test case 3
  //  int n = 3;
  //  Vector<float> p = {0, 34, 8, 50};
  //  Vector<float> q = {0, 0, 0, 0};
  //  Vector<std::string> labels = {"10", "12", "20"};

  // **OBST GENERATION**
  // The `OBST::generateTheOBST` function computes the OBST using:
  // - Probabilities of successful searches (`p`).
  // - Probabilities of unsuccessful searches (`q`).
  // - Node labels (`labels`).
  // The `true` parameter enables intermediate output (debugging or analysis purposes).
  Tree tree = OBST::generateTheOBST(p, q, labels, false);

  // **OUTPUT TREE**
  // Displays the generated tree structure in a readable format.
  std::cout << "MY TREE:" << std::endl;
  tree.displayTree();

  // **VISUALIZATION**
  // Generates a DOT file for the tree structure and visualizes it as an image.
  const std::string OUTPUT_IMAGE = "tree.png";
  const std::string DOT_FILE = "tree.dot";

  TreeVisualization::visualizeTree(tree, DOT_FILE, OUTPUT_IMAGE, true);

  return 0;
}

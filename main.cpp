/*
 * This project is licensed under the MIT License.
 * See the LICENSE file for details.
 */

/**
 * This project focuses on implementing and visualizing an Optimal Binary Search Tree (OBST),
 * a specialized data structure designed to minimize search costs when access probabilities are known.
 * It includes a dynamic programming algorithm to construct the OBST,
 * ensuring optimal arrangement of keys based on their probabilities.
 * Additionally, the project generates DOT files to visually represent the tree structure,
 * complete with null pointers and node connections, making the OBST easy to analyze and understand.
 */

/**
 * @file main.cpp
 * @brief Entry point for the Optimal Binary Search Tree (OBST) project.
 *
 * This file initializes and runs the OBST application. It demonstrates how to compute
 * the OBST using given probabilities and labels using DP, providing an interactive educational
 * tool for understanding OBST concepts.
 * This project focuses on implementing and visualizing an Optimal Binary Search Tree (OBST),
 * a specialized data structure designed to minimize search costs when access probabilities are known.
 * It includes a dynamic programming algorithm to construct the OBST,
 * ensuring optimal arrangement of keys based on their probabilities.
 * Additionally, the project generates DOT files to visually represent the tree structure,
 * complete with null pointers and node connections, making the OBST easy to analyze and understand.
 */

#include <iostream>
#include <string>
#include "Vector.h"            // Custom vector class used for dynamic arrays.
#include "OBST.h"              // Contains the OBST algorithm and related logic.
#include "Tree.h"              // Handles tree structure and visualization.
#include "TreeVisualization.h" // Generates DOT files for tree visualization.
#include "CLI/CLI.h"           // Command-line interface for user interaction.
#include "Settings.h"          // Handles reading settings from a file.

// Default settings
std::string Settings::DOT_FILE = "df_obst.dot";
std::string Settings::OUTPUT_IMAGE = "df_obst.png";
std::string Settings::GRAPH_LABEL = "✨ df The Optimal Binary Search Tree ✨";
int Settings::LABEL_FONTSIZE = 16;
std::string Settings::NODE_SHAPE = "circle";
std::string Settings::NODE_STYLE = "filled";
std::string Settings::NODE_COLOR = "lightblue";
std::string Settings::NODE_FONTCOLOR = "black";
int Settings::NODE_FONTSIZE = 12;
std::string Settings::EDGE_COLOR = "gray";

/**
 * @brief Main function for running and testing the Optimal Binary Search Tree (OBST) application.
 *
 * This function performs the following steps:
 * 1. Initializes data for probabilities and node labels.
 * 2. Calls the OBST algorithm to compute the tree structure and related metrics.
 * 3. Displays the resulting tree structure and outputs the execution results.
 */
int main()
{
  Utils::clearTerminal();

  std::string SETTINGS_FILE = "settings.txt";
  Settings::getSettings(SETTINGS_FILE);

  CLI cli;
  cli.show();

  Settings::setSettings(SETTINGS_FILE);

  return 0;
}

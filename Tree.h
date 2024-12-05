#pragma once

#include <iostream>
#include <iomanip>
#include "TreeNode.h"
#include <queue>
#include <sstream>

class Tree
{
private:
  TreeNode *root;

  // Helper function to display the tree
  void displayTreeHelper(TreeNode *node, int depth = 0) const
  {
    if (!node)
      return;

    // Display right subtree
    displayTreeHelper(node->right, depth + 1);

    // Display current node with indentation
    std::cout << std::setw(4 * depth) << "" << node->key << std::endl;

    // Display left subtree
    displayTreeHelper(node->left, depth + 1);
  }

  // Helper function for horizontal tree display
  void horizontalTreeHelper(TreeNode *node, int level, std::vector<std::string> &lines, int &max_width) const
  {
    if (!node)
      return;

    // Create space for the current level if it doesn't exist
    if (lines.size() <= level)
      lines.emplace_back("");

    // Add the node key to the current level
    std::ostringstream oss;
    oss << "[" << node->key << "]";
    std::string node_str = oss.str();
    max_width = std::max(max_width, static_cast<int>(node_str.size()));
    lines[level] += node_str + " ";

    // Process left and right children
    horizontalTreeHelper(node->left, level + 1, lines, max_width);
    horizontalTreeHelper(node->right, level + 1, lines, max_width);
  }

  // Helper function to delete the tree (for cleanup)
  void deleteTree(TreeNode *node)
  {
    if (!node)
      return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
  }

public:
  Tree() : root(nullptr) {}

  ~Tree()
  {
    deleteTree(root);
  }

  // Set the root of the tree
  void setRoot(TreeNode *node)
  {
    root = node;
  }

  // Display tree in sideways format
  void displayTree() const
  {
    std::cout << "\nSideways Tree View:\n";
    displayTreeHelper(root);
  }

  // Display tree in horizontal layered format
  void displayHorizontalTree() const
  {
    std::cout << "\nHorizontal Tree View:\n";
    std::vector<std::string> lines;
    int max_width = 0;
    horizontalTreeHelper(root, 0, lines, max_width);

    // Output each level
    for (const auto &line : lines)
      std::cout << line << std::endl;
  }
};
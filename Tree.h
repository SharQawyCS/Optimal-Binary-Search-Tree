#pragma once

#include <iostream>
#include <iomanip>
#include "TreeNode.h"

#include <fstream>
#include <stdexcept>

/**
 * @class Tree
 * A class to represent a binary tree and provide utilities like displaying
 * the tree structure and cleaning up memory.
 */
class Tree
{
private:
  TreeNode *root; // Pointer to the root of the tree

  /**
   * @brief Helper function to display the tree in a sideways format.
   *
   * This function prints the tree starting from the rightmost node
   * (to represent the tree as if it's lying sideways).
   *
   * @param node Current node being processed.
   * @param depth Current depth in the tree (used for indentation).
   */
  void displayTreeHelper(TreeNode *node, int depth = 0) const
  {
    if (!node)
      return;

    // Display the right subtree first
    displayTreeHelper(node->right, depth + 1);

    // Print the current node with indentation proportional to depth
    std::cout << std::setw(2 * depth) << "" << node->key << std::endl;

    // Display the left subtree
    displayTreeHelper(node->left, depth + 1);
  }

  /**
   * @brief Helper function to delete the tree and free memory.
   *
   * This function is used to recursively delete all nodes in the tree.
   *
   * @param node Current node being processed for deletion.
   */
  void deleteTree(TreeNode *node)
  {
    if (!node)
      return;

    // Recursively delete left and right subtrees
    deleteTree(node->left);
    deleteTree(node->right);

    // Delete the current node
    delete node;
  }

public:
  /**
   * @brief Default constructor for the Tree class.
   *
   * Initializes the tree with an empty root.
   */
  Tree() : root(nullptr) {}

  /**
   * @brief Destructor for the Tree class.
   *
   * Automatically deletes all nodes in the tree to prevent memory leaks.
   */
  ~Tree()
  {
    deleteTree(root);
  }

  /**
   * @brief Set the root node of the tree.
   *
   * This function assigns a node to be the root of the tree.
   *
   * @param node Pointer to the new root node.
   */
  void setRoot(TreeNode *node)
  {
    root = node;
  }

  /**
   * @brief Get the root node of the tree.
   *
   * This function returns the root node of the tree.
   *
   * @return Pointer to the root node.
   */
  TreeNode *getRoot() const
  {
    return root;
  }

  /**
   * @brief Display the tree structure in a sideways format.
   *
   * This function provides a visual representation of the tree,
   * showing the root at the left and branches going down.
   */
  void displayTree() const
  {
    displayTreeHelper(root);
  }

  /**
   * @brief Assign the structure of another tree to this tree.
   *
   * This function clears the current tree and deep-copies the structure
   * of the given tree.
   *
   * @param otherTree The tree to copy from.
   */
  void assign(const Tree &otherTree)
  {
    // Clear the current tree
    deleteTree(root);

    // Deep copy the root of the other tree
    root = copySubtree(otherTree.root);
  }

  /**
   * @brief Helper function to copy a subtree.
   *
   * This function recursively copies the structure of a subtree.
   *
   * @param node The root of the subtree to copy.
   * @return A pointer to the root of the new subtree.
   */
  TreeNode *copySubtree(TreeNode *node) const
  {
    if (!node)
      return nullptr;

    // Create a new node with the same key
    TreeNode *newNode = new TreeNode(node->key);

    // Recursively copy the left and right children
    newNode->left = copySubtree(node->left);
    newNode->right = copySubtree(node->right);

    return newNode;
  }
};

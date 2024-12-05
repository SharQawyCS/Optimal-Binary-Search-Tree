#pragma once

#include <iostream>
#include <string>

class TreeNode
{
public:
  std::string key;
  TreeNode *left, *right;

  TreeNode(const std::string &key) : key(key), left(nullptr), right(nullptr) {}
};

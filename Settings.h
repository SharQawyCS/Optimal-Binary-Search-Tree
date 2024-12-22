#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class Settings
{
private:
  // Static members
  static std::string DOT_FILE;
  static std::string OUTPUT_IMAGE;

  // Graph settings
  static std::string GRAPH_LABEL;
  static int LABEL_FONTSIZE;

  // Node settings
  static std::string NODE_SHAPE;
  static std::string NODE_STYLE;
  static std::string NODE_COLOR;
  static std::string NODE_FONTCOLOR;
  static int NODE_FONTSIZE;

  // Edge settings
  static std::string EDGE_COLOR;

public:
  // Getters
  static std::string getDotFile() { return DOT_FILE; }
  static std::string getOutputImage() { return OUTPUT_IMAGE; }

  static std::string getGraphLabel() { return GRAPH_LABEL; }
  static int getGraphFontSize() { return LABEL_FONTSIZE; }

  static std::string getNodeShape() { return NODE_SHAPE; }
  static std::string getNodeStyle() { return NODE_STYLE; }
  static std::string getNodeColor() { return NODE_COLOR; }
  static std::string getNodeFontColor() { return NODE_FONTCOLOR; }
  static int getNodeFontSize() { return NODE_FONTSIZE; }

  static std::string getEdgeColor() { return EDGE_COLOR; }

  // Setters
  static void setDotFile(const std::string &dotFile) { DOT_FILE = dotFile; }
  static void setOutputImage(const std::string &outputImage) { OUTPUT_IMAGE = outputImage; }

  static void setGraphLabel(const std::string &label) { GRAPH_LABEL = label; }
  static void setGraphFontSize(int fontSize) { LABEL_FONTSIZE = fontSize; }

  static void setNodeShape(const std::string &shape) { NODE_SHAPE = shape; }
  static void setNodeStyle(const std::string &style) { NODE_STYLE = style; }
  static void setNodeColor(const std::string &color) { NODE_COLOR = color; }
  static void setNodeFontColor(const std::string &fontColor) { NODE_FONTCOLOR = fontColor; }
  static void setNodeFontSize(int fontSize) { NODE_FONTSIZE = fontSize; }

  static void setEdgeColor(const std::string &color) { EDGE_COLOR = color; }

  // Function to read settings from a file
  static void getSettings(const std::string &filename)
  {
    std::ifstream file(filename);
    if (!file.is_open())
    {
      std::cerr << "Could not open settings file: " << filename << std::endl;
      std::cout << "Using default settings..." << std::endl;

      std::cout << "press any key to continue" << std::endl;
      std::cin.get();

      return;
    }

    std::string line;
    while (std::getline(file, line))
    {
      std::stringstream ss(line);
      std::string key, value;

      if (std::getline(ss, key, '=') && std::getline(ss, value))
      {
        // Trim whitespace (if any)
        key.erase(key.find_last_not_of(" \n\r\t") + 1);
        value.erase(value.find_last_not_of(" \n\r\t") + 1);

        // Set the appropriate setting based on the key
        if (key == "DOT_FILE")
        {
          DOT_FILE = value;
        }
        else if (key == "OUTPUT_IMAGE")
        {
          OUTPUT_IMAGE = value;
        }
        else if (key == "GRAPH_LABEL")
        {
          GRAPH_LABEL = value;
        }
        else if (key == "LABEL_FONTSIZE")
        {
          LABEL_FONTSIZE = std::stoi(value);
        }
        else if (key == "NODE_SHAPE")
        {
          NODE_SHAPE = value;
        }
        else if (key == "NODE_STYLE")
        {
          NODE_STYLE = value;
        }
        else if (key == "NODE_COLOR")
        {
          NODE_COLOR = value;
        }
        else if (key == "NODE_FONTCOLOR")
        {
          NODE_FONTCOLOR = value;
        }
        else if (key == "NODE_FONTSIZE")
        {
          NODE_FONTSIZE = std::stoi(value);
        }
        else if (key == "EDGE_COLOR")
        {
          EDGE_COLOR = value;
        }
      }
    }
    file.close();
  }

  // Function to write settings to a file
  static void setSettings(const std::string &filename)
  {
    std::ofstream file(filename);
    if (!file.is_open())
    {
      std::cerr << "Could not open settings file for writing: " << filename << std::endl;
      return;
    }

    file << "DOT_FILE=" << DOT_FILE << "\n";
    file << "OUTPUT_IMAGE=" << OUTPUT_IMAGE << "\n";
    file << "GRAPH_LABEL=" << GRAPH_LABEL << "\n";
    file << "LABEL_FONTSIZE=" << LABEL_FONTSIZE << "\n";
    file << "NODE_SHAPE=" << NODE_SHAPE << "\n";
    file << "NODE_STYLE=" << NODE_STYLE << "\n";
    file << "NODE_COLOR=" << NODE_COLOR << "\n";
    file << "NODE_FONTCOLOR=" << NODE_FONTCOLOR << "\n";
    file << "NODE_FONTSIZE=" << NODE_FONTSIZE << "\n";
    file << "EDGE_COLOR=" << EDGE_COLOR << "\n";

    file.close();
    std::cout << "Settings saved to " << filename << std::endl;
  }
};
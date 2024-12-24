**The OBST Project**

| El-Sharqawy Wael El-Sharqawy | 23P0360 |
| --- | --- |
| Nagy Ahmed | **23P0365** |
| Ahmed Mostafa | **23P0375** |
| Abdelrhman Mohammed Mahmoud | **23P0370** |
| Youssef Maged Morees | **2301081** |

Submitted to:

- **Dr. Ashraf Abdel-Raouf**
- **Eng. Ahmed Salama**
- **Eng. Nada Amr**

ENG – ASU – CAIE

Dec 22, 2024

## Overview

The Optimal Binary Search Tree (OBST) project is a C++ application designed for constructing and analyzing OBSTs interactively via a Command-Line Interface (CLI). It minimizes search costs based on provided probabilities, ensuring an efficient structure for search operations. Users can create, edit, visualize, and analyze OBSTs, along with viewing derived cost tables and probabilities.

## Features

###

Main Menu

The CLI provides a user-friendly menu to navigate through the features:


1. Edit Tree

Allows users to create or modify the OBST structure.

### Display Tree

Prints the constructed **OBST** in a **textual** format, showing parent-child relationships for each node.

### 3\. Visualize Tree

Generates a graphical representation of the OBST using **Graphviz**:

- Outputs a **.dot** file.
- Converts it into an **PNG** image.
- Displays the image for better understanding.

### 4\. Analyze Tree

Provides insights into the tree:

- **Total Cost**: Displays the cost of searching within the OBST.
- **Efficiency Metrics**: Calculates and presents efficiency statistics.

### 5\. Display Derived Tables

Displays the dynamic programming tables used during OBST construction:

- **Cost Table**: Shows the cost of all possible subtrees.
- **Weight Table**: Displays cumulative weights for the ranges.
- **Root Table**: Lists the roots of the optimal subtrees.

### 6\. Display Entered Data

Shows the input data in a clean tabular format:

- **Data Labels**: List of keys (nodes).
- **Probabilities (**p**)**: Probabilities of successful searches.
- **Probabilities (**q**)**: Probabilities of unsuccessful searches.

### 0\. Exit

Terminates the program.

## How It Works

### Create or Edit the Tree

- Define data labels and probabilities.
- The program validates input and builds the OBST using dynamic programming.

### Analyze the Tree

- View the cost matrix and identify the minimal search cost.
- Check the efficiency of the OBST structure.

### Visualize the Tree

- Generate a .**dot** file and visualize it graphically with Graphviz.

### Inspect Derived Tables

- Analyze the cost, weight, and root matrices to understand the OBST construction process.

## Dependencies

### 1\. Custom Vector Class

The project utilizes a custom Vector class for efficient dynamic array operations.

### Settings Class

The **Settings** class allows users to customize tree visualization properties (e.g., node color, shape, font size) by modifying an external **settings.txt** file. It enables easy personalization and persists changes across sessions. For missing files, defaults are automatically generated. This integrates seamlessly into the **Visualize Tree** feature, enhancing the clarity and usability of tree representations.

### 3\. Graphviz

Required for generating graphical representations of the OBST. The **.dot** files are processed into **PNG**.

### 4\. C++ Standard Library

**Used for:**

- Algorithms
- File I/O
- Dynamic memory management
- Exception handling

## Accessing the Source Code

The complete source code for the **Optimal Binary Search Tree CLI** project, including all dependencies, documentation, and the **settings.txt** file for customization, is available on **GitHub**. To access the repository, follow this link: [**Optimal-Binary-Search-Tree**](https://github.com/SharQawyCS/Optimal-Binary-Search-Tree)

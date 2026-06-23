# Huffman Coding Visualizer (C++)

## Overview

This project implements the Huffman Coding algorithm in C++ and visualizes the generated Huffman Tree in the console. Huffman Coding is a lossless data compression technique that assigns shorter binary codes to frequently occurring characters and longer codes to less frequent characters.

The project demonstrates several important Data Structures and Algorithms concepts, including:

* Priority Queue (Min Heap)

* Binary Trees

* Greedy Algorithms

* Hash Maps

* Recursion

* Data Compression

---

## Features

* Read text input from a file

* Calculate character frequencies

* Build a Huffman Tree using a Min Heap

* Generate Huffman Codes for each character

* Encode text into binary format

* Decode encoded text back to original form

* Display compression statistics

* Visualize Huffman Tree in console

---

## Project Structure

```

Huffman-Coding-Visualizer/

│

├── main.cpp

├── dataset.txt

├── README.md

 ```

---

## Sample Dataset

Create a file named `dataset.txt` and add the following content:

```text

Data Structures and Algorithms are fundamental concepts

for software engineering and competitive programming.

Huffman coding is a lossless data compression algorithm.

It assigns shorter binary codes to more frequent characters

and longer codes to less frequent characters.

The quick brown fox jumps over the lazy dog.

Machine learning and artificial intelligence generate

large amounts of data that often require compression.

```
---

## Compilation

Using g++:

```bash

g++ main.cpp -o huffman

```
Run:

```bash

./huffman

```
For Windows:
```bash

g++ main.cpp -o huffman.exe

huffman.exe

```
---
## Example Output
```text

====== HUFFMAN CODES ======



a -> 010

e -> 111

t -> 1010

[space] -> 100

Original Size : 1360 bits

Compressed Size : 720 bits

Compression Ratio : 52.94%

Decoded Correctly : YES

```
---
## Algorithm
### Step 1: Frequency Calculation

Count occurrences of every character in the input text.

### Step 2: Build Min Heap

Insert each character and its frequency into a Min Heap.

### Step 3: Construct Huffman Tree

Repeatedly:

1. Remove two nodes with minimum frequencies.

2. Create a new internal node with combined frequency.

3. Insert the new node back into the heap.

Continue until only one node remains.

### Step 4: Generate Codes

Traverse the tree:

* Left Edge → 0

* Right Edge → 1

The generated path becomes the Huffman Code.


### Step 5: Encode

Replace each character with its Huffman Code.

### Step 6: Decode

Traverse the Huffman Tree according to encoded bits to recover the original text.

---

## Time Complexity


| Operation          | Complexity |

| ------------------ | ---------- |

| Frequency Counting | O(n)       |

| Build Heap         | O(k log k) |

| Build Huffman Tree | O(k log k) |

| Generate Codes     | O(k)       |

| Encoding           | O(n)       |

| Decoding           | O(n)       |


Where:


* n = length of text

* k = number of unique characters


---

## DSA Concepts Covered



* Greedy Algorithm

* Priority Queue

* Binary Tree

* DFS Traversal

* Recursion

* Hash Table

* String Manipulation
---

## Future Enhancements

* Graphical Tree Visualization using SFML

* Graphviz Integration

* GUI Interface using Qt

* Real-time Compression Statistics

* Support for Binary Files

* Animation of Heap Operations

---
## Learning Outcomes

After completing this project, you will understand:

* How Huffman Compression works

* Tree-based encoding techniques

* Greedy algorithm design

* Priority Queue applications

* Lossless data compression concepts

---
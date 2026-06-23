#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

// Huffman Tree Node
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Comparator for Min Heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Generate Huffman Codes
void generateCodes(Node* root,
                   string code,
                   unordered_map<char, string>& huffmanCode) {

    if (!root)
        return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Encode text
string encode(string text,
              unordered_map<char, string>& huffmanCode) {

    string encoded = "";

    for (char ch : text)
        encoded += huffmanCode[ch];

    return encoded;
}

// Decode text
string decode(Node* root, string encoded) {

    string decoded = "";

    Node* curr = root;

    for (char bit : encoded) {

        if (bit == '0')
            curr = curr->left;
        else
            curr = curr->right;

        if (!curr->left && !curr->right) {
            decoded += curr->ch;
            curr = root;
        }
    }

    return decoded;
}

// Print tree sideways
void printTree(Node* root, int space = 0) {

    if (!root)
        return;

    space += 8;

    printTree(root->right, space);

    cout << endl;

    for (int i = 8; i < space; i++)
        cout << " ";

    if (root->ch == '\0')
        cout << "*(" << root->freq << ")";
    else
        cout << root->ch << "(" << root->freq << ")";

    cout << endl;

    printTree(root->left, space);
}

// Build Huffman Tree
Node* buildHuffmanTree(string text) {

    unordered_map<char, int> freq;

    for (char ch : text)
        freq[ch]++;

    priority_queue<Node*,
                   vector<Node*>,
                   Compare> pq;

    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) {

        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* merged =
            new Node('\0',
                     left->freq + right->freq);

        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    return pq.top();
}

int main() {

    string text =
        "Data Structures and Algorithms are fundamental concepts "
        "for software engineering and competitive programming. "
        "Huffman coding is a lossless data compression algorithm.";

    Node* root = buildHuffmanTree(text);

    unordered_map<char, string> huffmanCode;

    generateCodes(root, "", huffmanCode);

    cout << "====== HUFFMAN CODES ======\n\n";

    for (auto pair : huffmanCode) {

        if (pair.first == ' ')
            cout << "[space]";
        else
            cout << pair.first;

        cout << " -> "
             << pair.second
             << endl;
    }

    string encoded = encode(text, huffmanCode);

    cout << "\nOriginal Size : "
         << text.size() * 8
         << " bits\n";

    cout << "Compressed Size : "
         << encoded.size()
         << " bits\n";

    cout << "\nCompression Ratio : "
         << (double)encoded.size() /
                (text.size() * 8) * 100
         << "%\n";

    string decoded =
        decode(root, encoded);

    cout << "\nDecoded Correctly: "
         << (decoded == text ? "YES" : "NO")
         << endl;

    cout << "\n====== HUFFMAN TREE ======\n";

    printTree(root);

    return 0;
}
#include <bits/stdc++.h>
#include <cmath>
#include "Input.cpp"
#include "DCT_Round.cpp"

using namespace std;

// A Huffman tree node
struct Node {
    int ch;
    int freq;
    Node *left, *right;

    Node(int ch, int freq) {
        left = right = nullptr;
        this->ch = ch;
        this->freq = freq;
    }
};

// Comparison object to be used to order the heap
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Utility function to print Huffman codes and store them in a map
void storeCodes(struct Node* root, string str, unordered_map<int, string>& huffmanCode) {
    if (!root)
        return;

    if (root->ch != '$')
        huffmanCode[root->ch] = str;

    storeCodes(root->left, str + "0", huffmanCode);
    storeCodes(root->right, str + "1", huffmanCode);
}

// The main function that builds a Huffman Tree and stores codes in a map
void HuffmanCodes(vector<pair<int, int>>& vec, unordered_map<int, string>& huffmanCode) {
    // Aggregate frequencies of repeating symbols
    unordered_map<int, int> freqMap;
    for (auto& pair : vec) {
        freqMap[pair.first] += pair.second;
    }

    struct Node *left, *right, *top;

    // Create a min heap & inserts all characters of data[]
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (auto& pair : freqMap) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {
        // Extract the two minimum freq items from min heap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with frequency equal to the sum of the two nodes frequencies.
        top = new Node('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // Store Huffman codes using the Huffman tree built above
    storeCodes(minHeap.top(), "", huffmanCode);
}

// Function to calculate the size of the original data
int calculateOriginalSize(vector<pair<int, int>>& vec) {
    int size = 0;
    for (auto& pair : vec) {
        size += pair.second * 8; // Assuming each character is 8 bits
    }
    return size;
}

// Function to calculate the size of the compressed data
int calculateCompressedSize(vector<pair<int, int>>& vec, unordered_map<int, string>& huffmanCode) {
    int size = 0;
    for (auto& pair : vec) {
        size += pair.second * huffmanCode[pair.first].length();
    }
    return size;
}

int main(){
    int startRow = 0;
    int startCol = 0;
    double subMatrix[8][8];

    for(int startrow = 0; startrow < row; startrow = startrow + 8){
        for(int startCol = 0; startCol < col; startCol = startCol + 8){
            for(int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    subMatrix[i][j] = matrix[startRow + i][startCol + j];
                }
            }

            dctTransform(subMatrix, dct);
        }
    }

    unordered_map<int, string> huffmanCode;

    HuffmanCodes(encoded, huffmanCode);

    int originalSize = calculateOriginalSize(encoded);
    int compressedSize = calculateCompressedSize(encoded, huffmanCode);

    double compressionRatio = (double)originalSize / compressedSize;

    cout << "Original Size: " << originalSize << " bits\n";
    cout << "Compressed Size: " << compressedSize << " bits\n";
    cout << "Compression Ratio: " << compressionRatio << "\n";

    return 0;
}

Run "Huff_Comp.cpp" to get the compression ratio of an image whose pixels are defined in "Input.cpp" 
The code implements Discrete Cosine Transform (DCT) followed by Run Length Encoding in a zigzag manner and eventually doing Huffman Coding.
Compression ratio is found out by counting the bits used by huffman codeword divided by the total bits in image, assuming each pixel is 8 bits.

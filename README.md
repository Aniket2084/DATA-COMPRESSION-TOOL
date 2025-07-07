# DATA-COMPRESSION-TOOL

*COMPANY*: CODTECH IT SOLUTIONS

*NAME*: ANIKET KESHRI

*INTERN ID*: CT04DG990

*DOMAIN*: C PROGRAMMING

*DURATION*: 4 WEEKS

*MENTOR*: NEELA SANTOSH

# Run-Length Encoding Summary:
It replaces sequences of the same character (like AAAA) with a single character and its count (4A).

# What does this program do?
It helps you:

Compress a text file using Run-Length Encoding.

Decompress a previously compressed file back to the original.

# What is Run-Length Encoding (RLE)?
RLE is a simple way to compress data:

If a letter repeats multiple times, we store:
number of times + the letter.

For example:

Original: AAAABBBCCDAA

Compressed: 4A3B2C1D2A

# main() function:
Asks the user to:

Choose between compression (1) or decompression (2).

Enter the input and output file paths.

Calls either compressFile() or decompressFile() based on the user's choice.

# compressFile() function:
This function compresses the file.

What it does:
Opens the input file to read and output file to write.

Reads characters one by one.

Counts how many times a character repeats in a row.

Writes the count and the character to the output file.

*Example:*
If the file contains: AAAABBB,
It writes: 4A3B to the compressed file.

# decompressFile() function:
This function decompresses the file back to normal text.

What it does:
Opens the compressed file to read and output file to write.

Reads a number and a character (like 4A).

Writes the character that many times to the output.

*Example:*
If the file contains: 4A3B,
It writes: AAAABBB to the decompressed file.

# Example Workflow
You run the program.

You choose to compress.

You give the input file (like input.txt) and output file name (like compressed.txt).

The program compresses the content using RLE.

You can then run the program again to decompress and recover the original text.

#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Temporary node for counting character frequencies
typedef struct {
	unsigned char uch;			// Unsigned characters in units of 8bits
	unsigned long weight;		// Frequency of occurrence of each class (differentiated by binary code)
} TmpNode;

// Huffman Tree Node
typedef struct {
	unsigned char uch;				// Unsigned characters in units of 8bits
	unsigned long weight;			// Frequency of occurrence of each class (differentiated by binary code)
	char *code;						// Huffman coding for characters (dynamic allocation of storage space)
	int parent, lchild, rchild;		// Define parents and left and right children
} HufNode, *HufTree;


// Select the two nodes, the smallest and the second, to establish a Huffman tree call.
void TwoMinOfNode(HufNode *huf_tree, unsigned int n, int *s1, int *s2);

// Building a Huffman tree
void CreateTree(HufNode *huf_tree, unsigned int char_kinds, unsigned int node_num);

// Generating Huffman coding
void HufCode(HufNode *huf_tree, unsigned char_kinds);

// Compression function
int compress(char *ifname, char *ofname);

// extract function
int extract(char *ifname, char *ofname);

#endif


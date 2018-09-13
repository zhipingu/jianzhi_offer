#include"helper.h"

//fread wrapper function
void Fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    if(fread(ptr,size,nmemb,stream));
}

//fwrite wrapper function
void Fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    if(fwrite(ptr,size,nmemb,stream)!=nmemb)
    {
        printf("fwrite error\n");
        exit(1);
    }
}

//Select the two nodes of the smallest and the second to establish a Huffman tree call
void TwoMinOfNode(HufNode *huf_tree, unsigned int n, int *s1, int *s2)
{
	// Find the smallest
	unsigned int i;
	unsigned long min = ULONG_MAX;

    if(s1==NULL || s2==NULL)
    {
        printf("TwoMinOfNode input s1,s2 NULL\n");
        exit(1);
    }
    
	for(i = 0; i < n; ++i)           
		if(huf_tree[i].parent == 0 && huf_tree[i].weight < min)
		{
			min = huf_tree[i].weight;
			*s1 = i;
		}
		huf_tree[*s1].parent=1;   // Mark this node has been selected

	// find the second
	min=ULONG_MAX;
	for(i = 0; i < n; ++i)            
		if(huf_tree[i].parent == 0 && huf_tree[i].weight < min)
		{
			min = huf_tree[i].weight;
			*s2 = i;
		}
} 

// Building a Huffman tree
void CreateTree(HufNode *huf_tree, unsigned int char_kinds, unsigned int node_num)
{
	unsigned int i;
	int s1=0, s2=0;
	for(i = char_kinds; i < node_num; ++i)  
	{ 
		TwoMinOfNode(huf_tree, i, &s1, &s2);		// Select the smallest two nodes
		huf_tree[s1].parent = huf_tree[s2].parent = i; 
		huf_tree[i].lchild = s1; 
		huf_tree[i].rchild = s2; 
		huf_tree[i].weight = huf_tree[s1].weight + huf_tree[s2].weight; 
	} 
}

// Generating Huffman coding
void HufCode(HufNode *huf_tree, unsigned char_kinds)
{
	unsigned int i;
	int cur, next, index;
	char *code_tmp = (char *)malloc(256*sizeof(char));		// Temporary storage code, up to 256 leaves, encoding length is not more than 255
	code_tmp[256-1] = '\0'; 

	for(i = 0; i < char_kinds; ++i) 
	{
		index = 256-1;	// Encoding temporary space index initialization

		// Reverse traversal from leaf to root
		for(cur = i, next = huf_tree[i].parent; next != 0; 
			cur = next, next = huf_tree[next].parent)  
			if(huf_tree[next].lchild == cur) 
				code_tmp[--index] = '0';	// left~{!.~}0~{!/~}
			else 
				code_tmp[--index] = '1';	// right~{!.~}1~{!/~}
		huf_tree[i].code = (char *)malloc((256-index)*sizeof(char));			// Dynamically allocate storage space for the ith character encoding 
		strcpy(huf_tree[i].code, &code_tmp[index]);     // Forward save encoding to the corresponding node in the tree node
	} 
	free(code_tmp);		// Release coded temporary space
}

// compress function
int compress(char *ifname, char *ofname)
{
	unsigned int i, j;
	unsigned int char_kinds;		// Character type
	unsigned char char_temp;		// Temporary 8bits character
	unsigned long file_len = 0;
	FILE *infile, *outfile;
	TmpNode node_temp;
	unsigned int node_num;
	HufTree huf_tree;
	char code_buf[256] = "\0";		// Pending code buffer
	unsigned int code_len;
	/*
	** Dynamically allocate 256 nodes, temporarily store character frequency~{#,~}
	** Release and release immediately after copying to the tree node
	*/
	TmpNode *tmp_nodes =(TmpNode *)malloc(256*sizeof(TmpNode));		

	// Initialize the staging node
	for(i = 0; i < 256; ++i)
	{
		tmp_nodes[i].weight = 0;
		tmp_nodes[i].uch = (unsigned char)i;		// 256 subscripts of an array correspond to 256 characters
	}

	// Traverse the file to get the character frequency
	infile = fopen(ifname, "rb");
	// Determine if the input file exists
	if (infile == NULL)
		return -1;
	Fread((char *)&char_temp, sizeof(unsigned char), 1, infile);		// read a char
	while(!feof(infile))
	{
		++tmp_nodes[char_temp].weight;	//Count the weight of the corresponding character of the subscript, and use the random access of the array to quickly count the character frequency.
		++file_len;
		Fread((char *)&char_temp, sizeof(unsigned char), 1, infile);		// read a char
	}
	fclose(infile);

	// Sort, put the frequency to zero, put the last, cull
	for(i = 0; i < 256-1; ++i)           
		for(j = i+1; j < 256; ++j)
			if(tmp_nodes[i].weight < tmp_nodes[j].weight)
			{
				node_temp = tmp_nodes[i];
				tmp_nodes[i] = tmp_nodes[j];
				tmp_nodes[j] = node_temp;
			}

	// Count the actual character type (the number of occurrences is not 0)
	for(i = 0; i < 256; ++i)
		if(tmp_nodes[i].weight == 0) 
			break;
	char_kinds = i;

	if (char_kinds == 1)
	{
		outfile = fopen(ofname, "wb");					// Open the file that will be generated after compression
		Fwrite((char *)&char_kinds, sizeof(unsigned int), 1, outfile);		// Write character type
		Fwrite((char *)&tmp_nodes[0].uch, sizeof(unsigned char), 1, outfile);		// Write unique characters
		Fwrite((char *)&tmp_nodes[0].weight, sizeof(unsigned long), 1, outfile);		//Write character frequency, which is the file length
		free(tmp_nodes);
		fclose(outfile);
	}
	else
	{
		node_num = 2 * char_kinds - 1;		// Calculate the number of nodes required to establish a Huffman tree based on the number of characters 
		huf_tree = (HufNode *)malloc(node_num*sizeof(HufNode));		// Dynamically establish the required nodes of the Huffman tree    

		// Char_kinds nodes before initialization
		for(i = 0; i < char_kinds; ++i) 
		{ 
			// Copy the character and frequency of the temporary node to the tree node
			huf_tree[i].uch = tmp_nodes[i].uch; 
			huf_tree[i].weight = tmp_nodes[i].weight;
			huf_tree[i].parent = 0; 
		}	
		free(tmp_nodes); // Release the temporary storage area of character frequency statistics

		// Node_num-char_kins nodes after initialization
		for(; i < node_num; ++i) 
			huf_tree[i].parent = 0; 

		CreateTree(huf_tree, char_kinds, node_num);		// Creating a Huffman tree

		HufCode(huf_tree, char_kinds);		// Generating Huffman coding

		// Write characters and corresponding weights to reconstruct the Huffman tree when decompressing
		outfile = fopen(ofname, "wb");					// Open the file that will be generated after compression
		Fwrite((char *)&char_kinds, sizeof(unsigned int), 1, outfile);		// Write character type
		for(i = 0; i < char_kinds; ++i)
		{
			Fwrite((char *)&huf_tree[i].uch, sizeof(unsigned char), 1, outfile);			//Write characters (sorted, unchanged after reading)
			Fwrite((char *)&huf_tree[i].weight, sizeof(unsigned long), 1, outfile);		// Write character corresponding weight
		}

		// File length and character encoding are written immediately after the character and weight information
		Fwrite((char *)&file_len, sizeof(unsigned long), 1, outfile);		// Write file length
		infile = fopen(ifname, "rb");		// Open the file to be compressed in binary form
		Fread((char *)&char_temp, sizeof(unsigned char), 1, infile);     // Read 8bits each time
		while(!feof(infile))
		{
			// Matching character corresponding code
			for(i = 0; i < char_kinds; ++i)
				if(char_temp == huf_tree[i].uch)
					strcat(code_buf, huf_tree[i].code);

			// 8 bits (one byte length) as the processing unit
			while(strlen(code_buf) >= 8)
			{
				char_temp = '\0';		// Clear the character temporary storage space and change to the temporary character corresponding code
				for(i = 0; i < 8; ++i)
				{
					char_temp <<= 1;		//Move one bit to the left to make room for the next bit
					if(code_buf[i] == '1')
						char_temp |= 1;		// When the encoding is "1", it is added to the lowest bit of the byte by the or operator.
				}
				Fwrite((char *)&char_temp, sizeof(unsigned char), 1, outfile);		// Store the byte corresponding code in the file
				strcpy(code_buf, code_buf+8);		// Code Cache removes the first eight bits processed
			}
			Fread((char *)&char_temp, sizeof(unsigned char), 1, infile);     // Read 8bits each time
		}
		// Processing the final less than 8bits encoding
		code_len = strlen(code_buf);
		if(code_len > 0)
		{
			char_temp = '\0';		
			for(i = 0; i < code_len; ++i)
			{
				char_temp <<= 1;		
				if(code_buf[i] == '1')
					char_temp |= 1;
			}
			char_temp <<= 8-code_len;       //Move the encoded field from the tail to the high byte
			Fwrite((char *)&char_temp, sizeof(unsigned char), 1, outfile);       // Save the last byte
		}

		// close file
		fclose(infile);
		fclose(outfile);

		// Free memory
		for(i = 0; i < char_kinds; ++i)
			free(huf_tree[i].code);
		free(huf_tree);
	}
    return 0;
}//compress


// extract function
int extract(char *ifname, char *ofname)
{
	unsigned int i;
	unsigned long file_len;
	unsigned long writen_len = 0;		// Control file write length
	FILE *infile, *outfile;
	unsigned int char_kinds;		// Storage character type
	unsigned int node_num;
	HufTree huf_tree;
	unsigned char code_temp;		// Temporary 8bits encoding
	unsigned int root;		// Save the root node index for matching encoding

	infile = fopen(ifname, "rb");		// Open compressed file in binary mode
	// Determine if the input file exists
	if (infile == NULL)
		return -1;

	// Read the characters and corresponding codes of the front end of the compressed file for reconstructing the Huffman tree
	Fread((char *)&char_kinds, sizeof(unsigned int), 1, infile);     // Number of characters read
	if (char_kinds == 1)
	{
		Fread((char *)&code_temp, sizeof(unsigned char), 1, infile);     // Read unique characters
		Fread((char *)&file_len, sizeof(unsigned long), 1, infile);     //Read file length
		outfile = fopen(ofname, "wb");					// Open the file that will be generated after compression
		while (file_len--)
			Fwrite((char *)&code_temp, sizeof(unsigned char), 1, outfile);	
		fclose(infile);
		fclose(outfile);
	}
	else
	{
		node_num = 2 * char_kinds - 1;		// Calculate the number of nodes required to establish a Huffman tree based on the number of characters 
		huf_tree = (HufNode *)malloc(node_num*sizeof(HufNode));		// Dynamic allocation of Huffman tree node space
		// Read characters and corresponding weights and store them in the Huffman tree node
		for(i = 0; i < char_kinds; ++i)     
		{
			Fread((char *)&huf_tree[i].uch, sizeof(unsigned char), 1, infile);		// Read character
			Fread((char *)&huf_tree[i].weight, sizeof(unsigned long), 1, infile);	// Read characters corresponding weights
			huf_tree[i].parent = 0;
		}
		// Node_num-char_kins node's parent after initialization
		for(; i < node_num; ++i) 
			huf_tree[i].parent = 0;

		CreateTree(huf_tree, char_kinds, node_num);		// Reconstruct the Huffman tree (consistent with compression)

		// Read the character and weight information, then read the file length and encoding to decode
		Fread((char *)&file_len, sizeof(unsigned long), 1, infile);	// Read file length
		outfile = fopen(ofname, "wb");		// Open the file that will be generated after compression
		root = node_num-1;
		while(1)
		{
			Fread((char *)&code_temp, sizeof(unsigned char), 1, infile);		// ~{6AH!R;8vWV7{3$6H5D1`Bk~}

			// Handles the length of a character read (usually 8 bits)
			for(i = 0; i < 8; ++i)
			{
				// From the root down to the leaf node forward matching encoding corresponding characters
				if(code_temp & 128)
					root = huf_tree[root].rchild;
				else
					root = huf_tree[root].lchild;

				if(root < char_kinds)
				{
					Fwrite((char *)&huf_tree[root].uch, sizeof(unsigned char), 1, outfile);
					++writen_len;
					if (writen_len == file_len) break;		// Control file length, jump out of inner loop
					root = node_num-1;        // Reset to root index, match next character
				}
				code_temp <<= 1;		// Shift the next bit of the code buffer to the highest bit for matching
			}
			if (writen_len == file_len) break;		// Control file length, jump out of the outer loop
		}

		// close file
		fclose(infile);
		fclose(outfile);

		// Free memory
		free(huf_tree);
	}
    return 0;
}//extract()



#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>

#include "message.cpp"
#include "login.cpp"
using namespace std;

// This constant can be avoided by explicitly
// calculating height of Huffman Tree
#define MAX_TREE_HT 100

// A Huffman tree node
struct MinHeapNode {

	// One of the input characters
	char data;

	// Frequency of the character
	unsigned freq;

	// Left and right child of this node
	struct MinHeapNode *left, *right;
};

// A Min Heap: Collection of
// min-heap (or Huffman tree) nodes
struct MinHeap {

	// Current size of min heap
	unsigned size;

	// capacity of min heap
	unsigned capacity;

	// Array of minheap node pointers
	struct MinHeapNode** array;   //bujhena
};

// A utility function allocate a new
// min heap node with given character
// and frequency of the character
struct MinHeapNode* newNode(char data, unsigned freq)
{
	struct MinHeapNode* temp
		= (struct MinHeapNode*)malloc
(sizeof(struct MinHeapNode)); // MinHeapNode* temp = new MinHeapNode

	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;

	return temp;
}

// A utility function to create
// a min heap of given capacity
struct MinHeap* createMinHeap(unsigned capacity)

{

	struct MinHeap* minHeap
		= (struct MinHeap*)malloc(sizeof(struct MinHeap)); // MinHeap* minHeap = new MinHeap

	// current size is 0
	minHeap->size = 0;

	minHeap->capacity = capacity;

	minHeap->array
		= (struct MinHeapNode**)malloc(minHeap->
capacity * sizeof(struct MinHeapNode*)); // minHeap->array = new MinHeapNode*[minHeap->capacity];
	return minHeap;
}

// A utility function to
// swap two min heap nodes
//afnai way ma swap garum
void swapMinHeapNode(struct MinHeapNode** a,
					struct MinHeapNode** b)

{

	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

// The standard minHeapify function.
void minHeapify(struct MinHeap* minHeap, int idx)

{

	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < minHeap->size && minHeap->array[left]->
freq < minHeap->array[smallest]->freq)
		smallest = left;

	if (right < minHeap->size && minHeap->array[right]->
freq < minHeap->array[smallest]->freq)
		smallest = right;

	if (smallest != idx) {
		swapMinHeapNode(&minHeap->array[smallest],
						&minHeap->array[idx]);
		minHeapify(minHeap, smallest);
	}
}

// A utility function to check
// if size of heap is 1 or not
int isSizeOne(struct MinHeap* minHeap)
{

	return (minHeap->size == 1);
}

// A standard function to extract
// minimum value node from heap
//bujhena 
struct MinHeapNode* extractMin(struct MinHeap* minHeap)

{

	struct MinHeapNode* temp = minHeap->array[0];
	minHeap->array[0]
		= minHeap->array[minHeap->size - 1];

	--minHeap->size;
	minHeapify(minHeap, 0);

	return temp;
}

// A utility function to insert
// a new node to Min Heap
void insertMinHeap(struct MinHeap* minHeap,
				struct MinHeapNode* minHeapNode)

{

	++minHeap->size;
	int i = minHeap->size - 1;

	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {

		minHeap->array[i] = minHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}

	minHeap->array[i] = minHeapNode;
}

// A standard function to build min heap
void buildMinHeap(struct MinHeap* minHeap)

{

	int n = minHeap->size - 1;
	int i;

	for (i = (n - 1) / 2; i >= 0; --i)
		minHeapify(minHeap, i);
}
string answer;
// A utility function to print an array of size n
/*void printArr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		cout<< arr[i];

	cout<<"\n";
}
*/
// Utility function to check if this node is leaf
int isLeaf(struct MinHeapNode* root)

{

	return !(root->left) && !(root->right);
}

// Creates a min heap of capacity
// equal to size and inserts all character of
// data[] in min heap. Initially size of
// min heap is equal to capacity
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)

{

	struct MinHeap* minHeap = createMinHeap(size);

	for (int i = 0; i < size; ++i)
		minHeap->array[i] = newNode(data[i], freq[i]);

	minHeap->size = size;
	buildMinHeap(minHeap);

	return minHeap;
}

// The main function that builds Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)

{
	struct MinHeapNode *left, *right, *top;

	// Step 1: Create a min heap of capacity
	// equal to size. Initially, there are
	// modes equal to size.
	struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

	// Iterate while size of heap doesn't become 1
	while (!isSizeOne(minHeap)) {

		// Step 2: Extract the two minimum
		// freq items from min heap
		left = extractMin(minHeap);
		right = extractMin(minHeap);

		// Step 3: Create a new internal
		// node with frequency equal to the
		// sum of the two nodes frequencies.
		// Make the two extracted node as
		// left and right children of this new node.
		// Add this node to the min heap
		// '$' is a special value for internal nodes, not used
		top = newNode('$', left->freq + right->freq);

		top->left = left;
		top->right = right;

		insertMinHeap(minHeap, top);
	}

	// Step 4: The remaining node is the
	// root node and the tree is complete.
	return extractMin(minHeap);
}
typedef struct huffmanTableNode
    {
        char data;
        string code;
    }huffmanTableNode ;

//create huffman table
class huffmanTable
{
    public:
    huffmanTableNode *huffTable;
    int size;
    int i=0;
	string rawstring="",hexstring="";
    huffmanTable(int size)
    {
        this->size = size;
        huffTable = new huffmanTableNode[size];
    }
	huffmanTable(){};

    void createHuffmanTable(struct MinHeapNode* root, string str)
    {
        if (root->left)
            createHuffmanTable(root->left, str + "0");
        if (root->right)
            createHuffmanTable(root->right, str + "1");
        if (isLeaf(root))
        {
            huffTable[i].data = root->data;
            huffTable[i].code = str;
            i++;
        }
    }
    void printHuffmanTable()
    {	cout<<size<<endl;
		
        for (int i = 0; i < size; i++)
        {
            cout << huffTable[i].data << ": " << huffTable[i].code << endl;
        }
    }
	string Search(char data){
		for (int i = 0; i < size; i++)
		{
			if (huffTable[i].data == data)
			{
				return huffTable[i].code;
			}
		}
		return "";
		
	}


    void PrintHuffmanCode(string ans){
        cout<<rawstring<<endl;
    }
	void generateHuffmanCode(string ans){
        for(int i=0;i<ans.length();i++){
            rawstring+= Search(ans[i]);
        }
	

        
    }
	
	friend fstream& operator>>(fstream& in, huffmanTable& hT);
	friend fstream& operator<<(fstream& out, huffmanTable& hT);

};
//write huffman table to file
fstream& operator<<(fstream& out, huffmanTable& hT){
	out<<hT.size<<endl;
	for (int i = 0; i < hT.size; i++)
	{
		out<<hT.huffTable[i].data<<" "<<hT.huffTable[i].code<<endl;
	}
	out<<hT.rawstring<<endl;
	return out;
}
//read huffman table from file
fstream& operator>>(fstream& in, huffmanTable& hT){
	in>>hT.size;
	hT.huffTable = new huffmanTableNode[hT.size];
	for (int i = 0; i < hT.size; i++)
	{
		in>>hT.huffTable[i].data>>hT.huffTable[i].code;
	}
	in>>hT.rawstring;
	return in;
}

// The main function that builds a
// Huffman Tree and print codes by traversing
// the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size, string realData, char* receiver)

{
	// Construct Huffman Tree
	struct MinHeapNode* root
		= buildHuffmanTree(data, freq, size);

	// Print Huffman codes using
	// the Huffman tree built above
	huffmanTable hTable(size) ;
    hTable.createHuffmanTable(root, "");
	hTable.generateHuffmanCode(realData);
	fstream senderFile;

    	string path="../data/decompressThis/";
        string extension= ".bin";
        string sdr(currentLoggedInUsername), rec(receiver);   
        fstream receiverFile;
        receiverFile.open((path+rec+"/"+sdr+extension).c_str(), ios::app);
		receiverFile<<hTable;
        receiverFile.close();
		
}

int search(char arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Driver code
void compress( string ans, char* receiver)
{
    // string ans;
	// cout<<endl;
	// cin.ignore();
	// cout<<"Enter the string to be encoded: ";
	// cout<<endl;
    // getline(cin,ans);
    int n = ans.size();
    char uniqueArr[n];
	int freq[n];
	int j=0;
    for(int i=0;i<n;i++){
        int result = search(uniqueArr,n, ans[i]);
        if (result == -1)
        {	
            uniqueArr[j]=ans[i];
			j++;
            
        }
    }
	int uniqueArrSize = sizeof(uniqueArr) / sizeof(uniqueArr[0]);
    for(int i=0;i<j;i++){
        freq[i]=0;
    }
	for(int i=0;i<n;i++){
        int result = search(uniqueArr, uniqueArrSize, ans[i]);
        if (result != -1)
		{
			freq[result]++;
		}
    }
	HuffmanCodes(uniqueArr, freq, j, ans,receiver);
}



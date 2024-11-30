//Write a program to implement Huffman Encoding using greedy strategy

#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

//node structure to represent each character
struct Node{
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char character,int frequency)
    {
        ch=character;
        freq=frequency;
        left=right=nullptr;
    }
};

//compare for the priority queue
struct Compare{
    bool operator()(Node* left,Node* right){
        return left->freq > right->freq;
    }
};

//function to generate huffman codes by traversing the tree  
void generateCodes(Node* root,const string& code,unordered_map<char, string>& huffmanCodes){
    if(!root) return;

    if(!root->left && !root->right){
        huffmanCodes[root->ch]=code;
    }

    //traverse the left and right subtree
    generateCodes(root->left,code+"0",huffmanCodes);
    generateCodes(root->right,code+"1",huffmanCodes);
}

//function to build huffman code
unordered_map<char,string> buildHuffmanTree(const string& text){
    //count the freq of each character
    unordered_map<char,int>freq;
    for(char ch : text){
        freq[ch]++;
    }

    priority_queue<Node*,vector<Node*>,Compare> pq;

    //add in the priority queue
    for(auto pair :freq){
        pq.push(new Node(pair.first,pair.second));
    }

    //iterate while there is more than one node in the queue
    while(pq.size()>1){
        Node* left =pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        //create a new node with the combined frequency
        Node* sum = new Node('\0',left->freq + right->freq);
        sum->left = left;
        sum->right= right;

        //add this new node sum to the queue
        pq.push(sum);
    }

    Node*root =pq.top();

    //generate the huffman code
    unordered_map<char,string> huffmanCodes;
    generateCodes(root,"",huffmanCodes);

    return huffmanCodes;
}

//print huffman code
void printHuffmanCodes(const unordered_map<char,string>& huffmanCodes){
    cout<<"Huffman Codes: \n";
    for(auto pair: huffmanCodes){
        cout<<pair.first<<": "<<pair.second<<'\n';
    }
}

//encode the input text
string encode(const string& text, const unordered_map<char,string>&huffmanCodes){
    string encodedString;
    for(char ch: text){
        encodedString+=huffmanCodes.at(ch);
    }
    return encodedString;
}

//main function
int main()
{
    string text = "ABBCCCDDDD";
    //build huffman tree and generate code
    unordered_map<char,string> huffmanCodes = buildHuffmanTree(text);
    printHuffmanCodes(huffmanCodes);

    //encode the input text
    string encodedString = encode(text,huffmanCodes);
    cout<<"\nEncoded string:\n"<<encodedString<<endl;
    
    return 0;
}
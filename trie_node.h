#ifndef TRIE_NODE
#define TRIE_NODE

#define MAX_ALPHA_SIZE 26
#define CHAR_IND(c) ((int)c - (int)'a')


class trie_node{
    public:
    int leaf;
    trie_node* children[MAX_ALPHA_SIZE];     //heart of the program
    trie_node();                             // create a dummy node
    trie_node(char ch);                      // creates a node with character ASCII value ch
    static trie_node* get_node();            //gives the pointer to the created node
    ~trie_node();                            //destructor for trie_node class
};


#endif // TRIE_NODE


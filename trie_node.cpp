#include "trie_node.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <typeinfo>
#include <utility>
using namespace std;

#define MAX_ALPHA_SIZE 26
#define CHAR_IND(c) ((int)c - (int)'a')
/* create a node -- Constructor */
trie_node::trie_node(){
    leaf = 0;
    for(int i=0;i<MAX_ALPHA_SIZE;i++){
        children[i] = 0;
    }
}
/* create node with char ch */
trie_node::trie_node(char ch){
    children[ch] = get_node();
}
/* create node as a static member */
trie_node* trie_node::get_node(){
    trie_node* p = 0;
    p = new trie_node();
    return p;
}

/* destructor -- very important */

trie_node:: ~trie_node(){
    for(int i=0;i<MAX_ALPHA_SIZE;i++){
        delete children[i];
    }
    cerr << "trie_node: Deleted... No garbage Collection.";
}

//END OF THE SOURCE ----------
//COPYRIGHT POP II (IT IV SEM)

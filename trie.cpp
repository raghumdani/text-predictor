#include "trie.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <typeinfo>
#include <utility>
using namespace std;

#define MAX_ALPHA_SIZE 26
#define CHAR_IND(c) ((int)c - (int)'a')
/* Constructor for the trie data structure
--------------::R::---------------------*/
trie::trie(){
    root = trie_node::get_node();
    count = 0;
}
/*method to insert the word into the trie
data structure--------------------------*/

int trie::insert_word(const string str){
    int length = str.size();
    int index;
    trie_node* curr = root;
    count++;
    for(int i=0;i<length;i++){
        /* program specific code */
        index = CHAR_IND(str[i]);
        assert(index>=0 && index <=25);
        if(! (curr->children[index]) ){
            curr->children[index] = trie_node::get_node();
        }
        curr = curr->children[index];
    }
    curr->leaf = count;
    return 0;
}

/* if word is present in the trie: RETURNS 1
---------------::R::-----------------------*/

int trie::get_word(const string str){
    int length = str.size();
    int index;
    trie_node* curr = root;
    for(int i=0;i<length;i++){
        /* program specific code */
        index = CHAR_IND(str[i]);
        assert(index>=0 && index <=25);
        if(!curr->children[index]){
            return 0;
        }
        curr = curr->children[index];
    }
    return (curr!=0 && curr->leaf);
}

/*Counts the number of words with prefix "str"
in the trie---------------------------------*/

int trie::count_words(const string str){
    int length = str.size();
    int index;
    int countx = 0;
    trie_node* curr = root;
    for(int i=0;i<length;i++){
        /* program specific code */
        index = CHAR_IND(str[i]);
        assert(index>=0 && index <=25);
        if(!curr->children[index]){
            return 0;
        }
        curr = curr->children[index];
    }
    for(int i=0;i<MAX_ALPHA_SIZE;i++){
        if(curr!=0 && curr->children[i]) countx++;
    }
    return countx;
}

//------------------**BEWARE**--------------------
///////////////---PART FROM HERE IS NOT COMPLETELY
//DEBUGGED AND CONSTRUCTED------------------------*/

void trie::return_words(const string str,vector <string>& vec){
    int length = str.size();
    int index;
    trie_node* curr = root;
    for(int i=0;i<length;i++){
        index = CHAR_IND(str[i]);
        if(!curr->children[index]){
            return;
        }
        curr = curr->children[index];
    }
    helper_ret_words(curr,str,str,vec);
}

/* an helper function for return_words */

void trie::helper_ret_words(trie_node* curr,string str,string str1,vector <string>& vec){
    if(curr==0) return;
    if(curr->leaf){
        vec.push_back(str);
        str = str1;
    }
    for(int i=0;i<MAX_ALPHA_SIZE;i++){
        if(curr->children[i]){
            str.push_back(i+'a');
            helper_ret_words(curr->children[i],str,str1,vec);
            str.erase(str.begin()+str.size()-1);
        }
    }
}

//a destructor -----yet to write------
/*trie::~trie()
{

}*/


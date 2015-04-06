#ifndef TRIE_H
#define TRIE_H

#include "trie_node.h"
#define MAX_ALPHA_SIZE 26
#define CHAR_IND(c) ((int)c - (int)'a')
#include <bits/stdc++.h>
using namespace std;
class trie{
    trie_node* root;
    int count;
    string temp;
    void helper_ret_words(trie_node* curr,string str,string str1,vector<string>& vec);
    public:
    trie();                                     //create empty trie with dummy
    int insert_word(const string str);          //insert a word/input string object
    int get_word(const string str);             //get the word if its present in the trie-RETURNS 1
    int count_words(const string str);          //counts the number of words with prefix str
    void return_words(const string str,vector<string>& vec);    //returns all the words with prefix str
    //bool clear();                                             //clears the content. returns 1 if successful
};


#endif // TRIE_H


#include "mainwindow.h"
#include <QApplication>
#include "editdistance.h"
#include "trie.h"
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cassert>
using namespace std;

#define SUCCESS 0
#define FAILURE 1
#define MAXLENGTH 100

int retval = SUCCESS;
static char readBuffer[MAXLENGTH]; /* To read the input line */
static char *lastPointer;          /* Return Pointer to allocated string */
FILE* inputfp = NULL;              /* Reading Dictionary File */
FILE* outfp = NULL;                /* Log file if required */
string value;                      /* To be shared by other file */

trie node;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;                 /* Created main window */
    char* readInputLine();        /* declaration */
    inputfp = fopen("en-US.dic","r");
    if(inputfp == NULL) {
        fprintf(stderr,"Error Occurred. File en-US not found!\n");
        assert(inputfp != NULL);
        retval = FAILURE;
        return retval;
    }
    outfp = fopen("D://log.txt","a");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    fprintf(outfp, "\n*********************************************************\n");
    fprintf(outfp,"\n: Date: %d-%d-%d. Time: %d:%d:%d\n\n", tm.tm_year + 1900,
            tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    char* y;                     /* store string */
    while( (y = readInputLine()) != NULL ) {
        /* read one line at a time */
        string s = string(y);
        bool check = false;
        for(int i = 0; i < int(s.size()); ++i) {
            s[i] = tolower(s[i]);
            if(s[i] < 'a' || s[i] > 'z') {
                check = true;
                break;
            }
        }
        if(!check)
            node.insert_word(s);
    }
    fclose(outfp);                      /* close both files */
    fclose(inputfp);
    w.show();
    return a.exec();
}

void heartProgram(string S) {
    vector <string> vec;
    outfp = fopen("D://log.txt","a");            /* Make sure that you have drive D */
    char y[1000];
    /*********OPTIONAL CASE *********/
    if(outfp == NULL) {
        sprintf(y,"Please Make sure that you have Drive D. I should print a log file.\n");
        value = string(y);
        return;
    }
    /***CONVERT STRING INTO LOWERCASE ***/
    for(int i = 0; i < int(S.size()); ++i) {
        S[i] = tolower(S[i]);
        if(S[i] < 'a' || S[i] > 'z') {
            fprintf(outfp, "Would you please enter only words containing English alphabets?\n");
            sprintf(y,"Would you please enter only words containing English alphabets?\n");
            value = string(y);
            fclose(outfp);
            return;
        }
    }
    string p = S.substr(0,3);         /*check first 3 characters of word*/
    if(node.get_word(S)) {
        fprintf(outfp, "The word \"%s\" is Correct!\n",S.c_str());
        sprintf(y,"The word \"%s\" is Correct!\n",S.c_str());
        value = string(y);
        fclose(outfp);
        return;
    }
    node.return_words(p, vec);        /* return words with prefix p */
    int N = vec.size();
    if(N == 0) {
        fprintf(outfp,"There is no way to Correct the word \"%s\".\n",S.c_str());
        sprintf(y,"There is no way to Correct the word \"%s\".\n",S.c_str());
        value = string(y);
        fclose(outfp);
        return;
    }
    int index = -1, low = 0x7fffffff;         /* its' nothing but INT_MAX */
    for(int i = 0; i < N; ++i) {
        EditDistance x(S, vec[i]);            /* calclulate the minumum edit distance */
        int edit = x.getDistance();
        if(edit < low) {
            index = i;
            low = edit;
        }
    }
    if(index == -1) {
        fprintf(outfp, "There is no way to Correct the word \"%s\".\n",S.c_str());
        sprintf(y,"There is no way to Correct the word \"%s\".\n",S.c_str());
        value = string(y);
        fclose(outfp);
        return;
    }
    fprintf(outfp, "The word \"%s\" is incorrect. The correct word can be \"%s\".\n", S.c_str(), vec[index].c_str());
    sprintf(y,"The word \"%s\" is incorrect. The correct word can be \"%s\".\n", S.c_str(), vec[index].c_str());
    value = string(y);
    sprintf(y, "The related words are:\n");
    value = value + string(y);
    for(int i = 0; i < min(5, N); ++i) {
        sprintf(y, (vec[i] + string("\n")).c_str());
        value += string(y);
    }
    fclose(outfp);
    // GOOD BYE HEART
}

char *readInputLine()
{
    int   inputChar;              /* Input Character */
    int   index;                  /* To update array */

    /* Initialise */
    if (lastPointer != NULL) { free(lastPointer); lastPointer = NULL; }
    index = 0;
    /* Read Line */
    while ( ((inputChar = fgetc(inputfp)) != EOF) && (inputChar != '\n') )
    {
        /* Update Array */
        if (index < MAXLENGTH) { readBuffer[index] = inputChar; }
        index++;
    }
    readBuffer[index] = 0;
    /* Store Line */
    if ((inputChar != EOF) || (index != 0))
    {
        lastPointer = (char *) malloc(strlen(readBuffer) + 1);
        strcpy(lastPointer, readBuffer);
    }

    return(lastPointer);
}


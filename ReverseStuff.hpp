#pragma once

#include <string>

// reverse a string
inline void reverseString(char str[], int sz)
{
    for( int i=0 ; i<sz/2 ; ++i ) {
        char tmp = str[i];
        str[i] = str[sz - i - 1];
        str[sz - i - 1] = tmp;
    }
}

inline void reverseString(std::string& str)
{
    return reverseString(const_cast<char*>(str.c_str()), str.size());
}

// reverse words inside a sentence
// 1) reverse individual words
// 2) then inverse the entire string again
inline void reverseWords(std::string& str)
{
    int sz = str.size();
    char* data = const_cast<char*>(str.c_str());
    reverseString(data, sz);
    int tmpSz = 0;
    for( int i=sz-1 ; i>=0 ; --i ) {
        if(str[i] == ' ') {
            reverseString(data + i + 1, tmpSz);
            tmpSz = 0;
        }
        else {
            ++tmpSz;
        }
    }
    reverseString(data, tmpSz);
}

struct Node {
    Node* next = nullptr;
};

inline void reverseLinkedList(Node *curr, Node *prev, Node **head)
{
    /* If last node mark it head*/
    if (!curr->next)
    {
        *head = curr;
 
        /* Update next to prev node */
        curr->next = prev;
        return;
    }
 
    /* Save curr->next node for recursive call */
    Node *next = curr->next;
 
    /* and update next ..*/
    curr->next = prev;
}

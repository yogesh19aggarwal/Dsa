#include <iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
     TrieNode* root;

     Trie(){
        root = new TrieNode('\0');
     }

    void insertUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        // assumption all char are in caps
        int index = word[0] - 'A';
        TrieNode* child;
        
        // present
        if(root -> children[index] != NULL){
            child = root->children[index];
        }
        // absent
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion
        insertUtil(child , word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            return root->isTerminal;
        }

        // assumption all char are in caps
        int index = word[0] - 'A';
        TrieNode* child;

         // present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        // absent
        else{
            return false;
        }

        // recursion
        return searchUtil(child , word.substr(1));
    }
    bool search(string word){
        return searchUtil(root , word);
    }

    void removeUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            free(root);
            root->isTerminal = false;
            return ;
        }

        // assumption all char are in caps
        int index = word[0] - 'A';
        TrieNode* child;

         // present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        // absent
        else{
            return ;
        }

        // recursion
        removeUtil(child , word.substr(1));
    }
    void remove(string word){
        removeUtil(root , word);
    }
};

int main(){

    Trie* t = new Trie();
    t->insertWord("ABCD"); 
    t->insertWord("CAT"); 
    t->insertWord("DOG"); 
    t->insertWord("ABCDE");
    cout<<"present or not : "<<t->search("ABCD")<<endl;

    t->remove("ABCD");

    cout<<"present or not : "<<t->search("ABCD")<<endl;

    cout<<"present or not : "<<t->search("ABCDE")<<endl;


    return 0;
}

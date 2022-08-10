#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    char data;
    unordered_map<char,Node*> children;
    bool isTerminal;

    Node(char data){
        this->data = data;
        for(char ch='a';ch<='z';ch++){
            children[ch] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
private:
    Node *root;

public:
    Trie(){
        root = new Node('\0');
    }



    void insert(string word){
        Node *curr = root;
        for(int i=0;i<word.length();i++){
            char curr_ch = word[i];
            if(curr->children[curr_ch] == NULL){
                Node *newNode = new Node(curr_ch);
                curr->children[curr_ch] = newNode;

            }
            curr = curr->children[curr_ch];
            if(i==word.length()-1){
                curr->isTerminal = 1;
            }
        }
    }

    bool search(string word){
        Node *curr = root;
        for(int i=0;i<word.length();i++){
            char curr_ch = word[i];
            if(curr->children[curr_ch] == NULL) return 0;
            curr=curr->children[curr_ch];
            if(i==word.length()-1 and curr->isTerminal==1) return 1;
        }
        return 0;
    }

};

int main(){

    Trie *trie = new Trie();
    trie->insert("Apple");
    trie->insert("Ape");
    trie->insert("Mango");
    trie->insert("News");

    cout<<trie->search("Ape")<<endl;
    cout<<trie->search("New")<<endl;
    cout<<trie->search("News")<<endl;

    return 0;
}
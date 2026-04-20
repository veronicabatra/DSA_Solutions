class Node{
    public:
    unordered_map<char,Node*> children;
    bool end;
    Node(){
        end=false;
    }
};
class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            if(!temp->children.count(word[i])) temp->children[word[i]]=new Node();
            temp=temp->children[word[i]];
        }
        temp->end=true;
    }
    
    bool search(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            if(!temp->children[word[i]]) return false;
            temp=temp->children[word[i]];
        }
        return temp->end;
    }
    
    bool startsWith(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            if(!temp->children[word[i]]) return false;
            temp=temp->children[word[i]];
        }
        return true;
    }
};

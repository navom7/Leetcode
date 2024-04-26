class Node{
public:
    char ch;
    unordered_map<char, Node*> childs;
    bool isTerminal;
    
    
    Node(char c) {
        ch = c;
        isTerminal = false;
    }
};


class Trie {
    Node* root;
public:
    Trie() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        Node* temp = root;
        for(auto ch: word) {
            if(temp->childs[ch] == NULL) {
                temp->childs[ch] = new Node(ch);
            }
            temp = temp->childs[ch];
        }
        temp->isTerminal = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        cout << word << ":  ";
        for(auto ch: word) {
            if(temp->childs[ch] != NULL) {
                cout << ch << " " << temp->childs[ch]->isTerminal <<  ", ";
                temp = temp->childs[ch];
            } else {
                return false;
            }
        }
        cout << endl;
        return temp->isTerminal;
    }
    
    bool startsWith(string word) {
        Node* temp = root;
        for(auto ch: word) {
            if(temp->childs[ch] != NULL) {
                temp = temp->childs[ch];
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
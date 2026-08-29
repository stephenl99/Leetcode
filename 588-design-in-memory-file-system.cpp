struct Node {
    string name;
    bool isFile;
    string content;
    map<string, Node*> next;
};
class FileSystem {
public:
    Node* root;
    FileSystem() {
        root = new Node("", false, "", map<string, Node*>());
    }
    
    vector<string> ls(string path) {
        Node* curr = root;
        std::stringstream ss(path);
        vector<string> result;
        vector<string> ans;
        string token;
        while (std::getline(ss, token, '/')) {
            if (token != "") {
                result.push_back(token);
            }
        }
        for (string token : result) {
            curr = curr->next[token];
        }
        if (curr->isFile) {
            ans.push_back(curr->name);
            return ans;
        }
        auto keys_view = std::views::keys(curr->next);
        return std::vector<string> (keys_view.begin(), keys_view.end());
    }
    
    void mkdir(string path) {
        Node* curr = root;
        std::stringstream ss(path);
        vector<string> result;
        string token;
        while (std::getline(ss, token, '/')) {
            if (token != "") {
                result.push_back(token);
            }
        }
        for (string token : result) {
            if (!curr->next.contains(token)) {
                curr->next[token] = new Node(token, false, "", map<string, Node*>());
            }
            curr = curr->next[token];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        Node* curr = root;
        std::stringstream ss(filePath);
        vector<string> result;
        string tok;
        while (std::getline(ss, tok, '/')) {
            if (tok != "") {
                result.push_back(tok);
            }
        }
        for (string token : result) {
            if (!curr->next.contains(token)) {
                curr->next[token] = new Node(token, false, "", map<string, Node*>());
            }
            curr = curr->next[token];
        }
        curr->content += content;
        curr->isFile = true;
    }
    
    string readContentFromFile(string filePath) {
        Node* curr = root;
        std::stringstream ss(filePath);
        vector<string> result;
        string token;
        while (std::getline(ss, token, '/')) {
            if (token != "") {
                result.push_back(token);
            }
        }
        for (string token : result) {
            if (!curr->next.contains(token)) {
                curr->next[token] = new Node(token, false, "", map<string, Node*>());
            }
            curr = curr->next[token];
        }
        return curr->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
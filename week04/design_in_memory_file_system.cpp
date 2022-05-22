class FileNode {
public:
    map<string, FileNode*> children;
    string file, name;
    FileNode(string _name) {
        name = _name;
    }
    string getContent() {
        return file;
    }
    string getName() {
        return name;
    }
    void addContent(string content) {
        file += content; 
    }
    bool isFile() {
        return file.size() > 0;
    }
    vector<string> getList() {
        vector<string> list;
        if (isFile()) {
            list.push_back(getName());
        }
        else {
            for (auto &it : children) {
                list.push_back(it.first);
            }
        }
        return list;
    }
};

class FileSystem {
private:
    FileNode* root;
    vector<string> tokenize(string &s, char ch = '/') {
        stringstream ss(s);
        string temp;
        vector<string> contents;
        while(getline(ss, temp, ch)) {
            if (temp.size() > 0)
                contents.push_back(temp);
        }
        return contents;
    }
    FileNode* findNode(string &path) {
        vector<string> files = tokenize(path);
        FileNode* curr = root;
        for (auto &file : files) {
            curr->children[file] = curr->children[file] ? curr->children[file] : new FileNode(file);
            curr = curr->children[file];
            if (curr->isFile()) break;
        }
        return curr;
    }
public:
    FileSystem() {
        root = new FileNode("");
    }
    
    vector<string> ls(string path) {
        return findNode(path)->getList();
    }
    
    void mkdir(string path) {
        findNode(path);
    }
    
    void addContentToFile(string filePath, string content) {
        findNode(filePath)->addContent(content);
    }
    
    string readContentFromFile(string filePath) {
        return findNode(filePath)->getContent();
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
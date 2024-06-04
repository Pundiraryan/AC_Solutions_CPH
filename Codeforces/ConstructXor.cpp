class TrieNode {
    public:
        TrieNode *children[2];
        int count[2];
    };
    
    TrieNode* root = new TrieNode();
    
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 20; i >= 0; i--) {
            int idx = (num >> i) & 1;
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node->count[idx]++;
            node = node->children[idx];
        }
    }
    
    void del(int num){
        TrieNode* node=root;
        for (int i = 20; i >= 0; i--) {
            int idx = (num >> i) & 1;
            node->count[idx]--;
            node = node->children[idx];
        }
    }
    
    int maxor(int num) {
        TrieNode* node = root;
        int xorResult = 0;
        for (int i = 20; i >= 0; i--) {
            int a = (num >> i) & 1;
            int b = 1 - a;
            if (node->count[b] != 0) {
                xorResult = xorResult | 1<<i;
                node = node->children[b];
            } else {
                node = node->children[a];
            }
        }
        return xorResult;
    }
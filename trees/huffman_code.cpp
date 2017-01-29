typedef struct Node {
    int freq;
    char data;
    Node* left;
    Node* right;
};

void decode_huff(Node* root, string s) {
    int i = 0;
    while (i < s.size()) {
        Node* current = root;
        while (current->data == '\0') {
            if (s[i] == '0') current = current->left;
            if (s[i] == '1') current = current->right;
            i++;
        }
        cout << current->data;
    }
    cout << endl;
}

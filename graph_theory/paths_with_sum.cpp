void count_paths(Node* root, map<int, int>* path_count, int k, int* count) {
	LLNode* current = parents->head;
	int cum = current->data;
	(*count) += path_count[cum + root->data - k];
	(*path_count)[cum + root.data]++;
	for (int i = 0; i < root->children->size(); i++) {
		count_paths(rorrt->children[i], parents, k, count);
	}
	(*path_count)[cum + root.data]--;
}

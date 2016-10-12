template <class T> class Node {
	public:
		T data;
		Node<T>* left;
		Node<T>* right;

		Node<T>(T data) {
			this->data = data;
		}

		void insert(T data) {
			if (data < this->data) {
				if (this->left != NULL) {
					this->left->insert(data);
				} else {
					this->left = new Node<T>(data);
				}
			} else if (this->data < data) {
				if (this->right != NULL) {
					this->right->insert(data);
				} else {
					this->right = new Node<T>(data);
				}
			}
		}

};

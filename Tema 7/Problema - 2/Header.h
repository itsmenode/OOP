#include <iostream>

template <typename T>
class Tree {
private:
    struct Node {
        T value;
        Node* parent;
        Node** children;  
        int capacity;
        int size;

        Node(const T& val, Node* p = nullptr) : value(val), parent(p), capacity(10), size(0) {
            children = new Node * [capacity];
            for (int i = 0; i < capacity; i++) {
                children[i] = nullptr;
            }
        }

        ~Node() {
            delete[] children;
        }

        void resize() {
            int new_capacity = capacity * 2;
            Node** new_children = new Node * [new_capacity];

            for (int i = 0; i < size; i++) {
                new_children[i] = children[i];
            }

            for (int i = size; i < new_capacity; i++) {
                new_children[i] = nullptr;
            }

            delete[] children;
            children = new_children;
            capacity = new_capacity;
        }

        void add_child(Node* child) {
            if (size >= capacity) {
                resize();
            }
            children[size++] = child;
        }

        void insert_child(Node* child, int index) {
            if (index < 0 || index > size) {
                throw std::out_of_range("Index out of range");
            }

            if (size >= capacity) {
                resize();
            }

            for (int i = size; i > index; i--) {
                children[i] = children[i - 1];
            }

            children[index] = child;
            size++;
        }

        void remove_child(int index) {
            if (index < 0 || index >= size) {
                throw std::out_of_range("Index out of range");
            }

            for (int i = index; i < size - 1; i++) {
                children[i] = children[i + 1];
            }

            children[size - 1] = nullptr;
            size--;
        }
    };

    Node* root;

    void delete_subtree(Node* node) {
        if (!node) return;

        for (int i = 0; i < node->size; i++) {
            delete_subtree(node->children[i]);
        }

        delete node;
    }

    Node* find_node(Node* node, const T& value, bool (*compare)(const T&, const T&)) {
        if (!node) return nullptr;

        if (compare(node->value, value)) {
            return node;
        }
        for (int i = 0; i < node->size; i++) {
            Node* found = find_node(node->children[i], value, compare);
            if (found) return found;
        }

        return nullptr;
    }

    int count_nodes(Node* node) const {
        if (!node) return 0;

        int count = 1;
        for (int i = 0; i < node->size; i++) {
            count += count_nodes(node->children[i]);
        }

        return count;
    }

    void sort_children(Node* node, bool (*compare)(const T&, const T&)) {
        if (!node || node->size <= 1) return;

        for (int i = 0; i < node->size - 1; i++) {
            for (int j = 0; j < node->size - i - 1; j++) {
                if (compare) {
                    if (compare(node->children[j + 1]->value, node->children[j]->value)) {
                        Node* temp = node->children[j];
                        node->children[j] = node->children[j + 1];
                        node->children[j + 1] = temp;
                    }
                }
                else {
                    if (node->children[j + 1]->value < node->children[j]->value) {
                        Node* temp = node->children[j];
                        node->children[j] = node->children[j + 1];
                        node->children[j + 1] = temp;
                    }
                }
            }
        }
    }

public:
    Tree() : root(nullptr) {}

    ~Tree() {
        delete_node(nullptr);
    }

    Node* add_node(const T& value, Node* parent = nullptr) {
        Node* new_node = new Node(value, parent);

        if (!parent) {
            if (root) {
                delete new_node;
                throw std::runtime_error("Root already exists");
            }
            root = new_node;
        }
        else parent->add_child(new_node);

        return new_node;
    }

    Node* get_node(Node* parent = nullptr) const {
        if (!parent) {
            return root;
        }
        throw std::invalid_argument("Invalid parent node");
        return nullptr;
    }

    void delete_node(Node* node) {
        if (!node) {
            delete_subtree(root);
            root = nullptr;
            return;
        }

        Node* parent = node->parent;
        if (!parent) root = nullptr;
        else {
            int index = -1;
            for (int i = 0; i < parent->size; i++) {
                if (parent->children[i] == node) {
                    index = i;
                    break;
                }
            }

            if (index >= 0) {
                parent->remove_child(index);
            }
        }

        delete_subtree(node);
    }

    Node* find(const T& value, bool (*compare)(const T&, const T&)) {
        return find_node(root, value, compare);
    }

    Node* insert(const T& value, Node* parent, int index) {
        if (!parent && !root) {
            return add_node(value);
        }
        else if (!parent) {
            throw std::invalid_argument("Cannot insert at an index with nullptr parent when root exists");
        }

        Node* new_node = new Node(value, parent);
        parent->insert_child(new_node, index);
        return new_node;
    }

    void sort(Node* node = nullptr, bool (*compare)(const T&, const T&) = nullptr) {
        if (!node) {
            node = root;
        }

        if (!node) return;

        sort_children(node, compare);

        for (int i = 0; i < node->size; i++) {
            sort(node->children[i], compare);
        }
    }

    int count(Node* node = nullptr) const {
        if (!node) {
            node = root;
        }

        return count_nodes(node);
    }
};
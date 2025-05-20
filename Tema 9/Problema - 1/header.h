#pragma once

#include <iostream>
#include <stdio.h>
#include <utility>

template<typename K, typename V>
class Map {
private:
    struct Node {
        K key;
        V value;
        Node* next;

        Node(const K& k, const V& v) : key(k), value(v), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    Map() : head(nullptr), size(0) {}

    ~Map() {
        Clear();
    }

    Map(const Map& other) : head(nullptr), size(0) {
        Node* current = other.head;
        while (current) {
            Set(current->key, current->value);
            current = current->next;
        }
    }

    Map& operator=(const Map& other) {
        if (this != &other) {
            Clear();
            Node* current = other.head;
            while (current) {
                Set(current->key, current->value);
                current = current->next;
            }
        }
        return *this;
    }

    void Set(const K& key, const V& value) {
        Node* current = head;
        Node* prev = nullptr;

        while (current && !(current->key == key)) {
            prev = current;
            current = current->next;
        }

        if (current) {
            current->value = value;
        }
        else {
            Node* newNode = new Node(key, value);
            if (!prev) {
                newNode->next = head;
                head = newNode;
            }
            else {
                newNode->next = prev->next;
                prev->next = newNode;
            }
            size++;
        }
    }

    bool Get(const K& key, V& value) const {
        Node* current = head;

        while (current) {
            if (current->key == key) {
                value = current->value;
                return true;
            }
            current = current->next;
        }

        return false;
    }

    int Count() const {
        return size;
    }

    void Clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }

    bool Delete(const K& key) {
        Node* current = head;
        Node* prev = nullptr;

        while (current && !(current->key == key)) {
            prev = current;
            current = current->next;
        }

        if (!current) {
            return false;
        }

        if (!prev) {
            head = current->next;
        }
        else {
            prev->next = current->next;
        }

        delete current;
        size--;
        return true;
    }

    bool Includes(const Map<K, V>& map) const {
        Node* current = map.head;

        while (current) {
            V value;
            if (!Get(current->key, value)) {
                return false;
            }
            current = current->next;
        }

        return true;
    }

    V& operator[](const K& key) {
        Node* current = head;

        while (current) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }

        Node* newNode = new Node(key, V());
        newNode->next = head;
        head = newNode;
        size++;

        return newNode->value;
    }

    class Iterator {
    private:
        struct Item {
            K key;
            V value;
            int index;

            Item(const K& k, const V& v, int i) : key(k), value(v), index(i) {}
        };

        Item item;
        const Map* map;
        Node* current;
        int index;

    public:
        Iterator(const Map* m, Node* node, int idx)
            : item(node ? node->key : K(), node ? node->value : V(), idx),
            map(m), current(node), index(idx) {
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

        Iterator& operator++() {
            if (current) {
                current = current->next;
                index++;
                if (current) {
                    item = Item(current->key, current->value, index);
                }
            }
            return *this;
        }

        std::tuple<const K&, const V&, int> operator*() const {
            return std::tuple<const K&, const V&, int>(item.key, item.value, item.index);
        }
    };

    Iterator begin() const {
        return Iterator(this, head, 0);
    }

    Iterator end() const {
        return Iterator(this, nullptr, size);
    }
};

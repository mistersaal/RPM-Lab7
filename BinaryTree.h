/**
 * Бинарное дерево
 * @file BinaryTree.h
 * @author Сааль Степан
 */

#ifndef LAB7_BINARYTREE_H
#define LAB7_BINARYTREE_H

#include <stdexcept>
#include <string>

using namespace std;

/**
 * Узел дерева
 * @tparam A
 */
template<typename A>
struct node {
    A value;
    node *left = nullptr;
    node *right = nullptr;
};

/**
 * Бинарное дерево
 * @tparam T
 */
template<typename T>
class BinaryTree {
public:
    /**
     * Создание пустого дерева
     */
    BinaryTree() {
        root = nullptr;
    }
    /**
     * Удаление всего дерева
     */
    ~BinaryTree() {
        deleteTree();
    }

    /**
     * Вставка значения
     * @param value
     */
    void insert(T value) {
        if (root == nullptr) {
            root = new node<T>;
            root->value = value;
        } else {
            insert(value, root);
        }
    }

    /**
     * Удаление дерева
     */
    void deleteTree() {
        deleteNode(root);
        root = nullptr;
    }

    /**
     * Поиск значения в дереве
     * @param value
     * @return
     */
    node<T> *search(T value) {
        node<T> *leaf = search(value, root);
        return leaf;
    }

    /**
     * Печать дерева на экран
     */
    void print() {
        if (isEmpty()) {
            throw runtime_error("Tree is empty");
        }
        print(root);
        cout << endl;
    }

    /**
     * Печать части дерева на экран
     * @param value
     */
    void print(T value) {
        node<T> *leaf = search(value, root);
        print(leaf);
        cout << endl;
    }

    /**
     * Проверка на пустоту
     * @return
     */
    bool isEmpty() {
        return root == nullptr;
    }

    /**
     * Кол-во элементов в дереве
     * @return
     */
    int count() {
        int count = 0;
        countElements(root, count);
        return count;
    }

private:
    /** Вершина дерева */
    node<T> *root;

    /**
     * Удаление ветви дерева
     * @param leaf
     */
    void deleteNode(node<T> *leaf) {
        if (leaf != nullptr) {
            deleteNode(leaf->left);
            deleteNode(leaf->right);
            delete leaf;
        }
    }

    /**
     * Вставка значения
     * @param value
     * @param leaf
     */
    void insert(T value, node<T> *leaf) {
        if (value < leaf->value) {
            insertLeft(value, leaf);
        } else {
            insertRight(value, leaf);
        }
    }

    /**
     * Вставка значения в левую ветвь
     * @param value
     * @param leaf
     */
    void insertLeft(T value, node<T> *leaf) {
        if (leaf->left != nullptr) {
            insert(value, leaf->left);
        } else {
            leaf->left = new node<T>;
            leaf->left->value = value;
        }
    }

    /**
     * Вставка значения в правую ветвь
     * @param value
     * @param leaf
     */
    void insertRight(T value, node<T> *leaf) {
        if (leaf->right != nullptr) {
            insert(value, leaf->right);
        } else {
            leaf->right = new node<T>;
            leaf->right->value = value;
        }
    }

    /**
     * Поиск значения
     * @param value
     * @param leaf
     * @return
     */
    node<T> *search(T value, node<T> *leaf) {
        if (leaf != nullptr) {
            if (value == leaf->value) {
                return leaf;
            } else if (value < leaf->value) {
                return search(value, leaf->left);
            } else {
                return search(value, leaf->right);
            }
        } else {
            throw runtime_error("Element does not exists");
        }
    }

    /**
     * Вывод на экран
     * @param leaf
     */
    void print(node<T> *leaf) {
        if (leaf != nullptr) {
            print(leaf->left);
            cout << leaf->value << ", ";
            print(leaf->right);
        }
    }

    /**
     * Подсчёт элементов
     * @param leaf
     * @param count
     */
    void countElements(node<T> *leaf, int &count) {
        if (leaf != nullptr) {
            count++;
            countElements(leaf->left, count);
            countElements(leaf->right, count);
        }
    }
};

#endif //LAB7_BINARYTREE_H

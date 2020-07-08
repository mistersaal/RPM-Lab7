/**
 * Меню для работы с деревом
 * @file Menu.h
 * @author Сааль Степан
 */

#ifndef LAB7_MENU_H
#define LAB7_MENU_H

#include <iostream>
#include <string>
#include "BinaryTree.h"

using namespace std;

/**
 * Меню для работы с деревом
 * @tparam T
 */
template<typename T>
class Menu {
public:
    /**
     * Создание дерева
     */
    Menu() {
        tree = new BinaryTree<T>();
    }
    /**
     * Удаление дерева
     */
    ~Menu() {
        tree->deleteTree();
        delete tree;
    }
    /**
     * Показать меню
     */
    void show() {
        mainMenu();
    }

private:
    /** Дерево */
    BinaryTree<T> *tree;

    /**
     * Главное меню
     */
    void mainMenu() {
        cout << "1. Insert value to tree" << endl;
        cout << "2. Search value in tree" << endl;
        cout << "3. Print whole tree" << endl;
        cout << "4. Print node with value" << endl;
        cout << "5. Get count of elements" << endl;
        cout << "6. Check if tree is empty" << endl;
        cout << "7. Delete tree" << endl;
        cout << "0. Exit" << endl;
        mainMenuAction();
    }

    /**
     * Действия главного меню
     */
    void mainMenuAction() {
        int action;
        cin >> action;
        switch (action) {
            case 1: insertAction(); break;
            case 2: searchAction(); break;
            case 3: printAction(true); break;
            case 4: printAction(false); break;
            case 5: countAction(); break;
            case 6: emptyAction(); break;
            case 7: deleteAction(); break;
            case 0: cout << "Bye!" << endl; return;
            default: cout << "Wrong action, try again:" << endl;
        }
        cout << endl;
        mainMenu();
    }

    /**
     * Вставка данных
     */
    void insertAction() {
        cout << "Input value:" << endl;
        T value;
        cin >> value;
        tree->insert(value);
        cout << "Done!" << endl;
    }

    /**
     * Поиск значения
     */
    void searchAction() {
        cout << "Input value to searching:" << endl;
        T value;
        cin >> value;
        try {
            tree->search(value);
            cout << "Element exists!" << endl;
        } catch (const exception& e) {
            cout << e.what() << endl;
        }
    }

    /**
     * Вывод на экран дерева
     * @param whole Требуется ли выводить всё дерево или часть
     */
    void printAction(bool whole) {
        try {
            if (whole) {
                tree->print();
            } else {
                T value;
                cout << "Input value:" << endl;
                cin >> value;
                tree->print(value);
            }
        } catch (const exception& e) {
            cout << e.what() << endl;
        }
    }

    /**
     * Вывод кол-ва элементов
     */
    void countAction() {
        cout << tree->count() << endl;
    }

    /**
     * Проверка на пустоту
     */
    void emptyAction() {
        cout << (tree->isEmpty() ? "Empty" : "Not empty") << endl;
    }

    /**
     * Очистка дерева
     */
    void deleteAction() {
        tree->deleteTree();
        cout << "Done!" << endl;
    }
};


#endif //LAB7_MENU_H

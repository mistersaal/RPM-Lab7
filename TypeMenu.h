/**
 * Меню выбора типа
 * @file TypeMenu.h
 * @author Сааль Степан
 */

#ifndef LAB7_TYPEMENU_H
#define LAB7_TYPEMENU_H

#include <iostream>
#include <string>
#include "Menu.h"

using namespace std;

/**
 * Меню выбора типа
 */
class TypeMenu {
public:
    /**
     * Показать меню
     */
    static void show() {
        int type;
        cout << "Choose type:" << endl;
        cout << "1. int" << endl;
        cout << "2. double" << endl;
        cout << "3. string" << endl;
        cin >> type;
        showMenuForType(type);
    }

private:
    /**
     * Создание меню работы с деревом в зависимости от типа
     * @param type
     */
    static void showMenuForType(int type) {
        if (type == 1) {
            auto *menu = new Menu<int>;
            menu->show();
        } else if (type == 2) {
            auto *menu = new Menu<double>;
            menu->show();
        } else if (type == 3) {
            auto *menu = new Menu<string>;
            menu->show();
        } else {
            cout << "Wrong number, try again:" << endl;
            show();
        }
    }
};


#endif //LAB7_TYPEMENU_H

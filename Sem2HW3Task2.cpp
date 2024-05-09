//С помощью ассоциативного контейнера реализовать генеалогическое древо
//Каждом элементу дерева сопоставляется целое неотрицательное число, называемое высотой.У родоначальника высота равна 0, у любого другого элемента высота на 1 больше,
//чем у его родителя.
//Вам дано генеалогическое древо, определите высоту всех его элементов.
//Входные данные. Программа получает на вход из файла число элементов в генеалогическом древе 𝑁. Далее следует 𝑁−1 строка, задающие родителя для каждого элемента древа,
//кроме родоначальника. Каждая строка имеет вид имя_потомка имя_родителя.
//Выходные данные. Программа должна вывести список всех элементов древа в лексикографическом порядке.После вывода имени каждого элемента необходимо вывести его высоту.

#include <iostream>
#include <map>
#include <string>

int main() {

    int N;
    std::cin >> N;
    std::map<std::string, std::pair<std::string, int>> family_tree; //пары ребёнок, родитель, высота относительная

    for (int i = 0; i < N - 1; ++i) {

        std::string child, parent;
        std::cin >> child >> parent;
        family_tree[child] = {parent, 0};

    }

    std::map<std::string, int> heights; //абсолютные высоты

    for (const auto& [child, parent_height] : family_tree) {

        int height = 0;
        std::string current_child = child; //чтобы не перепуталось

        while (!current_child.empty()) {

            height++;
            current_child = family_tree[current_child].first;

            if (current_child.empty())
                height--; //ибо в таком случае посчитали лишний отрезок древа

        }

        heights[child] = height;

    }

    std::cout << std::endl;

    for (const auto& [elem, height] : heights) {

        std::cout << elem << " " << height << std::endl;
        
    }

    return 0;
}
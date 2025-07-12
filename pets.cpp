#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <cstring>
#include <windows.h>

using namespace std;

struct Pet {
    string owner;
    string species;
    string name;
    int age;
};

Pet pets[1000];
int petCount = 0;

int parseAge(const string& ageStr) {
    if (ageStr.empty()) return -1;
    if (ageStr == "один год") return 1;
    stringstream ss(ageStr);
    int age;
    ss >> age;
    return ss.fail() ? -1 : age;
}

void readInputFile(const string& filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string owner, species, name, ageStr;

        getline(ss, owner, ',');
        getline(ss, species, ',');
        getline(ss, name, ',');
        getline(ss, ageStr);

        pets[petCount++] = { owner, species, name, parseAge(ageStr) };
    }
}

void question1() {
    map<string, set<string>> ownerSpeciesMap;
    for (int i = 0; i < petCount; ++i) {
        ownerSpeciesMap[pets[i].owner].insert(pets[i].species);
    }
    for (map<string, set<string>>::iterator it = ownerSpeciesMap.begin(); it != ownerSpeciesMap.end(); ++it) {
        cout << it->first << ": " << it->second.size() << " видов\n";
    }
}

void question2() {
    cout << "Введите вид животного: ";
    string targetSpecies;
    cin.ignore();
    getline(cin, targetSpecies);

    set<string> owners;
    set<string> names;
    for (int i = 0; i < petCount; ++i) {
        if (pets[i].species == targetSpecies) {
            owners.insert(pets[i].owner);
            if (!pets[i].name.empty())
                names.insert(pets[i].name);
        }
    }
    if (owners.empty()) {
        cout << "Такой вид животных не найден.\n";
        return;
    }
    cout << "Владельцы: ";
    for (set<string>::iterator it = owners.begin(); it != owners.end(); ++it) {
        cout << *it << ", ";
    }
    cout << "\nКлички: ";
    for (set<string>::iterator it = names.begin(); it != names.end(); ++it) {
        cout << *it << ", ";
    }
    cout << "\n";
}

void question3() {
    cout << "Введите кличку: ";
    string targetName;
    cin.ignore();
    getline(cin, targetName);

    set<string> speciesSet;
    for (int i = 0; i < petCount; ++i) {
        if (pets[i].name == targetName) {
            speciesSet.insert(pets[i].species);
        }
    }
    cout << "Кличка '" << targetName << "' у животных " << speciesSet.size() << " видов\n";
}

void question4() {
    map<string, pair<int, int>> speciesAgeMap;
    for (int i = 0; i < petCount; ++i) {
        if (pets[i].age >= 0) {
            pair<int, int>& ages = speciesAgeMap[pets[i].species];
            if (ages.first == 0 && ages.second == 0) ages.first = ages.second = pets[i].age;
            else {
                if (pets[i].age < ages.first) ages.first = pets[i].age;
                if (pets[i].age > ages.second) ages.second = pets[i].age;
            }
        }
    }
    for (map<string, pair<int, int>>::iterator it = speciesAgeMap.begin(); it != speciesAgeMap.end(); ++it) {
        cout << it->first << ": младший - " << it->second.first << ", старший - " << it->second.second << "\n";
    }
}

int main() {
    SetConsoleOutputCP(65001);
    readInputFile("input.txt");

    while (true) {
        cout << "---------------------------------------------------------------------\n";
        cout << "1. Посчитать количество различных видов животных у каждого владельца.\n";
        cout << "2. Для конкретного вида животного вывести всех его владельцев и клички.\n";
        cout << "3. Определить, сколько видов животных носит определённую кличку.\n";
        cout << "4. Вывести информацию о возрасте самого старого и самого молодого животного каждого вида.\n";
        cout << "Выберите операцию (другое - выход): ";
        int numberOperation;
        cin >> numberOperation;
        switch (numberOperation) {
        case 1: question1(); break;
        case 2: question2(); break;
        case 3: question3(); break;
        case 4: question4(); break;
        default: return 0;
        }
    }
}
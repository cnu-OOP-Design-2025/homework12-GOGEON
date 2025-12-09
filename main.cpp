#include <iostream>
#include <memory>
#include <vector>
#include "character.h"

using namespace std;

void equip_test1(shared_ptr<Character> c1) {
    c1 = make_shared<Armor>(c1);
    c1 = make_shared<Boots>(c1);
    c1 = make_shared<Sword>(c1);
    cout << c1->getDescription()
        << " | Attack: " << c1->getAttack()
        << " | Speed: " << c1->getSpeed()
        << " | Defense: " << c1->getDefense() << endl;
}

void equip_test2(shared_ptr<Character> c1) {
    c1 = make_shared<Armor>(c1);
    c1 = make_shared<Bow>(c1);
    cout << c1->getDescription()
        << " | Attack: " << c1->getAttack()
        << " | Speed: " << c1->getSpeed()
        << " | Defense: " << c1->getDefense() << endl;
}

void equip_test3(shared_ptr<Character> c1) {
    c1 = make_shared<Boots>(c1);
    c1 = make_shared<Staff>(c1);
    cout << c1->getDescription()
        << " | Attack: " << c1->getAttack()
        << " | Speed: " << c1->getSpeed()
        << " | Defense: " << c1->getDefense() << endl;
}

void doTest() {
    vector<shared_ptr<Character>> players;
    players.push_back(make_shared<Knight>());
    players.push_back(make_shared<Wizard>());
    players.push_back(make_shared<Archer>());

    for(auto player: players){
        cout << "-------------------------------------------------------------" << endl;
        try {equip_test1(player);} 
        catch (invalid_argument& e) {
            Logger::getInstance()->log("[Fail to Equip] ");
            cout << e.what() << endl;
        }
        try {equip_test2(player);} 
        catch (invalid_argument& e) {
            Logger::getInstance()->log("[Fail to Equip] ");
            cout << e.what() << endl;
        }
        try {equip_test3(player);} 
        catch (invalid_argument& e) {
            Logger::getInstance()->log("[Fail to Equip] ");
            cout << e.what() << endl;
        }
        
    }
    cout << "-------------------------------------------------------------" << endl;

}

struct Student{
    string name;
    Student(string name): name(name) {};
    Student() = delete;
    ~Student() { cout << "Delete Student " << name << endl; }
};



int main(int argc, const char *argv[]) {
    doTest();
    return 0;
}

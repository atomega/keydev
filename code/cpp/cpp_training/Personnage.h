#pragma once

#include <string>
#include "Weapon.h"

class Personnage
{
public:
    void recieveDmg(int dmg); 
    void attac(Personnage& target); 
    void dirnkPotion(int potionQte);
    void changeWeapon(std::string newWeaponName, int newWeaponDamage);
    bool isAlive() const; 
    void showStatus() const; 
    void setName(std::string name); 

    //Construct Overload Destruct
    Personnage();
    Personnage(std::string weaponName, int weaponDamage);
    ~Personnage();
    
private:
    int m_hp;
    int m_mana;
    std::string m_name;
    Weapon m_weapon;
};

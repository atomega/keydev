#include "Personnage.h"

using namespace std;

void Personnage::recieveDmg(int dmg) 
{
	m_hp -= dmg; 
	if (m_hp <= 0)
	{
		m_hp = 0;
	}
}

void Personnage::attac(Personnage& target)
{
	target.recieveDmg(m_weapon.getDamage());
}

void Personnage::dirnkPotion(int potionQte)
{
	m_hp += potionQte; 
	
	if (m_hp > 100)
	{
		m_hp = 100; 
	}
}

void Personnage::changeWeapon(std::string newWeaponName, int newWeaponDamage)
{
	m_weapon.change(newWeaponName, newWeaponDamage); 
}

bool Personnage::isAlive() const 
{
	return m_hp > 0;
}

void Personnage::showStatus() const
{
	cout << "Name : " << m_name << endl; 
	cout << "Life : " << m_hp << endl; 
	cout << "Mana : " << m_mana << endl; 
	m_weapon.show(); 
}

void Personnage::setName(std::string name)
{
	m_name = name; 
}


// Default constructor
Personnage::Personnage() 
: m_name("unknown"), m_hp(100), m_mana(100)
{

}

//Constructor overloading with weapon class that have some definitions of it's own. 
Personnage::Personnage(string weaponName, int weaponDamage) 
: m_hp(100), m_mana(100), m_weapon(weaponName,weaponDamage)
{	

}

Personnage::~Personnage()
{

}
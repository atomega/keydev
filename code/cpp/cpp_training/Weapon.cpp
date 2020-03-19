#include "Weapon.h"

using namespace std; 

Weapon::Weapon() : m_name("Epee Rouiller"), m_damage(10)
{}

Weapon::Weapon(string name, int damage) : m_name(name), m_damage(damage)
{}

void Weapon::change(string name, int damage)
{
	m_name = name; 
	m_damage = damage;
}

void Weapon::show() const 
{
	cout << "Weapon : " << m_name << " ( Dmg : " << m_damage << " )" << endl; 
}

int Weapon::getDamage() const 
{
	return m_damage;
}

Weapon::~Weapon()
{

}
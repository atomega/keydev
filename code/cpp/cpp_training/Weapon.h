#pragma once

#include <iostream>
#include <string>

class Weapon
{
public: 
	Weapon(); 
	Weapon(std::string name, int damage); 
	void change(std::string name, int damage); 
	void show() const;

	int getDamage() const; 
	~Weapon(); 
private: 
	std::string m_name; 
	int m_damage;
};


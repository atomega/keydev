// cpp_training.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>
//#include "Personnage.h"

using namespace std;

void testingValRefPtr(); 
void testPointer(int *firstPointer);
void testPointer2(int *secondPointer);

int main()
{


	int myVar[32];
	for (int i = 0 ; i < 32; i++)
	{
		myVar[i] = i; 
	}

	cout << "myVar = " << myVar[0] << endl; 
	testPointer(myVar);
	cout << "myVar = " << myVar[0] << endl; 

    cout << "\n\n\n Reched end of Main" << endl;
    return 0; 
}



void testPointer(int *firstPointer)
{
	cout << "firstPOinter = " << (*firstPointer)<< endl; 
	testPointer2(firstPointer);
}

void testPointer2(int *secondPointer)
{
	*secondPointer += 2;	
	cout << "secondPointer = " << (*secondPointer)<< endl; 
}


void testingValRefPtr()
{
    std::cout << "##################################################" << endl;
    std::cout << "|| Var\t\t|| Value\t|| Address\t||" << endl;
    std::cout << "##################################################" << endl;
                                                                    
    int foo = 30;
    std::cout << "|| foo\t\t|| " << foo << "\t\t|| " << &foo << "\t||" << endl;
    
    int& ref = foo;
    std::cout << "|| &Ref = foo\t|| " << ref << "\t\t|| " << &ref << "\t||" << endl;
    
    int* ptr = 0;
    std::cout << "|| ptr = 0\t|| " << ptr << "\t|| " << &ptr << "\t||" << endl;
    
    ptr = &foo;
    std::cout << "|| ptr = &foo\t|| " << *ptr << "\t\t|| " << &ptr << "\t||" << endl;
    
    std::cout << "##################################################" << endl;

    delete ptr; 
    ptr = 0; 
}
/*
	int i = 0; 
    int j = 0; 
    int playerQte = 0;
    const int playerArraySize = 0; 
    string inputName = "unknown"; 
    string inputWeapon = "unknown"; 
    int inputDamage = 0;

    Personnage player[10];

    cout << "please selec the number of player that you want : "; 
    cin >> playerQte; 

    for (i = 0; i < playerQte; i++)
    {
        cout << "Player " << i+1 << " 's name : " << endl;
        cin >> inputName; 
        cout << "Player " << i+1 << " 's Wepaon name : " << endl;
        cin >> inputWeapon; 
        cout << "Player " << i+1 << " 's Wepaon Damage : " << endl;
        cin >> inputDamage;

        player[i].setName(inputName);
        player[i].changeWeapon(inputWeapon, inputDamage); 
    }

    for (i = 0; i <= playerQte; i++)
    {
        player[i].showStatus();
    }

    Personnage goliath("Sharpened blade", 20); // creating an overloaded Goliaht with new weapon.
    Personnage david(goliath);  // But david is jealous and want to be just like goliath. copy Constructor. 

    goliath.attac(david);   //goliath Attacs david
    david.dirnkPotion(20);  //david heals for 20 hp
    goliath.attac(david);   //goliath Attacs david back
    david.attac(goliath);   //david counter attack... and so on and so on.
    goliath.changeWeapon("Double hache tranchante venereuse de la mort", 40);
    goliath.attac(david);

    cout << "David" << endl;
    david.showStatus();
    cout << "Goliath" << endl; 
    goliath.showStatus(); 
*/ 

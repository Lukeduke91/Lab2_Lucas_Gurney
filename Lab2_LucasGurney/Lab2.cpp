#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Character
{
private:
	string name;
	int health;
public:
	Character(string n, int h)
	{
		name = n;
		health = h;
	}

	Character()
	{
		name = "No name";
		health = 0;
	}

	void setName(string N)
	{
		name = N;
	}

	void setHealth(int H)
	{
		health = H;
	}

	string getName()
	{
		return name;
	}

	int getHealth()
	{
		return health;
	}

	string getCharacterDescription()
	{
		string character = "\nCharacters name ====> " + name;
		character += "\nCharacters health =====> " + to_string(health) + "\n";
		return character;
	}

};

class Weapon: public Character
{
private:
	string weaponName;
	string description;
	int damageValue;
	string specialAbilities;
public:
	Weapon(string WN, string D, int DV, string SA)
	{
		weaponName = WN;
		description = D;
		damageValue = DV;
		specialAbilities = SA;
	}

	Weapon()
	{
		weaponName = "No name";
		description = "no description";
		damageValue = 0;
		specialAbilities = "No special abilities";
	}

	void setWeapon(string N)
	{
		weaponName = N;
	}

	void setDescription(string D)
	{
		description = D;
	}
		
	void setDamage(int DV)
	{
		damageValue = DV;
	}

	void setSpecialAbilities(string SA)
	{
		specialAbilities = SA;
	}

	string getWeapon()
	{
		return weaponName;
	}

	string getDescription()
	{
		return description;
	}

	int getDamage()
	{
		return damageValue;
	}

	string getSpecialAbilities()
	{
		return specialAbilities;
	}

	string getWeaponInformation()
	{
		string WeaponInfo = "\nWeapon Name ======> " + weaponName;
		WeaponInfo += "\nWeapon description ===> " + description;
		WeaponInfo += "\nWeapon damage value ===> " + to_string(damageValue);
		WeaponInfo += "\nWeapon ablility ===> " + specialAbilities + "\n";

		return WeaponInfo;
	}
};

class SpecialCharacter : private Character 
{
private:
	string specialName, specialAttack;
	int modifiedHealth;
public:
	SpecialCharacter(string SN, string SA, int MH)
	{
		specialName = SN;
		specialAttack = SA;
		modifiedHealth = MH;
	}

	SpecialCharacter()
	{
		specialName = "No name";
		specialAttack = "No special attack";
		modifiedHealth = 0;
	}

	void setSpecialName(string SN)
	{
		specialName = SN;
	}

	void setSpecialAttack(string SA)
	{
		specialAttack = SA;
	}

	void setModifiedHealth(int MH)
	{
		modifiedHealth = MH;
	}

	string getSpecialName()
	{
		return specialName;
	}

	string getSpecialAttack()
	{
		return specialAttack;
	}

	int getModifiedHealth()
	{
		return modifiedHealth;
	}

	string getSpecialCharacterDescription()
	{
		string specialCharacter = "\nNew characters last name =====> " + specialName;
		specialCharacter += "\nCharacters special attack =====> " + specialAttack;
		specialCharacter += "\nNew characters added health =====> " + to_string(getModifiedHealth()) + "\n";
		return specialCharacter;
	}
};

int main()
{
	const int limit = 9999;
	int option;
	int i = 0;

	char name[limit];
	char weapon[limit];
	char description[limit];
	char specialWeapon[limit];

	int finished1 = 0;
	int finished2 = 0;
	int finished3 = 0;
	int finished4 = 0;
	int finished5 = 0;
	int health;
	int damage;
	Character list[5];
	Weapon list1[5];
	SpecialCharacter list2[5];

	cout << "\tWelcome to my character creation." << endl;
	cout << "=======================================================" << endl;

	while (true)
	{
		cout << "\nWhat would you like to do: \n1. Create a new character. \n2. View your characters. \n3. Delete a character \n4. Exit." << endl;
		cin >> option;

		if (option == 1)
		{
			cout << "Which of the five save slots are you using: ";
			cin >> option;
			if (option == 1 && finished1 == 0)
			{
				i = 0;
				cout << "What is your name: ";
				cin.getline(name, limit);
				cin.getline(name, limit);
				cout << "How much health do you have: ";
				cin >> health;
				list[i] = Character(name, health);
				cout << "Here is your character:" << list[i].getCharacterDescription();

				cout << "Alright, now it is time to name your weapon.\nwhat do you want to name it: ";
				cin.getline(weapon, limit);
				cin.getline(weapon, limit);
				cout << "What does this weapon do: ";
				cin.getline(description, limit);
				cout << "How much damage does this weapon: ";
				cin >> damage;
				cout << "what is the weapons special ability: ";
				cin.getline(specialWeapon, limit);
				cin.getline(specialWeapon, limit);
				list1[i] = Weapon(weapon, description, damage, specialWeapon);
				cout << "Here is your Weapon: \n" << list1[i].getWeaponInformation();

				cout << "Alright, lets get more specific about your character.\nwhich race do you want to be: \n1.Elf \n2.Dwarves \n3.gnomes ";//1.Siannodel 2.balderk 3.beren
				cin >> option;
				if (option == 1)
				{
					list2[i] = SpecialCharacter("Siannodel ", "You are able move quickly allowing you to deal 45 more damage.", 20);
				}

				else if (option == 2)
				{
					list2[i] = SpecialCharacter("balderk ", "You are able to make one extra attack.", 30);
				}

				else if (option == 3)
				{
					list2[i] = SpecialCharacter("beren ", "You are harder to hit so you take half damage on some turns.", 15);
				}

				cout << "Alright here is your new character:\n" << list2[i].getSpecialCharacterDescription();
				finished1++;
			}
			
			else if (option == 2 && finished2 == 0)
			{
				i = 1;
				cout << "What is your name: ";
				cin.getline(name, limit);
				cin.getline(name, limit);
				cout << "How much health do you have: ";
				cin >> health;
				list[i] = Character(name, health);
				cout << "Here is your character:" << list[i].getCharacterDescription();

				cout << "Alright, now it is time to name your weapon.\nwhat do you want to name it: ";
				cin.getline(weapon, limit);
				cin.getline(weapon, limit);
				cout << "What does this weapon do: ";
				cin.getline(description, limit);
				cout << "How much damage does this weapon: ";
				cin >> damage;
				cout << "what is the weapons special ability: ";
				cin.getline(specialWeapon, limit);
				cin.getline(specialWeapon, limit);
				list1[i] = Weapon(weapon, description, damage, specialWeapon);
				cout << "Here is your Weapon: \n" << list1[i].getWeaponInformation();

				cout << "Alright, lets get more specific about your character.\nwhich race do you want to be: \n1.Elf \n2.Dwarves \n3.gnomes ";//1.Siannodel 2.balderk 3.beren
				cin >> option;
				if (option == 1)
				{
					list2[i] = SpecialCharacter("Siannodel ", "You are able move quickly allowing you to deal 45 more damage.", 20);
				}

				else if (option == 2)
				{
					list2[i] = SpecialCharacter("balderk ", "You are able to make one extra attack.", 30);
				}

				else if (option == 3)
				{
					list2[i] = SpecialCharacter("beren ", "You are harder to hit so you take half damage on some turns.", 15);
				}

				cout << "Alright here is your new character:\n" << list2[i].getSpecialCharacterDescription();
				finished2++;
			}

			else if (option == 3 && finished3 == 0)
			{
				i = 0;
				cout << "What is your name: ";
				cin.getline(name, limit);
				cin.getline(name, limit);
				cout << "How much health do you have: ";
				cin >> health;
				list[i] = Character(name, health);
				cout << "Here is your character:" << list[i].getCharacterDescription();

				cout << "Alright, now it is time to name your weapon.\nwhat do you want to name it: ";
				cin.getline(weapon, limit);
				cin.getline(weapon, limit);
				cout << "What does this weapon do: ";
				cin.getline(description, limit);
				cout << "How much damage does this weapon: ";
				cin >> damage;
				cout << "what is the weapons special ability: ";
				cin.getline(specialWeapon, limit);
				cin.getline(specialWeapon, limit);
				list1[i] = Weapon(weapon, description, damage, specialWeapon);
				cout << "Here is your Weapon: \n" << list1[i].getWeaponInformation();

				cout << "Alright, lets get more specific about your character.\nwhich race do you want to be: \n1.Elf \n2.Dwarves \n3.gnomes ";//1.Siannodel 2.balderk 3.beren
				cin >> option;
				if (option == 1)
				{
					list2[i] = SpecialCharacter("Siannodel ", "You are able move quickly allowing you to deal 45 more damage.", 20);
				}

				else if (option == 2)
				{
					list2[i] = SpecialCharacter("balderk ", "You are able to make one extra attack.", 30);
				}

				else if (option == 3)
				{
					list2[i] = SpecialCharacter("beren ", "You are harder to hit so you take half damage on some turns.", 15);
				}

				cout << "Alright here is your new character:\n" << list2[i].getSpecialCharacterDescription();
				finished3++;
			}

			else if (option == 4 && finished4 == 0)
			{
				i = 0;
				cout << "What is your name: ";
				cin.getline(name, limit);
				cin.getline(name, limit);
				cout << "How much health do you have: ";
				cin >> health;
				list[i] = Character(name, health);
				cout << "Here is your character:" << list[i].getCharacterDescription();

				cout << "Alright, now it is time to name your weapon.\nwhat do you want to name it: ";
				cin.getline(weapon, limit);
				cin.getline(weapon, limit);
				cout << "What does this weapon do: ";
				cin.getline(description, limit);
				cout << "How much damage does this weapon: ";
				cin >> damage;
				cout << "what is the weapons special ability: ";
				cin.getline(specialWeapon, limit);
				cin.getline(specialWeapon, limit);
				list1[i] = Weapon(weapon, description, damage, specialWeapon);
				cout << "Here is your Weapon: \n" << list1[i].getWeaponInformation();

				cout << "Alright, lets get more specific about your character.\nwhich race do you want to be: \n1.Elf \n2.Dwarves \n3.gnomes ";//1.Siannodel 2.balderk 3.beren
				cin >> option;
				if (option == 1)
				{
					list2[i] = SpecialCharacter("Siannodel ", "You are able move quickly allowing you to deal 45 more damage.", 20);
				}

				else if (option == 2)
				{
					list2[i] = SpecialCharacter("balderk ", "You are able to make one extra attack.", 30);
				}

				else if (option == 3)
				{
					list2[i] = SpecialCharacter("beren ", "You are harder to hit so you take half damage on some turns.", 15);
				}

				cout << "Alright here is your new character:\n" << list2[i].getSpecialCharacterDescription();
				finished4++;
			}

			else if (option == 5 && finished5 == 0)
			{
				i = 0;
				cout << "What is your name: ";
				cin.getline(name, limit);
				cin.getline(name, limit);
				cout << "How much health do you have: ";
				cin >> health;
				list[i] = Character(name, health);
				cout << "Here is your character:" << list[i].getCharacterDescription();

				cout << "Alright, now it is time to name your weapon.\nwhat do you want to name it: ";
				cin.getline(weapon, limit);
				cin.getline(weapon, limit);
				cout << "What does this weapon do: ";
				cin.getline(description, limit);
				cout << "How much damage does this weapon: ";
				cin >> damage;
				cout << "what is the weapons special ability: ";
				cin.getline(specialWeapon, limit);
				cin.getline(specialWeapon, limit);
				list1[i] = Weapon(weapon, description, damage, specialWeapon);
				cout << "Here is your Weapon: \n" << list1[i].getWeaponInformation();

				cout << "Alright, lets get more specific about your character.\nwhich race do you want to be: \n1.Elf \n2.Dwarves \n3.gnomes ";//1.Siannodel 2.balderk 3.beren
				cin >> option;
				if (option == 1)
				{
					list2[i] = SpecialCharacter("Siannodel ", "You are able move quickly allowing you to deal 45 more damage.", 20);
				}

				else if (option == 2)
				{
					list2[i] = SpecialCharacter("balderk ", "You are able to make one extra attack.", 30);
				}

				else if (option == 3)
				{
					list2[i] = SpecialCharacter("beren ", "You are harder to hit so you take half damage on some turns.", 15);
				}

				cout << "Alright here is your new character:\n" << list2[i].getSpecialCharacterDescription();
				finished5++;
			}

			else if (finished1 == 1 || finished2 == 1 || finished3 == 1 || finished4 == 1 || finished5 == 1)
			{
			cout << "Sorry, this save slots seem to have a character right know. pick another one or delete it to use that slot.\n";
			}
		}

		else if (option == 2)
		{
			int flame = 0;
			for (int l = 0; l < 5; l++)
			{
				cout << endl << ++flame << ": \n" << list[l].getCharacterDescription() << list1[l].getWeaponInformation() << list2[l].getSpecialCharacterDescription();
			}
		}

		else if (option == 3)
		{
			cout << "Which save slot would you like to delete?: ";
			cin >> option;
			if (option == 1)
			{
				--option;
				list[option] = Character();
				list1[option] = Weapon();
				list2[option] = SpecialCharacter();
				finished1 = 0;
					
			}

			if (option == 2)
			{
				--option;
				list[option] = Character();
				list1[option] = Weapon();
				list2[option] = SpecialCharacter();
			}

			if (option == 3)
			{
				--option;
				list[option] = Character();
				list1[option] = Weapon();
				list2[option] = SpecialCharacter();
			}
			
			if (option == 4)
			{
				--option;
				list[option] = Character();
				list1[option] = Weapon();
				list2[option] = SpecialCharacter();
			}

			if (option == 5)
			{
				--option;
				list[option] = Character();
				list1[option] = Weapon();
				list2[option] = SpecialCharacter();
			}
		}

		else if (option == 4)
		{
			cout << "Have a nice day sir." << endl;
			break;
		}
	}

	return 0;
}
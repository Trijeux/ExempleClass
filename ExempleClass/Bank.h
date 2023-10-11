/*=============================
 Author :	SOARES Christophe
 Date  :	08.10.2023
 ==============================*/

#pragma once
#include <string>

namespace Bank
{
	class UBS
	{
	public:
		#pragma region CONSTRUCTORS
		// Default constructor (optional)
		// If no constructor, C++ do it automatically
		UBS() = default; 

		// Constructor with "name" & "lastName" as parameter
		// The amount of CHF & EURO will be default (0.0f)
		UBS(std::string name, std::string lastName);

		// Constructor with "name" & "lastName" and the choice between the currency amount
		// Parameter:
		//	string name	-> The first name of the account owner
		//	string lastName	-> The last name of the account owner
		//	string currency	-> The currency type you have on the account ("CHF", "EURO")
		//	float amount	-> The amount of money you have on the account
		UBS(std::string name, std::string lastName, std::string currency, float amount);

		// Constructor with all properties as parameter.
		UBS(std::string name, std::string lastName, float amountCHF, float amountEURO);
		#pragma endregion

		#pragma region PROPERTIES
		// Public propertie "Name", default value -> null
		std::string Name;
		// Public propertie "LastName", default value -> null
		std::string LastName;
		#pragma endregion

		#pragma region METHODS
		// This method allows the user to send money to another account
		// Parameter:
		//	UBS receiver	-> The account that will receive the money
		//	string currency	-> The currency type you want to send ("CHF", "EURO")
		//	float amount	-> The amount of money you want to send
		void Transfer(UBS& receiver, std::string currency, float amount);

		// This method allows the user to deposit money to his account
		// Parameter:
		//	string currency	-> The currency type you want to deposit ("CHF", "EURO")
		//	float amount	-> The amount of money you want to deposit
		void Deposit(std::string currency, float amount);

		// This method allows the user to change a currency for another one
		// Parameter:
		//	string fromCurrency	-> The currency type you want to change ("CHF", "EURO")
		//	string toCurrency		-> The currency type you want to have ("CHF", "EURO")
		//	float amount		-> The amount of money you want to change
		void Change(std::string fromCurrency, std::string toCurrency, float amount);

		// This method shows the account information
		// Format:
		//	Name       :
		//	LastName   :
		//	amountCHF  :
		//	amountEURO :
		void ShowAccount();
		#pragma endregion

	private:
		#pragma region PROPERTIES
		// Private propertie "amountCHF", default value -> 0.0f
		float amountCHF = 0.0f;
		// Private propertie "amountEURO", default value -> 0.0f
		float amountEURO = 0.0f;
		#pragma endregion

		#pragma region METHODS
		// This method will show an error message when used
		// Parameter:
		//	string errType		-> The error that will be shown
		void err(std::string errType);
		#pragma endregion
	};

#pragma region COMMUN ERROR
	/* 
		C++ can't have two constructors with exactly the same variable type as parameter
		C++ don't care about the name of the variable

	ConstructorX(float varName1);
	ConstructorX(float varName2);
					||
					\/
			 Do that instead
	ConstructorX(float varName);
	ConstructorX(double varName);

		Changing the variable type in one of the constructor can solve the problem
	*/
	
	/*
		Adding a parameter to a function/method will copy the data of the variable
		Doing that will create a new object and won't affect the original one

	void Func(objetType objet);
					||
					\/
			 Do that instead
	void Func(objetType& objet);
		
		Adding & will create a reference to the object
		All modifications made to the reference will affect the original object
	*/
#pragma endregion
}



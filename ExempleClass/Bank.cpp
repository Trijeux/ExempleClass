/*=============================
 Author :	SOARES Christophe
 Date  :	08.10.2023
 ==============================*/

#include <iostream>
#include "Bank.h"

namespace Bank
{
	#pragma region CONSTRUCTORS
	UBS::UBS(std::string name, std::string lastName) : Name(name), LastName(lastName) {}

	UBS::UBS(std::string name, std::string lastName, std::string currency, float amount) : Name(name), LastName(lastName) 
	{
		if (currency=="CHF")
		{
			amountCHF += amount;
		}
		if (currency=="EURO")
		{
			amountEURO += amount;
		}
	}

	UBS::UBS(std::string name, std::string lastName, float amountCHF, float amountEURO) : Name(name), LastName(lastName), amountCHF(amountCHF), amountEURO(amountEURO) {}
	#pragma endregion

	#pragma region METHODS
	void UBS::Transfer(UBS& receiver, std::string currency, float amount)
	{
		// if the currency is CHF
		if (currency == "CHF")
		{
			// call the method "Deposit" from the receiver with CHF and the amount
			receiver.Deposit("CHF", amount);
			// subtract the amount to the sender's bank account CHF
			amountCHF -= amount;
			
		}// else if the currency is EURO
		else if (currency == "EURO")
		{
			// call the method "Deposit" from the receiver with EURO and the amount
			receiver.Deposit("EURO", amount);
			// subtract the amount to the sender's bank account EURO
			amountEURO -= amount;
		}
		else // else show an error from the receiver "currencyErr"
		{
			receiver.err("currencyErr");
		}
	}

	void UBS::Deposit(std::string currency, float amount)
	{
		// if the currency is CHF
		if (currency == "CHF")
		{
			// add the amount to the bank account CHF
			amountCHF += amount;

		}// else if the currency is EURO
		else if (currency == "EURO")
		{
			// add the amount to the bank account EURO
			amountEURO += amount;
		}
		else // else show an error "currencyErr"
		{
			err("currencyErr");
		}
	}

	void UBS::Change(std::string fromCurrency, std::string toCurrency, float amount)
	{
		float exchangeRateEuroCHF = 0.9646f;
		float exchangeRateCHFEuro = 1.0366f;

		// if the currency to change is CHF
		if (fromCurrency == "CHF")
		{	// if the currency to receive is EURO
			if (toCurrency == "EURO")
			{
				// subtract the amount to bank account CHF
				amountCHF -= amount;
				// add the amount to bank account EURO with the exchange rate
				amountEURO += amount * exchangeRateCHFEuro;
				// quit the function
				return;
			}
		}// else if the currency to change is EURO
		else if (fromCurrency == "EURO")
		{	// if the currency to receive is CHF
			if (toCurrency == "CHF")
			{
				// subtract the amount to bank account EURO
				amountEURO -= amount;
				// add the amount to bank account CHF with the exchange rate
				amountCHF += amount * exchangeRateEuroCHF;
				// quit the function
				return;
			}
		}

		// else show an error "currencyErr"
		err("currencyErr");

	}

	void UBS::ShowAccount()
	{
		std::cout << "Prenom		: " << Name << std::endl;
		std::cout << "Nom		: " << LastName << std::endl;
		std::cout << "Montant CHF	: " << amountCHF << std::endl;
		std::cout << "Montant EURO	: " << amountEURO << std::endl << std::endl;
	}

	void UBS::err(std::string errType)
	{
		std::cout << "Erreur de type : " << errType << std::endl << std::endl;
	}
	#pragma endregion

#pragma region COMMUN ERROR
	/*
		On a namespace, you can define multiple class in the header file (.h)
		To make your constructor or method do something, you need to tell C++ for which class it is

	func(param){}
			  ||
			  \/
		Do that instead
	className::func(param){}
	*/
#pragma endregion
}

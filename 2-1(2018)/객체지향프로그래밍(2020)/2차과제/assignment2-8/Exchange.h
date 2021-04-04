#pragma once
#include <iostream>
using namespace std;

class Exchange
{
public:
	void Print(double con_money, const char con_country[])
	{
		if (con_money != 0)
		{
			cout << round(con_money) << " " << con_country << "\n\n"; // round
		}
	}
};

class ToKRW : public Exchange
{
	double usd = 1200;
	double jpy = 11;
	double eur = 1300;
	double cny = 170;
	//exchange rate
	int conver_money = 0;

public:
	double Con_KRW(double price, char after_country[]);

};

double ToKRW::Con_KRW(double price, char before_country[])
{
	if (strcmp(before_country, "KRW") == 0)
	{
		conver_money = price;
	} // convert KRW
	else if (strcmp(before_country, "USD") == 0)
	{
		conver_money = price * usd; //convert USD to KRW
	}
	else if (strcmp(before_country, "JPY") == 0)
	{
		conver_money = price * jpy;  //convert JPY to KRW
	}
	else if (strcmp(before_country, "EUR") == 0)
	{
		conver_money = price * eur;  //convert EUR to KRW
	}
	else if (strcmp(before_country, "CNY") == 0)
	{
		conver_money = price * cny;  //convert CNY to KRW
	}

	return conver_money; //money exchanged
}

class ToUSD : public Exchange
{
	double usd = 1200;
	double conver_money = 0;

public:
	double Con_USD(double price)
	{
		conver_money = price / usd; //convert KRW to USD
		return conver_money;
	}
};

class ToJPY : public Exchange
{
	double jpy = 11;
	double conver_money = 0;

public:
	double Con_JPY(double price)
	{
		conver_money = price / jpy; //convert KRW to JPY
		return conver_money;
	}

};

class ToEUR : public Exchange
{
	double eur = 1300;
	double conver_money = 0;

public:
	double Con_EUR(double price)
	{
		conver_money = price / eur; //convert KRW to EUR
		return conver_money;
	}

};

class ToCNY : public Exchange
{
	double cny = 170;
	double conver_money = 0;

public:
	double Con_CNY(double price)
	{
		conver_money = price / cny; //convert KRW to CNY
		return conver_money;
	}

};

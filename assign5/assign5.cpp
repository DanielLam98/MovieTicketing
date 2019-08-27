// assign5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program can be used by a small theater to sell tickets for performances.

#include "pch.h"
#include <iostream>
#include <fstream> //required for external files
#include <conio.h> //required to hold output screen
#define in_file "data.txt"
void setUpChart();
void initial_chart();
int Menu();
using namespace std;
char chart[15][30];
float specific_row[16];
float Prices[16];
float TotalSales[16];
int main()
{
	ifstream ins;
	ins.open(in_file);
	int option, row, column;
	int answer;
	int quit = 1, counter = 450;
	double total_cost = 0.0, cost = 0.0;
	initial_chart();
	cout << "seats 123456789012345678901234567890" << endl;
	for (int row = 0; row < 15; row++)
	{
		cout << "row " << row + 1;
		for (int column = 0; column < 30; column++)
			cout << chart[row][column];
		cout << endl;
	}
	for (int i = 1; i < 16; i++) //initializing each row to 30 seats
	{
		specific_row[i] = 30;
	}
	for (int i = 1; i < 16; i++) //reads prices from file
	{
		ins >> Prices[i];
	}
	for (int i = 0; i < 16; i++)
		TotalSales[i] = 0.0;
	do
	{
		option = Menu();
		switch (option)
		{
		case 1:
		{
			cout << "PRINT CHART" << endl << endl; //displays the current chart to user
			setUpChart();
			break;
		}
		case 2:
			cout << "TOTAL AVAILABLE" << endl; //displays total availability
			cout << counter <<endl;
			break;
		case 3:
			cout << "TOTAL AVAILABLE FOR ROW" << endl;
			cout << "Enter the row " << endl;
			cin >> row;
			cout << specific_row[row] <<" are available for row " <<row<<endl; //displays the specific row availabilites
			break;
		case 4:
			cout << "PURCHASE TICKET" << endl; //prompts users a set of instructions to purchase a ticket
			do
			{
				cout << "select the row you would like to sit in" << endl;
				cin >> row;
				cout << "select the seat you would like to sit in" << endl;
				cin >> column;
				if (chart[row -1][column - 1] == '*')
				{
					cout << "That seat is taken" << endl;
					break;
				}
				else
				{
					cost = Prices[row];
					cout << "The ticket will be $" << cost << endl;
					cout << "Do you want to buy the ticket? (1 = yes, 2 = no)" << endl;
					cin >> answer;
					if (answer == 1)
					{
						cout << "You have successfully purchased your ticket" << endl;
						chart[row -1][column-1] = '*'; //replaces the empty seat with a occupied seat
						TotalSales[row] += Prices[row]; //totals up sales for each individual row
						total_cost += Prices[row]; //totals up sales for the entire theatre
						counter--; //used for seats occupied
						specific_row[row]--; //used for seats occupied in a specific row
						break;
					}
					else if (answer == 2)
						break;
				}
			}
			while (quit == 1);
			break;
		case 5:
			cout << "TOTAL SALES FOR WHOLE THEATRE" << endl; //displays total sales for entire theatre and for each row
			for (int row = 1; row <= 15; row++)
				cout <<row << " $"<< TotalSales[row] <<endl;
			cout << endl << "The total sales of all the rows will be: $"<< total_cost << endl;
			break;
		case 6:
			cout << "QUIT" << endl; //exits the program
			break;

		default: cout << "Wrong input";
		}
	} while (option != 6);
	return 0;
}
int Menu()
{
	int choice;
	cout << endl;
	cout << "MENU" << endl;
	cout << "1) PRINT CHART" << endl;
	cout << "2) TOTAL AVAILABLE" << endl;
	cout << "3) TOTAL AVAILABLE FOR ROW" << endl;
	cout << "4) PURCHASE TICKET" << endl;
	cout << "5) TOTAL SALES FOR WHOLE THEATRE" << endl;
	cout << "6) quit" << endl<<endl;
	cin >> choice; //prompts user for choice
	cout << endl;
	return choice;
}
void setUpChart() //displays the current seats including taken seats
{
	for (int row = 0; row < 15; row++)
	{
		cout << "row " << row + 1;
		for (int column = 0; column < 30; column++)
			cout << chart[row][column];
		cout << endl;
	}
}
void initial_chart() //initial display of seats
{
	for (int row = 0; row < 15; row++)
		for (int column = 0; column < 30; column++)
			chart[row][column] = '#';
}
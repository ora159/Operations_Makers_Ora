// Operations_Makers_Ora.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Ora Bitan
// Operations_Maker.cpp : 
// 
#include <iostream>
#include<string.h>
#include <conio.h>
#include <time.h>
#include <ctime>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include<ostream>
#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;


int count_setions = 0;
const char* Operations_Array[] = { "canceling operation", "waiting operation", "blocking operation", "undefined operation","success operation","special operation" };

void view_option()
{
	cout << "Welcome, what option would you like to perform?\n"
		<< "to start press Y to stop press N.\n"
		<< "You can press E at any time to stop the operation.\n ";
}
void operations_maker(char* dt_s)
{
	bool OperationStatus = true;
	int seconds = 0;
	int count_suc = 0;
	int count_block = 0;
	int count_spe = 0;
	char dt[26]{};
	int randNum;


	//open file for writing
	
	ofstream myfile_0;
	myfile_0.open("canceling.log", ofstream::app);
	ofstream myfile_1;
	myfile_1.open("waiting.log", ofstream::app);
	ofstream myfile_2;
	myfile_2.open("blocking.log", ofstream::app);
	ofstream myfile_3;
	myfile_3.open("undefined.log", ofstream::app);
	ofstream myfile_4;
	myfile_4.open("success.log", ofstream::app);
	ofstream myfile_5;
	myfile_5.open("special.log", ofstream::app);

	myfile_0.seekp(ios::end);
	myfile_1.seekp(ios::end);
	myfile_2.seekp(ios::end);
	myfile_3.seekp(ios::end);
	myfile_4.seekp(ios::end);
	myfile_5.seekp(ios::end);

	//cout << "setion number:  " << count_setions << endl;
	myfile_0 << "The setion time and date is:" << dt_s << "\n";
	myfile_0 << "*****************************************\n";
	myfile_1 << "The setion time and date is:" << dt_s << "\n";
	myfile_1 << "*****************************************\n";
	myfile_2 << "The setion time and date is:" << dt_s << "\n";
	myfile_2 << "*****************************************\n";
	myfile_3 << "The setion time and date is:" << dt_s << "\n";
	myfile_3 << "*****************************************\n";
	myfile_4 << "The setion time and date is:" << dt_s << "\n";
	myfile_4 << "*****************************************\n";
	myfile_5 << "The setion time and date is:" << dt_s << "\n";
	myfile_5 << "*****************************************\n";

	
	while (OperationStatus)
	{
		//second in 00:00:00 format
		printf("%02i:%02i:%02i\n", (seconds / 60 * 60) % 60, (seconds / 60) % 60, seconds % 60);
		seconds++;
		time_t now = time(NULL);
		//rand one string from the Operations_Array[7] every second.
		//rand a number 0-6 and print the string in the Array[randNum].
		randNum = rand() % 6;
		//print random string
		//printRandOperation();
		switch (randNum)
		{
		case 0:
		{
			// code block
			cout << "waiting operation" << endl;
			ctime_s(dt, sizeof dt, &now);

			myfile_1 << "The operation time : " << dt << "\n";
			myfile_1 << "**************************************\n";
			break;
		}
		case 1:
			{
			cout << "waiting operation" << endl;
			ctime_s(dt, sizeof dt, &now);

			myfile_1 << "The operation time : " << dt << "\n";
			myfile_1 << "**************************************\n";
			break;
			}
			
		case 2:
		{
			count_block++;
			cout << "blocking operation" << endl;
			ctime_s(dt, sizeof dt, &now);
			myfile_2 << "The operation time : " << dt << "\n";
			myfile_2 << "**************************************\n";
			break;
		}
		case 3:
		{
			cout << "undefined operation \n";
			ctime_s(dt, sizeof dt, &now);
			myfile_3 << "The operation time : " << dt << "\n";
			myfile_3 << "**************************************\n";
			break;
		}
			
		case 4:
			count_suc++;
			cout << "success operation\n";
			ctime_s(dt, sizeof dt, &now);
			myfile_4 << "The operation time: " << dt << "\n";
			myfile_4 << "**************************************\n";
			break;
		case 5:
			count_spe++;
			cout << "special operation\n";
			ctime_s(dt, sizeof dt, &now);
			myfile_5 << "The operation time: " << dt << "\n";
			myfile_5 << "**************************************\n";
			break;
		}
		
		
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'E'://exit
			{
				cout << "the setion is finish" << endl;
				myfile_2.seekp(ios::end);
				myfile_4.seekp(ios::end);
				myfile_2 << dt << "\n In this setion ther are :" << count_block << " blocking\n";
				myfile_4 << dt << "\n In this setion ther are :" << count_suc << " sucsses\n";
				myfile_5.seekp(ios::end);
				float avg_s = ((float)count_spe / count_setions);
				myfile_5 << "\n The AVG of special operation is: " << avg_s << "\n";
				//close the files
				myfile_0.close();
				myfile_1.close();
				myfile_2.close();
				myfile_3.close();
				myfile_4.close();
				myfile_5.close();

				OperationStatus = false;
				break;
			}
			case 'ETX'://ctr-C in ASCII code.
				cout << "the setion is finish \n" << endl;
				OperationStatus = false;
				break;
			default:
				//cout << "the operation continue" << endl;
				break;
			}


		}
		

		

	}
	
	
	
}


int main()
{
	//the start number for the rand function.
	srand((unsigned)time(NULL));
	//time_t setion_time = time(0);
	char dt_setion[26];
	bool flag = true;

	while (flag)
	{
		view_option();
		switch (_getch())
		{
		case 'Y':
		{
			cout << "START OPERATION" << endl;
			time_t setion_time = time(0);
			// convert setion_time to string form
			ctime_s(dt_setion, sizeof dt_setion, &setion_time);
			count_setions++;
			operations_maker(dt_setion);
			view_option();
			break;
		}
			
		case 'N':
			return 0;

		default:
			cout << "You must choose only Y / N / E." << endl;
			break;
		}
	}
}

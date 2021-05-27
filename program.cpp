//============================================================================
// Name        : project_1.cpp
// Author      : Kudrin Semen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <fstream>

using namespace std;

float summ;
long stop_num = 1;
long menu_num = 10;
long num;
long new_num;
float new_price;
string new_name;
string new_can_name;
long del_num;
long num_del;


ofstream fout;				// for txt


class can {	//class can
public:

	long number;
	string name;
	float price;
	int count;


	can ( long valueNumber, string valueName, float valuePrice ){ //constr for can

	number = valueNumber;
	name = valueName;
	price = valuePrice;
	count = 0;
}

	void summa(){

			summ = summ + price*count;
	}

	void receipt(){
		if(count != 0){
			fout<< count << "x " << name << " (" << price << " eur)"<< endl ;
		}
	}


	long get_num(){
		return number;
	}
};


int main() {


	list<can*> can_list;	// who already known

	can_list.push_back(new can(9002490100773, "Can of Red Bull, 0,25 liters", 0.15));
	can_list.push_back(new can(6415600501781, "Plastic Bottle of Coca-cola, 0,5 liters", 0.20));
	can_list.push_back(new can(5410228141266, "Glass Bottle of Stella Artois beer, 0.33 liters", 0.1));






while(num != stop_num){
	cin >> num;
	bool a = 0;
	for(auto it = can_list.begin(); it != can_list.end(); it++){
		if(num == (*it)->number){
			a = 1;
			(*it)->count ++;
			break;
		}
	}
	if(!a && num != 10 && num != 1){
		cout<<"EAN code not recognized"<< endl;
	}


if (num == menu_num){

	cout << "-------------" << endl;
	cout << "1) Add new EAN code" << endl;
	cout << "2) Remove existing EAN code" << endl;
	cout << "3) Save changes and return to normal mode" << endl;

	short choice = 0;
	while(choice != 3){

		cin >> choice;
		cout << "Choice: " << choice << endl;

		switch(choice){

		case 1:{
			cout << "-------------" << endl;
			cout << "New EAN code: ";
			cin >> new_num;
			cout << endl << "Article name: ";
			cin.ignore();
			getline(cin, new_can_name);
			cout << endl << "Refund price: ";
			cin >> new_price;
			cout << endl;

			bool ifboo = 0;
			for(auto it = can_list.begin(); it != can_list.end(); it++){
				if(new_num == (*it)->number){
					ifboo = 1;
							break;
				}

			}
			if(ifboo){
				cout << "this EAN code is already installed" << endl;
			}

			else{
			can_list.push_back(new can(new_num, new_can_name, new_price));	//new can
			}
			cout << "-------------" << endl;
			cout << "1) Add new EAN code" << endl;
			cout << "2) Remove existing EAN code" << endl;
			cout << "3) Save changes and return to normal mode" << endl;

		}
		break;


		case 2:{									//delete can
			cout <<"EAN code to be removed: ";
			cin >> num_del;
			for(auto it = can_list.begin(); it != can_list.end(); it++){
					if((*it)->number == num_del){
						can_list.erase(it);
					}
			}
			cout << "-------------" << endl;
			cout << "1) Add new EAN code" << endl;
			cout << "2) Remove existing EAN code" << endl;
			cout << "3) Save changes and return to normal mode" << endl;
		}
		break;

		case 3:
			cout << "-------------" << endl;
		break;
		}
	}
	choice = 0;
}
}


	for(auto it = can_list.begin(); it != can_list.end(); it++){
		(*it)->summa();
	}

cout << "-------------" << endl;
cout << "Recycling finished." << endl;
cout << "Total amount of refund is " << summ << " euros.";

fout.open("receipt.txt", ofstream::trunc);

for(auto it = can_list.begin(); it != can_list.end(); it++){
	(*it)->receipt();
}
fout<<"Total: "<< summ << " eur" << endl;
fout.close();
return 0;
}

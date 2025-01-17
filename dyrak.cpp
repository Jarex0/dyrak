#include <iostream>
#include<vector>
#include<iomanip>
#include <string>
#include <algorithm>

using namespace std;


const vector<int> rang{ 6,7,8,9,10,11,12,13,14 };
const vector<char> mast{ 3,4 };// , 5, 6 };
bool x = true;
bool y = true;
bool ff = true;


class Deck
{
public:

	Deck(const vector <int>& p_cart, const vector<char>& p_mas)
	{
		string tmp;
		
		for (int j = 0; j < p_mas.size(); j++)
		{
			for (int i = 0; i < p_cart.size(); i++)
			{
				
				tmp = to_string(p_cart[i]) + (char(p_mas[j]));
				card.push_back(tmp);
			}
		}

	};
	~Deck() {}

	void Start()
	{
		cout << "Player 1: ";
		for (int i = 0; i < 6; i++)
		{
			int tmp = rand() % card.size();
			p1.push_back(card[tmp]);
			cout << p1[i]<<"\t";
			card.erase(card.begin()+tmp);
		}
		cout <<"\n";


		cout << "Player 2: ";
		for (int i = 0; i < 6; i++)
		{
			int tmp = rand() % card.size();
			p2.push_back(card[tmp]);
			cout << p2[i] << "\t";
			card.erase(card.begin() + tmp);
		}
		cout << "\n";		


		int kz = rand() % card.size();
		koz.push_back(card[kz]);
		card.erase(card.begin() + kz);
		string kozc = koz[0];
		kozch = kozc[(kozc.size() - 1)];
		cout << "\n\t\t\t\t\t\t\t\t" << koz[0] << "-" << card.size() << endl;
	}

	void PrintDeck1()
	{
		cout << "Hand player 1:  ";
		for (auto x : p1)
			cout <<x << "\t";
		cout << endl << endl;
	}

	void PrintDeck2()
	{
		cout << "Hand player 2:  ";
		for (auto x : p2)
			cout << x << "\t";
		cout << endl<<endl;
	}

	void printKoz()
	{		
		cout << "Card in Deck - " << card.size() << "\t\n";
		if (!koz.empty())
			cout << "koz - " << koz[0] << endl << endl;
		else
			cout <<"koz - "<<kozch<<endl;
		if(!table.empty())
		{
			for (int i = 0; i <= table.size() - 1; i++)
			{

				if (i % 2 == 0 && i != 0)
				{
					cout << endl;
				}
				cout << "para" << (i / 2) + 1 << ":  " << table[i] << "\t";
			}
		}
		cout << endl;
		//PrintDeck1();
		//PrintDeck2();
	}

	
	int Move1(bool pos)
	{		
		
		int k1{};
		bool moove1 = false;
		ff = true;
		if(pos)		
		{			
			if (!p1.empty())
			{
				system("cls");
				printKoz();
				PrintDeck1();
				cout << "p1.Enter num card: ";
				cin >> k1;
				while (k1 > p1.size())
				{
					cout << "Enter correct num card at 1 to " << p1.size() << " - ";
					cin >> k1;					
				}
				if (table.empty())
				{
					table.push_back(p1[k1 - 1]);
					stolew.push_back(stoi(p1[k1 - 1]));
					//cout << p1[k1 - 1] << endl;
					cout << endl;
				}
				else
				{
					do
					{
						vector <int> ::iterator f;
						f = find(stolew.begin(), stolew.end(), stoi(p1[k1 - 1]));
						if (f != stolew.end())
						{
							table.push_back(p1[k1 - 1]);
							stolew.push_back(stoi(p1[k1 - 1]));
							//cout << p1[k1 - 1] << endl;
							moove1 = true;
							cout << "mojno" << endl;
							system("cls");
						}						
						else
						{
							k1 = 999;
							while (k1 > p1.size())
							{
								system("cls");
								cout << "Poprobui ewe raz!\n";
								printKoz();
								PrintDeck1();
								cout << "Enter correct num cardDDD 1 to " << p1.size() << "\nor enter '111' if you don't have a card\n";
								cin >> k1;
								system("cls");
								if (k1 == 111)
								{
									moove1 = true;
									break;
								}
							}
						}
					} while (moove1 != true);
					moove1 = false;
				}
			}
			else
			{
				cout << "Hand without card\n";
				y = false;
			}
		}
		else
		{
			system("cls");
			int keq1;
			do
			{
				printKoz();
				PrintDeck1();
				cout<<"p1.select an option:\n"
					<< "Bitsya - 1" << endl
					<< "Bzyat' - 2" << endl;
				cin >> keq1;
				system("cls");
			}while (keq1 < 1 || keq1 > 2);

			 switch (keq1)
			 {
				 case 1:
				 {
					 printKoz();
					 PrintDeck1();
					 cout << "enter num card: "; cin >> k1;
					 if (!p1.empty())
					 {
						// cout << "p1.size= " << p1.size();
						 while (k1 > p1.size())
						 {
							 printKoz();
							 PrintDeck1();
							 cout << "Enter correct num card at 1 to " << p1.size() << " - ";
							 cin >> k1;
							 system("cls");
						 }
						 table.push_back(p1[k1 - 1]);
						 stolew.push_back(stoi(p1[k1 - 1]));
						 //cout << p1[k1 - 1] << endl;
					 }
					 else
					 {
						 cout << "Hand without card\n";
						 y = false;
					 }
					 break;
				 }
				 case 2:
				 {	
					 ff = false;					
					 break;
				 }
			 }
		}
		return k1;
	}	
	
	int Move2(bool pos)
	{
		
		int k2{};
		bool moove2 = false;
		ff = true;
		if (!pos)
		{			
			if (!p2.empty())
			{
				system("cls");
				printKoz();
				PrintDeck2();
				cout << "p2.Enter num card: ";
				cin >> k2;
				while (k2 > p2.size())
				{
					system("cls");
					printKoz();
					PrintDeck2();
					cout << "Enter correct num card at 1 to " << p2.size() << " - ";
					cin >> k2;
					system("cls");
				}
				if (table.empty())
				{
					table.push_back(p2[k2 - 1]);
					stolew.push_back(stoi(p2[k2 - 1]));
					//cout << p2[k2 - 1] << endl;
				}
				else
				{
					do
					{
						vector <int> ::iterator f;
						f = find(stolew.begin(), stolew.end(), stoi(p2[k2 - 1]));
						if (f != stolew.end())
						{
							table.push_back(p2[k2 - 1]);
							stolew.push_back(stoi(p2[k2 - 1]));
							//cout << p2[k2 - 1] << endl;
							moove2 = true;
							cout << "mojno" << endl;
							system("cls");
						}
						else
						{
							k2 = 999;
							while (k2 > p2.size())
							{
								system("cls");
								cout << "Poprobui ewe raz!\n";
								printKoz();
								PrintDeck2();
								cout << "Enter correct num cardDDD 1 to " << p2.size() << "\nor enter '111' if you don't have a card\n";
								cin >> k2;
								system("cls");
								if (k2 == 111)
								{
									moove2 = true;
									break;
								}
							}
						}
					} while (moove2 != true);
					moove2 = false;									
				}
			}
			else
			{
				cout << "Hand without card\n";
				y = false;
			}
		}
		else
		{
			system("cls");
			int keq1;
			do
			{
				printKoz();
				PrintDeck2();
				cout << "p2.select an option:\n"
					<< "Bitsya - 1" << endl
					<< "Bzyat' - 2" << endl;
				cin >> keq1;
				system("cls");
			} while (keq1 < 1 || keq1 > 2);

			switch (keq1)
			{
			case 1:
			{
				printKoz();
				PrintDeck2();
				cout << "enter num card: "; cin >> k2;
				if (!p2.empty())
				{
					while (k2 > p2.size())
					{
						cout << "Enter correct num card at 1 to " << p2.size() << " - ";
						cin >> k2;
					}
					table.push_back(p2[k2 - 1]);
					stolew.push_back(stoi(p2[k2 - 1]));
					//cout << p2[k2 - 1] << endl;
				}
				else
				{
					cout << "Hand without card\n";
					y = false;
				}
				break;
			}
			case 2:
			{
				ff = false;
				break;
			}
			}
			
		}
		return k2;
	}

	bool Take()
	{
		PrintDeck1();
		PrintDeck2();
		printKoz();
		table.clear();
		stolew.clear();
		//cout<<"\np1.size= "<<p1.size()<<endl;
		//printKoz();
		cout << "Player 1: ";
		if(p1.size()<6)
		{
			for (int i = p1.size(); i < 6; i++)
			{
				if (!card.empty())
				{
					int tmp = rand() % card.size();
					p1.push_back(card[tmp]);
					cout << p1[i] << "\t";
					card.erase(card.begin() + tmp);
				}
				else if (!koz.empty())
				{
					p1.push_back(koz[0]);
					cout << p1[i] << "\t";
					koz.erase(koz.begin());
				}
			}
		}
		cout << "\n";
	
		cout << "Player 2: ";
		if(p2.size()<6)
		{
			for (int i = p2.size(); i < 6; i++)
			{
				if (!card.empty())
				{
					int tmp = rand() % card.size();
					p2.push_back(card[tmp]);
					cout << p2[i] << "\t";
					card.erase(card.begin() + tmp);
				}
				else if (!koz.empty())
				{				
						p2.push_back(koz[0]);
						cout << p2[i] << "\t";
						koz.erase(koz.begin());
				}						
			}
		}
		cout << "\n";
		y = true;
		return x;
	}

	bool Game()
	{
		if (card.empty()&&koz.empty()&&(p1.empty()||p2.empty()))
		{
			x = false;

			cout << "gameover\n";
		}
		return x;
	}

	void Fight(int &ka1, int &ka2, bool pos)
	{
		int q1, q2;
		char w1, w2;
		bool Tfight = false;
		do {
			if(ff==true)
			{
				q1 = stoi(p1[ka1 - 1]);
				q2 = stoi(p2[ka2 - 1]);
				if (q1 >= 10)
				{
					w1 = char(p1[ka1 - 1][2]);
				}
				else
				{
					w1 = char(p1[ka1 - 1][1]);
				}
				if (q2 >= 10)
				{
					w2 = char(p2[ka2 - 1][2]);
				}
				else
				{
					w2 = char(p2[ka2 - 1][1]);
				}

				if (pos)
				{
					if ((q1 <= q2 && w1 == w2) || (w1 == w2 == char(kozch) && q1 <= q2) || (w2 == char(kozch) && w1 != w2))
					{
						p1.erase(p1.begin() + ka1 - 1);
						p2.erase(p2.begin() + ka2 - 1);
						cout << "\nMolodec" << endl;
						Tfight = true;
						system("cls");
					}
					else
					{							
						cout << "\nNot molodec" << endl;
						table.erase(table.begin() + table.size() - 1);
						stolew.erase(stolew.begin() + stolew.size() - 1);
						int* ka22{ &ka2 };
						system("cls");
						cout << "NE OBMANESH!!!!\n";
						*ka22 = Move2(pos);							
					}
				}
				else
				{
					if ((q2 <= q1 && w2 == w1) || (w2 == w1 == char(kozch) && q2 <= q1) || (w1 == char(kozch) && w2 != w1))
					{
						p1.erase(p1.begin() + ka1 - 1);
						p2.erase(p2.begin() + ka2 - 1);
						cout << "\nMolodec" << endl;
						Tfight = true;
						system("cls");
					}
					else
					{						
						cout << "\nNot molodec" << endl;
						table.erase(table.begin() + table.size() - 1);
						stolew.erase(stolew.begin() + stolew.size() - 1);
						int* ka11{ &ka1};
						system("cls");
						cout << "NE OBMANESH!!!!\n";
						*ka11 = Move1(pos);
					}						
				}		
			}
			else
			{
				if (pos)
				{
					cout << "4ywka\n";
					p1.erase(p1.begin() + ka1 - 1);
					Zabor(pos);
					Take();
					Tfight = true;
				}
				else
				{
					cout << "lowka\n";
					p2.erase(p2.begin() + ka2 - 1);
					Zabor(pos);
					Take();
					Tfight = true;
				}
			}
		} while (Tfight != true);
	}
	void Zabor(bool pos)
	{
		if(!pos)
		{
			for (auto x : table)
				p1.push_back(x);
		}
		else
		{
			for (auto x : table)	
				p2.push_back(x);
		}
		//table.clear();
		//stolew.clear();
	}
	void PrintTable()
	{
		if (!table.empty())
		{
			for (int i = 0; i <= table.size() - 1; i++)
			{

				if (i % 2 == 0 && i != 0)
				{
					cout << endl;
				}
				cout << "para" << (i / 2) + 1 << ":  " << table[i] << "\t";
			}
		}
		cout << endl;
		//for (auto x : table)
		//	cout << x << " ";
		//cout << endl;
	}	
	void test()
	{
		int q1;
		char w1;
		q1 = stoi(p1[3]);
		if(q1>=10)
		{		
			w1 = char(p1[3][2]);
		}
		else
		{			
			w1 = char(p1[3][1]);
		}


		int q2;
		char w2;
		q2 = stoi(p2[3]);
		if (q2 >= 10)
		{
			w2 = char(p2[3][2]);
		}
		else
		{
			w2 = char(p2[3][1]);
		}

		cout << endl << p1[3] << endl << q1 << endl << w1 << endl;
		cout << endl << p2[3] << endl << q2 << endl << w2 << endl;

		if ((q1 <= q2) && (w1 == w2))
		{
			cout << "molodec" << endl;
		}
		else
		{
			cout << "He pravilno" << endl;
		}


	}
	
private:
	vector<string> card;
	vector<string> p1;
	vector<string> p2;
	vector<string> koz;
	vector<string> table;
	vector <int> stolew;
	char kozch{};
};

int main()
{
	srand(time(0));
	Deck car{ rang,mast };	

	car.Start();

	int a{};
	int b{};
	bool pos = true;
	int key, players=1;

	while (x != false)
	{	
		cout << endl << endl <<"x= "<< x << endl << endl;
		while (y != false)
		{
			if (car.Game() == false)
				break;
		//	cout << "\nY= " << y<<"\n";
			if (pos==true)
			{
				players =1;
			}
			else
			{
				players =2;
			}
			do
			{
				cout << "\n\n";
				if (pos)
				{
					car.PrintDeck1();
				}
				else
				{
					car.PrintDeck2();
				}
				system("cls");
				if (pos)
				{
					car.printKoz();
					car.PrintDeck1();
				}
				else
				{
					car.printKoz();
					car.PrintDeck2();
				}
				cout << "Players " << players << " enter move : \n"
					<< "1.Podbros\n"
					<< "2.bita\n"
					<< "3.Bzyat'\n"
					<< "4.KozblRb\n"
					<< "5. Exit\n";					
				cout << "your choice: ";
				cin >> key;
					cout << endl;
			} while (key < 1 || key>6);
			car.Game();
			switch (key)
			{
			case 1:
			{
				"podbros";
				if (pos)
				{
					if (car.Game() == false)
					{
						break;
					}
					else
					{
						a = car.Move1(pos);
						if (a == 111)
						{
							car.Take();
							pos = !pos;
						}
						else
						{
							b = car.Move2(pos);
							car.Fight(a, b, pos);
						}
						//system("cls");
						car.printKoz();
					}
				}
				else
				{
					if(car.Game()==false)
					{
						break;
					}
					else
					{
						b = car.Move2(pos);
						if (b == 111)
						{
							car.Take();
							pos = !pos;
						}
						else
						{
							a = car.Move1(pos);
							car.Fight(a, b, pos);
						}
						//system("cls");
						car.printKoz();
					}
				}
				break;
			}
			case 2:
			{
				"Bita";
				car.Take();
				pos = !pos;
				//system("cls");
				break;
			}
			case 3:
			{
				"Bzyat'";
				car.Zabor(pos);
				car.Take();
				//system("cls");

				break;
			}
			case 4:
			{
				//system("cls");
				car.printKoz();

				break;
			}
			case 5:
			{
				exit(0);
			}
			//system("cls");			
			}
			car.Game();
		}
	}
	system("cls");
	cout << "YRA!!!!!!KONEC!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	system("pause");
}
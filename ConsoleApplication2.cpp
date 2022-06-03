#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <fstream>
#include <nlohmann/json.hpp>

bool loadPatch();
void drawInf(short int* pos, bool* leadV, std::vector<char>& arr_load, float* hp, float* hk, float* dh, float* r);
void leadDefV(float* nf, bool* lead, short int* lockk);
void Warning(int num_code, const char text[50]);
void leh_text(int* js, const char text[25]);
void us_ffInsertF(float* h, float* hp, float* hk, float* dh, float* r, double* S, double* I, bool* xs, char* path);
void us_whInsertF(float* h, float* hp, float* hk, float* dh, float* r, double* S, double* I, bool* xs, char* path);
void us_dWHInsertF(float* h, float* hp, float* hk, float* dh, float* r, double* S, double* I, bool* xs, char* path);
void DrawLineDecoration(int a, int b);
void DrawResultONInterface(short int* pos, void (*xmathCount)(float* h, float* hp, float* hk, float* dh, float* r, double* S, double* I, bool* xs, char* path), float* h, float* hp, float* hk, float* dh, float* r, double* S, double* I, bool* xs, short int* pp, char* path);
int opensf(float* h, float* hp, float* hk, float* dh, float* R, bool* lead, short int* lockk, char* txt);
void rdValue(char* txtIN, char* txtOUT);
void updateps(char* txtIN, char* txtOUT);

HANDLE console_cf;
CONSOLE_CURSOR_INFO cursorcf;

int main()
{
	system("chcp 437");
	Sleep(1000);
	srand(time(NULL));
	SetConsoleTitle(L"LB v0.1 Beta");
	console_cf = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(console_cf, &cursorcf);
	cursorcf.bVisible = false;
	SetConsoleCursorInfo(console_cf, &cursorcf);
	short int clBX = 3, lockk = 1, pos = 2;
	bool stat_work = 1, leadV = 0;
	float H, Hp, Hk, dH, R;
	double I, S = 0;
	char pathffile[42] = "INPUT.txt";
	char pathffile2[30] = "OUTPUT.txt";
	std::vector<char> movel;
	char lds[] = "PLEASE ENTER THE VALUE OF ALL VARIABLES; TO DO THIS, PRESS ITEM ONE     ";
	SetConsoleTextAttribute(console_cf, 6);
	rdValue(pathffile, pathffile2);
	for (int x = 0; x != strlen(lds); x++)
	{
		movel.push_back(lds[x]);
	}
	if (!loadPatch())
	{
		do
		{
			drawInf(&clBX, &leadV, movel, &Hp, &Hk, &dH, &R);
			if (_kbhit())
			{
				switch (_getch())
				{
				case 'w': clBX--; break;
				case 's': clBX++; break;
				case 'x':
					if (clBX == 3)
					{
						leadDefV(&Hp, &leadV, &lockk);
						lockk++;
						leadDefV(&Hk, &leadV, &lockk);
						lockk++;
						leadDefV(&dH, &leadV, &lockk);
						lockk++;
						leadDefV(&R, &leadV, &lockk);
						if (Hp > Hk)
						{
							Warning(16, "You have entered invalid values!");
							leadV = 0;
						}
					}
					else if (clBX == 4)
					{
						if (leadV && !(std::ifstream(pathffile).is_open()))
						{
							DrawResultONInterface(&pos, us_ffInsertF, &H, &Hp, &Hk, &dH, &R, &S, &I, &stat_work, &clBX, pathffile2);
						}
						else if (leadV && (std::ifstream(pathffile).is_open()))
						{
							char agree;
							do
							{
								system("cls");
								std::cout << "\nDo you want to use the file for work?( Y <|> N):"; std::cin >> agree;
								if (agree == 'Y' || agree == 'N' || agree == 'y' || agree == 'n')
								{
									break;
								}
							} while (true);
							if (agree == 'y' || agree == 'Y')
							{
								if (opensf(&H, &Hp, &Hk, &dH, &R, &leadV, &lockk, pathffile) != 33)
								{
									DrawResultONInterface(&pos, us_ffInsertF, &H, &Hp, &Hk, &dH, &R, &S, &I, &stat_work, &clBX, pathffile2);
								}
							}
							else
							{
								DrawResultONInterface(&pos, us_ffInsertF, &H, &Hp, &Hk, &dH, &R, &S, &I, &stat_work, &clBX, pathffile2);
							}
						}
						else if (!leadV && !std::ifstream(pathffile).is_open())
						{
							Warning(11, "There is not one source for taking values!");
						}
						else
						{
							if (opensf(&H, &Hp, &Hk, &dH, &R, &leadV, &lockk, pathffile) != 33)
							{
								leadV = 1;
								Warning(16, "Used data from a file");
								DrawResultONInterface(&pos, us_ffInsertF, &H, &Hp, &Hk, &dH, &R, &S, &I, &stat_work, &clBX, pathffile2);
							}
						}

					}
					else if (clBX == 5)
					{
						if (leadV && !(std::ifstream(pathffile).is_open()))
						{
							DrawResultONInterface(&pos, us_whInsertF, &H, &Hp, &Hk, &dH, &R, &S, &I, &stat_work, &clBX, pathffile2);
						}
						else if (leadV && (std::ifstream(pathffile).is_open()))
						{
							char agree;
							do
							{
								system("cls");
								std::cout << "\nDo you want to use the file for work?( Y <|> N):"; std::cin >> agree;
								if (agree == 'Y' || agree == 'N' || agree == 'y' || agree == 'n')
								{
									break;
								}
							} while (true);
							if (agree == 'y' || agree == 'Y')
							{
								if (opensf(&H, &Hp, &Hk, &dH, &R, &leadV, &lockk, pathffile) != 33)
								{
									DrawResultONInterface(&pos, us_whInsertF, &H, &Hp, &Hk, &dH, &R, &S, &I, &stat_work, &clBX, pathffile2);
								}
							}
							else
							{
								DrawResultONInterface(&pos, us_whInsertF, &H, &Hp, &Hk, &dH, &R, &S, &I, &stat_work, &clBX, pathffile2);
							}
						}
						else if (!leadV && !std::ifstream(pathffile).is_open())
						{
							Warning(11, "There is not one source for taking values!");
						}
						else
						{
							if (opensf(&H, &Hp, &Hk, &dH, &R, &leadV, &lockk, pathffile) != 33)
							{
								leadV = 1;
								Warning(16, "Used data from a file");
								DrawResultONInterface(&pos, us_whInsertF, &H, &Hp, &Hk, &dH, &R, &S, &I, &stat_work, &clBX, pathffile2);
							}
						}
					}
					else if (clBX == 6)
					{
						if (leadV && !(std::ifstream(pathffile).is_open()))
						{
							DrawResultONInterface(&pos, us_dWHInsertF, &H, &Hp, &Hk, &dH, &R, &S, &I, &stat_work, &clBX, pathffile2);
						}
						else if (leadV && (std::ifstream(pathffile).is_open()))
						{
							char agree;
							do
							{
								system("cls");
								std::cout << "\nDo you want to use the file for work?( Y <|> N):"; std::cin >> agree;
								if (agree == 'Y' || agree == 'N' || agree == 'y' || agree == 'n')
								{
									break;
								}
							} while (true);
							if (agree == 'y' || agree == 'Y')
							{
								if (opensf(&H, &Hp, &Hk, &dH, &R, &leadV, &lockk, pathffile) != 33)
								{
									DrawResultONInterface(&pos, us_dWHInsertF, &H, &Hp, &Hk, &dH, &R, &S, &I, &stat_work, &clBX, pathffile2);
								}
							}
							else
							{
								DrawResultONInterface(&pos, us_dWHInsertF, &H, &Hp, &Hk, &dH, &R, &S, &I, &stat_work, &clBX, pathffile2);
							}
						}
						else if (!leadV && !std::ifstream(pathffile).is_open())
						{
							Warning(11, "There is not one source for taking values!");
						}
						else
						{
							if (opensf(&H, &Hp, &Hk, &dH, &R, &leadV, &lockk, pathffile) != 33)
							{
								leadV = 1;
								Warning(16, "Used data from a file");
								DrawResultONInterface(&pos, us_dWHInsertF, &H, &Hp, &Hk, &dH, &R, &S, &I, &stat_work, &clBX, pathffile2);
							}
						}
					}
					else if (clBX == 7)
					{
						bool xset = 1;
						short int se_pos = 1;
						do
						{
							system("cls");
							std::cout << std::endl << std::endl;
							for (int i = 0; i != 15; i++)
							{
								std::cout << "\t";
								for (int j = 0; j != 60; j++)
								{
									if (i % 2 == 0)
									{
										std::cout << "-";
									}
									else if (i == 1 && j == 1)
									{
										leh_text(&j, " Change path(<");
										SetConsoleTextAttribute(console_cf, 4);
										leh_text(&j, pathffile);
										j += 2;
										SetConsoleTextAttribute(console_cf, 6);
										leh_text(&j, ">)");
									}
									else if (i == 3 && j == 1)
									{
										leh_text(&j, " Change output file name(<");
										SetConsoleTextAttribute(console_cf, 4);
										leh_text(&j, pathffile2);
										SetConsoleTextAttribute(console_cf, 6);
										std::cout << ">)";
										j += 3;
									}
									else if (i == 7 && j == 1)
									{
										leh_text(&j, " Open ");
										leh_text(&j, pathffile2);
										j++;
									}
									else if (i == 5 && j == 1)
									{
										leh_text(&j, " Open ");
										leh_text(&j, pathffile);
										j++;
									}
									else if (i == 9 && j == 1)
									{
										leh_text(&j, " Return default settings");
									}
									else if (i == 11 && j == 1)
									{
										leh_text(&j, " View Information about software");
									}
									else if (i == 13 && j == 1)
									{
										leh_text(&j, " Close");
									}
									else
									{
										if (j == 0 && se_pos == i || j == 59 && se_pos == i)
										{
											std::cout << "|";
										}
										else
										{
											std::cout << " ";
										}
									}
								}
								std::cout << std::endl;
							}
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'w': se_pos -= 2; break;
								case 's': se_pos += 2; break;
								case 'x':
									if (se_pos == 1)
									{
										SetConsoleTextAttribute(console_cf, 4);
										std::cout << "\n\nIMPORTANT!! The program reads only the first 42 characters\n\n\n";
										SetConsoleTextAttribute(console_cf, 6);
										std::cout << "Enter a new file path:\n\t\t"; std::cin.getline(pathffile, 42 + 1);
										updateps(pathffile, pathffile2);
									}
									else if (se_pos == 3)
									{
										SetConsoleTextAttribute(console_cf, 4);
										std::cout << "\n\nIMPORTANT!! The program reads only the first 30 characters\n\n\n";
										SetConsoleTextAttribute(console_cf, 6);
										std::cout << "Enter a new file path:\n\t\t"; std::cin.getline(pathffile2, 30 + 1);
										updateps(pathffile, pathffile2);
									}
									else if (se_pos == 5)
									{
										try
										{
											if (!std::ifstream(pathffile))
											{
												throw 66;
											}
											else
											{
												system(pathffile);
											}
										}
										catch (int a)
										{
											Warning(16, "Failed to recognize the file among the options!");
										}
									}
									else if (se_pos == 7)
									{
										try
										{
											if (!std::ifstream(pathffile2))
											{
												throw 66;
											}
											else
											{
												system(pathffile2);
											}
										}
										catch (int a)
										{
											Warning(16, "Failed to recognize the file among the options!");
										}
									}
									else if (se_pos == 9)
									{
										for (int a = 0; a != 10; a++)
										{
											pathffile[a] = "INPUT.txt"[a];
										}
										for (int a = 0; a != 11; a++)
										{
											pathffile2[a] = "OUTPUT.txt"[a];
										}
										updateps(pathffile, pathffile2);
									}
									else if (se_pos == 11)
									{
										short int timesx = 100;
										std::cout << std::endl << std::endl;
										SetConsoleTextAttribute(console_cf, 18 + rand() % (99 - 18 + 1));
										for (auto el : "Hey! You opened my miracle program. Let me tell you a little about how to use it.\nWhen you first start you will see a simple interface in front of you, where you can also select the operation you need to perform.\n\n\nIMPORTANT! Use the <W><S> keys to navigate between items and to confirm the action <X>\n\n\nIt is also possible to use the file to enter data through it, for this you need to create it!!")
										{
											std::cout << el;
											Sleep(timesx);
											if (_kbhit())
											{
												switch (_getch())
												{
												case 'x':
													timesx = 0;
													break;
												}
											}
										}
										SetConsoleTextAttribute(console_cf, 6);
										std::cout << "\n\nWait 5 sec..";
										Sleep(5000);
									}
									else if (se_pos == 13)
									{
										system("cls");
										xset = 0;
									}
									break;
								}
							}
							if (se_pos < 1)
							{
								se_pos = 13;
							}
							else if (se_pos > 13)
							{
								se_pos = 1;
							}
							Sleep(150);
						} while (xset);
						break;
					}
					else if (clBX == 8)
					{
						stat_work = 0;
					}
					break;
				}
			}
			if (clBX < 3)
			{
				clBX = 8;
			}
			else if (clBX > 8)
			{
				clBX = 3;
			}
			Sleep(150);
		} while (stat_work);
	}
}

bool loadPatch()
{
	short int score_load = 0;
	do
	{
		system("cls");
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
		for (int i = 0; i != 3; i++)
		{
			std::cout << "\t ";
			for (int j = 0; j <= 102; j++)
			{
				if (i % 2 == 0)
				{
					std::cout << "-";
				}
				else
				{
					if (j == 0 || j == 102)
					{
						std::cout << "|";
					}
					else if (j == 1)
					{
						SetConsoleTextAttribute(console_cf, 14);
						for (int k = 0; k <= score_load; k++)
						{
							std::cout << "#";
							j++;
						}
						j--;
						SetConsoleTextAttribute(console_cf, 6);
					}
					else
					{
						std::cout << " ";
					}
				}
			}
			std::cout << std::endl;
		}
		std::cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t  " << score_load << "%";
		score_load++;
		if (score_load == 101)
		{
			return false;
		}
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'x':
				system("cls");
				Sleep(100);
				return false;
				break;
			}
		}
		Sleep(150);
	} while (true);
}

void drawInf(short int* pos, bool* leadV, std::vector<char>& arr_load, float* hp, float* hk, float* dh, float* r)
{
	system("cls");
	std::string text_v = "  H{initial}=";
	for (int i = 0; i != 10; i++)
	{
		for (int j = 0; j != 120; j++)
		{
			if (i == 0 || i == 2 || i == 9)
			{
				if (j == 0 || j == 79 || j == 6)
				{
					std::cout << "+";
				}
				else
				{
					std::cout << "-";
				}
			}
			else
			{
				if (j == 0 || j == 79 || j == 6)
				{
					std::cout << "|";
				}
				else if (i == 1 && j == 3)
				{
					SetConsoleTextAttribute(console_cf, 4);
					if (!*leadV)
					{
						std::cout << "X";
					}
					else
					{
						std::cout << "+";
					}
					SetConsoleTextAttribute(console_cf, 6);
				}
				else if (i == 1 && j == 7)
				{
					if (!*leadV)
					{
						SetConsoleTextAttribute(console_cf, 70);
						for (int y = 0; y != arr_load.size(); y++)
						{
							std::cout << arr_load[y];
							j++;
						}
						arr_load.insert(arr_load.begin(), arr_load.at(arr_load.size() - 1));
						arr_load.pop_back();
						SetConsoleTextAttribute(console_cf, 6);
					}
					else
					{
						text_v += std::to_string(*hp) + "  H{final}=" + std::to_string(*hk) + "  H{delta}=" + std::to_string(*dh) + "  R=" + std::to_string(*r);
						for (int y = 0; y != text_v.length(); y++)
						{
							std::cout << text_v[y];
							j++;
						}
					}
					j--;
				}
				else if (i == 3 && j == 9)
				{
					leh_text(&j, "Lead Values");
				}
				else if (i == 4 && j == 9)
				{
					leh_text(&j, "Use A For Loop");
				}
				else if (i == 5 && j == 9)
				{
					leh_text(&j, "Use A While Loop");
				}
				else if (i == 6 && j == 9)
				{
					leh_text(&j, "Use A DoWhile Loop");
				}
				else if (i == 7 && j == 9)
				{
					leh_text(&j, "Settings");
				}
				else if (i == 8 && j == 9)
				{
					leh_text(&j, "Exit");
				}
				else if (i == *pos && j == 3)
				{
					SetConsoleTextAttribute(console_cf, 4);
					std::cout << (char)(16);
					SetConsoleTextAttribute(console_cf, 6);
				}
				else
				{
					std::cout << " ";
				}
			}
		}
		std::cout << std::endl;
	}
}

void leadDefV(float* nf, bool* lead, short int* lockk)
{
	system("cls");
	do
	{
		switch (*lockk)
		{
		case 1:
			std::cout << "\n\nenter value <h-initial>"; break;
		case 2:
			std::cout << "\nenter value enter value <H-terminal>"; break;
		case 3:
			std::cout << "\nenter value <h-DELTA>"; break;
		case 4:
			std::cout << "\nenter value <R>"; break;
		}
		std::cin >> *nf;
		if (std::cin.fail() || *nf <= 0)
		{
			std::cin.clear();
			std::cin.ignore();
			Warning(16, "A value entry error has been detected. Check out the instructions!");
		}
		else if (std::cin.good() && *lockk == 4)
		{
			*lead = true;
			*lockk = 1;
		}
	} while (*nf <= 0);
}

void Warning(int num_code, const char text[50])
{
	system("cls");
	SetConsoleTextAttribute(console_cf, 2 + rand() % 15);
	std::cout << (char)(num_code);
	for (int i = 0; i != strlen(text); i++)
	{
		std::cout << text[i];
	}
	Sleep(1000);
	system("cls");
	SetConsoleTextAttribute(console_cf, 6);
}

void leh_text(int* js, const char text[25])
{
	for (int g = 0; text[g] != '\0'; g++)
	{
		std::cout << text[g];
		++(*js);
	}
	--(*js);
}
void us_ffInsertF(float* h, float* hp, float* hk, float* dh, float* r, double* S, double* I, bool* xs, char* path)
{
	std::ofstream withe(path);
	short int sc = 0;
	for (*h = *hp; *h <= *hk; *h += *dh)
	{
		*I = sqrt(pow(*r, 2) + pow(*h, 2));
		*S = 3.14 * *r * (*r + *I);
		std::cout << (char)(179) << ++sc << "\t\t" << *I << "\t\t" << *S << "\t\t" << (char)(179) << std::endl;
		withe << sc << " :: " << *I << " -> " << *S << std::endl;
	}
	withe.close();
}

void us_whInsertF(float* h, float* hp, float* hk, float* dh, float* r, double* S, double* I, bool* xs, char* path)
{
	std::ofstream withe(path);
	short int sc = 0;
	*h = *hp;
	while (*h <= *hk)
	{
		*I = sqrt(pow(*r, 2) + pow(*h, 2));
		*S = 3.14 * *r * (*r + *I);
		std::cout << (char)(179) << ++sc << "\t\t" << *I << "\t\t" << *S << "\t\t" << (char)(179) << std::endl;
		withe << sc << " :: " << *I << " -> " << *S << std::endl;
		*h += *dh;
	}
	withe.close();
}

void us_dWHInsertF(float* h, float* hp, float* hk, float* dh, float* r, double* S, double* I, bool* xs, char* path)
{
	std::ofstream withe(path);
	short int sc = 0;
	*h = *hp;
	do
	{
		*I = sqrt(pow(*r, 2) + pow(*h, 2));
		*S = 3.14 * *r * (*r + *I);
		std::cout << (char)(179) << ++sc << "\t\t" << *I << "\t\t" << *S << "\t\t" << (char)(179) << std::endl;
		withe << sc << " :: " << *I << " -> " << *S << std::endl;
		*h += *dh;
	} while (*h <= *hk);
	withe.close();
}

void DrawLineDecoration(int a, int b)
{
	for (int i = 0; i != 49; i++)
	{
		if (i == 0)
		{
			std::cout << (char)(a);
		}
		else if (i == 48)
		{
			std::cout << (char)(b);
		}
		else
		{
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}

void DrawResultONInterface(short int* pos, void (*xmathCount)(float* h, float* hp, float* hk, float* dh, float* r, double* S, double* I, bool* xs, char* path), float* h, float* hp, float* hk, float* dh, float* r, double* S, double* I, bool* xs, short int* pp, char* path)
{
	bool xresult = true;
	do
	{
		system("cls");
		for (int i = 0; i != 5; i++)
		{
			for (int j = 0; j != 55; j++)
			{
				if (i == 0 && j == 0)
				{
					leh_text(&j, "Choose how you want to display results");
					if (*pp == 4)
					{
						SetConsoleTextAttribute(console_cf, 70);
						leh_text(&j, "    <FOOR>    ");
						SetConsoleTextAttribute(console_cf, 6);
					}
					else if (*pp == 5)
					{
						SetConsoleTextAttribute(console_cf, 70);
						leh_text(&j, "    <WHILE>    ");
						SetConsoleTextAttribute(console_cf, 6);
					}
					else if (*pp == 6)
					{
						SetConsoleTextAttribute(console_cf, 70);
						leh_text(&j, "    <DO-WHILE>    ");
						SetConsoleTextAttribute(console_cf, 6);
					}
				}
				else if (i == 2 && j == 0)
				{
					std::cout << (char)(249); j++;
					std::cout << "["; j++;
					if (i == *pos && j == 2)
					{
						SetConsoleTextAttribute(console_cf, 4);
						std::cout << "#"; j++;
						SetConsoleTextAttribute(console_cf, 6);
					}
					else
					{
						std::cout << " ";
					}
					leh_text(&j, "]Show the whole list");
				}
				else if (i == 3 && j == 0)
				{
					std::cout << (char)(249); j++;
					std::cout << "["; j++;
					if (i == *pos && j == 2)
					{
						std::cout << "#"; j++;
					}
					else
					{
						std::cout << " ";
					}
					leh_text(&j, "]Show element by ordinal");
				}
				else if (i == 4 && j == 0)
				{
					std::cout << (char)(249); j++;
					std::cout << "["; j++;
					if (i == *pos && j == 2)
					{
						SetConsoleTextAttribute(console_cf, 4);
						std::cout << "#"; j++;
						SetConsoleTextAttribute(console_cf, 6);
					}
					else
					{
						std::cout << " ";
					}
					leh_text(&j, "]Close");
				}
				else
				{
					std::cout << " ";
				}
			}
			std::cout << std::endl;
		}
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':
				--(*pos); break;
			case 's':
				++(*pos); break;
			case 'x':
				if (*pos == 2)
				{
					SetConsoleTextAttribute(console_cf, 2 + rand() % (15 - 2 + 1));
					system("cls");
					DrawLineDecoration(218, 191);
					xmathCount(&*h, &*hp, &*hk, &*dh, &*r, &*S, &*I, &*xs, &*path);
					DrawLineDecoration(192, 217);
					system("pause");
					SetConsoleTextAttribute(console_cf, 6);
				}
				else if (*pos == 3)
				{
					//
					//
					//
					//
					//
					//
					//
				}
				else if (*pos == 4)
				{
					xresult = 0;
				}
				break;
			}
		}
		if (*pos > 4)
		{
			*pos = 2;
		}
		else if (*pos < 2)
		{
			*pos = 4;
		}
		Sleep(150);
	} while (xresult);
}

int opensf(float* h, float* hp, float* hk, float* dh, float* R, bool* lead, short int* lockk, char* txt)
{
	system("cls");
	std::ifstream withe(txt);
	if ((bool)(withe >> *hp >> *hk >> *dh >> *R))
	{
		withe >> *hp >> *hk >> *dh >> *R;
		withe.close();
		if (*hp > *hk || *hp <= 0 || *hk <= 0 || *dh <= 0 || *R <= 0)
		{
			Warning(16, "Invalid data entered into file");
			return 33;
		}
	}
	else
	{
		Warning(16, "Make sure the values ​​given in the file are correct");
		return 33;
	}
}

void rdValue(char* txtIN, char* txtOUT)
{
	nlohmann::json j;
	std::ifstream config("ob.json");
	try
	{
		if (config.peek() == EOF)
		{
			throw 13;
		}
		if (config.is_open())
		{
			config >> j;
			for (int i = 0; i != j["INPUT"].get<nlohmann::json::string_t>().length() + 1; i++)
			{
				txtIN[i] = j["INPUT"].get<nlohmann::json::string_t>()[i];
			}
			for (int i = 0; i != j["OUTPUT"].get<nlohmann::json::string_t>().length() + 1; i++)
			{
				txtOUT[i] = j["OUTPUT"].get<nlohmann::json::string_t>()[i];
			}
			config.close();
		}
	}
	catch (int a)
	{
		std::ofstream config("ob.json");
		j["INPUT"] = txtIN;
		j["OUTPUT"] = txtOUT;
		config << j;
		config.close();
	}
}

void updateps(char* txtIN, char* txtOUT)
{
	nlohmann::json j;
	j["INPUT"] = txtIN;
	j["OUTPUT"] = txtOUT;
	std::ofstream config("ob.json");
	config << j;
	config.close();
}
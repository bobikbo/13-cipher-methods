#include "stdafx.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void showMenu()
{
	cout << "Select one of the algorithms (1-13):" << endl;
	string n = "+--+------------------------------+";
	cout << n << endl;
	cout << "| 1| cipher of Caesar             |" << endl;
	cout << "| 2| the slogan cipher            |" << endl;
	cout << "| 3| a polybian square            |" << endl;
	cout << "| 4| Trisemus cipher system       |" << endl;
	cout << "| 5| Playfair cipher              |" << endl;
	cout << "| 6| systems of homophones        |" << endl;
	cout << "| 7| cipher Vigenera              |" << endl;
	cout << n << endl;
	cout << "| 8| cipher of freemasons         |" << endl;
	cout << "| 9| biggram cipher Ports         |" << endl;
	cout << "|10| Hill's Cipher                |" << endl;
	cout << "|11| variant cipher               |" << endl;
	cout << "|12| cipher Teni                  |" << endl;
	cout << "|13| combined cipher              |" << endl;
	cout << n << endl;
}

int main()
{
	cout << "WELCOME TO BOBIK_BO CIPHER PROGRAM!\n\n";
	bool gameLoop = true;

	while (gameLoop)
	{
		showMenu();
		int number = 0;
		cout << "Your choice: ";
		while (true)
		{
			cin >> number;
			if (number > 13 || number < 1)
				cout << "Please, enter correct number!\nYour choice: ";
			else
				break;
		}
		cout << "\n";
		string surname;

		switch (number)
		{
		case 1: {
			cout << "Cipher of Caesar\nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			//65-90 : A-Z,  97-122 : a-z
			//String ABCDEFGHIJKLMNOPQRSTUVWXYZ
			string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			transform(surname.begin(), surname.end(), surname.begin(), toupper);
			for (int i = 0; i < surname.length(); i++)
			{
				int index = -1;
				for (int j = 0; j < letters.length(); j++)
					if (letters[j] == surname[i]) { index = j; break; }
				if (index != -1) {
					index += 3;
					if (index >= letters.length())index -= letters.length();
					surname[i] = letters[index];
				}
			}
			cout << "Encrypted string: " << surname << endl;
			break;
		}
		case 2: {
			cout << "The slogan cipher\nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			transform(surname.begin(), surname.end(), surname.begin(), toupper);
			
			string key = "";
			cout << "Enter the string key: ";
			getline(cin, key);
			transform(key.begin(), key.end(), key.begin(), toupper);

			string letters	= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			string let1		= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			string let2		= "";

			for (int i = 0; i < key.length(); i++)
				for (int j = 0; j < let1.length(); j++)
					if (let1[j] == key[i])
					{
						let1[j] = '>';
						let2 += key[i];
						break;
					}

			for(int i=0; i<let1.length(); i++)
				if (let1[i] != '>')
					let2 += let1[i];

			//draw table
			/*cout << "\n\n ";
			for (int i = 0; i < letters.length(); i++)cout << letters[i] << " | "; cout << endl;
			for (int i = 0; i < letters.length(); i++)cout << "---+"; cout << "\n ";
			for (int i = 0; i < let2.length(); i++)cout << let2[i] << " | "; cout << endl;*/

			for (int i = 0; i < surname.length(); i++)
			{
				int index = -1;
				for (int j = 0; j < letters.length(); j++)
					if (letters[j] == surname[i]) { index = j; break; }
				if (index != -1)
					surname[i] = let2[index];
			}
			cout << "Encrypted string: " << surname << endl;

			break;
		}
		case 3: {
			cout << "A polybian square\nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			transform(surname.begin(), surname.end(), surname.begin(), toupper);
			for (int i = 0; i < surname.length(); i++)
				if (surname[i] == 'I' || surname[i] == 'J')surname[i] = '>';

			map<char, int> grid;

			char letter = 'A';
			int number = 11;
			while (number / 10 < 6){
				if (number % 10 < 6){
					if (letter == 'I'){
						grid['>'] = number;
						letter += 2;
						number++;
					}
					else{
						grid[letter] = number;
						number++; letter++;
					}
				}
				else number += 5;

			}
			
			//draw table
			/*cout << "\n\n "; char c = 'A';
			for (int i = 0; i < 26; i++, c++)cout << c << " | "; cout << endl; c = 'A';
			for (int i = 0; i < 26; i++, c++)cout << "---+"; cout << "\n "; c = 'A';
			for (int i = 0; i < 26; i++, c++) {
				if (c == 'I' || c == 'J') cout << grid['>'] << "| ";
				else cout << grid[c] << "| ";
			}
			cout << endl;*/

			cout << "Encrypted string: ";
			map<char, int>::iterator it;
			for (int i = 0; i < surname.length(); i++) {
				it = grid.find(surname[i]);
				if (it == grid.end())cout << surname[i] << " ";
				else cout << grid[surname[i]] << " ";
			}

			break;
		}
		case 4: {
			cout << "Trisemus cipher system\nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			transform(surname.begin(), surname.end(), surname.begin(), toupper);

			string key = "";
			cout << "Enter the string key: ";
			getline(cin, key);
			transform(key.begin(), key.end(), key.begin(), toupper);

			string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			string let1    = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			string let2    = "";

			for (int i = 0; i < key.length(); i++)
				for (int j = 0; j < let1.length(); j++)
					if (let1[j] == key[i])
					{
						let1[j] = '>';
						let2 += key[i];
						break;
					}

			for (int i = 0; i<let1.length(); i++)
				if (let1[i] != '>')
					let2 += let1[i];

			//draw table
			/*cout << "+-+-+-+-+-+\n";
			int pos = 0;
			for (int i = 0; i < 6; i++) {
				cout << "|";
				for (int j = 0; j < 5; j++, pos++) {
					if (pos <= 25)cout << let2[pos] << "|";
					else cout << "-|";
				}
				cout << endl;
			}
			cout << "+-+-+-+-+-+\n\n";*/

			for (int i = 0; i < surname.length(); i++)
			{
				int index = -1;
				for (int j = 0; j < let2.length(); j++)
					if (let2[j] == surname[i]) { index = j; break; }
				if (index != -1){ 

					index += 5;
					if (index >= let2.length())index = index % 10;
					surname[i] = let2[index];
				}
			}
			cout << "Encrypted string: " << surname << endl;

			break;
		}
		case 5: {
			cout << "Playfair cipher\nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			transform(surname.begin(), surname.end(), surname.begin(), toupper);

			string key = "";
			cout << "Enter the string key: ";
			getline(cin, key);
			transform(key.begin(), key.end(), key.begin(), toupper);

			for (int i = 0; i < surname.length(); i++)if (surname[i] == 'I' || surname[i] == 'J')surname[i] = '0';
			for (int i = 0; i < key.length(); i++)if (key[i] == 'I' || key[i] == 'J')key[i] = '0';

			string letters = "ABCDEFGH0KLMNOPQRSTUVWXYZ";
			string let1 = "ABCDEFGH0KLMNOPQRSTUVWXYZ";
			string let2 = "";

			string prom = "";
			for (int i = 0; i < surname.length(); i++)
				if (surname[i] >= 'A' && surname[i] <= 'Z' || surname[i] == '0')prom += surname[i];
			surname = prom;

			//build table
			for (int i = 0; i < key.length(); i++)
				for (int j = 0; j < let1.length(); j++)
					if (let1[j] == key[i])
					{
						let1[j] = '>';
						let2 += key[i];
						break;
					}

			for (int i = 0; i<let1.length(); i++)
				if (let1[i] != '>')
					let2 += let1[i];

			//draw table
			/*cout << "+-+-+-+-+-+\n";
			int pos = 0;
			for (int i = 0; i < 5; i++) {
				cout << "|";
				for (int j = 0; j < 5; j++, pos++) {
					if (pos <= 25)cout << let2[pos] << "|";
					else cout << "-|";
				}
				cout << endl;
			}
			cout << "+-+-+-+-+-+\n\n";*/

			//build bigrams
			string bigrams = "";
			for (int i = 0; i < surname.length(); i += 2) {
				if (i + 1 == surname.length()) {
					bigrams += surname[i];
					bigrams += 'X';
				}
				else if (surname[i] == surname[i + 1]) {
					bigrams += surname[i];
					bigrams += "X ";
					i--;
				}
				else {
					bigrams += surname[i];
					bigrams += surname[i + 1];
					bigrams += ' ';
				}
			}

			//encrypt
			for (int i = 0; i < bigrams.length(); i += 3) {
				int x1, x2, y1, y2;
				int n = 0;
				for (int j = 0; j < let2.length() && n != 2; j++) {
					if (bigrams[i] == let2[j]) { y1 = j / 5; x1 = j % 5; n++; }
					else if (bigrams[i + 1] == let2[j]) { y2 = j / 5; x2 = j % 5; n++; }
				}
				if (x1 != x2 && y1 == y2) {
					int pos = y1 * 5 + x1 + 1;
					int x = pos % 5; 
					bigrams[i] = let2[(y1 * 5 + x)];
					//---------
					pos = y2 * 5 + x2 + 1;
					x = pos % 5;
					bigrams[i + 1] = let2[(y2 * 5 + x)];
				}
				else if (y1 != y2 && x1 == x2) {
					int pos = y1 * 5 + x1 + 5;
					if (pos >= let2.length())bigrams[i] = let2[pos % 5];
					else bigrams[i] = let2[pos];
					//---------
					pos = y2 * 5 + x2 + 5;
					if (pos >= let2.length())bigrams[i + 1] = let2[pos % 5];
					else bigrams[i + 1] = let2[pos];
				}
				else if (x1 != x2 && y1 != y2) {
					int pos = y1 * 5 + x2;
					bigrams[i] = let2[pos];
					//----------
					pos = y2 * 5 + x1;
					bigrams[i + 1] = let2[pos];
				}
			}

			cout << "Encrypted string: " << bigrams << endl;

			break;
		}
		case 6: {
			cout << "Systems of homophones \nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			transform(surname.begin(), surname.end(), surname.begin(), toupper);

			vector<int> numbers;
			for (int i = 1; i <= 52; i++)
				numbers.push_back(i);
			random_shuffle(numbers.begin(), numbers.end());

			//draw table
			/*cout << "\n "; char c = 'A'; int pos = 0;
			for (int i = 0; i < 26; i++, c++)cout << c << " | "; cout << endl;
			for (int i = 0; i < 26; i++)cout << "---+"; cout << "\n ";
			for (int i = 0; i < 26; i++, pos++) {
				if(numbers[pos] < 10) cout << numbers[pos] << " | ";
				else cout << numbers[pos] << "| ";
			}cout << endl;
			for (int i = 0; i < 26; i++)cout << "---+"; cout << "\n ";
			for (int i = 0; i < 26; i++, pos++) {
				if (numbers[pos] < 10) cout << numbers[pos] << " | ";
				else cout << numbers[pos] << "| ";
			}cout << endl;*/

			srand(time(0));
			for (int i = 0; i < surname.length(); i++) {
				int pos = surname[i] - 'A';
				int r = rand() % 2 + 1;
				if (r == 2) pos += 26;
				cout << numbers[pos] << " ";
			}
			cout << endl;

			break;
		}
		case 7: {
			cout << "Cipher Vigenera \nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			transform(surname.begin(), surname.end(), surname.begin(), toupper);

			string key = "";
			cout << "Enter the string key: ";
			getline(cin, key);
			transform(key.begin(), key.end(), key.begin(), toupper);

			while (key.length() < surname.length()) {
				key += key;
			}
			
			vector<vector<char> > table(26, vector<char>(26,0));
			for (int i = 0; i < 26; i++) {
				char tek = 'A' + i;
				for (int j = 0; j < 26; j++, tek++) {
					if (tek > 'Z')tek = 'A';
					table[i][j] = tek;
				}
			}

			for (int i = 0; i < surname.length(); i++) {
				int x = surname[i] - 'A';
				int y = key[i] - 'A';
				surname[i] = table[y][x];
			}
			cout << "Encrypted string: " << surname << endl;
			
			//draw table
			/*for (int i = 0; i < 26; i++) {
				cout << endl;
				for (int j = 0; j < 26; j++)
					cout << table[i][j] << " ";
			}
			cout << endl;*/

			break;
		}
		case 8: {
			cout << "Cipher of Freemasons \nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			transform(surname.begin(), surname.end(), surname.begin(), toupper);
			
			vector<vector<string> >table;// (26, vector<string>(26, 0));
			table.resize(3);
			for (int i = 0, size = table.size(); i<size; ++i)   table[i].resize(26);
			//A-B-C-D-E--------------------------------------------------------------------------------------------------
			table[0][0] = " _ "; table[0][1] = " _ "; table[0][2] = "   "; table[0][3] = " _ "; table[0][4] = " _ ";
			table[1][0] = " *|"; table[1][1] = " *|"; table[1][2] = " *|"; table[1][3] = "|*|"; table[1][4] = "|*|";
			table[2][0] = "  |"; table[2][1] = " _|"; table[2][2] = " _|"; table[2][3] = "| |"; table[2][4] = "|_|";
			//F-G-H-I-J--------------------------------------------------------------------------------------------------
			table[0][5] = "   "; table[0][6] = " _ "; table[0][7] = " _ "; table[0][8] = "   "; table[0][9] = " _ ";
			table[1][5] = "|*|"; table[1][6] = "|* "; table[1][7] = "|* "; table[1][8] = "|* "; table[1][9] = "  |";
			table[2][5] = "|_|"; table[2][6] = "|  "; table[2][7] = "|_ "; table[2][8] = "|_ "; table[2][9] = "  |";
			//K-L-M-N-O--------------------------------------------------------------------------------------------------
			table[0][10] = " _ "; table[0][11] = "   "; table[0][12] = " _ "; table[0][13] = " _ "; table[0][14] = "   ";
			table[1][10] = "  |"; table[1][11] = "  |"; table[1][12] = "| |"; table[1][13] = "| |"; table[1][14] = "| |";
			table[2][10] = " _|"; table[2][11] = " _|"; table[2][12] = "| |"; table[2][13] = "|_|"; table[2][14] = "|_|";
			//P-Q-R-S-T--------------------------------------------------------------------------------------------------
			table[0][15] = " _ "; table[0][16] = " _ "; table[0][17] = "   "; table[0][18] = "   ";  table[0][19] = " / ";
			table[1][15] = "|  "; table[1][16] = "|  "; table[1][17] = "|  "; table[1][18] = "\\*/"; table[1][19] = "<* ";
			table[2][15] = "|  "; table[2][16] = "|_ "; table[2][17] = "|_ "; table[2][18] = "   ";  table[2][19] = " \\ ";
			//U-V-W-X-Y-Z--------------------------------------------------------------------------------------------------
			table[0][20] = "   ";  table[0][21] = " \\ "; table[0][22] = "   ";  table[0][23] = " / ";  table[0][24] = "   ";  table[0][25] = " \\ ";
			table[1][20] = "/*\\"; table[1][21] = " *>";  table[1][22] = "\\/ "; table[1][23] = "<  ";  table[1][24] = "/\\ "; table[1][25] = "  >";
			table[2][20] = "   ";  table[2][21] = " / ";  table[2][22] = "   ";  table[2][23] = " \\ "; table[2][24] = "   ";  table[2][25] = " / ";
			//---------------------------------------------------------------------------------------------------------------

			for (int i = 0; i < 3; i++) {

				for (int j = 0; j < surname.length(); j++) {
					int pos = surname[j] - 'A';
					if (pos > 25 || pos < 0)cout << "   ";
					else cout << table[i][pos] << "   ";
				}
				cout << endl;
			}

			break;
		}
		case 9: {
			cout << "Biggram cipher Ports \nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			transform(surname.begin(), surname.end(), surname.begin(), toupper);

			string prom = "";
			for (int i = 0; i < surname.length(); i++) {
				int pos = surname[i] - 'A';
				if (pos <= 25 && pos >= 0)prom += surname[i];
			}
			surname = prom;
			if (surname.length() % 2 != 0)surname += 'X';

			string bigrams = "";
			for (int i = 0; i < surname.length(); i += 2) {
				bigrams += surname[i];
				bigrams += surname[i + 1];
				bigrams += ' ';
			}

			vector<vector<int> >table(26, vector<int>(26, 0));
			//table.resize(3);
			//for (int i = 0, size = table.size(); i<size; ++i)   table[i].resize(26);
			int number = 1;
			for (int i = 0; i < 26; i++)
				for (int j = 0; j < 26; j++, number++)
					table[i][j] = number;

			for (int i = 0; i < bigrams.length(); i += 3) {
				int y = bigrams[i] - 'A';
				int x = bigrams[i + 1] - 'A';
				if (table[y][x] < 100) {
					if (table[y][x] < 10)
						cout << "00" << table[y][x] << " ";
					else cout << "0" << table[y][x] << " ";
				}
				else cout << table[y][x] << " ";
			}
			cout << "\n\n";

			//draw table
			/*for (char c = 'A'; c <= 'Z'; c++)cout << "  " << c << " ";
			cout << endl;
			char c = 'A';
			for (int i = 0; i < 26; i++, c++) {
				cout << c << " ";
				for (int j = 0; j < 26; j++) {
					if (table[i][j] < 100) {
						if (table[i][j] < 10)
							cout << "00" << table[i][j] << " ";
						else cout << "0" << table[i][j] << " ";
					}
					else cout << table[i][j] << " ";
				}
				cout << endl;
			}*/

			break;
		}
		case 10: {
			cout << "Hill's Cipher \nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			transform(surname.begin(), surname.end(), surname.begin(), toupper);

			string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

			string prom = "";
			for (int i = 0; i < surname.length(); i++) {
				int pos = surname[i] - 'A';
				if (pos <= 25 && pos >= 0)prom += surname[i];
			}
			surname = prom;
			while(surname.length() % 3 != 0)surname += 'X';

			string bigrams = "";
			for (int i = 0; i < surname.length(); i += 3) {
				bigrams += surname[i];
				bigrams += surname[i + 1];
				bigrams += surname[i + 2];
				if(i + 3 < surname.length())bigrams += ' ';
			}
	
			/* ENCRYPTION   |   DECRYPTION
			  6	    27	1   |   2	26	17
			  13	16	32  |  26   20   4  
			  28	17	15  |  13   30  21*/
			cout << "Encrypted string: ";
			for (int i = 0; i < bigrams.length(); i += 4) {
				int pos1 = bigrams[i] - 'A';
				int pos2 = bigrams[i + 1] - 'A';
				int pos3 = bigrams[i + 2] - 'A';
				int res = (6 * pos1 + 27 * pos2 + 1 * pos3) % 26;
				cout << letters[res];
				res = (13 * pos1 + 16 * pos2 + 32 * pos3) % 26;
				cout << letters[res];
				res = (28 * pos1 + 17 * pos2 + 15 * pos3) % 26;
				cout << letters[res] << " ";
			}
			cout << endl;

			break;
		}
		case 11: {
			cout << "Variant cipher \nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			transform(surname.begin(), surname.end(), surname.begin(), toupper);

			string key = "";
			cout << "Enter the string key: ";
			getline(cin, key);
			transform(key.begin(), key.end(), key.begin(), toupper);

			for (int i = 0; i < surname.length(); i++)if (surname[i] == 'I' || surname[i] == 'J')surname[i] = '0';
			for (int i = 0; i < key.length(); i++)if (key[i] == 'I' || key[i] == 'J')key[i] = '0';

			string letters = "ABCDEFGH0KLMNOPQRSTUVWXYZ";
			string let1 = "ABCDEFGH0KLMNOPQRSTUVWXYZ";
			string let2 = "";

			string prom = "";
			for (int i = 0; i < surname.length(); i++)
				if (surname[i] >= 'A' && surname[i] <= 'Z' || surname[i] == '0')prom += surname[i];
			surname = prom;

			//build table
			for (int i = 0; i < key.length(); i++)
				for (int j = 0; j < let1.length(); j++)
					if (let1[j] == key[i])
					{
						let1[j] = '>';
						let2 += key[i];
						break;
					}
			for (int i = 0; i<let1.length(); i++)
				if (let1[i] != '>')
					let2 += let1[i];

			vector<string> rows;
			vector<string> cols;
			rows.push_back("FU"); rows.push_back("CA"); rows.push_back("PR"); rows.push_back("OL"); rows.push_back("DG");
			cols.push_back("W0"); cols.push_back("YK"); cols.push_back("QX"); cols.push_back("EH"); cols.push_back("TN");

			//draw table
			/*for(int i=0; i<2; i++){
				cout << "   ";
				for (int j = 0; j < 5; j++)
					cout << cols[j][i] << " ";
				cout << endl;
			}
			cout << "   ---------\n";
			int pos = 0;
			for (int i = 0; i < 5; i++) {
				cout << rows[i][0] << rows[i][1] << "|";
				for (int j = 0; j < 5; j++, pos++)cout << let2[pos] << " ";
				cout << endl;
			}
			cout << endl;*/

			cout << "Encrypted string: ";
			srand(time(0));
			for (int i = 0; i < surname.length(); i++) {
				for (int j = 0; j < let2.length(); j++) {
					if (surname[i] == let2[j]) {
						int x = j % 5;
						int y = j / 5;
						int rowL = rand() % 2;
						int colL = rand() % 2;
						int whoFirst = rand() % 2;
						if (whoFirst == 0) cout << cols[x][colL] << rows[y][rowL] << " ";
						else cout << rows[y][rowL] << cols[x][colL] << " ";
						break;
					}
				}
			}
			cout << endl;

			break;
		}
		case 12: {
			cout << "Cipher Teni \nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			transform(surname.begin(), surname.end(), surname.begin(), toupper);

			vector<vector<string> >table;// (26, vector<string>(26, 0));
			table.resize(2);
			for (int i = 0, size = table.size(); i<size; ++i)   table[i].resize(26);

			//A-B-C-D-E--------------------------------------------------------------------------------------------------
			table[0][0] = "\\ /"; table[0][1] = "   ";  table[0][2] = "  /";  table[0][3] = "\\  "; table[0][4] = "\\ /";
			table[1][0] = "   ";  table[1][1] = "/ \\"; table[1][2] = "  \\"; table[1][3] = "/  ";  table[1][4] = "/ \\";
			//F-G-H-I-J--------------------------------------------------------------------------------------------------
			table[0][5] = "_|_";  table[0][6] = " | "; table[0][7] = "___"; table[0][8] = "\\  "; table[0][9] = "  /";
			table[1][5] = " | ";  table[1][6] = " | "; table[1][7] = "   "; table[1][8] = " \\ "; table[1][9] = " / ";
			//K-L-M-N-O--------------------------------------------------------------------------------------------------
			table[0][10] = " |_"; table[0][11] = "_| "; table[0][12] = "  _"; table[0][13] = " _ "; table[0][14] = " |_";
			table[1][10] = "   "; table[1][11] = "   "; table[1][12] = " | "; table[1][13] = "  |"; table[1][14] = " | ";
			//P-Q-R-S-T--------------------------------------------------------------------------------------------------
			table[0][15] = "_| "; table[0][16] = "_|_"; table[0][17] = "___"; table[0][18] = "\\/ ";  table[0][19] = "\\  ";
			table[1][15] = " | "; table[1][16] = "   "; table[1][17] = " | "; table[1][18] = " \\ ";  table[1][19] = "/\\ ";
			//U-V-W-X-Y-Z--------------------------------------------------------------------------------------------------
			table[0][20] = " \\/";  table[0][21] = "  /";   table[0][22] = " | ";  table[0][23] = "\\ /";  table[0][24] = "\\__";  table[0][25] = "__/";
			table[1][20] = " / ";   table[1][21] = " /\\";  table[1][22] = "/ \\"; table[1][23] = " | ";   table[1][24] = "/  ";   table[1][25] = "  \\";
			//---------------------------------------------------------------------------------------------------------------

			cout << "Encrypted string: ";
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < surname.length(); j++) {
					int pos = surname[j] - 'A';
					if (pos > 25 || pos < 0)cout << "   ";
					else cout << table[i][pos] << "   ";
				}
				cout << "\n                  ";
			}
			cout << endl;

			break;
		}
		case 13: {
			cout << "Combined cipher \nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			transform(surname.begin(), surname.end(), surname.begin(), toupper);

			string key = "";
			cout << "Enter the string key: ";
			getline(cin, key);
			transform(key.begin(), key.end(), key.begin(), toupper);

			string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			string let1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			string let2 = "";
			string let3 = "";

			for (int i = 0; i < key.length(); i++)
				for (int j = 0; j < let1.length(); j++)
					if (let1[j] == key[i])
					{
						let1[j] = '>';
						let2 += key[i];
						break;
					}

			for (int i = 0; i<let1.length(); i++)
				if (let1[i] != '>')
					let3 += let1[i];

			//draw table
			/*cout << " |0 ";
			for (int i = 9; i > 0; i--)cout << i << " ";
			cout << "\n-+-------------------\n";
			cout << " |";
			for (int i = 0; i < let2.length(); i++)cout << let2[i] << " ";
			cout << endl; int pos = 0;
			for (int i = 1; i < 3; i++) {
				cout << i << "|";
				for (int i = 0; i < 10; i++, pos++)cout << let3[pos] << " ";
				cout << endl;
			}
			cout << endl;*/

			cout << "Encrypted string: ";
			for (int i = 0; i < surname.length(); i++) {
				int pos = surname[i] - 'A';
				if (pos <= 25 && pos >= 0) {
					int flag = 0;
					for (int j = 0; j < let2.length(); j++) {
						if (surname[i] == let2[j]) {
							int ed = j % 10;
							if (ed == 0)cout << "0";
							else {
								ed = (ed - 10) * (-1);
								cout << ed;
							}
							flag++; break;
						}
					}
					if (flag == 0) {
						for (int j = 0; j < let3.length(); j++) {
							if (surname[i] == let3[j]) {
								int des = j / 10 + 1;
								des *= 10;
								int ed = j % 10;
								if (ed == 0)cout << des;
								else {
									ed = (ed - 10) * (-1);
									des += ed;
									cout << des;
								}
							}
						}
					}
				}
				else cout << surname[i];
			}
			cout << endl;

			break;
		}
		default:
			break;
		}
		int again = 0;
		cout << "\n\nDo you want to encrypt the string again? (1 - yes, else - no): ";
		cin >> again;
		if (again != 1) gameLoop = false;
		cout << "\n\n";
	}

	system("pause");
    return 0;
}


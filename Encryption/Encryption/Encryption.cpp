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
	cout << "Select one of the algorithms (1-22):" << endl;
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
	cout << "|14| simple single permutation    |" << endl;
	cout << "|15| block single permutation     |" << endl;
	cout << "|16| tabular route permutation    |" << endl;
	cout << "|17| vertical permutation         |" << endl;
	cout << "|18| rotary grating               |" << endl;
	cout << "|19| magic square                 |" << endl;
	cout << "|20| double permutation           |" << endl;
	cout << n << endl;
	cout << "|21| gamming cipher by module N/2 |" << endl;
	cout << n << endl;
	cout << "|22| ADFGVX                       |" << endl;
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
			if (number > 22 || number < 1)
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
		case 14: {
			cout << "Simple single permutation \nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			transform(surname.begin(), surname.end(), surname.begin(), toupper);

			vector<vector<int> >table(2, vector<int>(surname.length(), 0));
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < surname.length(); j++)
					table[i][j] = j + 1;
			}
			srand(time(0));
			random_shuffle(table[1].begin(), table[1].end());

			//draw table
			string prob = "+";
			for (int i = 0; i < surname.length(); i++)
				prob += "--+";

			cout << prob << endl;
			for (int i = 0; i < 2; i++) {
				cout << '|';
				for (int j = 0; j < surname.length(); j++) {
					if (table[i][j] >= 10)cout << table[i][j] << '|';
					else cout << ' ' << table[i][j] << '|';
				}
				cout << endl << prob << endl;
			}

			//Enc
			string result = "";
			for (int i = 0; i < surname.length(); i++) {
				for (int j = 0; j < surname.length(); j++) {
					if (table[1][j] == i + 1) {
						result += surname[j];
						break;
					}
				}
			}
			cout << "\nEncrypted string: " << result << endl;
			break;
		}
		case 15: {
			cout << "Block single permutation \nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			transform(surname.begin(), surname.end(), surname.begin(), toupper);

			for (int i = 0; i < surname.length(); i++)if (surname[i] == ' ')surname[i] = '_';
			vector<vector<int> >table(2, vector<int>(3, 0));
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 3; j++)
					table[i][j] = j + 1;
			}
			srand(time(0));
			random_shuffle(table[1].begin(), table[1].end());
			while (surname.length() % 3 != 0) {
				if (surname.length() % 2 == 0)surname += 'X';
				else surname += 'Z';
			}

			//draw table
			string prob = "+";
			for (int i = 0; i < 3; i++)
				prob += "--+";

			cout << prob << endl;
			for (int i = 0; i < 2; i++) {
				cout << '|';
				for (int j = 0; j < 3; j++) {
					if (table[i][j] >= 10)cout << table[i][j] << '|';
					else cout << ' ' << table[i][j] << '|';
				}
				cout << endl << prob << endl;
			}

			//Enc
			string result = "";
			int block = surname.length() / 3, ind = 0;
			
			int f = 0, s = 0, t = 0;
			if (table[1][0] == 1) f = 0;
			else if (table[1][1] == 1) f = 1;
			else if (table[1][2] == 1) f = 2;
			if (table[1][0] == 2) s = 0;
			else if (table[1][1] == 2) s = 1;
			else if (table[1][2] == 2) s = 2;
			if (table[1][0] == 3) t = 0;
			else if (table[1][1] == 3) t = 1;
			else if (table[1][2] == 3) t = 2;
			for (int i = 0; i < block; i++) {
				result += surname[3 * i + f];
				result += surname[3 * i + s];
				result += surname[3 * i + t];
			}
			cout << "\nEncrypted string: " << result << endl;
			break;
		}
		case 16: {
			cout << "Tabular route permutation \nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			transform(surname.begin(), surname.end(), surname.begin(), toupper);
			
			for (int i = 0; i < surname.length(); i++)if (surname[i] == ' ')surname[i] = '_';
			while (surname.length() % 6 != 0)surname += '_';
			int str = surname.length() / 6;

			vector<vector<char> >table(str, vector<char>(6, 0));
			string napZap = "", napEnc = "";
			cout << "Enter the fill direction (lr, rl, ud, du) : ";
			//cin.ignore();
			getline(cin, napZap);
			transform(napZap.begin(), napZap.end(), napZap.begin(), toupper);
			cout << "Enter the encrypt direction (lr, rl, ud, du) : ";
			//cin.ignore();
			getline(cin, napEnc);
			transform(napEnc.begin(), napEnc.end(), napEnc.begin(), toupper);

			int kl = 0;
			//zap
			{
				if (napZap == "LR") {
					for (int i = 0; i < str; i++)
						for (int j = 0; j < 6; j++, kl++)
							table[i][j] = surname[kl];
				}
				else if (napZap == "RL") {
					for (int i = 0; i < str; i++)
						for (int j = 5; j >= 0; j--, kl++)
							table[i][j] = surname[kl];
				}
				else if (napZap == "UD") {
					for (int i = 0; i < 6; i++)
						for (int j = 0; j < str; j++, kl++)
							table[j][i] = surname[kl];
				}
				else if (napZap == "DU") {
					for (int i = 0; i < 6; i++)
						for (int j = str-1; j >= 0; j--, kl++)
							table[j][i] = surname[kl];
				}
			}


			//draw
			string prob = "+"; for (int i = 0; i < 6; i++)prob += "-+"; cout << prob << endl;
			for (int i = 0; i < str; i++) {
				cout << '|';
				for (int j = 0; j < 6; j++) {
					cout << table[i][j] << '|';
				}
				cout << endl << prob << endl;
			}


			//cout
			string res = "";
			{
				if (napEnc == "LR") {
					for (int i = 0; i < str; i++)
						for (int j = 0; j < 6; j++, kl++)
							res += table[i][j];
				}
				else if (napEnc == "RL") {
					for (int i = 0; i < str; i++)
						for (int j = 5; j >= 0; j--, kl++)
							res += table[i][j];
				}
				else if (napEnc == "UD") {
					for (int i = 0; i < 6; i++)
						for (int j = 0; j < str; j++, kl++)
							res += table[j][i];
				}
				else if (napEnc == "DU") {
					for (int i = 0; i < 6; i++)
						for (int j = str - 1; j >= 0; j--, kl++)
							res += table[j][i];
				}
			}
			cout << "\nEncrypted string: " << res << endl;
			break;
		}
		case 17: {
			cout << "Vertical permutation \nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			transform(surname.begin(), surname.end(), surname.begin(), toupper);

			string key = "";
			cout << "Enter the string key: ";
			getline(cin, key);
			transform(key.begin(), key.end(), key.begin(), toupper);

			//sozd poryadka
			vector<int> numbers(key.length());
			string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			char l = 'A';
			int och = 1;
			for (int i = 0; i < 26 && och <= key.length(); i++, l++) {
				for (int j = 0; j < key.length(); j++) {
					if (key[j] == l) { numbers[j] = och; och++;}
				}
			}

			//kor str
			for (int i = 0; i < surname.length(); i++)if (surname[i] == ' ')surname[i] = '_';
			while (surname.length() < key.length() || surname.length() % key.length() != 0)surname += '_';
			unsigned int str = surname.length() / key.length();

			//zap table
			vector<vector<char> >table(str, vector<char>(key.length(), 0));
			int kl = 0;
			for (int i = 0; i < str; i++)
				for (int j = 0; j < key.length(); j++, kl++)
					table[i][j] = surname[kl];


			//draw table
			{
				string prob = "+";
				for (int i = 0; i < key.length(); i++)
					prob += "--+";

				cout << prob << endl;
				for (int i = 0; i < 1; i++) {
					cout << '|';
					for (int j = 0; j < key.length(); j++) {
						cout << ' ' << key[j] << '|';
					}
					cout << endl << prob << endl;
					cout << '|';
					for (int j = 0; j < key.length(); j++) {
						if (numbers[j] >= 10)cout << numbers[j] << '|';
						else cout << ' ' << numbers[j] << '|';
					}
					cout << endl << prob << endl;
				}
				for (int i = 0; i < str; i++) {
					cout << '|';
					for (int j = 0; j < key.length(); j++) {
						cout << ' ' << table[i][j] << '|';
					}
					cout << endl << prob << endl;
				}
			}


			//cout
			string result = "";
			{
				for (int i = 0; i < key.length(); i++) {
					for (int j = 0; j < key.length(); j++) {
						if (numbers[j] == i + 1) {
							for (int z = 0; z < str; z++)
								result += table[z][j];
						}
					}
				}
			}
			cout << "\nEncrypted string: " << result << endl;
			break;
		}
		case 18: {
			cout << "Rotary grating \nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			transform(surname.begin(), surname.end(), surname.begin(), toupper);

			for (int i = 0; i < surname.length(); i++)if (surname[i] == ' ')surname[i] = '_';
			//uravnivanie
			int raz = 16;
			if (surname.length() < 16) {
				while (surname.length() < 16)surname += '_';
			}
			else {
				while (raz < surname.length())raz += 8;
				while (surname.length() < raz)surname += '_';
			}

			//sozd
			int y = raz / 4, ind = 0;
			vector<vector<char> >table(4, vector<char>(y, 0));
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < y; j += 2, ind++)
					table[i][j] = surname[ind];
				for (int j = 1; j < y; j += 2, ind++)
					table[i + 2][j] = surname[ind];
				for (int j = 1; j < y; j += 2, ind++)
					table[i][j] = surname[ind];
				for (int j = 0; j < y; j += 2, ind++)
					table[i + 2][j] = surname[ind];
			}

			//draw
			string prob = "+"; for (int i = 0; i < y; i++)prob += "-+"; cout << prob << endl;
			for (int i = 0; i < 4; i++) {
				cout << '|';
				for (int j = 0; j < y; j++) {
					cout << table[i][j] << '|';
				}
				cout << endl << prob << endl;
			}

			//cout
			string result = "";
			{
				for (int i = 0; i < y; i++) {
					for (int j = 0; j < 4; j++) {
						result += table[j][i];
					}
				}
			}
			cout << "\nEncrypted string: " << result << endl;
			break;
		}
		case 19: {
			cout << "Magic square \nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			transform(surname.begin(), surname.end(), surname.begin(), toupper);
			
			for (int i = 0; i < surname.length(); i++)if (surname[i] == ' ')surname[i] = '_';
			//create magic square
			int n = 1;
			while (n*n < surname.length())n++;
			if (n % 2 == 0)n++;

			vector<vector<int> > matrix(n, vector<int>(n, 0));
			int nsqr = n * n;
			int i = 0, j = n / 2;

			//filling mahic square
			{
				for (int k = 1; k <= nsqr; ++k) {
					matrix[i][j] = k;
					i--;
					j++;
					if (k % n == 0) {
						i += 2;
						--j;
					}
					else {
						if (j == n)
							j -= n;
						else if (i < 0)
							i += n;
					}
				}
			}

			//draw table
			{
				string prob = "+";
				for (int i = 0; i < n; i++)
					prob += "--+";
				cout << prob << endl;
				for (int i = 0; i < n; i++) {
					cout << '|';
					for (int j = 0; j < n; j++) {
						if (matrix[i][j] >= 10)cout << matrix[i][j] << '|';
						else cout << ' ' << matrix[i][j] << '|';
					}
					cout << endl << prob << endl;
				}
			}


			//changing surname and filling square 
			while (surname.length() < n*n)surname += '.';
			vector<vector<char> >table(n, vector<char>(n, 0));
			string result = "";
			{
				int flag = 0;
				for (int i = 0; i < surname.length(); i++) {
					flag = 0;
					for (int j = 0; j < n && flag == 0; j++) {
						for (int z = 0; z < n; z++) {
							if (matrix[j][z] == i + 1) {
								table[j][z] = surname[i];
								flag++;
								break;
							}
						}
					}
				}

				//res
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						result += table[i][j];
					}
				}

			}
			cout << "\nEncrypted string: " << result << endl;


			break;
		}
		case 20: {
			cout << "Double permutation \nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			transform(surname.begin(), surname.end(), surname.begin(), toupper);

			for (int i = 0; i < surname.length(); i++)if (surname[i] == ' ')surname[i] = '_';
			//create table and cls and rows
			int n = 1;
			while (n*n < surname.length())n++;
			while (surname.length() < n*n) surname += '_';
			vector<vector<char> >tableFirst(n, vector<char>(n, 0));
			vector<vector<char> >tableSecond(n, vector<char>(n, 0));
			vector<vector<char> >tableThird(n, vector<char>(n, 0));
			
			srand(time(0));
			vector<int> tableR; for (int i = 0; i < n; i++)tableR.push_back(i);
			vector<int> tableC; for (int i = 0; i < n; i++)tableC.push_back(i);
			random_shuffle(tableR.begin(), tableR.end());
			random_shuffle(tableC.begin(), tableC.end());

			//enter table and change
			{
				//first
				for (int i = 0, kl = 0; i < n; i++) {
					for (int j = 0; j < n; j++, kl++) {
						tableFirst[i][j] = surname[kl];
					}
				}
				//second
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						tableSecond[j][tableC[i]] = tableFirst[j][i];
					}
				}
				//third
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						tableThird[tableR[i]][j] = tableSecond[i][j];
					}
				}
			}

			//draw table
			{
				string prob = "-+";
				cout << endl;
				for (int i = 0; i < n; i++)prob += "-+";
				prob += "   +"; for (int i = 0; i < n; i++)prob += "-+";
				prob += "   +"; for (int i = 0; i < n; i++)prob += "-+";

				cout << "  "; for (int i = 0; i < n; i++)cout << tableC[i] + 1 << '|';
				cout << "    "; for (int i = 0; i < n; i++)cout << i + 1 << '|';
				cout << "    "; for (int i = 0; i < n; i++)cout << i + 1 << '|';
				cout << endl;
				cout << prob << endl;
				for (int z = 0; z < n; z++) {
					cout << tableR[z] + 1 << '|';
					for (int i = 0; i < n; i++)cout << tableFirst[z][i] << '|';
					cout << "  " << tableR[z] + 1 << '|';
					for (int i = 0; i < n; i++)cout << tableSecond[z][i] << '|';
					cout << "  " << z + 1 << '|';
					for (int i = 0; i < n; i++)cout << tableThird[z][i] << '|';
					cout << endl << prob << endl;
				}
			}

			//cout
			string result = "";
			{
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						result += tableThird[j][i];
					}
				}
			}
			cout << "\nEncrypted string: " << result << endl;
			break;
		}
		case 21: {
			cout << "Gamming cipher by module N/2 \nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			transform(surname.begin(), surname.end(), surname.begin(), toupper);

			string key = "";
			cout << "Enter the string key: ";
			getline(cin, key);
			transform(key.begin(), key.end(), key.begin(), toupper);
			
			cout << "Enter the module(2 or else number): ";
			int mod = 0;
			cin >> mod;
			while (mod < 2) { cout << "Please, enter the correct number(2 or higher): "; cin >> mod; }

			//obr key
			if (key.length() > surname.length()) {
				string key2 = "";
				for (int i = 0; i < surname.length(); i++)key2 += key[i];
				key = key2;
			}
			if (key.length() < surname.length()) {
				string key2 = "";
				for (int i = 0, j = 0; i < surname.length(); i++, j++) {
					if (j >= key.length())j = 0;
					key2 += key[j];
				}
				key = key2;
			}


			/*int z = 28;
			for (int i = 0; i<8; i++)
			{
				if (z & 128) cout << "1";
				else cout << "0";
				z <<= 1;
			}*/

			//mod 2
			if (mod == 2) {
				
				map<char, int> table;
				char s = 'A';
				for (int i = 65; i <= 90; i++, s++)table[s] = i;

				vector<int> result;
				for (int i = 0; i < surname.length(); i++) {
					result.push_back(surname[i] ^ key[i]);
				}

				//draw table
				{
					string prob = "+";
					for (int i = 0; i < surname.length(); i++)
						prob += "---------+";
					cout << prob << endl << '|';
					//surname
					for (int i = 0; i < surname.length(); i++) {
						cout << "    " << surname[i] << "    |";
					}
					cout << endl << prob << endl << '|';
					//surname - kod
					for (int i = 0; i < surname.length(); i++) {
						if (table[surname[i]] >= 10)cout << "    " << table[surname[i]] << "   |";
						else cout << "   " << table[surname[i]] << "   |";
					}
					cout << endl << prob << endl << '|';
					//surname - binary kod
					for (int i = 0; i < surname.length(); i++) {
						string str = "";
						int z = surname[i];
						for (int i = 0; i<8; i++)
						{
							if (i == 4)str += ' ';
							if (z & 128) str += "1";
							else str += "0";
							z <<= 1;
						}
						cout << str << '|';
					}
					cout << endl << prob << endl << '|';
					//key
					for (int i = 0; i < key.length(); i++) {
						cout << "    " << key[i] << "    |";
					}
					cout << endl << prob << endl << '|';
					//key - kod
					for (int i = 0; i < key.length(); i++) {
						if (table[key[i]] >= 10)cout << "    " << table[key[i]] << "   |";
						else cout << "   " << table[key[i]] << "   |";
					}
					cout << endl << prob << endl << '|';
					//key - binary kod
					for (int i = 0; i < key.length(); i++) {
						string str = "";
						int z = key[i];
						for (int i = 0; i<8; i++)
						{
							if (i == 4)str += ' ';
							if (z & 128) str += "1";
							else str += "0";
							z <<= 1;
						}
						cout << str << '|';
					}
					cout << endl << prob << endl << '|';
					//result
					for (int i = 0; i < result.size(); i++) {
						//cout << "   " << result[i] << "|";
						if (result[i] >= 10 && result[i] < 100)cout << "    " << result[i] << "   |";
						else if (result[i] >= 100)cout << "   " << result[i] << "   |";
						else if (result[i] < 10)cout << "    " << result[i] << "    |";
					}
					cout << endl << prob << endl << '|';
					//result - kod
					for (int i = 0; i < result.size(); i++) {
						//if (table[result[i]] >= 10)cout << table[result[i]] << '|';
						//else cout << ' ' << table[result[i]] << '|';
						string str = "";
						int z = result[i];
						for (int i = 0; i<8; i++)
						{
							if (i == 4)str += ' ';
							if (z & 128) str += "1";
							else str += "0";
							z <<= 1;
						}
						cout << str << '|';
					}
					cout << endl << prob << endl;
				}

			}
			//mod > 2
			else {

				map<char, int> table;
				char s = 'A';
				for (int i = 0; i < 26; i++, s++)table[s] = i;

				string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
				string result = "";

				//result
				for (int i = 0; i < surname.length(); i++) {
					result += letters[(table[surname[i]] + table[key[i]]) % mod];
					/*int q = table[surname[i]];
					int q1 = table[key[i]];
					int res = (q + q1) % mod;
					result += letters[res];*/
				}

				//draw table
				{
					string prob = "+";
					for (int i = 0; i < surname.length(); i++)
						prob += "--+";
					cout << prob << endl << '|';
					//surname
					for (int i = 0; i < surname.length(); i++) {
						cout << ' ' << surname[i] << '|';
					}
					cout << endl << prob << endl << '|';
					//surname - kod
					for (int i = 0; i < surname.length(); i++) {
						if (table[surname[i]] >= 10)cout << table[surname[i]] << '|';
						else cout << ' ' << table[surname[i]] << '|';
					}
					cout << endl << prob << endl << '|';
					//key
					for (int i = 0; i < key.length(); i++) {
						cout << ' ' << key[i] << '|';
					}
					cout << endl << prob << endl << '|';
					//key - kod
					for (int i = 0; i < key.length(); i++) {
						if (table[key[i]] >= 10)cout << table[key[i]] << '|';
						else cout << ' ' << table[key[i]] << '|';
					}
					cout << endl << prob << endl << '|';
					//result
					for (int i = 0; i < result.length(); i++) {
						cout << ' ' << result[i] << '|';
					}
					cout << endl << prob << endl << '|';
					//result - kod
					for (int i = 0; i < result.length(); i++) {
						if (table[result[i]] >= 10)cout << table[result[i]] << '|';
						else cout << ' ' << table[result[i]] << '|';
					}
					cout << endl << prob << endl;
				}
			}

			break;
		}
		case 22: {
			cout << "ADFGVX \nEnter your string: ";
			cin.ignore();
			getline(cin, surname);
			transform(surname.begin(), surname.end(), surname.begin(), toupper);

			string key = "";
			cout << "Enter the string key: ";
			getline(cin, key);
			transform(key.begin(), key.end(), key.begin(), toupper);
			
			for (int i = 0; i < surname.length(); i++)if (surname[i] == ' ')surname[i] = '_';
			for (int i = 0; i < key.length(); i++)if (key[i] == ' ')key[i] = '_';

			string res = "";
			//first part
			{
				//create table 
				vector<char> table; char z = 'A';
				for (int i = 0; i < 26; i++, z++) {
					table.push_back(z);
				}
				table.push_back('_');
				srand(time(0));
				random_shuffle(table.begin(), table.end());

				//draw table
				string outp = "ADFGVX", meg = "-+-+-+-+-+-+-+\n"; cout << " |";
				for (int i = 0; i < outp.length(); i++)cout << outp[i] << "|"; cout << endl << meg;
				for (int i = 0, z = 0; i < outp.length(); i++) {
					cout << outp[i] << "|";
					if (z >= 27)for (int j = 0; j < 6; j++, z++)cout << "-|";
					else for (int j = 0; j < 6; j++, z++)if (z < 27)cout << table[z] << "|"; else cout << "-|";
					cout << endl << meg;
				}

				//create prom string
				map<int, char> tab;
				tab[0] = 'A'; tab[1] = 'D'; tab[2] = 'F';
				tab[3] = 'G'; tab[4] = 'V'; tab[5] = 'X';

				int index = 0;
				for (int i = 0; i < surname.length(); i++) {
					for (int j = 0; j < 27; j++) {
						if (surname[i] == table[j]) { index = j; break; }
					}
					res += tab[index / 6];
					res += tab[index % 6];
				}

				//cout prom
				cout << "Intermediate result: ";
				for (int i = 0, kl = 1; i < res.length(); i++) {
					if (kl % 3 == 0){cout << " "; kl = 1;}
					cout << res[i];
					kl++;
				}
				cout << "\n\n";
			}

			//second part
			{
				//sozd poryadka
				vector<int> numbers(key.length());
				string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
				char l = 'A';
				int och = 1;
				for (int i = 0; i < 26 && och <= key.length(); i++, l++) {
					for (int j = 0; j < key.length(); j++) {
						if (key[j] == l) { numbers[j] = och; och++; }
					}
				}
				
				//draw table
				string pr = "+"; for (int i = 0; i < key.length(); i++)pr += "-+";
				cout << pr << endl << "|";
				for (int i = 0; i < key.length(); i++)cout << key[i] << "|";
				cout << endl << pr << endl << "|";
				for (int i = 0; i < key.length(); i++)cout << numbers[i] << "|";
				cout << endl << pr << endl;
				int rows = res.length() / key.length();
				if (res.length() % key.length() != 0)rows++;
				for (int i = 0, z = 0; i < rows; i++) {
					cout << "|";
					for (int j = 0; j < key.length(); j++, z++) {
						if (z < res.length())cout << res[z] << "|";
						else cout << " |";
					}
					cout << endl << pr << endl;
				}

				//create res string
				int num = 1;
				string promRes = "";
				for (int i = 0; i < key.length(); i++, num++) {
					int index = -1;
					for (int j = 0; j < key.length(); j++)if (numbers[j] == num) { index = j; break; }
					for (int j = index; j < res.length(); ) {
						promRes += res[j];
						j += key.length();
					}
				}

				//cout result
				cout << "\nEncrypted string: ";
				for (int i = 0, kl = 1; i < promRes.length(); i++) {
					if (kl % 6 == 0) { cout << " "; kl = 1; }
					cout << promRes[i];
					kl++;
				}
				cout << "\n\n";
			}
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


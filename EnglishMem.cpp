#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include<conio.h>
#include <algorithm>
using namespace std;

class Flashcard {
private:
	vector<string>name;
	string word;
	string meaning;

public:
	void setWord(string newWord);  //�P��
	void setMeaning(string newMeaning);  //�Ӗ�
	void showcard(); //�t���b�V���J�[�h�J�n
	void showAll(); //�t�@�C�����S�P��\��
	void addWord(string filename); //�P��ǉ�
	void deleteWord(string filename); //�P��폜
	void deleteAll(string filename); //�S�P��폜
};
void Flashcard ::setWord(string newWord) {
	word = newWord;
}

void Flashcard ::setMeaning(string newMeaning) {
	meaning = newMeaning;
}
void Flashcard ::showcard() {
	cout << "�P��:" << word << endl; Sleep(2 * 1000);
	cout << "�Ӗ�:" << meaning << endl; Sleep(2 * 1000);
}
void Flashcard ::showAll() {
	cout << "�P��:" << word << "�@�@�Ӗ�:" << meaning << endl;
}

void Flashcard ::addWord(string filename) {
	string word;
	string meaning;
	vector<string> vocabs;
	ofstream file(filename, ios::app);
	if (!file.is_open()) {
		cout << "�t�@�C�����J���܂���ł����B\n";
	}
	cout << "�P��:";
	cin >> word;
	cout << "�Ӗ�:";
	cin >> meaning;
	vocabs.emplace_back(word);
	vocabs.emplace_back(meaning);

	for (string name : vocabs) {
		file << name << endl;
	}
	file.close();
}

void Flashcard ::deleteWord(string filename) {
	string word_to_delete;
	string meaning_to_delete;
	char tango[30];

	cout << "\n�ǂ̒P����폜���܂���? �p�P�����͂��Ă�������:";
	cin >> word_to_delete;
	ifstream read(filename);
	ofstream write("new.txt");

	while (!read.eof()) {
		read >> tango;
		name.emplace_back(tango);
		
		const char* a = word_to_delete.c_str();
		vector<string>::iterator it;
		it = find(name.begin(), name.end(), a);
		int pos = distance(name.begin(), it);
		/*//�m�F�p
		if (it != name.end()) {
			cout << "FOUND  " << *it << "  at position: " << pos << endl;
		}
		else {
			cout << "NOT FOUND" << endl;
		}*/
		try {
			//cout << "pos+1�̈ʒu�̒P���:"<<name.at(pos+1) << endl; //�m�F�p
			meaning_to_delete = name.at(pos + 1);
		}
		catch (const out_of_range& oor) {
			//cout << "Error " << oor.what() << endl;�@//�m�F�p
		}
		if (tango != word_to_delete && tango != meaning_to_delete) {
			write << endl << tango << endl;
		}
		else {
			cout << "\n�폜����܂����B" << endl;
		}
	}
	write.close();
	read.close();

	string str = filename;
	const char* dst = str.c_str();

	if (remove(dst) != 0) {
		cout << "\n�P��͍폜����܂���ł����B" << endl;
	}
	if (rename("new.txt", dst) != 0) {
		cout << "\n�t�@�C������ύX�ł��܂���ł����B" << endl;
	}
}
void Flashcard::deleteAll(string filename) {

	string str = filename;
	const char* dst = str.c_str();
	if (remove(dst) != 0) {
		cout << "�P�ꂪ�o�^����Ă��܂���B" << endl;
	}
	else {
		cout << "���ׂč폜����܂����B" << endl;
	}

}

int main() {
	cout << "���p�Ŕԍ�����͂��Ă��������B";
	loop:
		cout << "\n�ǂ�ɂ��܂����B\n -1- �t���b�V���J�[�h \n -2- �P��ҏW\n -3- �S�P��\��\n Enter:";
		int select;
		int select2_1;
		int select2_2;
		int select2_2_1;
		int select2_3;
		int yes_no;
		cin >> select;
		string word, meaning;
		Flashcard flashcard1;
		Flashcard flashcard2;
		Flashcard flashcard3;

		vector<Flashcard> flash;
		
		
		//1.�t���b�V���J�[�h
		switch (select) {
		case 1: {

			cout << "\n------------------ [�t���b�V���J�[�h] ------------------\n �ǂ̃Z�b�g���w�т܂����B \n -1- set1 \n -2- set2 \n -3- set3 \n -0- �߂� \n Enter:";//select2_1
			cin >> select2_1;
			switch (select2_1) {
			case 0: {
				goto loop;
			}
			case 1: {
				cout << "\n���X�y�[�X�L�[�������Œ��f" << endl << endl;
				ifstream infile("wordlist.txt");
				while (infile >> word >> meaning) {
					flash.emplace_back();
					flash[flash.size() - 1].setWord(word);
					flash[flash.size() - 1].setMeaning(meaning);
				}
				infile.close();
				
				for (int i = 0; i < flash.size(); i++) {
				
					if (_kbhit()) {
						break;
						cout << "���f" << endl;
						goto loop;
					}
						flash[i].showcard();
				}
				goto loop;
			}
			case 2: {
				cout << "\n���X�y�[�X�L�[�������Œ��f" << endl << endl;
				ifstream infile("wordlist2.txt");
				while (infile >> word >> meaning) {
					flash.emplace_back();
					flash[flash.size() - 1].setWord(word);
					flash[flash.size() - 1].setMeaning(meaning);
				}
				infile.close();

				for (int i = 0; i < flash.size(); i++) {
					if (_kbhit()) {
						break;
						cout << "���f" << endl;
						goto loop;
					}
					flash[i].showcard();
				}
				goto loop;
			}
			case 3: {
				cout << "\n���X�y�[�X�L�[�������Œ��f" << endl << endl;
				ifstream infile("wordlist3.txt");
				while (infile >> word >> meaning) {
					flash.emplace_back();
					flash[flash.size() - 1].setWord(word);
					flash[flash.size() - 1].setMeaning(meaning);
				}
				infile.close();

				for (int i = 0; i < flash.size(); i++) {
					if (_kbhit()) {
						break;
						cout << "���f" << endl;
						goto loop;
					}
					flash[i].showcard();
				}
				goto loop;
			}
			}
			goto loop;
			break;
		}

	    //2.�P��o�^
		case 2: {
			cout << "\n---------------------- [�P��ҏW] ----------------------\n �ǂ��ҏW���܂����B\n -1- set1 \n -2- set2 \n -3- set3 \n -0- �߂� \n Enter:";//select2_2
			cin >> select2_2;
			switch(select2_2) {
			case 0: {
				goto loop;
			}
			case 1: {
				ifstream infile("wordlist.txt");
				while (infile >> word >> meaning) {
					flash.emplace_back();
					flash[flash.size() - 1].setWord(word);
					flash[flash.size() - 1].setMeaning(meaning);
				}
				infile.close();
		    	for (int i = 0; i < flash.size(); i++) flash[i].showAll();
				loop_1:
				cout << "\n -1- �P��ǉ� \n -2- �P��폜 \n -3- �t�@�C�����̒P���S�폜 \n -0- �߂�\n Enter:";
				cin >> select2_2_1;
				if (select2_2_1 == 1) {
					flashcard1.addWord("wordlist.txt");
					goto loop_1;
				}
				else if (select2_2_1 == 2) {
					flashcard1.deleteWord("wordlist.txt");
					goto loop_1;
				}
				else if (select2_2_1 == 3) {
					cout << "�t�@�C�����̒P������ׂč폜���܂��B�{���ɂ�낵���ł����H\n -1- �͂� or -2- ������ \n Enter:";
					cin >> yes_no;
					if (yes_no ==1) {
						flashcard1.deleteAll("wordlist.txt");
						goto loop;
					}
					else {
						goto loop_1;
					}
				}
				else if (select2_2_1 == 0) {
					goto loop;
				}
				else {
					goto loop;
				}
			}
			case 2: {
				ifstream infile("wordlist2.txt");
				while (infile >> word >> meaning) {
					flash.emplace_back();
					flash[flash.size() - 1].setWord(word);
					flash[flash.size() - 1].setMeaning(meaning);
				}
				infile.close();
				for (int i = 0; i < flash.size(); i++) flash[i].showAll();
			loop_1_2:
				cout << "\n -1- �P��ǉ� \n -2- �P��폜 \n -3- �t�@�C�����̒P���S�폜 \n -0- �߂�\n Enter:";
				cin >> select2_2_1;
				if (select2_2_1 == 1) {
					flashcard1.addWord("wordlist2.txt");
					goto loop_1_2;
				}
				else if (select2_2_1 == 2) {
					flashcard1.deleteWord("wordlist2.txt");
					goto loop_1_2;
				}
				else if (select2_2_1 == 3) {
					cout << "�t�@�C�����̒P������ׂč폜���܂��B�{���ɂ�낵���ł����H\n -1- �͂� or -2- ������ \n Enter:";
					cin >> yes_no;
					if (yes_no == 1) {
						flashcard1.deleteAll("wordlist2.txt");
						goto loop;
					}
					else {
						goto loop_1_2;
					}
				}
				else if (select2_2_1 == 0) {
					goto loop;
				}
				else {
					goto loop;
				}

				
			}
			case 3: {
				ifstream infile("wordlist3.txt");
				while (infile >> word >> meaning) {
					flash.emplace_back();
					flash[flash.size() - 1].setWord(word);
					flash[flash.size() - 1].setMeaning(meaning);
				}
				infile.close();
				for (int i = 0; i < flash.size(); i++) flash[i].showAll();
			loop_1_3:
				cout << "\n -1- �P��ǉ� \n -2- �P��폜 \n -3- �t�@�C�����̒P���S�폜 \n -0- �߂�\n Enter:";
				cin >> select2_2_1;
				if (select2_2_1 == 1) {
					flashcard1.addWord("wordlist3.txt");
					goto loop_1_3;
				}
				else if (select2_2_1 == 2) {
					flashcard1.deleteWord("wordlist3.txt");
					goto loop_1_3;
				}
				else if (select2_2_1 == 3) {
					cout << "�t�@�C�����̒P������ׂč폜���܂��B�{���ɂ�낵���ł����H\n -1- �͂� or -2- ������ \n Enter:";
					cin >> yes_no;
					if (yes_no == 1) {
						flashcard1.deleteAll("wordlist3.txt");
						goto loop;
					}
					else {
						goto loop_1_3;
					}
				}
				else if (select2_2_1 == 0) {
					goto loop;
				}
				else {
					goto loop;
				}
				
			}

			}
			goto loop;
			break;
		}
	    //3.�S�P��\��
		case 3: {
			loop_2:
			cout << "\n--------------------- [�S�P��\��] ---------------------\n -1- �P��y�шӖ����ꊇ�\�� \n -2- �P��̂݃A���t�@�x�b�g���\�� \n -0- �߂�\n Enter:";
			cin >> select2_3;
			switch (select2_3) {
			case 1: {
				vector<string> arr;
				int size;
				ifstream infile("wordlist.txt");
				ifstream infile2("wordlist2.txt");
				ifstream infile3("wordlist3.txt");
				if (!infile.is_open() || !!infile2.is_open() || !infile3.is_open()) {
					cout << "�J���Ȃ��t�@�C��������܂����B" << endl;
				}
				string input;
				while (infile >> word >> meaning) {
					flash.emplace_back();
					flash[flash.size() - 1].setWord(word);
					flash[flash.size() - 1].setMeaning(meaning);
				}
				while (infile2 >> word >> meaning) {
					flash.emplace_back();
					flash[flash.size() - 1].setWord(word);
					flash[flash.size() - 1].setMeaning(meaning);
				}
				while (infile3 >> word >> meaning) {
					flash.emplace_back();
					flash[flash.size() - 1].setWord(word);
					flash[flash.size() - 1].setMeaning(meaning);
				}
				infile.close();
				infile2.close();
				infile3.close();
				for (int i = 0; i < flash.size(); i++) flash[i].showAll();
				goto loop_2;
			}
			case 2: {
				vector<string> arr;
				int size;
				ifstream infile("wordlist.txt");
				ifstream infile2("wordlist2.txt");
				ifstream infile3("wordlist3.txt");
				if (!infile.is_open() || !!infile2.is_open() || !infile3.is_open()) {
					cout << "�J���Ȃ��t�@�C��������܂����B" << endl;
				}
				string input;
				while (getline(infile, input)) {
					arr.emplace_back(input);
				}
				while (getline(infile2, input)) {
					arr.emplace_back(input);
				}
				while (getline(infile3, input)) {
					arr.emplace_back(input);
				}
				sort(arr.begin(), arr.end());

				for (int i = 0; i < arr.size() / 2; i++) {
					cout << arr[i] << endl;
				}
				goto loop_2;
			}

				goto loop;
				break;
			}
		}

		default: {
			goto loop;
		}

		}
	
}


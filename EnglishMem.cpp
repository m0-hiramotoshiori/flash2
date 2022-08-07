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
	void setWord(string newWord);  //単語
	void setMeaning(string newMeaning);  //意味
	void showcard(); //フラッシュカード開始
	void showAll(); //ファイル内全単語表示
	void addWord(string filename); //単語追加
	void deleteWord(string filename); //単語削除
	void deleteAll(string filename); //全単語削除
};
void Flashcard ::setWord(string newWord) {
	word = newWord;
}

void Flashcard ::setMeaning(string newMeaning) {
	meaning = newMeaning;
}
void Flashcard ::showcard() {
	cout << "単語:" << word << endl; Sleep(2 * 1000);
	cout << "意味:" << meaning << endl; Sleep(2 * 1000);
}
void Flashcard ::showAll() {
	cout << "単語:" << word << "　　意味:" << meaning << endl;
}

void Flashcard ::addWord(string filename) {
	string word;
	string meaning;
	vector<string> vocabs;
	ofstream file(filename, ios::app);
	if (!file.is_open()) {
		cout << "ファイルを開けませんでした。\n";
	}
	cout << "単語:";
	cin >> word;
	cout << "意味:";
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

	cout << "\nどの単語を削除しますか? 英単語を入力してください:";
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
		/*//確認用
		if (it != name.end()) {
			cout << "FOUND  " << *it << "  at position: " << pos << endl;
		}
		else {
			cout << "NOT FOUND" << endl;
		}*/
		try {
			//cout << "pos+1の位置の単語は:"<<name.at(pos+1) << endl; //確認用
			meaning_to_delete = name.at(pos + 1);
		}
		catch (const out_of_range& oor) {
			//cout << "Error " << oor.what() << endl;　//確認用
		}
		if (tango != word_to_delete && tango != meaning_to_delete) {
			write << endl << tango << endl;
		}
		else {
			cout << "\n削除されました。" << endl;
		}
	}
	write.close();
	read.close();

	string str = filename;
	const char* dst = str.c_str();

	if (remove(dst) != 0) {
		cout << "\n単語は削除されませんでした。" << endl;
	}
	if (rename("new.txt", dst) != 0) {
		cout << "\nファイル名を変更できませんでした。" << endl;
	}
}
void Flashcard::deleteAll(string filename) {

	string str = filename;
	const char* dst = str.c_str();
	if (remove(dst) != 0) {
		cout << "単語が登録されていません。" << endl;
	}
	else {
		cout << "すべて削除されました。" << endl;
	}

}

int main() {
	cout << "半角で番号を入力してください。";
	loop:
		cout << "\nどれにしますか。\n -1- フラッシュカード \n -2- 単語編集\n -3- 全単語表示\n Enter:";
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
		
		
		//1.フラッシュカード
		switch (select) {
		case 1: {

			cout << "\n------------------ [フラッシュカード] ------------------\n どのセットを学びますか。 \n -1- set1 \n -2- set2 \n -3- set3 \n -0- 戻る \n Enter:";//select2_1
			cin >> select2_1;
			switch (select2_1) {
			case 0: {
				goto loop;
			}
			case 1: {
				cout << "\n※スペースキー長押しで中断" << endl << endl;
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
						cout << "中断" << endl;
						goto loop;
					}
						flash[i].showcard();
				}
				goto loop;
			}
			case 2: {
				cout << "\n※スペースキー長押しで中断" << endl << endl;
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
						cout << "中断" << endl;
						goto loop;
					}
					flash[i].showcard();
				}
				goto loop;
			}
			case 3: {
				cout << "\n※スペースキー長押しで中断" << endl << endl;
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
						cout << "中断" << endl;
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

	    //2.単語登録
		case 2: {
			cout << "\n---------------------- [単語編集] ----------------------\n どれを編集しますか。\n -1- set1 \n -2- set2 \n -3- set3 \n -0- 戻る \n Enter:";//select2_2
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
				cout << "\n -1- 単語追加 \n -2- 単語削除 \n -3- ファイル内の単語を全削除 \n -0- 戻る\n Enter:";
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
					cout << "ファイル内の単語をすべて削除します。本当によろしいですか？\n -1- はい or -2- いいえ \n Enter:";
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
				cout << "\n -1- 単語追加 \n -2- 単語削除 \n -3- ファイル内の単語を全削除 \n -0- 戻る\n Enter:";
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
					cout << "ファイル内の単語をすべて削除します。本当によろしいですか？\n -1- はい or -2- いいえ \n Enter:";
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
				cout << "\n -1- 単語追加 \n -2- 単語削除 \n -3- ファイル内の単語を全削除 \n -0- 戻る\n Enter:";
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
					cout << "ファイル内の単語をすべて削除します。本当によろしいですか？\n -1- はい or -2- いいえ \n Enter:";
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
	    //3.全単語表示
		case 3: {
			loop_2:
			cout << "\n--------------------- [全単語表示] ---------------------\n -1- 単語及び意味を一括表示 \n -2- 単語のみアルファベット順表示 \n -0- 戻る\n Enter:";
			cin >> select2_3;
			switch (select2_3) {
			case 1: {
				vector<string> arr;
				int size;
				ifstream infile("wordlist.txt");
				ifstream infile2("wordlist2.txt");
				ifstream infile3("wordlist3.txt");
				if (!infile.is_open() || !infile2.is_open() || !infile3.is_open()) {
					cout << "開けないファイルがありました。" << endl;
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
				if (!infile.is_open() || !infile2.is_open() || !infile3.is_open()) {
					cout << "開けないファイルがありました。" << endl;
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


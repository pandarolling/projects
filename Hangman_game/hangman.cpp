// hangman.cpp


#include<iostream>
#include <stdlib.h>
#include<string>
#include<vector>
using namespace std;

class words{
private:

public:
	string randomWord(){
		return "games";
	}

};

class hangman: public words{
private:
	string theWord;
	string guess;
	int wordlen;
	bool completed;
public:
	hangman(){
		theWord = randomWord();
		completed = false;
		wordlen = theWord.length();
		cout<<wordlen;
		// guess(wordlen, '_')
	}

	string whatistheword(){
		return theWord;
	}

	int wordlength(){
		return theWord.length();
	}
	string returnafterchecking(string paramtr){
		int i = 0;
		string ogWord = theWord;
		int size = theWord.length();
		string word(size, '_');
		
		char c;

		while(word[i] != '\0' ){
			if ( c = (guess[i] == ogWord[i])){
				word[i] = c;
			}else{
				word[i] = '_';
			}
			i++;
		}
		
		return word;
	}
	bool wordcompleted(){
		
		return completed;
	}
};

vector<char> encase(string word){
	int i =0;
	vector<char>encasedword;
	while(word[i] != '\0'){
		encasedword.push_back('[');
		encasedword.push_back(word[i]);
		encasedword.push_back(']');
		i++;
	}
	return encasedword;
}
int main(){
	char ch;
	cout<<"\nWelcome to the hangman game\n";
	cout<<"\n****************************\n";

	cout<<"Do you wish to play(y /n)";
	cin>>ch;

	while(ch == 'y'){
		hangman hg;
		int size = hg.wordlength(); 
		string word(size,'_');
		cout<<"the word length is "<<size<<endl;


		vector <char> result  = encase(hg.returnafterchecking(word));
		string s(result.begin(), result.end());
		cout << s;
		
		while(!hg.wordcompleted()){
			cout<<"\nyou have "<< size<<" guesses\t";
			cout<<"\nEnter a word to guess:\t";
			cin>>word;

			result  = encase(hg.returnafterchecking(word));
			string s(result.begin(), result.end());
			cout << s;
		}

		
	}

	return 0;
}
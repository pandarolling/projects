// wordle.cpp

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

class Wordle: public words{
private:
	string theWord;
	string guess;
	bool completed;
public:
	Wordle(){
		theWord = randomWord();
		completed = false;
	}

	void setNull(int pos){
		guess.resize(100);
		int i = 0;
		while(i < pos){
			guess[i++] = '_';
		}
		guess[i] ='\0';
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
		// string word(size, '_');
		
		int c;

		while(guess[i] != '\0'){
			if(guess[i] == '_'){
				if ( paramtr[i] == ogWord[i]){
				guess[i] = paramtr[i];
				}
			}
			
			i++;
		}
		
		return guess;
	}
	bool wordcompleted(){
		
		return completed;
	}

	bool wordsCompare(){
		
		int i =0;
		while(theWord[i] != '\0'){
			if(theWord[i] != guess[i])
				return false;
			i++;
		}
		return true;
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
	cout<<"\nWelcome to the Wordle game\n";
	cout<<"\n****************************\n";

	cout<<"Do you wish to play(y /n)";
	cin>>ch;
	cout << "\n\n";

	while(ch == 'y' ){
		Wordle wrdl;
		int size = wrdl.wordlength(); 
		wrdl.setNull(size);
		string word(size,'_');
		cout<<"Word length : "<<size<<endl<<endl;


		vector <char> result  = encase(wrdl.returnafterchecking(word));
		string s(result.begin(), result.end());
		cout << s;
		
		while(!wrdl.wordcompleted() && size){
			cout<<"\n\nRemaining Guesses : "<< size-- <<"\t";
			cout<<"\nEnter a word to guess:\t";
			cin>>word;

			result  = encase(wrdl.returnafterchecking(word));
			string s(result.begin(), result.end());
			cout <<endl << s;

			if(wrdl.wordsCompare()){

				cout<<"Yay !!You won! The word was "<<wrdl.whatistheword()<<endl;
				break;

			}
			if(!wrdl.wordcompleted() && !size){
				cout<<"Better luck next time!\n";
				cout<<"The word was " << wrdl.whatistheword()<<endl;
			}
		}
		cout<<"Do you wish to play again?(y /n)";
		cin>>ch;

	}

	return 0;
}
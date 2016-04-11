#include <iostream>

using namespace std;

int main(){
	string input = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011111111110000000000000000000000000000000000011110000000011110000000000000000000000000000011110000000000000011110000000000000000000000000110000000000000000000011000000000000000000000011100000000000000000000001110000000000000000000110000000000000000000000000011000000000000000001100000000000000000000000000001100000000000000011000000000000000000000000000000110000000000000010000000000000000000000000000000010000000000000110000000000000000000000000000000011000000000001100000000000000000000000000000000001100000000001000000000001111000000111100000000000100000000010000000000001111000000111100000000000110000000010000000000001111000000111100000000000010000000010000000000001111000000111100000000000010000000100000000000001111000000111100000000000011000000100000000000001111000000111100000000000001000000100000000000001111000000111100000000000001000000100000000000001111000000111100000000000001000000100000000000001111000000111100000000000001000000100000000000001111000000111100000000000001000000100000000000001111000000111100000000000001000000100000000000001111000000111100000000000001000000110000000000001111000000111100000000000011000000010000000000001111000000111100000000000010000000010000000000001111000000111100000000000010000000011000000000001111000000111100000000000110000000001000000000001111000000111100000000000100000000001100000000000000000000000000000000001100000000000110000000000000000000000000000000011000000000000010000000000000000000000000000000010000000000000011000000000000000000000000000000110000000000000001100000000000000000000000000001100000000000000000110000000000000000000000000011000000000000000000011100000000000000000000001110000000000000000000000110000000000000000000011000000000000000000000000011110000000000000011110000000000000000000000000000011110000000011110000000000000000000000000000000000011111111110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	
	for (size_t i = 0; i < input.size(); ++i){
		if (i%48==0) cout << endl;
		cout << input[i];
	}
	cout << endl;
	cout << endl;
	
	string first = "";
	string second = "";
	string third = "";

	for (size_t i = 0; i < 64; ++i){
		if (i%32==0){
			cout << first;
			cout << second;
			cout << third;
			first = "";
			second = "";
			third = "";
		}
		for (size_t j = 0; j < 48; ++j){
			if (j < 16){
				first += input[j + 48*i];
			}
			else if (j < 32){
				second += input[j+48*i];
			}
			else{
				third += input[j+48*i];
			}
		}
	}
	
	cout << first;
	cout << second;
	cout << third;
}
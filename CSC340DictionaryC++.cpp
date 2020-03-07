#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <list>
#include <algorithm>
#include<unistd.h>

using namespace std;
//FUNCTION PARAMETER
void placer(string &s, const string &search, const string &replace);
string switcher(string word);

int main() {
string line;
ifstream file("Data.CS.SFSU.txt");
map<string, vector<string>> MAP;

if (file.is_open()) {
cout << "! Opening data file... ./Data.CS.SFSU.txt .3..2..1.."<< sleep(1) << endl;
cout << "! Loading data..." << sleep(2)<< endl;

while (getline(file, line)) {
istringstream ss(line);
string founder;

//VECTOR DECLARATION
vector<string> loderv;
vector<string> newv;
vector<string> lastv;

while (getline(ss, founder, '|')) {
loderv.push_back(founder);
}


for (int i = 1; i < loderv.size(); i++) {
newv.push_back(loderv[i]);
}

//keyword
string keyword = loderv[0];

//forloop to display output
for (int i = 0; i < newv.size(); i++) {
string temp = newv[i];
placer(temp, "=>", " ");
placer(temp, "noun ", "[noun] : ");
placer(temp, "adjective ", "[adjective] : ");
placer(temp, "verb ", "[verb] : ");
lastv.push_back(temp);
}

//MAPPING KEYWORD WITH MAP
MAP.insert(make_pair(keyword, lastv));
}

//CLOSING FILE
file.close();
cout << "! Loading completed..." << endl;
sleep(1);
cout << "! Closing data file... ./Data.CS.SFSU.txt" << endl;
sleep(1);
}

//Displaying Messages on the Screen
//I used sleep command to make it like its loading file
cout << "*** 340 DICTONARY C++ ***\n\n";
sleep(1);
cout << "!Opening datafile... ./Data.CS.SFSU.txt\n";





//creates a vector of key values to search if the userinput is valid (later in program)
vector<string> keyWords;

for (map<string, vector<string>>::iterator it = MAP.begin(); it != MAP.end(); it++) {
keyWords.push_back(it->first);
}


//gets user input
while (true) {
cout << "Search: ";
string input;
getline(cin, input);

//if nothing is entered, output error
if (input == "") {
cout << " |" << endl;
cout << " <Please enter a search key (and a part of speech).>" << endl;
cout << " |" << endl;
}
else {
//makes userinput lowercase to match the vector of keyvalues for validation
for (int i = 0; i < input.length(); i++) {
input[i] = tolower(input[i]);
}

istringstream s2(input);
vector<string> v;
string tmp;

//puts user input into vector
while (s2 >> tmp) {
v.push_back(tmp);
}


string wordSearch = v[0];
wordSearch = switcher(wordSearch);

//proccesses user input ************************


//if !Q entered, exit program
if ((v[0] == "!Q") || (v[0] == "!q")) {
cout << endl;
cout << "----- THANK YOU----- " << endl;
break;
}
else {

cout << " |" << endl;

//if nothing is entered, output error message
if (v.size() == 0) {
cout << " <Please enter a search key (and a part of speech).>" << endl;

}

//if one word is entered, output definitions or error message
if (v.size() == 1) {
if (find(keyWords.begin(), keyWords.end(), v[0]) != keyWords.end()) {
//iterate through map and find keyword, print all values in vector
for (auto map_iter = MAP.cbegin(); map_iter != MAP.cend(); ++map_iter) {
if (v[0] == map_iter->first) {
for (auto vec_iter = map_iter->second.cbegin(); vec_iter != map_iter->second.cend(); ++vec_iter)
std::cout << " " << wordSearch << " " << *vec_iter << endl;


}
}
}
else {
cout << " <Not found.>" << endl;

}
}

//if two or more words are entered, output definition or error message
if (v.size() == 2) {
if ((v[1] != "noun") && (v[1] != "adjective") && (v[1] != "verb")) {
cout << " <2nd argument must be a part of speech.>" << endl;

}
else {
if (find(keyWords.begin(), keyWords.end(), v[0]) != keyWords.end()) {
//cout << "return vector >> if pos if found return definition" << endl;

for (auto map_iter = MAP.cbegin(); map_iter != MAP.cend(); ++map_iter) {
if (v[0] == map_iter->first) {
if ((v[1] == "noun") || (v[1] == "adjective") || (v[1] == "verb")) {
int count = 0;
for (auto vec_iter = map_iter->second.cbegin(); vec_iter != map_iter->second.cend(); ++vec_iter) {
string str1 = *vec_iter;
string str2 = v[1];
if (str1.find(str2) != string::npos) {
std::cout << " " << wordSearch << " " << *vec_iter << endl;
count++;
}
}
if (count == 0) {
cout << " <Not found.>" << endl;

}
}
else {
cout << " <Not found.>" << endl;

}
}
}
}
else {
cout << " <Sorry Keyword Not found!!>" << endl;

}
}
}
if (v.size() > 2) {
cout << " <Enter Keyword :>" << endl;

}
cout << " |" << endl;
}
}
}
return 0;
}

void placer(string &s, const string &search, const string &replace) {
for (size_t pos = 0; ; pos += replace.length()) {
// Locate the substring to replace
pos = s.find(search, pos);
if (pos == string::npos) break;
// Replace by erasing and inserting
s.erase(pos, search.length());
s.insert(pos, replace);
}
}


string switcher(string word) {
if (word == "book")
return "Book";
if (word == "bookable")
return "Bookable";
if (word == "bookbinder")
return "Bookbinder";
if (word == "bookcase")
return "Bookcase";
if (word == "csc210")
return "CSC210";
if (word == "csc220")
return "CSC220";
if (word == "csc340")
return "CSC340";
else
return word;
}

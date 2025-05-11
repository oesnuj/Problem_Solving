#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int L, C;
vector <char> words;

bool is_pwd_valid(const string& pwd) {
	int vowel = 0, consonant = 0;
	const string vowels = "aeiou";

	for (char c : pwd) {
		if (vowels.find(c) != string::npos) vowel++;
		else consonant++;
	}
	return vowel >= 1 && consonant >= 2;
}


void make_password(string pwd, int index) {
	if (pwd.size() == L) {
		if (is_pwd_valid(pwd)) cout << pwd << "\n";
		return;  
	}
	for (int i = index; i < C; ++i){
		make_password(pwd + words[i], i + 1);
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> L >> C;
	words.resize(C);
	for (auto& i : words) {
		cin >> i;
	}
	sort(words.begin(), words.end());
	make_password("", 0);
	return 0;
}
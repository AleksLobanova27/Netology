#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class bad_len : public exception {
public:
	const char* what() const noexcept override {
		return "Вы ввели слова запретной длины! Досвидания.";
	}
};

int function(string str, int forbid_len) {
	int len = str.length();
	if (len == forbid_len) { throw bad_len(); }
	return len;
}

int main() {

	setlocale(LC_ALL, "Russian");
	int forbid_len;
	cout << "Введите запретную длинну: ";
	cin >> forbid_len;

	string word;
	while (true) {
		setlocale(LC_ALL, "Russian");
		cout << "Введите слово: ";
		cin >> word;

		try {

			int len = function(word, forbid_len);
			cout << "Длина слова " << word << " равна " << len << endl;
		}
		catch (const bad_len& e) {
			cout << e.what() << endl;
			break;
		}
	}
	return 0;
}
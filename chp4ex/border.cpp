#include<string>
#include<vector>
#include<iostream>
#include <fstream> // ���� �۾��� ���� �ʿ�
#include <iomanip> // setprecision�� ���� �ʿ�

using namespace std;


string::size_type width(const vector<string>& v) {
	string::size_type maxlen = 0;

	for (vector<string>::size_type i = 0; i != v.size(); i++) {
		maxlen = max(maxlen, v[i].size());
	}

	return maxlen;
}


vector<string> frame(const vector<string>& v) {
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, ' *');

	//��� �׵θ��� �߰�
	ret.push_back(border);

	//�� ���� ��ǥ�� �������� �ѷ�����
	//���ڿ����� ���� �߰�
	for (vector<string>::size_type i = 0;
		i != v.size(); i++) {
		ret.push_back("*" + v[i]+
			string(maxlen - v[i].size(), ' ') + "*");
	}


	ret.push_back(border);
	return ret;
}

//���� ����
vector<string> vcat(const vector<string>& top,
	const vector <string>& bottom) {
	vector <string> ret = top;
	//�Ʒ��� ���� �׸��� ����
	for (vector<string>::const_iterator it = bottom.begin();
		it != bottom.end(); ++it) {
		ret.push_back(*it);
	}

	return ret;
}

vector<string> hcat(const vector<string>& left,
	const vector <string>& right) {
	vector<string> ret;

	string::size_type width1 = width(left) + 1;

	vector<string>::size_type i = 0, j = 0;

	while (i != left.size() || j != right.size()) {
		string s;

		if (i != left.size()) {
			s = left[i++];
		}

		s += string(width1 - s.size(), ' ');

		if (j != right.size()) {
			s += right[j++];
		}

		ret.push_back(s);
	}
	return ret;
}
vector<string> split(const string& s) {
	vector<string> ret;
	string word;
	for (char ch : s) {
		if (isspace(ch)) {
			if (!word.empty()) {
				ret.push_back(word);
				word.clear();
			}
		}
		else {
			word += ch;
		}
	}
	if (!word.empty()) {
		ret.push_back(word);
	}
	return ret;
}

int main() {
	string s;

	while (getline(cin, s)) {
		vector<string> v = split(s);

		for (const string& word : v) {
			cout << word << endl;
		}

		vector<string> framed = frame(v);
		for (const string& line : framed) {
			cout << line << endl;
		}
	}
	ofstream outFile("out.txt");

	// �Է¹��� ���ڿ��� ���ͷ� �и��Ͽ� ����
	while (getline(cin, s)) {
		vector<string> v = split(s);

		// split() ��� ���
		for (const string& word : v) {
			cout << word << endl;
			outFile << word << endl;
		}

		// �������� �����Ͽ� ���
		vector<string> framed = frame(v);
		for (const string& line : framed) {
			cout << line << endl;
			outFile << line << endl;
		}

		// ���� ����(vcat)�� ������ ��� ���
		vector<string> top = { "Top 1", "Top 2", "Top 3" };
		vector<string> bottom = { "Bottom 1", "Bottom 2", "Bottom 3" };
		vector<string> vcat_result = vcat(top, bottom);
		for (const string& line : vcat_result) {
			cout << line << endl;
			outFile << line << endl;
		}

		// ���� ����(hcat)�� ������ ��� ���
		vector<string> left = { "Left 1", "Left 2", "Left 3" };
		vector<string> right = { "Right 1", "Right 2", "Right 3" };
		vector<string> hcat_result = hcat(left, right);
		for (const string& line : hcat_result) {
			cout << line << endl;
			outFile << line << endl;
		}
	}

	// out.txt ���� �ݱ�
	outFile.close();

	return 0;
}
//���� 1.split()�������� ����ϱ�
//2. vcat()����ϱ�
//3.hcat() ����ϱ�
//4.out.txt ���Ϸ��� ��� ��� �������ּ���
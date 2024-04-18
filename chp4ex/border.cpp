#include<string>
#include<vector>
#include<iostream>
#include <fstream> // 파일 작업을 위해 필요
#include <iomanip> // setprecision을 위해 필요

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

	//상단 테두리를 추가
	ret.push_back(border);

	//양 끝이 별표와 공백으로 둘러싸인
	//문자열들을 각각 추가
	for (vector<string>::size_type i = 0;
		i != v.size(); i++) {
		ret.push_back("*" + v[i]+
			string(maxlen - v[i].size(), ' ') + "*");
	}


	ret.push_back(border);
	return ret;
}

//수평 결합
vector<string> vcat(const vector<string>& top,
	const vector <string>& bottom) {
	vector <string> ret = top;
	//아래쪽 문자 그림을 복사
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

	// 입력받은 문자열을 벡터로 분리하여 저장
	while (getline(cin, s)) {
		vector<string> v = split(s);

		// split() 결과 출력
		for (const string& word : v) {
			cout << word << endl;
			outFile << word << endl;
		}

		// 프레임을 적용하여 출력
		vector<string> framed = frame(v);
		for (const string& line : framed) {
			cout << line << endl;
			outFile << line << endl;
		}

		// 수직 결합(vcat)을 적용한 결과 출력
		vector<string> top = { "Top 1", "Top 2", "Top 3" };
		vector<string> bottom = { "Bottom 1", "Bottom 2", "Bottom 3" };
		vector<string> vcat_result = vcat(top, bottom);
		for (const string& line : vcat_result) {
			cout << line << endl;
			outFile << line << endl;
		}

		// 수평 결합(hcat)을 적용한 결과 출력
		vector<string> left = { "Left 1", "Left 2", "Left 3" };
		vector<string> right = { "Right 1", "Right 2", "Right 3" };
		vector<string> hcat_result = hcat(left, right);
		for (const string& line : hcat_result) {
			cout << line << endl;
			outFile << line << endl;
		}
	}

	// out.txt 파일 닫기
	outFile.close();

	return 0;
}
//과제 1.split()가져오고 사용하기
//2. vcat()사용하기
//3.hcat() 사용하기
//4.out.txt 파일레서 모든 출력 저장해주세요
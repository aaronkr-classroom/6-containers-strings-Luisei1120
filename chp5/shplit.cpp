// split.cpp
#include <cctype>
#include <istream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> split(const string& s) {
	vector<string> ret;
	typedef string::size_type string_size; // ���̽� as ó��
	string_size i = 0; //int ��� string::size_type ���

	// �Һ���: ���ݰ��� [������i, ������ i) ������ �ִ�
	// ���ڵ��� ó��
	while (i != s.size()) {
		// �����ϴ� ������� ����
		// �Һ���: ���ݰ��� [������i, ������ i) ������ �ִ�
		// ���ڵ��� ��� ����
		while (i != s.size() && isspace(s[i])) {
			++i;
		}

		// ������ ���� �ܾ��� ���� ã��
		string_size j = i;

	// �Һ���: ���ݱ���[������j, ������ j) ������ �ִ�
	// ���ڵ��� ������ �ƴ�
		while (j != s.size() && !isspace(s[j])) {
			j++;
		}

		//������ �ƴ� ���ڵ��� ã���� ��
		if (i != j) {
			// i�������� j-i���� ���ڵ餷�� s�� ����
			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	}
}
int main() {
	string s;

	// ���ڿ� �� �྿�Է¹޾� ����
	while (getline(cin, s)) {
		vector<string> v = split(s);

		// ���� v�� ������ �ܾ ���� ���
		for (vector<string>::size_type i = 0; i != v.size(); ++i)
			cout << v[i] << endl;
		

		}
	return 0;
	}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> v1;
	vector<int> v2(1, 5);
	vector<int> v3 = { 1, 2, 3, 4, 5 };

	v3.push_back(6);
	v3.push_back(7);

	cout << v3.size() << endl;	// 7
	cout << v3[6] << endl;	// 7

	v3.pop_back();

	cout << v3[0] << endl;	// 1	(맨 마지막 것.. 7이 삭제.)
	cout << v3[5] << endl;	// 6
	cout << v3.size() << endl;	// 6

	return 0;
}
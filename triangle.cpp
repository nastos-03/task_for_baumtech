// ������ 5 - ������������ 
// ��� ����������� (� ���� ������ �������, ��� triangle[i] - ��� ������ � i+1 ���������
// ����� ����������� ����� ���� �� ������� ������������ �� ��� ���������
// �� ������ ���� �������� ������������� �� �������� ����� � ������ ����
// ���� �� ���������� �� ������� i � ������� ������, �� ����� �������� �� i � ������� �� i + 1 � ��������� ������
// ������� �� ����� �(n^2) 

// �������
// ������ �� ������������ ����������������. 
// ���� �� ������� � �������� ������ � ������ - �� ������ ���� ������ ����. ���, �� ��� ������, �������. 
// ��� ���������: �� ������ ������� ������� (������� ������ / ����������) ������� ���������, ��� ����� ���� 
// [-1 3 -3 1], � �� [-1 2 -1  1] 

// ������� �������������� ���� ������������� �� �����
// ����� �������, ��� ������� �� ����������� O(n^2) �������� O(n^2) 


#include "stdafx.h" // ��� ������ � ��������. ���� �� Visual Studio 2010 
#include <iostream>	
#include <vector>	// ��� �������� ��������
#include <algorithm>

using namespace std;

// ������� ���������� ������������ ���� �� O(n^2) � �� O(n) ������
int ShortWay(vector<vector<int>> & triangle) { 
	if(triangle.empty()) return 0;
	
	int triangle_size = triangle.size();
	vector<int> dp(triangle_size, 0); 
	dp[0] = triangle[0][0];

	for (int i = 1; i < triangle_size; i++) {
		vector<int> temp = dp;
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[j] = triangle[i][j] + temp[j];
			} else if (j == i) {
				dp[j] = triangle[i][j] + temp[j-1];
			} else {
				dp[j] = triangle[i][j] + min(temp[j-1], temp[j]);
			}
		}
	}

	return *min_element(dp.begin(), dp.end());
}

int main() {
	cout << "Hello, baumtech " << endl;
	//vector<vector<int>> triangle1 = {{2},{3,4},{6,5,7},{4,1,8,3}}; - ��� �++11
	vector<vector<int>> triangle1(4);
	triangle1[0].push_back(2);

	triangle1[1].push_back(3);
	triangle1[1].push_back(4);

	triangle1[2].push_back(6);
	triangle1[2].push_back(5);
	triangle1[2].push_back(7);

	triangle1[3].push_back(4);
	triangle1[3].push_back(1);
	triangle1[3].push_back(8);
	triangle1[3].push_back(3);
	
	//vector<vector<int>> triangle2 = {{-1},{2,3},{1,-1,-3},{4,2,1,3}}; - ��� �++11

	vector<vector<int>> triangle2(4);
	triangle2[0].push_back(-1);

	triangle2[1].push_back(2);
	triangle2[1].push_back(3);

	triangle2[2].push_back(1);
	triangle2[2].push_back(-1);
	triangle2[2].push_back(-3);

	triangle2[3].push_back(4);
	triangle2[3].push_back(2);
	triangle2[3].push_back(1);
	triangle2[3].push_back(3);


	cout << "Answer for Trangle 1: " << endl;
	cout << "Short way is: " << ShortWay(triangle1) << endl;

	cout << "Answer for Trangle 2: " << endl;
	cout << "Short way is: " << ShortWay(triangle2) << endl;


	system("pause"); //  ��� ��������� �������
}


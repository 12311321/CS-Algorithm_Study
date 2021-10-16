#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
����: �Է����� �־��� IPv6�� ������ ���� ���¸� ���
1. �� �׷��� ���ڸ��� 0�� ��ü �Ǵ� �Ϻθ� ���� �� �� �ִ�.
2. 0���θ� �̷���� �ִ� �׷� -> �ݷ� 2��(::)�� �ٲ� �� �ִ�.
3. 2�� ���� �� ���� ����� �� �ִ�.
*/

string s;

void sol()
{
	//0���θ� �̷���� �ִ� �׷� -> �ݷ� 2��(::)�� �ٲ� �� �ִ�.
	if (s == "::")
	{
		cout << "0000:0000:0000:0000:0000:0000:0000:0000"; return;
	}

	vector<string> answer;
	string temp = ""; int idx = -1; bool flag = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ':') //: ���� �Ľ�
		{
			if (!temp.empty())
			{
				while (temp.length() < 4)//0�� ������ ���̹Ƿ� ä���ش�
					temp = "0" + temp;
				answer.push_back(temp);

				temp = "";
			}
			if (s[i + 1] == ':') //2�� ����
			{
				idx = answer.size();
				flag = true;
			}
		}
		else
			temp += s[i];
	}

	if (flag) //������ ��ġ�� 0000 �߰�
	{
		while (answer.size() < 7)
			answer.insert(answer.begin() + idx++, "0000");
	}
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << ":";
	if (!temp.empty())
	{
		while (temp.length() < 4)
			temp = "0" + temp;
		cout << temp;
	}
	else if (answer.size() < 8)
		cout << "0000";
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
}
int main()
{
	init();
	sol();

	return 0;
}
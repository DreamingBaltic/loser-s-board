//只能处理正确输入，无法处理类似000005/0001这种数据
#include <bits/stdc++.h>
using namespace std;

int a[101],b[101],c[101];
void init(int a[])
{
	string s;
	cin >> s;
	a[0] = s.length();
	for (int i = 1; i <= a[0]; i++)
		a[i] = s[a[0]-i] - '0';
}

void print(int a[])
{
	if (!a[0])
	{
		cout << 0 << endl;
		return;
	}
	for (int i = a[0]; i > 0; i--)
		cout << a[i];
	cout << endl;
}

int compare(int a[], int b[])
{
	if (a[0] > b[0])	return 1;
	if (a[0] < b[0])	return -1;
	for (int i = a[0]; i > 0; i--)
	{
		if (a[i] > b[i])	return 1;
		if (a[i] < b[i])	return -1;
	}
	return 0;
}

void jian(int a[], int b[])
{
	int flag = compare(a,b);
	if (!flag)
	{
		a[0] = 0;
		return;
	}
	if (flag == 1)
	{
		for (int i = 1; i <= a[0]; i++)
		{
			if (a[i] < b[i])
			{
				a[i+1]--;
				a[i] += 10;
			}
			a[i] -= b[i];
		}
		while (a[0] > 0 && a[a[0]] == 0)
			a[0]--;
	}
}

void numcpy(int p[], int q[], int det)//复制p数组到q数组从det开始的地方
{
	for (int i = 1; i <= p[0]; i++)
		q[i+det-1] = p[i];
	q[0] = p[0]+det-1;
}

void chugao(int a[], int b[], int c[])
{
	c[0] = a[0] - b[0] +1;
	int temp[101];
	for (int i = c[0]; i > 0; i--)
	{
		memset(temp,0,sizeof(temp));
		numcpy(b,temp,i);
		while (compare(a,temp) >= 0)
		{
			c[i]++;
			jian(a,temp);
		}
	}
	while (c[0] > 0 && !c[c[0]])
		c[0]--;
}

int main()
{
	init(a),init(b);
	chugao(a,b,c);
	print(c);
	print(a);
	return 0;
}
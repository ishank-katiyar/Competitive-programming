#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,c=0,count[3]={0};
	scanf("%d\n",&n);
	string s;
	getline(cin,s);
	for(i=0;i<n;i++)
	{
		count[s[i]-'0']++;
	}
	if(count[0]<n/3)
	{
		for(i=0;i<n;i++)
		{
			if(count[s[i]-'0']>n/3)
			{
				count[s[i]-'0']--;
				count[0]++;
				s[i]='0';
			}
			if(count[0]>=n/3)
			{
				break;
			}
		}
	}
	if(count[2]<n/3)
	{
		for(i=n-1;i>=0;i--)
		{
			if(count[s[i]-'0']>n/3)
			{
				count[s[i]-'0']--;
				count[2]++;
				s[i]='2';
			}
			if(count[2]>=n/3)
			{
				break;
			}
		}
	}
	if(count[1]<n/3)
	{
		for(i=0;i<n;i++)
		{
			if(s[i]=='0')
			{
				c++;
				if(c>=n/3)
				{
					c=i;
					break;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			if(count[1]>=n/3)
			{
				break;
			}
			if(s[i]=='0' && i>c && count[0]>n/3)
			{
				count[0]--;
				count[1]++;
				s[i]='1';
			}
			else if(s[i]=='2' && count[2]>n/3)
			{
				count[2]--;
				count[1]++;
				s[i]='1';
			}
		}
	}
	cout<<s << '\n';
	return 0;
}

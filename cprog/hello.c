#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define f first
#define s second
#define inf 61243876128716
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> p;
	while(n>0)
	{
	    p.pb(n%10);
	    n=n/10;
	}
	bool b[17389]={0};
	int l=1;
	for(int i=0;i<p.size();i++)
	{    //cout<<p[i]<<" ";
	    for(int j=i;j<p.size();j++)
	    {    ll a=1;
	        for(int k=i;k<=j;k++)
	        {
	            a=a*p[k];
	        }
	        if(b[a]==1)
	       {l=0;//cout<<a<<" ";
	       }
	        b[a]=1;
	    }
	}
	
	cout<<l;
	
	return 0;
}


//String Matching
//vinay
#include<bits/stdc++.h>
using namespace std;



void string_match(string str,string pat)
{
	int k,f=0;
	for(int i=0;i<str.size();i++)
	{  

		if(str[i]==pat[0])
		{   
			int l=1,k=1;
	    	for(int j=i+1;k<pat.size();j++,k++)
		  {
		        if(str[j]==pat[k])
		        	l++;

		        if(l==pat.size())
		        {
		        	f=1;
		        	cout<<"Matched from index "<<i<<" to "<<j;
		        	break;
		        }

	    	  }
    	}
    }

      if(f==0)
      	cout<<"Not Matched"<<endl;

}



int main()
{
	string str,pat;
	cin>>str;
	cin>>pat;
   string_match(str,pat);

}
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main()
{
int edges,a,b;
vector<int>nodes[1000];
cout<<"Enter the no. of edges:"<<endl;
	cin>>edges;
	for(int i=0;i<edges;i++){
		cin>>a>>b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	cout<<endl;
for(int i=0;i<1000;i++)
{
	if(!nodes[i].empty())
	{	cout<<"[ "<<i<<" ]"<<"-->";
		for(vector<int>::iterator it=nodes[i].begin();
				it!=nodes[i].end();++it)
		{
		cout<<*it<<"-->";
		}
		cout<<"NULL"<<endl;
	}	
}

stack<int> stk;
bool visited[1000] = { false };

int start;
cout<<"\nEnter the starting node"<<endl;
cin>>start;

stk.push(start);

while(!stk.empty()) 
{
int top = stk.top();
stk.pop();
	if(visited[top]==false)
	{
		visited[top]=true;
		cout<<top<<" ";
		for(vector<int>::iterator it=nodes[top].begin(); it!=nodes[top].end(); ++it)
			if(visited[*it]==false)
				stk.push(*it);
	}
}

cout<<endl;
return 0;
}

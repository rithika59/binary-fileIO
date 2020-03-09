#include<iostream>
#include<fstream>
using namespace std;

void write(char* fName)
{
	ofstream fout(fName,ios::binary);
	if(!fout)
	{
		cerr<<"Could not open the file \n";
	}
	else
	{
		int n;
		cout<<"Enter numbers to write into binary file (-1 to stop) \n";
		cin>>n;
		while(n != -1)
		{
			fout.write((char*)&n,sizeof(int));
			cin>>n;
		}
	}
}


void read(char* fName)
{
	ifstream fin(fName,ios::binary | ios::in);
	if(!fin)
	{
		cerr<<"could not open the file\n";
	}
	else
	{
		int no;
		fin.read((char*)&no, sizeof(int));
		while(!fin.eof())
		{
			cout<<no<<endl;
			fin.read((char*)&no, sizeof(int));
		}
		
	}
}

void readRev(char* fName)
{
	ifstream fin(fName,ios::binary | ios::in);
	if(!fin)
	{
		cerr<<"could not open the file\n";
	}
	else
	{
		int n;
		fin.seekg(0, ios::end);
		n = (fin.tellg()/ sizeof(int) );
		cout<<"There are "<<n<<" numbers written in the file. \n";
		cout<<"Reading them in reverse \n";
		int no = 50;
//		fin.read((char*)&no, sizeof(int));
		for(int i=n-1; i>=0;i--)
		{
			fin.seekg((sizeof(int))*i, ios::beg);
			fin.read((char*)&no, sizeof(int));
			cout<<no<<endl;
		}
		
	}
}


int main()
{
	write("bin.txt");
	read("bin.txt");
	readRev("bin.txt");
	return 0;
}

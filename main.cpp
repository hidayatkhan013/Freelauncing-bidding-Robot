#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string username;
string password, projname;
int projectbidding;
history(string a, int b)
{
	ofstream noproblem;
	ifstream thanks;
	string getcontent;
	noproblem.open("projname.txt", ios::app);
	thanks.open("projname.txt",ios::out);
	

     noproblem << a <<" "<< b << endl;
     cout<<"Your original order:"<<endl;
    noproblem<< projname << " " << projectbidding <<endl;
	 while(!thanks.eof())
        {
            getline(thanks, getcontent);
            cout<<endl;
        
		cout<<"			"<< getcontent;
        }
        cout<<endl;
}

int robotwrt(int &x)
{
	int c;
		if(x%2>0)
		{
		c=x-5;
		return c;
	}
		else if (x%2==0)
		{
			c=x-7;
			return c;
		}
		else if (x%2<0)
		{
			c=x-9;
			return c;
			
		}

}

void reduction(string a, int b)
{
   int x,l,lessbid,o,plus,minus,f,stop,save,up=0,time,price;
   	cout<<"*************************Bidding Area*************************"<<endl;
cout<<"The project name is:"<<a<<endl;
{
	cout<<"The starting bid is:"<<b<<"$"<<endl;
	cout<<"User! What do you bid?"<<endl;
    cin>>l;
    while(b>0)
    {
if(l<b)
{
	up++;
b=l;
cout<<"the user bid:"<<b<<"$"<<endl;
plus=robotwrt (b);
cout<<"the robot bid:"<<plus<<"$"<<endl;
if(plus<=5 || b<=5)
{
	cout<<"Robot has won!"<<endl<<"Robot's RULE!"<<endl;
	cout<<"When do you need the order done?"<<endl;
	cout<<"Options available: 24h, 48h; 24h has $5 extra charge"<<endl;
	cin>>time;
	if(time==24)
	{
		cout<<"Price of order ="<<"$"<<l<<"+"<<"$5";
		price = l+5;
	}
	else if(time==48)
	{
		cout<<"Price of order ="<<l;
		price =l;
	}
	cout<<"Going to User's order history"<<endl;
	history(a,price);
	break;
}
if(l==10 || plus==10)
{
	cout<<"Human has won! "<<endl;
	cout<<"When do you need the order done?"<<endl;
	cout<<"Options available: 24h, 48h; 24h has $5 extra charge"<<endl;
	cin>>time;
	
	if(time==24)
	{
		cout<<"Price of order = $10 + $5"<<endl;
		price = 15;
	}
	else if(time==48)
	{
		cout<<"Price of order = $10"<<endl;
		price = 10;
	}
	cout<<"going to user's order history";
	history(a,price);
	break;
	
	
}

cout<<"the bid is:"<<plus<<"$"<<endl;
cout<<"User! What do you bid?"<<endl;
    cin>>l;
if (l>plus)
{
	cout<<"You've entered a false bid!"<<endl;
	cout<<"The bid is still:"<<l<<endl;
	cout<<"User! What do you bid?"<<endl;
    cin>>l;
    continue;	
}

}

}
}
}
void User ()
{ //create a function with project reduction of bid
	int projectdemand;
	int option;
	string cat;
	cout<<"*************************Welcome to the User Area*************************"<<endl;
	cout<<"Please choose one of the following categories:"<<endl;
	cout<<"Pressing 1 will take you to the Writing Section. Category: Wrt"<<endl;
	cout<<"Pressing 2 will take you to the Video Editing section. Category Ved"<<endl;
	cout<<"Pressing 3 wll take you to the Programming section. Category Prgm."<<endl;
	cin>>option;
	switch(option)
	{
	 case 1:
	 	int choice;
	 	cout<<"Welcome to the Writing section."<<endl;
	 		cat='w';
	 		cout<<"Please enter the project name you want our FreeLancers to pick up:";
	cin>>projname;
	cout<<"Where do we start the bidding?";
	cin>>projectbidding;
	reduction (projname, projectbidding);
	break;

	case 2:
	 	cat='v';
	 	cout<<"Welcome to the Video Editing section."<<endl;
	 		cout<<"Please enter the project name you want our FreeLancers to pick up:";
	cin>>projname;
	cout<<"Where do we start the bidding?";
	cin>>projectbidding;
reduction (projname, projectbidding);break;
		

	case 3:
		cat='p';
	 	cout<<"Welcome to the Programming section."<<endl;
	 		cout<<"Please enter the project name you want our FreeLancers to pick up:";
	cin>>projname;
	cout<<"Where do we start the bidding?";
	cin>>projectbidding;
reduction (projname, projectbidding);
break;

	}

	

}
int logchck (string username, string password)
{
    ifstream user;
    int n=0;
    string usernf, passwf;
    user.open("users.txt");
    if (user.is_open())
    {
        while (!user.eof())
        {
            user >> usernf >> passwf;
            n++;
            if (username==usernf && password==passwf)
                return n;
        }
    }
    else
    {
        cout << "file not open" << endl;
    }
    return 0;
}
void registeration()
{
	string usrnm,passwd,passconf;
	bool validuser = false;
	int u=0, p=0;
	ifstream user;
	ofstream nusers;
	user.open ("users.txt", ios::app);
	nusers.open("users.txt", ios::app);
	while (!validuser)
	{
		cout<<"Please enter a username:";
		cin>>usrnm;
		cout<<"Please enter a password:";
		cin>>passwd;
		cout<<"Please confirm your password:";
		cin>>passconf;
		while(user >> username >> password)
		{
			u++;
			if(usrnm !=username)
			p++;
		}
		if(u==p && passwd==passconf)
		validuser=true;
		else if(u!=p)
		cout<<"This username already exists!";
		else 
		{
			"Passwords do NOT match!";
		}
	}
	nusers<<usrnm<<" "<<passwd<<endl;
	user.close();
	nusers.close();
	
}
int main (void)
{
	int attemptlogin, options;
	string us, ps;
	fstream file;
   file.open("users.txt",ios::app);
	if(!file.is_open())
	{
	cout<<"File doesn't exist!";
    }
else
{
	cout<<"1 to register, 2 to login:";
	cin>>options;
	switch(options)
	{
case 1:
	registeration ();
	case 2:		
	{

			while(logchck(username, password)==0)
			{
				attemptlogin++;
				cout<<"please enter your username:";
				cin>>username;
				cout<<"Please enter your password:";
				cin>>password;
				if(logchck(username,password)!=0)
				{
					cout<<"welcome user!"<<endl;;
					User();
				}
				else if(attemptlogin==3)
				{
					cout<<"you dont have any more login attempts remaining!"<<endl;;
					break;
				}
				else
				{
					cout<<"you've entered a wrong combination of pass / username"<<endl;;
				}
								
				}
				file.close();
				
			}
	}
}	
}

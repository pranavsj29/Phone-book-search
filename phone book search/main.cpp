#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include <fstream>
 
using namespace std;
//global declaratin
typedef struct{
	char name[40];
	char phone[20];
}listing;
const int max_size = 60;
//prototype declaratin
void buildlist(listing phonelist[],int& last);
void searchlist(listing *phonelist,int last);
bool seqsearch(listing list[],int last,
				char  *target,int& locn);
				
int main(){
	//local defination
	listing phonelist[max_size];
	int last;
	//statments
	cout<<"Begin Phone listing"<<endl;
	last =max_size-1;
	buildlist(phonelist,last);
	searchlist(phonelist,last);
	cout<<"end phone listing"<<endl;
}//main

/*======================================build list==============================
read phone number file and load into array.
pre phonelist is array to be filed
last is index to last element loaded
post array filed
*/
void buildlist(listing phonelist[],int& last){


	//local defination
	ifstream fsphonenums;
	int i;
	//steatments
	fsphonenums.open("P2-03.TXT");
	if(!fsphonenums)
	{
		cout<<"can't open phone file"<<endl;
	}//if
	i=0;
	while(i<=last && !fsphonenums.eof())
	{
		fsphonenums.getline(phonelist[i].name,
						sizeof(phonelist[0].name),';');
		fsphonenums.getline(phonelist[i].phone,
							sizeof(phonelist[0].phone));
							i++;
	}//while
	if(!fsphonenums.eof())
	cout<<"File too large .not all numbers read"<<endl;
	last=i-1;
	return;
}//buildlist
/*===================searchlist=========================
prompt user for name and look up in array.
pre phonelist has been intialized
post user requested quit
*/
void searchlist(listing *phonelist,int last)
{
	//local definition
	char srchname[31];
	char more;
	bool found;
	int locn;
	
	//statment
	do{
		cout<<"enter your name";
		cin>>srchname;
		found = seqsearch(phonelist,last,srchname,locn);
		if(found){
		
			cout<<phonelist[locn].name<<"("<<locn<<")"
			<<phonelist[locn].phone<<endl;
		}
		else{
			cout<<srchname<<"not found"<<endl;
		}
		cout<<"look up another number<Y/N>?";
		cin>>more;
		
	}while(more=='Y'||more=='y');
}//searchlist
/*=================================seqsearch=============================
locate the target in an unorderd list.
pre : list must contain at least one iteam .
		last is index to last element in the list 
		target contain the data to be located 
		locn is address to index in calling function.
post:found:matching index stored at locn
			return true (found)
	not found: last stored in locn address,
				retrun false(not found)
*/
bool seqsearch
(
listing list[],
int last,
char *target,
int &locn
)
{
	//local defination
	int looker;
	//statments
	looker=0;
	while(looker<last&&strcmp(target,list[looker].name)!=0)
	looker++;
	locn=looker;
	return(strcmp(target,list[looker].name)==0);
	
}//seqsearch
	















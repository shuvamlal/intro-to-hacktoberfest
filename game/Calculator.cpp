#include<iostream>
using namespace std;

int main()
{
int a,b,res,rem;
char ch,choice;
do
{
cout<<"\n\t\t **********CALCULATOR********** ";
cout<<"\n Enter first number : ";
cin>>a;
cout<<" Enter second number : ";
cin>>b;
cout<<"\n 1. '+' \n 2. '-' \n 3. '*' \n 4. '/'";
cout<<"\n Enter the choice : ";
cin>>ch;

switch(ch)
{
 case '1':
  res=a+b;
  cout<<" Addition = "<<res;
  break;
 case '2':
  res=a-b;
  cout<<" Subtraction = "<<res;
  break;
 case '3':
  res=a*b;
  cout<<" Multiplication = "<<res;
  break;
 case '4':
  res=a/b;
  rem=a%b;
  cout<<" Quotient = "<<res;
  cout<<" Remainder = "<<rem;
  break;
 default:
  cout<<" Wrong Choice Entered!! ";
}
cout<<" \n Do you want to continue.....(Y/N): ";
cin>>choice;
}while(choice=='Y' || choice=='y');
return 0;
}

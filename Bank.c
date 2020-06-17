#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct transaction
{
	char type[10];
	int amount;
	int balance;
}stmnt;
typedef int pass;
typedef struct customer{
	char name[20];
	char acc_type[10];
	float balance;
	long int acc_number;
	pass PIN;
	stmnt statement[10];
}customer;
char reset[1];//using this to reset the trailing new line left by scanf
void viewBalance(customer this)
{
	printf("Balance: %f\n\n",this.balance);
}
long int acc_num=1000100010001000;
void display(customer this)
{
	printf("\nAccount Details:\n\nAccount Holder Name: ");
	puts(this.name);
	printf("Account Number: %ld\n",this.acc_number);
	printf("Account Type: ");
	puts(this.acc_type);
	viewBalance(this);
}
float deposit(customer this)
{
	int flag;
	float d;
	do
	{
		flag=0;
		printf("Enter Amount (Enter 0 to cancel) :");
		scanf("%f",&d);
		if(d+this.balance<3000 && d!=0)
		{
			printf("Minimum Balance should be 3000\n\nTransaction Declined\n\nPlease Re-Enter\n\n");
			flag=1;
		}
	}while(flag==1);
	this.balance+=d;
	if(d!=0)
		printf("Transaction Sucessful\nUpdated ");
	viewBalance(this);
	return d;
}
float withdraw(customer this)
{
	int flag;
	float w;
	do
	{
		flag=0;
		printf("Enter Amount: (Enter -1 to cancel) :");
		scanf("%f",&w);
		if(this.balance-w<3000 && w!=0)
		{
			printf("Minimum remaining balance should be 3000\n\nTransaction Declined\n\nPlease Re-Enter\n\n");
			flag=1;
		}
	}while(flag==1);
	this.balance-=w;
	if(w!=0)
		printf("Transaction Sucessful\nRemaining ");
	viewBalance(this);
	return w;
}


customer newAccount()
{
	customer new;
	printf("Enter Name: ");
	gets(reset);
	fflush(stdin);
	gets(new.name);
	int f;
	do
	{
		f=0;
		printf("\nSelect Account type:\nPress 1 for Savings\nPress 2 for current\nEnter Choice: ");
		int ch;
		scanf(" %d",&ch);
		switch(ch)
		{
			case 1 :
			{
				strcpy(new.acc_type,"Savings");
				break;
			}
			case 2 :
			{
				strcpy(new.acc_type,"Current");
				break;
			}
			default :
			{
				printf("Wrong Choice\n");
				f=1;
				break;
			}
		}
	}while(f==1);
	printf("Deposit amount (Minimum 3000)\n");
	new.balance=0.0;
	new.balance+=deposit(new);
	new.acc_number=acc_num;
	acc_num+=25;
	do
	{
		printf("Create PIN: ");
		pass newp,confirm;
		scanf("%d",&newp);
		printf("Re-Enter PIN: ");
		scanf("%d",&confirm);
		if(newp==confirm)
		{
			printf("PIN Generated\n");
			new.PIN=newp;
			break;
		}
	}while(1);
	printf("---------------------------------------\n Account Number Generated Sucessfully!!\n---------------------------------------\n");
	display(new);
	return new;
}
int search(long int acc,char name[],customer list[],int l)
{
	int i;
	if (acc!=0)
	{
		for(i=0;i<l;i++)
		{
			if(list[i].acc_number==acc)
			{
				printf("Account found\n");
				return i;
			}
			else
			{
				printf("Accont number has no match");
				return -1;
			}
		}
	}
	else if(name!=NULL)
	{
		int count=0;
		for(i=0;i<l;i++)
		{
			if(strcmp(name,list[i].name)==0)
			{
				count++;
				printf("Name: ");
				puts(list[i].name);
				printf("Accont Type: ");
				puts(list[i].acc_type);
				printf("Accont number: %ld\n",list[i].acc_number);
			}
		}
		if(count==1)
		{
			printf("Found account!!\n");
			return i;
		}
		else if(count>1)
		{
			printf("Total match found: %d\n",count);
			printf("Please note down you account number and re-enter\n");
			printf("Enter account number: \n");
			scanf("%ld",&acc);
			return search(acc,NULL,list,l);
		}
		else
		{
			printf("No Match found\n");
			return -1;
		}	
	}
	else
	{
		printf("Invalid details\n");
		return -999;
	}
}
int authenticate(customer this)
{
	pass in_pin;
	printf("Enter PIN: \n");
	scanf("%d",&in_pin);
	int flag=in_pin==this.PIN?1:0;
	return flag;

}
customer Banking(customer this)
{
	if(authenticate(this))
	{	
		printf("Acess Granted!\n");
		int flag;
		do 
		{
			flag=0;
			printf("Press 1 to view Balance\nPress 2 to withdraw\nPress 3 to deposit\nPress 4 to return to previous menu\n\nEnter choice: ");
			int choice;
			scanf("%d",&choice);
			switch(choice)
			{
				case 1 :
				{
					viewBalance(this);
					break;
				}
				case 2 :
				{
					this.balance-=withdraw(this);
					break;
				}
				case 3 :
				{
					this.balance+=deposit(this);
					break;
				}
				case 4 :
				{
					flag = 1;
					break;
				}
				default :
				{
					printf("Wrong Choice!\n");
				}
			}
		}while(flag!=1);
	}
	else
		printf("Acess Denied!!!\n");
	return this;


}

void main()
{
	int n=0,i,flag;
	customer list[30];//=(customer*)malloc(n*sizeof(customer));
	do {

		printf("Press 1 for new account\nPress 2 to search and select account\n\nPress 0 to exit\n\n");
		int ch1;
		printf("Enter choice: ");
		scanf("%d",&ch1);
		flag=0;
		switch(ch1)
		{
			case 1 :
			{
				//list=(customer*)malloc(sizeof(customer));
				list[n]=newAccount();
				n++;
				break;
			}
			case 2 :
			{
				long int acn;
				do
				{
					printf("Enter account number (if you have forgot account number enter 0 to search for your account by name)\n" );
					scanf("%ld",&acn);
					int index=-1;
					if(acn>0)
					{
						index=search(acn,NULL,list,n);
						
					}
					else if(acn==0)
					{
						printf("Enter Name: ");
						char sk[20];
						gets(reset);
						gets(sk);
						index=search(0,sk,list,n);
					}
					else
					{
						printf("Please try again\n\n");
					}
					if(index!=-1)
					{

						customer temp=Banking(list[index]);
						list[index]=temp;
						break;
					}
					else
					{
						printf("Account not found\n\n");
						break;
					}
				}while(1);
				break;
			}
			case 0 :
			{
				flag=1;
				break;
			}
			default :
			{
				printf("Wrong Choice\n");
				break;
			}

		}
	}while(flag!=1);
	printf("Thank You\n");
}
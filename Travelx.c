/*
Developed by: Abdul Basit, Hafsa, Nizamuddin, Danish
Project name: Travelx
Project Overview:
Created Date: 18th December 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Signup FUNCTIONS: If an account does not exists then you are to provide with the required details for the account, which then later on
will be stored in a file and can be use for the LOGIN FUNCTION.=========================================================================================================================
*/

void Signup()
{
	char username[50];
	char password[50];
	
	printf("\t\tWelcome to SignUp Process!\t\t\n\n\n");
	printf("Enter your\n");
	printf("Username:");
	scanf("%s",username);
	printf("Enter your\n");
	printf("Password:");
	scanf("%s",password);
	printf("\nCongratulations your account has being created.\n\n");
	printf("Your account is:\n");
	puts(username);
	puts(password);
	FILE * fp;
	fp=fopen("account.txt", "w");
	fprintf(fp, "%s\n",username);
	fprintf(fp, "%s",password);
	fclose(fp);
	Login();
	
}

/*
LOGIN FUNCTIONS : Ask for a login from the user if account already exists, if it doesnt exists
then print an error message or if the account exist and the user entered username and password
doesnt match with the file it should also print an error!.==============================================================================================================================
*/

int Login()
{
	char username[50];
	char password[50];
	
	printf("\t\tWelcome to Login Process!\t\t\n\n\n");
	printf("Enter your\n");
	printf("Username:");
	scanf("%s",username);
	printf("Enter your\n");
	printf("Password:");
	scanf("%s",password);
	FILE * fp;
	int num; 
	char buffer[50],buffer2[50];
	fp=fopen("account.txt", "r");
	if(fp==NULL)
	{
		printf("Error, Your account does not exist");
		return 1;
	}
	else
	{
		fscanf(fp,"%s",buffer);
		fscanf(fp,"%s",buffer2);	
    }
    fclose(fp);
    int x=strcmp(username,buffer);
    int y=strcmp(password,buffer2);
    if(x==0 && y==0)
    {
    	printf("Your account has been succesfully logged in.");
	}
	else
	{
		printf("Error,Username or Password is incorrect");
		return 2;
	}
}

/*
SEAT BOOKING FUNCTION: in where we book the seats for the input in a flight and check if it is available then mark it with a X or if it is not
then print an error message saying "Seat is booked". An open seat should show a 0 that can be book by the user if they want.=============================================================
*/

int ticket_verification(int size)
{
	int i,s,j,k;
	char c[9][24];
	printf("   Seats  Plan\t\n\n");
	FILE *fptr;
		fptr=fopen("Seats.txt","r");
		if(fptr==NULL)
		{
			printf("ERROR!, No seats were found");
		}
		else
		{
			for(i=0;i<8;i++)
			{ 
				for(j=0;j<17;j++)
				{
					fscanf(fptr,"%c",&c[i][j]);
				}
				
			}
		}
	fclose(fptr);
	
	for(i=0;i<8;i++)
	{ 
		for(j=0;j<17;j++)
		{
			printf("%c",c[i][j]);
		}
	}
	for(i=0;i<size;i++)
	{
		printf("\n\nWhich seat you want to book?\n");
		printf("(Enter Row number)");
		scanf("%d",&s);
		printf("Now enter your seat number (Column number)");
		scanf("%d",&k);
		if(c[s-1][k-1]=='X' || c[s-1][k+2]== 'X' || c[s-1][k+5]== 'X')
		{
			printf("Seat is already booked!\n");
			return 1;
		}else if(k<4)
		{
			c[s-1][k-1]= 'X';
		}
		else if(k>3 && k<8){
			c[s-1][k+2]= 'X';		
		}else if(k>7)
		{
			c[s-1][k+5]= 'X';
		}
	}
	
	printf("\nSeating plan after your booking is...\n\n");
	for(i=0;i<8;i++)
	{ 
		for(j=0;j<17;j++)
		{
			printf("%c",c[i][j]);
		}
	}
	printf("\n\n");
	FILE *fp;
	fp=fopen("Seats_temp.txt","w");
	for(i=0;i<8;i++)
	{ 
		for(j=0;j<17;j++)
		{
			fprintf(fp,"%c",c[i][j]);
		}
	}
	fclose(fp);
	remove("Seats.txt");
	rename("Seats_temp.txt","Seats.txt");
	return 3;
}

/*
BUS FUNCTIONS
*/

char ch[10][130]={"fortune  Express"," Lucky Express","Alfredo  Express "," dora Express","winter Express","Paris Express"};
void bus();//for list of bus
void booking();//for booking the tickets
void bus1();
void bus2();
void bus3();
void bus4();
void ticket();

void bus()
{
    printf("\n\n\n");
    printf("\t\t\t\t\t[1]  =>  %s\n",ch[0]);
    printf("\n");
    printf("\t\t\t\t\t[2]  =>  %s\n",ch[1]);
    printf("\n"); 
	printf("\t\t\t\t\t[3]  =>  %s\n",ch[2]);
    printf("\n"); 
	printf("\t\t\t\t\t[4]  =>  %s\n",ch[3]);
    printf("\n"); 
	printf("\t\t\t\t\t[5]  =>  %s\n",ch[4]);
}

void booking()
{   int n;
   bus();
   printf("enter bus number");
   scanf("%d",&n);
   if(n==1){
   	bus1();
   }else if(n==2){
   	bus2();
   }else if(n==3){
   	bus3();
   }else if(n==4){
   	bus4();
   }
}

void bus1(){
	ticket();
	printf("booking sucessful");
	}
void bus2(){
	ticket();
	printf("booking sucessful");
}
void bus3(){
	ticket();
	printf("booking sucessful");
}
void bus4(){
	ticket();
	printf("booking sucessful");
}
void bus5(){
	ticket();
	printf("booking sucessful");
}	
	void ticket(){
	int a;
	int t;
	printf("Re-enter your bus number");
	scanf("%d",&a);	
	printf(" %d => %s",a,ch[a-1]);
	printf("\nenter tickets you want to book\n\n");
	scanf("%d",&t);
	switch(t){
		case 1 : {
			char name[10];
			printf("enter name\n");
			scanf("%s",&name);
		//	printf("booking sucessful");
			break;
		}
		case 2 : {
			char n1[10];
			char n2[10];
			printf("enter name for person 1\n");
			scanf("%s",&n1);
			printf("enter name for person 2\n");
			scanf("%s",&n2);
			
			
			break;
		}
		
		case 3 : {
			
		
		char n1[10];
		char n2[10];
		char n3[10];
		printf("enter name for person 1\n");
		scanf("%s",&n1);
		printf("enter name for person 2\n");
		scanf("%s",&n2);
		printf("enter name for person 3\n");
		scanf("%s",&n3);
		break; }
		
		case 4 : {
			char n1[10];
			char n2[10];
			char n3[10];
			char n4[10];
			printf("enter name for person 1\n");
			scanf("%s",&n1);
			printf("enter name for person 2\n");
			scanf("%s",&n2);
			printf("enter name for person 3\n");
			scanf("%s",&n3);
			printf("enter name for person 4\n");
			scanf("%s",&n4);
			
			break;
		}
		case 5 : {
			char n1[10];
			char n2[10];
			char n3[10];
			char n4[10];
			char n5[10];
			printf("enter name for person 1\n");
			scanf("%s",&n1);
			printf("enter name for person 2\n");
			scanf("%s",&n2);
			printf("enter name for person 3\n");
			scanf("%s",&n3);
			printf("enter name for person 4\n");
			scanf("%s",&n4);
			printf("enter name for person 5\n");
			scanf("%s",&n5);
			break;
		}
		
		
	}
}

/*
HOTEL FUNCTIONS=============================================================================================================================================================================
*/

char hotel_name[][130] = {"Hotel Elite", "The New View", "Happy Stay", "Welcome Stay", "Desi Hotel"};
void hotel();
void name();
void room();
void bookings();
void hotel1();
void hotel2();
void hotel3();
void hotel4();
void hotel5();
void members();


struct hotel{
	char name[20];
	char room[20];
	char booking[20];

}h;

void name(){
			
			printf("\t\t\t 1= %s\n\n", hotel_name[0]);
			printf("\t\t\t 2= %s\n\n", hotel_name[1]);
			printf("\t\t\t 3= %s\n\n", hotel_name[2]);
			printf("\t\t\t 4= %s\n\n", hotel_name[3]);
			printf("\t\t\t 5= %s\n\n", hotel_name[4]);
		}
		
		void bookings(){
			
			int n;
			
			printf("enter hotel number: ");
			scanf("%d", &n);
			
			if(n==1){
         	hotel1();	
           }
           
		    else if(n==2){
   			hotel2();
   			}
			
			else if(n==3){
   			hotel3();
   			}
			   
			else if(n==4){
   			hotel4();
			}
			
			else if(n==5){
			hotel5();
			}
}

void hotel1(){
	members();
	printf("Successfully booked!!");
}
void hotel2(){
	members();
	printf("Successfully booked!!");
}
void hotel3(){
	members();
	printf("Successfully booked!!");
}
void hotel4(){
	members();
	printf("Successfully booked!!");
}
void hotel5(){
	members();
	printf("Successfully booked!!");
}


void members(){
	
	int m;
	
	printf("\nEnter members want to stay: \n\n");
	scanf("%d", &m);
	
	switch(m) {
	
		case 1 : {
		
			char name[20];
			printf("Enter the name: \n");
			scanf("%s", &name);
			break;
	}
	case 2 : { 
		char n1[20];
		char n2[20];
		
		printf("Enter the name for person 1\n");
		scanf("%s", &n1);
		printf("Enter the name for person 2\n");
		scanf("%s", &n2);
		break;
	}
	case 3 : {
		char n1[20];
		char n2[20];
		char n3[20];
		
		printf("Enter the name for person 1\n");
		scanf("%s", &n1);
		printf("Enter the name for person 2\n");
		scanf("%s", &n2);
		printf("Enter the name for person 3\n");
		scanf("%s", &n3);
		break;
	}
	case 4 : {
		char n1[20];
		char n2[20];
		char n3[20];
		char n4[20];
		
		printf("Enter the name for person 1\n");
		scanf("%s", &n1);
		printf("Enter the name for person 2\n");
		scanf("%s", &n2);
		printf("Enter the name for person 3\n");
		scanf("%s", &n3);
		printf("Enter the name for person 4\n");
		scanf("%s", &n4);
		break;
	}
	case 5 : {
		char n1[20];
		char n2[20];
		char n3[20];
		char n4[20];
		char n5[20];
		
		printf("Enter the name for person 1\n");
		scanf("%s", &n1);
		printf("Enter the name for person 2\n");
		scanf("%s", &n2);
		printf("Enter the name for person 3\n");
		scanf("%s", &n3);
		printf("Enter the name for person 4\n");
		scanf("%s", &n4);
		printf("Enter the name for person 5\n");
		scanf("%s", &n5);
		break;
}
}
}

//Services Functions====================================================================================================================================================================

	void funct(){
	
        char name[50];
		int cont_no;
		char deprtmt[50];
		char prob[50];
		int i;
        printf("Enter your Name:");
        scanf("%s",&name);
        printf("Enter your contact_no :");
        scanf("%d",&cont_no);
        printf("Enter your Department :");
        scanf("%s",&deprtmt);
        printf("Enter your Problem :");
        scanf("%s",&prob);
        FILE * fptr;
        char fn[100];
        fptr = fopen("fputc_Danish.txt", "a");  
            fprintf(fptr,"%s",name);
            fprintf(fptr,"%s"," ");
            fprintf(fptr,"%d",cont_no);
            fprintf(fptr,"%s"," ");
            fprintf(fptr,"%s",deprtmt);
            fprintf(fptr,"%s"," ");
            fprintf(fptr,"%s",prob);
			fprintf(fptr,"%s","\n");
            
        fclose(fptr);
  
        
    }
    void delete1(){
   
    int lno, ctr = 0;
        char ch;
        FILE *fptr1, *fptr2;
		char fname[1000];
        char str[1000], temp[] = "temp.txt";
	
		printf("-----------------------------------------\n"); 
			
        fptr1 = fopen("fputc_Danish.txt", "r");
       
        fptr2 = fopen(temp, "w"); // open the temporary file in write mode 
        if (!fptr2) 
		{
                printf("Unable to open a temporary file to write!!\n");
                fclose(fptr1);
        }
        printf(" Input the line you want to remove : ");
        scanf("%d", &lno);
		lno++;
        // copy all contents to the temporary file except the specific line
        while (!feof(fptr1)) 
        {
            strcpy(str, "\0");
            fgets(str, 1000, fptr1);
            if (!feof(fptr1)) 
            {
                ctr++;
                /* skip the line at given line number */
                if (ctr != lno) 
                {
                    fprintf(fptr2, "%s", str);
                }
            }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove("fputc_Danish.txt");  		// remove the original file 
        rename(temp, "fputc_Danish.txt");
    
    
}

int main ()
{
	printf("\t\tWelcome to Travelx Application!\t\t");
	printf("\n\n");
	printf("\t|Where all your travelling services are for cheap!|");
	printf("\n\n");
	printf("\t  Signup \t\t");
	printf("\t\t Login \t\t\n");
	printf("\t   [1] \t\t");
	printf("\t\t\t  [2]\t\t\n");
	
	int n,w,number,num,i,deals;
	
	printf("\n\nSignup if you dont already have an account.\n");
	printf("Login if you already have an account.\n");
	scanf("%d",&n);
	printf("\n");
	if(n==1)
	{
		Signup();
	}
	else if(n==2)
	{
		int z=Login();
		if(z==1 || z==2)
		{
			return 1;
		}
	}
	else
	{
		printf("\tERROR!, Key pressed was invalid.");
		return 1;
	}
	printf("\n\n\n");
	printf("\tFlight Booking\t\t Bus Services\t\tHotel Booking\n");
	printf("\t      [1]\t\t     [2]\t\t    [3]\n\n");
	printf("\t\t\tDeals\t\t\tServices\n");
	printf("\t\t\t [4]\t\t\t  [5]");
	scanf("%d",&w);
	printf("\n\n\n\n");
	int a1=0;
	switch(w){
		case 1:
			//Flight reservation========================================================================================================================================================
			printf("\t\t\tWelcome to Flight Booking!\t\t\n\n");
			printf("1.International Flights!(75,000 PKR)\n2.Domestic Flights(15,000PKR)\n");
			int f;
			scanf("%d",&f);
			if(f==1)
			{
				char dep[50];
				char date[50];
				char arrive[50];
				char c;
				int s,a,v,ID,i,n=1000,price;
	
				printf("Flying from...\n");
				scanf("%s",dep);
				printf("Flying to...\n");
				scanf("%s",arrive);
				printf("Departure Date\n");
				scanf("%s",date);
				printf("How many tickets do you want\n");
				scanf("%d",&s);
				price = 75000 * s;
				
				ID=ticket_verification(s);
				if(ID==3)
				{
					for(i=1;i<=s;i++)
					{
						n=n+i;
					}
					a=n-s;
					
				}
				FILE *nfp;
				nfp=fopen("Data.txt","a");
				fprintf(nfp,"=============================\n");
				fprintf(nfp,"International Flight \n");
				fprintf(nfp,"Flying from %s\n",dep);
				fprintf(nfp,"Flying to %s\n",arrive);
				fprintf(nfp,"Departure date is %s\n",date);
				fprintf(nfp,"Your price is %d\n",price);
				if(s>1)
				{
					fprintf(nfp,"Your ticket ID's are %d till %d \n",a,n);
				}else{
					fprintf(nfp,"Your ticket ID is %d",n);
				}
				fprintf(nfp,"\n=============================\n\n");
				fclose(nfp);
				printf("\n Do you want to view your booking information?\n");
				printf("Type (1) for yes or (0) for a no");
				scanf("%d",&v);
				if(v==1)
				{
					nfp=fopen("Data.txt","r");
					
					while ((c = fgetc(nfp)) != EOF)
						printf("%c", c);
					
				fclose(nfp);
				}
				
			}else if(f==2)
			{
				char dep[50];
				char date[50];
				char arrive[50];
				char c;
				int s,a,v,ID,i,n=1000,price;
	
				printf("Flying from...\n");
				scanf("%s",dep);
				printf("Flying to...\n");
				scanf("%s",arrive);
				printf("Departure Date\n");
				scanf("%s",date);
				printf("How many tickets do you want\n");
				scanf("%d",&s);
				price = 15000 * s;
				
				ID=ticket_verification(s);
				if(ID==3)
				{
					for(i=1;i<=s;i++)
					{
						n=n+i;
					}
					a=n-s;
					
				}else if(ID==1)
				{
					printf("Error,Seat could not be booked");
					return 1;
				}
				FILE *nfp;
				nfp=fopen("Data.txt","w");
				fprintf(nfp,"=============================\n");
				fprintf(nfp,"Domestic Flight \n");
				fprintf(nfp,"Flying from %s\n",dep);
				fprintf(nfp,"Flying to %s\n",arrive);
				fprintf(nfp,"Departure date is %s\n",date);
				fprintf(nfp,"Your price is %d\n",price);
				if(s>1)
				{
					fprintf(nfp,"Your ticket ID's are %d till %d \n",a,n);
				}else{
					fprintf(nfp,"Your ticket ID is %d",n);
				}
				fprintf(nfp,"\n=============================\n\n");
				fclose(nfp);
				printf("\n Do you want to view your booking information?\n");
				printf("Type (1) for yes or (0) for a no");
				scanf("%d",&v);
				if(v==1)
				{
					nfp=fopen("Data.txt","r");
					
					while ((c = fgetc(nfp)) != EOF)
						printf("%c", c);
					
				fclose(nfp);
				}
			}
		break;
		case 2:
			//Bus services===============================================================================================================================================================
			printf("\t\t\t\t\t[1]=> View Bus List\n");
		    printf("\n");
		    printf("\t\t\t\t\t[2]=> Book Tickets\n");
		    printf("\n");
		    printf("\t\t\t\t\t[3]=> Exit\n");
		    printf("\n");
		    printf("===============================================================================================================\n\n");
		    printf("\t\t\tEnter Your Choice:: ");
		    scanf("%d",&num);
		    switch(num)
		    {
		    case 1:
		        bus();//for list of bus
		        break;
		    case 2:
		        booking();//for booking the tickets
		        break;
		    }
				break;
		case 3:
			//Hotel booking=============================================================================================================================================================
			
	
				printf("\t\t\t\t\t\t   ------------------------------");
				printf("\t\t\t\t\t\t*  WELCOME TO HOTEL MANAGEMENT!!!  *\n");
				printf("\t\t\t\t\t\t   ------------------------------");
				
				printf("\nHELLO User And Welcome To Hotel!!");
				
				printf("\n>>>\tTo view hotel names list -> enter 1\t\n\n<<<");
			
				printf("\n>>>\tTo request booking of room -> enter 2\t\n\n<<<");
				printf("\n");
	
				scanf("%d", &number);
				
				switch(number){
					case 1:
						
						name();
						
					case 2:
							
						bookings();
						break;
				
				
				}
		break;
		case 4:
			//Deals=====================================================================================================================================================================
			printf("\t\t\t\t\t\t<Deals>\n");
	
			printf("Deal 1 : Buy 1 hotel room and 2 flight tickets and get 10 percent off\n");
			printf("Deal 2 : Buy 5 flight tickets and get 25 percent off\n");
			printf("Deal 3 : Buy 7 flight tickets and get 2 flight tickets free");
			printf("\n");
			scanf("%d",&deals);
			
			if(deals==1)
			{
				printf("\t\t\tWelcome to Flight Booking!\t\t\n\n");
			printf("1.International Flights!(75,000 PKR)\n2.Domestic Flights(15,000PKR)\n");
			int f;
			scanf("%d",&f);
			if(f==1)
			{
				char dep[50];
				char date[50];
				char arrive[50];
				char c;
				int s,a,v,ID,i,n=1000,price;
	
				printf("Flying from...\n");
				scanf("%s",dep);
				printf("Flying to...\n");
				scanf("%s",arrive);
				printf("Departure Date\n");
				scanf("%s",date);
				price = 75000 * 0.9 * 2;
				
				ID=ticket_verification(2);
				if(ID==3)
				{
					for(i=1;i<=s;i++)
					{
						n=n+i;
					}
					a=n-s;
					
				}else if(ID==1)
				{
					printf("Seat is already booked");
				}
				printf("\t\t\t\t\t\t   ------------------------------");
				printf("\t\t\t\t\t\t*  WELCOME TO HOTEL MANAGEMENT!!!  *\n");
				printf("\t\t\t\t\t\t   ------------------------------");
				
				printf("\nHELLO User And Welcome To Hotel!!");
				
				printf("\n>>>\tTo view hotel names list -> enter 1\t\n\n<<<");
			
				printf("\n>>>\tTo request booking of room -> enter 2\t\n\n<<<");
				printf("\n");
	
				scanf("%d", &number);
				
				switch(number){
					case 1:
						
						name();
						
					case 2:
							
						bookings();
						break;
				
				
				}
				FILE *nfp;
				nfp=fopen("Data.txt","a");
				fprintf(nfp,"=============================\n");
				fprintf(nfp,"International Flight \n");
				fprintf(nfp,"Flying from %s\n",dep);
				fprintf(nfp,"Flying to %s\n",arrive);
				fprintf(nfp,"Departure date is %s\n",date);
				fprintf(nfp,"Your price is %d\n",price);
				if(s>1)
				{
					fprintf(nfp,"Your ticket ID's are %d till %d \n",a,n);
				}else{
					fprintf(nfp,"Your ticket ID is %d",n);
				}
				fprintf(nfp,"\n=============================\n\n");
				fclose(nfp);
				printf("\n Do you want to view your booking information?\n");
				printf("Type (1) for yes or (0) for a no");
				scanf("%d",&v);
				if(v==1)
				{
					nfp=fopen("Data.txt","r");
					
					while ((c = fgetc(nfp)) != EOF)
						printf("%c", c);
					
				fclose(nfp);
				}
				
			}else if(f==2)
			{
				char dep[50];
				char date[50];
				char arrive[50];
				char c;
				int s,a,v,ID,i,n=1000,price;
	
				printf("Flying from...\n");
				scanf("%s",dep);
				printf("Flying to...\n");
				scanf("%s",arrive);
				printf("Departure Date\n");
				scanf("%s",date);
				price = 15000 *0.9 * 2;
				
				ID=ticket_verification(2);
				if(ID==3)
				{
					for(i=1;i<=s;i++)
					{
						n=n+i;
					}
					a=n-s;
					
				}else if(ID==1)
				{
					printf("Error,Seat could not be booked");
					return 1;
				}
				printf("\t\t\t\t\t\t   ------------------------------");
				printf("\t\t\t\t\t\t*  WELCOME TO HOTEL MANAGEMENT!!!  *\n");
				printf("\t\t\t\t\t\t   ------------------------------");
				
				printf("\nHELLO User And Welcome To Hotel!!");
				
				printf("\n>>>\tTo view hotel names list -> enter 1\t\n\n<<<");
			
				printf("\n>>>\tTo request booking of room -> enter 2\t\n\n<<<");
				printf("\n");
	
				scanf("%d", &number);
				
				switch(number){
					case 1:
						
						name();
						
					case 2:
							
						bookings();
						break;
				
				
				}
				FILE *nfp;
				nfp=fopen("Data.txt","w");
				fprintf(nfp,"=============================\n");
				fprintf(nfp,"Domestic Flight \n");
				fprintf(nfp,"Flying from %s\n",dep);
				fprintf(nfp,"Flying to %s\n",arrive);
				fprintf(nfp,"Departure date is %s\n",date);
				fprintf(nfp,"Your price is %d\n",price);
				if(s>1)
				{
					fprintf(nfp,"Your ticket ID's are %d till %d \n",a,n);
				}else{
					fprintf(nfp,"Your ticket ID is %d",n);
				}
				fprintf(nfp,"\n=============================\n\n");
				fclose(nfp);
				printf("\n Do you want to view your booking information?\n");
				printf("Type (1) for yes or (0) for a no");
				scanf("%d",&v);
				if(v==1)
				{
					nfp=fopen("Data.txt","r");
					
					while ((c = fgetc(nfp)) != EOF)
						printf("%c", c);
					
				fclose(nfp);
				}
			}
			}else if (deals==2)
			{
				printf("\t\t\tWelcome to Flight Booking!\t\t\n\n");
			printf("1.International Flights!(75,000 PKR)\n2.Domestic Flights(15,000PKR)\n");
			int f;
			scanf("%d",&f);
			if(f==1)
			{
				char dep[50];
				char date[50];
				char arrive[50];
				char c;
				int s,a,v,ID,i,n=1000,price;
	
				printf("Flying from...\n");
				scanf("%s",dep);
				printf("Flying to...\n");
				scanf("%s",arrive);
				printf("Departure Date\n");
				scanf("%s",date);
				price = 75000 * 0.75 * 5;
				ID=ticket_verification(5);
				if(ID==3)
				{
					for(i=1;i<=s;i++)
					{
						n=n+i;
					}
					a=n-s;
					
				}
				FILE *nfp;
				nfp=fopen("Data.txt","a");
				fprintf(nfp,"=============================\n");
				fprintf(nfp,"International Flight \n");
				fprintf(nfp,"Flying from %s\n",dep);
				fprintf(nfp,"Flying to %s\n",arrive);
				fprintf(nfp,"Departure date is %s\n",date);
				fprintf(nfp,"Your price is %d\n",price);
				if(s>1)
				{
					fprintf(nfp,"Your ticket ID's are %d till %d \n",a,n);
				}else{
					fprintf(nfp,"Your ticket ID is %d",n);
				}
				fprintf(nfp,"\n=============================\n\n");
				fclose(nfp);
				printf("\n Do you want to view your booking information?\n");
				printf("Type (1) for yes or (0) for a no");
				scanf("%d",&v);
				if(v==1)
				{
					nfp=fopen("Data.txt","r");
					
					while ((c = fgetc(nfp)) != EOF)
						printf("%c", c);
					
				fclose(nfp);
				}
				
			}else if(f==2)
			{
				char dep[50];
				char date[50];
				char arrive[50];
				char c;
				int s,a,v,ID,i,n=1000,price;
	
				printf("Flying from...\n");
				scanf("%s",dep);
				printf("Flying to...\n");
				scanf("%s",arrive);
				printf("Departure Date\n");
				scanf("%s",date);
				price = 15000 * 0.75 * 5;
				ID=ticket_verification(5);
				if(ID==3)
				{
					for(i=1;i<=s;i++)
					{
						n=n+i;
					}
					a=n-s;
					
				}else if(ID==1)
				{
					printf("Error,Seat could not be booked");
					return 1;
				}
				FILE *nfp;
				nfp=fopen("Data.txt","w");
				fprintf(nfp,"=============================\n");
				fprintf(nfp,"Domestic Flight \n");
				fprintf(nfp,"Flying from %s\n",dep);
				fprintf(nfp,"Flying to %s\n",arrive);
				fprintf(nfp,"Departure date is %s\n",date);
				fprintf(nfp,"Your price is %d\n",price);
				if(s>1)
				{
					fprintf(nfp,"Your ticket ID's are %d till %d \n",a,n);
				}else{
					fprintf(nfp,"Your ticket ID is %d",n);
				}
				fprintf(nfp,"\n=============================\n\n");
				fclose(nfp);
				printf("\n Do you want to view your booking information?\n");
				printf("Type (1) for yes or (0) for a no");
				scanf("%d",&v);
				if(v==1)
				{
					nfp=fopen("Data.txt","r");
					
					while ((c = fgetc(nfp)) != EOF)
						printf("%c", c);
					
				fclose(nfp);
				}
			}
			}else if(deals==3)
			{
				printf("\t\t\tWelcome to Flight Booking!\t\t\n\n");
			printf("1.International Flights!(75,000 PKR)\n2.Domestic Flights(15,000PKR)\n");
			int f;
			scanf("%d",&f);
			if(f==1)
			{
				char dep[50];
				char date[50];
				char arrive[50];
				char c;
				int s,a,v,ID,i,n=1000,price;
	
				printf("Flying from...\n");
				scanf("%s",dep);
				printf("Flying to...\n");
				scanf("%s",arrive);
				printf("Departure Date\n");
				scanf("%s",date);
				price = 75000 * 7;
				
				ID=ticket_verification(9);
				if(ID==3)
				{
					for(i=1;i<=s;i++)
					{
						n=n+i;
					}
					a=n-s;
					
				}
				FILE *nfp;
				nfp=fopen("Data.txt","a");
				fprintf(nfp,"=============================\n");
				fprintf(nfp,"International Flight \n");
				fprintf(nfp,"Flying from %s\n",dep);
				fprintf(nfp,"Flying to %s\n",arrive);
				fprintf(nfp,"Departure date is %s\n",date);
				fprintf(nfp,"Your price is %d\n",price);
				if(s>1)
				{
					fprintf(nfp,"Your ticket ID's are %d till %d \n",a,n);
				}else{
					fprintf(nfp,"Your ticket ID is %d",n);
				}
				fprintf(nfp,"\n=============================\n\n");
				fclose(nfp);
				printf("\n Do you want to view your booking information?\n");
				printf("Type (1) for yes or (0) for a no");
				scanf("%d",&v);
				if(v==1)
				{
					nfp=fopen("Data.txt","r");
					
					while ((c = fgetc(nfp)) != EOF)
						printf("%c", c);
					
				fclose(nfp);
				}
				
			}else if(f==2)
			{
				char dep[50];
				char date[50];
				char arrive[50];
				char c;
				int s,a,v,ID,i,n=1000,price;
	
				printf("Flying from...\n");
				scanf("%s",dep);
				printf("Flying to...\n");
				scanf("%s",arrive);
				printf("Departure Date\n");
				scanf("%s",date);
				price = 15000 * 7;
				
				ID=ticket_verification(9);
				if(ID==3)
				{
					for(i=1;i<=s;i++)
					{
						n=n+i;
					}
					a=n-s;
					
				}else if(ID==1)
				{
					printf("Error,Seat could not be booked");
					return 1;
				}
				FILE *nfp;
				nfp=fopen("Data.txt","w");
				fprintf(nfp,"=============================\n");
				fprintf(nfp,"Domestic Flight \n");
				fprintf(nfp,"Flying from %s\n",dep);
				fprintf(nfp,"Flying to %s\n",arrive);
				fprintf(nfp,"Departure date is %s\n",date);
				fprintf(nfp,"Your price is %d\n",price);
				if(s>1)
				{
					fprintf(nfp,"Your ticket ID's are %d till %d \n",a,n);
				}else{
					fprintf(nfp,"Your ticket ID is %d",n);
				}
				fprintf(nfp,"\n=============================\n\n");
				fclose(nfp);
				printf("\n Do you want to view your booking information?\n");
				printf("Type (1) for yes or (0) for a no");
				scanf("%d",&v);
				if(v==1)
				{
					nfp=fopen("Data.txt","r");
					
					while ((c = fgetc(nfp)) != EOF)
						printf("%c", c);
					
				fclose(nfp);
				}
			}
			}
		break;
		case 5:
			//Services'
			
			printf("solve problem? press 1 or add problem press 2  ");
			scanf("%d",&a1);
			if(a1==1)
			{
				delete1();
			}
			else if(a1==2)
			{
				funct();
			}
			
    		
		break;					
	}
	
	
	
	
}

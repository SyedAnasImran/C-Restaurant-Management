#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

struct time{
		
		char table[6][6];
		
}time[11];
	
void home(int end);	
void menu(int booked);
float billing();
void booking();


int main(){
	
	//Creating Seatong Layout
	
	int i,j,k;
	char cont,a='A';
	
			for(i=0;i<11;i++){
				
				for(j=0;j<6;j++){
					
					for(k=0;k<6;k++){
						
						time[i].table[j][k]=a;		
					}	
				}
			}
	
	home(0);

	
	
}

void home(int end){

int i,j,t,cont;
char choice;
home:
	
	if(end==1) goto end;
	do{
	
		//HOME SCREEN

		system("cls");
	 	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t");
		for(i=0;i<41;i++)printf("=");
		printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tTHE FOOD CLUB RESTAURANT\t\t\n\t\t\t\t\t\t\t\t\t\t\t\t");
		for(i=0;i<41;i++)printf("=");
		
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tBOOK YOUR PLACE NOW (1)\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    VIEW MENU (2)\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t      EXIT(3)\n\n");
		scanf(" %c",&choice);
		
		switch(choice){
		
			case '1':	
				booking();
				break;
			
			case '2':	
				menu(0);
				break;
			
			case '3':
				system("cls");
				printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tExited Successfully");
				sleep(1);
				goto end;
				break;
				
			default:
				printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tInvalid Input, Try again");
				sleep(1);	
				break;
		}	
		
	}while(choice!=3);

end:
end=0;	
printf("\n\n\n\t\t\t\t\t\t\t\t\t\tEnter any key to continue: ");
scanf(" %c",&cont);
goto home;




}


void booking(){
	
			int i,j,k;
			char t1[10];
			int t;
			
	
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  THE");
			sleep(1);
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t SEATING");
			sleep(1);
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  PLANS");
			sleep(1);
			system("cls");
			
			for(i=0;i<11;i++){
				
				printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tFor %d:00 PM\n\n",i+1);
				
				for(j=0;j<6;j++){
					
					printf("\n\n\t\t\t\t\t\t\t\t\t\t ");	
					for(k=0;k<6;k++){
						
						printf("\t%c",time[i].table[j][k]);
					}
					
				}
				usleep(99999);
			} 		
			
			
			//CHECKING AVAILABILITY					
			//Flag2 for all day
			//Flag1 for given time
				
			
			int flag1=0,flag2=0;	
			
			for(k=0;k<11;k++){									//Checking for all day
			
				for(i=0;i<6;i++){
					
					for(j=0;j<6;j++){
							
						if(time[k].table[i][j]=='A'){   
						flag2=1;
						goto flag2break;
						}
					}
				}
			}
			flag2break:			//GOTO LABEL
		if(flag2==1){
				
			choosetime: 	//CHOSE TIME LABEL (FOR GOTO STATMENT)
			
			printf("\n\n\n\t\t\t\t\tEnter your time of arrival: ");
			scanf(" %s",&t1);
			t=atoi(t1);
			if(t<1||t>11){
				printf("\n\n\n\t\t\t\t\t\t\t\t\tPlease Select from given slots");
				goto choosetime;
			}
			
			system("cls");
			printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tFor %d:00 PM\n\n",t);
			for(i=0;i<6;i++){
			
					printf("\n\n\t\t\t\t\t\t\t\tRow %d)\t\t ",i+1);
					for(j=0;j<6;j++){
						
						printf("\t%d(%c)",j+1,time[t-1].table[i][j]);
					}
				}
			

			

														
		 										//Checking for provided time
			for(i=0;i<6;i++){
				
				for(j=0;j<6;j++){
						
					if(time[t-1].table[i][j]=='A'){
						flag1=1;    
						goto flag1break;
					}
				}
			}
			flag1break: 		//GOTO LABEL
			
			if(flag1==1){
				
				int r,c;
				char row[2],col[2],s;
					
					//CHOOSING THE TABLE
					choosetable:
					
					printf("\n\n\n\n\nEnter the row number you wish to dine in:\n");
					scanf(" %s",&row);
					printf("\nEnter the table number of Row: \n");
					scanf(" %s",&col);
					r=atoi(row);
					c=atoi(col);
					if(r<1||c<1||r>6||c>6){
						printf("\n\n\n\n\n\t\t\t\t\t\t\t\tInvalid Input, Choose from following layout");
						goto choosetable;
					}
					printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\tAre you sure you want to book this table ( Y/y | N/n ): ");
					scanf(" %c",&s);
					
					if(s=='Y'||s=='y'){
						
					
						if(time[t-1].table[r-1][c-1]=='A'){
							time[t-1].table[r-1][c-1]='B';
							
							menu(1);
							printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tTotal: %.2f",billing());
							usleep(99999);
							
							printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tBOOKED FOR %dPM\n",t);
							for(i=0;i<6;i++){
								
								printf("\n\n\t\t\t\t\t\t\t\t\t\t    ");
								for(j=0;j<6;j++){
									
									printf("\t%c",time[t-1].table[i][j]);
								}
							}
					
							home(1);
					
						
						}	
						else{
							printf("\n\nCHOOSE ANOTHER TABLE:");
							goto flag1break;
						}
					}
					else if(s=='n'||s=='N'){
						system("cls");
						printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tFor %d:00 PM\n\n",t);
						for(i=0;i<6;i++){
				
							printf("\n\n\t\t\t\t\t\t\t\tRow %d)\t\t ",i+1);
							for(j=0;j<6;j++){
							
							printf("\t%d(%c)",j+1,time[t-1].table[i][j]);
							}
						}
						sleep(1);
						goto choosetable;
					}
					else{
						printf("\n\n\t\t\t\t\t\t\t\t\t\tInvalid Input");
						goto choosetable;
					}
			}
			else{
				printf("ALL BOOKED CHOOSE ANOTHER TIME");
				goto choosetime;
			}
		}
		else 
		printf("\n\nALL BOOKED COME BACK LATER :)");
		sleep(2);
			
}



void menu(int booked){
	
	system("cls");
	char cont;
	printf("\n==============================================================================");
	
	printf("\n\n* APETIZERS:\n");
	printf("\n\t1) Chicken Strips\t\t280/-");
	printf("\n\t2) Peri Peri Bites\t\t280/-");
	printf("\n\t3) Buffalo Wings\t\t270/-");
	printf("\n\t4) Loaded Fries \t\t250/-");
	printf("\n\n*) STEAK:");
	printf("\n\t5) Chicken Taragon\t\t1100/-");
	printf("\n\t6) Grilled Beef\t\t\t850/-");
	printf("\n\t7) Smoked Chicken\t\t800/-");
	printf("\n\t8) Lamb Shank \t\t\t800/-");
	printf("\n\n*) ITALIAN:\n");
	printf("\n\t9  Bruschetta\t\t\t300/-");
	printf("\n\t10 Pasta Carbonara\t\t350/-");
	printf("\n\t11 Mushroom Risotto\t\t320/-");
	printf("\n\t12 Alfredo\t\t\t250");
	printf("\n\n*) BAR B.Q:\n");
	printf("\n\t13) Chicken Tikka\t\t190/-");
	printf("\n\t14) Malai Tikka\t\t\t260/-");
	printf("\n\t15) Bihari Tikka\t\t300/-");
	printf("\n\t16) Reshmi Kabab\t\t420/-");
	printf("\n\t17) Beef Roll\t\t\t120/-");
	printf("\n\t18) Beef Cheese Roll\t\t140/-");
	printf("\n\t19) Chicken Roll\t\t120/-");
	printf("\n\t20) Chicken Zinger Roll\t\t180/-");
	printf("\n\t21) Chicken Cheese Roll\t\t140/-");
	printf("\n\n*) BURGERS:\n");
	printf("\n\t22) Classic Beef\t\t350/-");
	printf("\n\t23) Krunch Delight\t\t550/-");
	printf("\n\t24) Double Krunch\t\t740/-");
	printf("\n\t25) Texas Burger\t\t500/-");
	printf("\n\n*) BEVERAGES:\n");
	printf("\n\t26) Mint Margarita\t\t180");
	printf("\n\t27) Blueberry Fuzz\t\t180");
	printf("\n\t28) Chocolate Latte\t\t240");
contorhome:
	printf("\n\n\n\t**Enter 1 to continue 0 for home: ");
	scanf(" %c",&cont);
	if(cont=='0'||cont=='1'){

		switch(booked){
			case 1:
				
				if(cont=='0'){
					home(0);
					break;
				}
				break;
			case 0:
				
				if(cont=='1'){
					booking();
					break;
				}
				else if(cont=='0'){
					home(0);
					break;
				}	
				break;
		}
	}
	else{
			printf("\n\n\t\t\t\t\t\t\tInvalid Input");
			sleep(1);
			goto contorhome;
	}
		
	}
	
float billing(){
	
int i,n,q[99];
char number[2];
float sum=0; 
	
	nofitems:            //GOTO LABEL
	 printf("\nEnter Number of items: ");
		scanf(" %s",&number);
		n=atoi(number);
		if(n<1) {
			
			printf("\t\t\t\t\t\tInvalid Input");
			goto nofitems;
		}
		int item[n];
		char itemchar[2],name[n][50];
		printf("\n\nPlease Enter the S.No of the item from the menu:\n");
		
		//Choosing items
		for(i=0;i<n;i++){
		
			printf("\nEnter item number %d : ",i+1);
			scanf(" %s",&itemchar);
			item[i]=atoi(itemchar);
				
			if(item[i]>28||item[i]<1){
				printf("Invalid Input");
				i--;
				continue;
			}
				
			printf("Enter quantity:",item[i]);
			scanf("%d",&q[i]);
		}
		
	
		system("cls");
		printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tItems \t\t\t\tPrice\tQuantity\n");
		//billing them
		for(i=0;i<n;i++){
		
			switch(item[i]){

				case 1:sum=sum+q[i]*280;
					strcpy(name[i],"Chicken Strip");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t\t%d\t%d",name[i],280,q[i]);break;
				case 2:sum=sum+q[i]*280;
					strcpy(name[i],"Peri Peri Bites");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t%d\t%d",name[i],280,q[i]);break;
				case 3:sum=sum+q[i]*270; 
					strcpy(name[i],"Buffalo Wings");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t\t%d\t%d",name[i],270,q[i]);break;
				case 4:sum=sum+q[i]*250;
					strcpy(name[i],"Loaded Fries");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t\t%d\t%d",name[i],250,q[i]);break;
				case 5:sum=sum+q[i]*1100;
					strcpy(name[i],"Chicken Taragon");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t%d\t%d",name[i],1100,q[i]);break;
				case 6:sum=sum+q[i]*850;
					strcpy(name[i],"Grilled Beef");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t\t%d\t%d",name[i],850,q[i]);break;
				case 7:sum=sum+q[i]*800;
					strcpy(name[i],"Smoke Chicken");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t\t%d\t%d",name[i],800,q[i]);break;
				case 8:sum=sum+q[i]*800;
					strcpy(name[i],"Lamb Shank");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t\t%d\t%d",name[i],800,q[i]);break;
				case 9:sum=sum+q[i]*300;
					strcpy(name[i],"Bruschetta");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t\t%d\t%d",name[i],300,q[i]);break;
				case 10:sum=sum+q[i]*350;
					strcpy(name[i],"Pasta Carbonara");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t%d\t%d",name[i],350,q[i]);break;
				case 11:sum=sum+q[i]*320;
					strcpy(name[i],"Mushroom Risotto");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t%d\t%d",name[i],320,q[i]);break;
				case 12:sum=sum+q[i]*250;
					strcpy(name[i],"Alfredo");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t\t%d\t%d",name[i],250,q[i]);break;
				case 13:sum=sum+q[i]*190;
					strcpy(name[i],"Chicken Tikka");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t\t%d\t%d",name[i],190,q[i]);break;
				case 14:sum=sum+q[i]*260;
					strcpy(name[i],"Malai Tikka");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t\t%d\t%d",name[i],260,q[i]);break;
				case 15:sum=sum+q[i]*300;
					strcpy(name[i],"Bihari Tikka");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t\t%d\t%d",name[i],300,q[i]);break;
				case 16:sum=sum+q[i]*420;
					strcpy(name[i],"Reshmi Kabab");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t\t%d\t%d",name[i],420,q[i]);break;
				case 17:sum=sum+q[i]*120;
					strcpy(name[i],"Beef Roll");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t\t%d\t%d",name[i],120,q[i]);break;
				case 18:sum=sum+q[i]*140;
					strcpy(name[i],"Beef Cheese Roll");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t%d\t%d",name[i],140,q[i]);break;
				case 19:sum=sum+q[i]*120;
					strcpy(name[i],"Chicken Roll");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t\t%d\t%d",name[i],120,q[i]);break;
				case 20:sum=sum+q[i]*180;
					strcpy(name[i],"Chicken Zinger Roll");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t%d\t%d",name[i],180,q[i]);break;
				case 21:sum=sum+q[i]*140;
					strcpy(name[i],"Chicken Cheese Roll");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t\t%d\t%d",name[i],140,q[i]);break;
				case 22:sum=sum+q[i]*350;
					strcpy(name[i],"Classic Beef");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t\t%d\t%d",name[i],350,q[i]);break;
				case 23:sum=sum+q[i]*550;
					strcpy(name[i],"Krunch Delight");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t\t%d\t%d",name[i],550,q[i]);break;
				case 24:sum=sum+q[i]*740;
					strcpy(name[i],"Double Krunch");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t\t%d\t%d",name[i],740,q[i]);break;
				case 25:sum=sum+q[i]*500;
					strcpy(name[i],"Texas Burger");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t\t%d\t%d",name[i],500,q[i]);break;
				case 26:sum=sum+q[i]*180;
					strcpy(name[i],"Mint Margarita");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t\t%d\t%d",name[i],180,q[i]);break;
				case 27:sum=sum+q[i]*180;
					strcpy(name[i],"Blueberry Fuzz");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t\t%d\t%d",name[i],180,q[i]);break;
				case 28:sum=sum+q[i]*240;
					strcpy(name[i],"Chocolate Latte");
					printf("\n\t\t\t\t\t\t\t\t\t\t\t %s\t\t%d\t%d",name[i],240,q[i]);break;
			
							
			}
		}

	
	return sum;
}	
	
	








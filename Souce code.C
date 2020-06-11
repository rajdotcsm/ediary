#define check puts("HERE"); getch(); exit(0);

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#define C_LEFT   printf("\x1B[D");
#define C_RIGHT  printf("\x1B[C");
#define C_UP     printf("\x1B[A");

#define C_DOWN   printf("\x1B[B");
#define L_UP	 printf("\xC9");
#define R_UP	 printf("\xBB");
#define L_DOWN	 printf("\xC8");
#define R_DOWN   printf("\xBC");
#define A_LEFT    75
#define A_RIGHT   77
#define A_UP      72
#define A_DOWN    80

#define verticalLine 	    printf("\xCD");
#define parallelLine        printf("\xBA");
#define verticalLine 	    printf("\xCD");
#define parallelLine        printf("\xBA");

#define E printf("\xCA");
#define R printf("\xCB");
#define S printf("\xCD");
#define A printf("\xBA");
#define Q printf("\xC9");
#define Z printf("\xC8");
#define W printf("\xBB");
#define X printf("\xBC");
#define F printf("\xB9");
#define D printf("\xCC");
#define SEL printf("\x2");
#define UNS printf(" ");
//sel for select and uns select


void Move(int, int);
void login(int);
void frames(int);
int selectmode();
void W_MODE();
void S_MODE();
void R_MODE();
void personlize(int);
void exitFun();

struct per{
	int text;
	int back;
};

struct dParts{
	char *date;
	char paragraph[1000];
};



int forLogin=0;

void main()
{

personlize(1);

if(forLogin==0) 	{login(1); forLogin++;}
Flag1:  // for manual exit
switch(selectmode())

{
	case 0: W_MODE(); break;
	case 1: R_MODE(); break;
	case 2: S_MODE(); break;
	case 3: clrscr(); exitFun();  getch(); delay(500); exit(0);

}
goto Flag1;

}


void exitFun(){
frames(1);
Move(35,5);
printf("\x1B[7m  ABOUT  \x1B[0m");
window(10,8,70,20);
cprintf("              EDiary i.e. Electronic Diary\n\rThis is a password protected user-personal electronic diary.\n");
cprintf("   This is second project, Developed by RACUBEM Group from \n\n\r            IMCS BSCS PM/2K18, University Of Sindh ");
cprintf("\n\n\r                  Thanks For Using EDiary %c",2);
cprintf("\n\n\r               Web   : rajdotcsm84.wordpress.com");
cprintf("\n\n\r                 Email : rajdotcsm84@gmail.com ");

}

void personlize(int x)
{
	struct per var;
	switch(x)
	{
		case 1:
		{
			FILE *t=fopen("text.txt","r");
			FILE *b=fopen("back.txt","r");
			fscanf(t,"%d",&var.text);
			fscanf(b,"%d",&var.back);
			textcolor(var.text);
			textbackground(var.back);

			fflush(stdin);
			fclose(t);
			fclose(b);

		}
		break;

		case 2:
		{
			FILE *t=fopen("text.txt","w");
			FILE *b=fopen("back.txt","w");
			int choice=0, key;
			clrscr();
			frames(1);
			Move(28,7);
			puts("\x1B[7m    PERSONILIZE    \x1B[0m");
			Move(20,10);
			cprintf("FONT-COLOR : YELLOW  WITH  FONT-BACKGROUNG : BLACK");
			Move(20,12);
			cprintf("FONT-COLOR : WHITE   WITH  FONT-BACKGROUNG : BLACK");
			Move(20,14);
			cprintf("FONT-COLOR : BROWN   WITH  FONT-BACKGROUNG : LIGHTGRAY");
			Move(20,16);
			cprintf("FONT-COLOR : CYAN    WITH  FONT-BACKGROUNG : YELLOW");
			Move(20,18);
			cprintf("FONT-COLOR : YELLOW  WITH  FONT-BACKGROUNG : MAGENTA");
			Move(18,10);
			SEL;
			while(1){
			EXTRA:
			key=getch();
			if(key==13){break;}
			 switch(key){
			 case A_UP:
			 {
			  if(choice==0) {choice=4; Move(18,10); UNS; Move(18,18); SEL; }
			  else if (choice==1) {choice--; Move(18,12); UNS; Move(18,10); SEL; }
			  else if (choice==2) {choice--; Move(18,14); UNS; Move(18,12); SEL; }
			  else if (choice==3) {choice--; Move(18,16); UNS; Move(18,14); SEL; }
			  else if (choice==4) {choice--; Move(18,18); UNS; Move(18,16); SEL; }

			 }
			 break;
			 case A_DOWN:
			 {
			  if(choice==0) {choice++; Move(18,10); UNS; Move(18,12); SEL; }
			  else if (choice==1) {choice++; Move(18,12); UNS; Move(18,14); SEL; }
			  else if (choice==2) {choice++; Move(18,14); UNS; Move(18,16); SEL; }
			  else if (choice==3) {choice++; Move(18,16); UNS; Move(18,18); SEL; }
			  else if (choice==4) {choice=0; Move(18,18); UNS; Move(18,10); SEL; }
			 }
			 break;
			 default:
			 goto EXTRA;
			 }


			}//while
			 switch(choice)
			 {
			case 0:{
				var.text=14;
				var.back=0;
				textcolor(var.text);
				textbackground(var.back);
				fprintf(t,"%d",var.text);
				fprintf(b,"%d",var.back);

				}
			break;
				case 1:{
				var.text=15;
				var.back=0;
				textcolor(var.text);
				textbackground(var.back);
				fprintf(t,"%d",var.text);
				fprintf(b,"%d",var.back);

				}
			break;
				case 2:{
				var.text=6;
				var.back=7;
				textcolor(var.text);
				textbackground(var.back);
				fprintf(t,"%d",var.text);
				fprintf(b,"%d",var.back);
				}
			break;
				case 3:{
				var.text=11;
				var.back=14;
				textcolor(var.text);
				textbackground(var.back);
				fprintf(t,"%d",var.text);
				fprintf(b,"%d",var.back);
				}
			break;
				case 4:{
				var.text=14;
				var.back=13;
				textcolor(var.text);
				textbackground(var.back);
				fprintf(t,"%d",var.text);
				fprintf(b,"%d",var.back);
				}
			break;
			 }

			fclose(t);
			fclose(b);

		}

		break;


	}

fflush(stdin);

}



void Move(int x, int y)
{
	gotoxy(x,y);
}

void login(int type)
{
    static int chance = 3;
    clrscr();
	frames(1);
	switch(type)
	{
		case 1: CHANCE:   //label for re-try
		{
			char ruid[25],rpass[25];  //input the saved
			FILE *ptUser=fopen("username.dat","r");
			FILE *ptPass=fopen("password.dat","r");
			int mUser, mPass, i=0;// chance = 3;
			char ch;
			static char uId[25], uPass[25];  //input from user
			strcpy(ruid,"");
			strcpy(rpass,"");

			fscanf(ptUser,"%s",ruid);
			fscanf(ptPass,"%s",rpass);
			frames(1);
			Move(15,6);
			printf("\x1B[7m  ENTER USERNAME AND PASSWORD TO ACCESS THE EDIARY  \x1B[0m ");
			Move(7,6+4);
			for(i=0;i<68;i++)
			verticalLine
			Move(7,19+4);
			for(i=0;i<68;i++)
			verticalLine
			for(i=0;i<12;i++){
			Move(6,7+i+4);
			parallelLine
			}
			for(i=0;i<12;i++){
			Move(75,7+i+4);
			parallelLine
			}
			Move(6,10);  printf("\xC9");
			Move(75,10);  printf("\xBB");
			Move(6,23);  printf("\xC8");
			Move(75,23);  printf("\xBC");

			i=0;  //set back
			gotoxy(15,13);
			cprintf("Enter Username : ");
			gotoxy(15,15);
			cprintf("Enter Password : ");

			gotoxy(32,13);
			strcpy(uId,"");
			gets(uId);
			gotoxy(32,15);

			while(1){
			passRepeat:
			ch=getch();
			if(ch==8){
			printf("\b \b");
			i--;
			goto passRepeat;
			}
			if(ch==13){
			break;
			}
			uPass[i]=ch;
			cprintf("*");
			i++;
			}
			uPass[i]='\0';

			fflush(stdin);   //move
			fclose(ptUser);
			fclose(ptPass);

			Move(32,17);
			{
			int i=0;
			char array[]="   CONFIRMING   ";
			for(i=0;i<strlen(array);i++)
			 {
			 printf("\x1B[7m%c\x1B[0m",array[i]);
			 delay(50);
			 }
			}



			mUser=strcmp(uId,ruid);
			mPass=strcmp(uPass,rpass);
			if((mUser==0)&&(mPass==0)){
				Move(35,20);
				printf("\x1B[7m Vefified \x1B[0m");
				getch();
			}
			else{
			if((mUser==0)||(mPass==0)){
				Move(26,20);
				cprintf("Invalid Username OR Password");
			}
			if((mUser!=0)&&(mPass!=0)){
				gotoxy(26,20);
				cprintf("Invalid Username AND Password");
			}
			gotoxy(28,21);
			cprintf("You Have %d More Chances",--chance);
			gotoxy(28,22);
			printf("\x1B[5mPress SPACE to try again\x1B[0m");
			getch();
			if(chance==0) { puts("Exiting"); exit(0); }
			uId[0]='\0';
			uPass[0]='\0';
			goto CHANCE;
			}//end of inner-else

		} break; // end of case 1


		case 2:
		frames(1);
		{// for changing the password
		int x;
		char pass[20];
		char p[20];
		char np[20], np2[20];
		FILE *pp=fopen("password.dat","r");
		gotoxy(27,9);
		printf("\x1B[7m    CHANGE PASSWORD    \x1B[0m");
		Move(25,12);
		cprintf("Enter current password  : ");
		scanf("%s",pass);
		fscanf(pp,"%s",p);
		if((x=strcmp(pass,p))==0)
		{
			clrscr();
			Re_Enter:

			frames(1);
			gotoxy(27,9);
			printf("\x1B[7m    CHANGE PASSWORD    \x1B[0m");

			Move(25,12);	cprintf("Enter new password   : ");
			Move(25,14);    cprintf("Re-Enter  password   : ");

			Move(48,12);	gets(np);
			Move(48,14);	gets(np2);
			if((x=strcmp(np,np2))==0)
			{
			FILE *pp=fopen("password.dat","w");
			fprintf(pp,"%s",np);
			Move(32,18);  puts("Password Changed");
			}
			else
			{       Move(31,21);
				cprintf("Password matching failed...");
				Move(31,22);
				cprintf("Please try again");
				getch();
				clrscr();
				goto Re_Enter;
			}
		}
		else
		{
			Move(31,22);
			printf("Incorrect password");
		}
		fflush(stdin);
		getch(); cprintf("%d",x); clrscr();
		fclose(pp);
		}
		break;

	}

}

void frames(int frameType)
{
	int i;
	clrscr();
	switch(frameType)
	{
		case 1:
		gotoxy(2,1);
		for(i=0; i<78; i++)
		verticalLine
		gotoxy(2,25);
		for(i=0; i<78; i++)
		verticalLine
		for(i=2; i<25; i++){
		gotoxy(2,i);
		parallelLine
		}
		for(i=2; i<25; i++){
			gotoxy(79,i);
			parallelLine
		}
		gotoxy(2,1);  L_UP
		gotoxy(79,1); R_UP
		gotoxy(2,25);  L_DOWN
		gotoxy(79,25); R_DOWN
		break;

		case 2:
		clrscr();
		gotoxy(2,1);
		for(i=0; i<78; i++)
		verticalLine
		gotoxy(2,25);
		for(i=0; i<78; i++)
		verticalLine
		for(i=2; i<25; i++){
		gotoxy(2,i);
		parallelLine
		}
		for(i=2; i<25; i++){
			gotoxy(79,i);
			parallelLine
		}
		gotoxy(2,1);  L_UP
		gotoxy(79,1); R_UP
		gotoxy(2,25);  L_DOWN
		gotoxy(79,25); R_DOWN

		gotoxy(3,3);
		for(i=0; i<76; i++)
		verticalLine
		for(i=2; i<25; i++){
		gotoxy(20,i);
		parallelLine
		}
		gotoxy(2,3);    printf("\xCC");
		gotoxy(20,3);   printf("\xCE");
		gotoxy(79,3);   printf("\xB9");
		gotoxy(20,1);   printf("\xCB");
		gotoxy(20,25);  printf("\xCA");
		break;
	}

}

int selectmode()
{
int choice=0, key;
int i;
clrscr();
frames(1);
gotoxy(27,9);
puts("\x1B[7m       MAIN MENU       \x1B[0m");
gotoxy(31,11);
cprintf("Write Diary");
gotoxy(31,13);
cprintf("Read Diary");
gotoxy(31,15);
cprintf("Setting");
gotoxy(31,17);
cprintf("Quit Diary");
gotoxy(25,11);

SEL;
C_LEFT;
while(1)
{
  key=getch();
  if(key==13)
    break;

  switch(key)
  {
  case A_UP:
      {    if(choice==0) { choice=3; gotoxy(25,11); UNS; gotoxy(25,17); SEL; C_LEFT; break;  }
      else if(choice==1) { choice=0; gotoxy(25,13); UNS; gotoxy(25,11); SEL; C_LEFT; break; }
      else if(choice==2) { choice=1; gotoxy(25,15); UNS; gotoxy(25,13); SEL; C_LEFT; break; }
      else if(choice==3) { choice=2; gotoxy(25,17); UNS; gotoxy(25,15); SEL; C_LEFT; break; }

      }
  case A_DOWN:
      {	    if(choice==0) { choice++; gotoxy(25,11); UNS; gotoxy(25,13); SEL; C_LEFT; break; }
       else if(choice==1) { choice++; gotoxy(25,13); UNS; gotoxy(25,15); SEL; C_LEFT; break; }
       else if(choice==2) { choice++; gotoxy(25,15); UNS; gotoxy(25,17); SEL; C_LEFT; break; }
       else if(choice==3) { choice=0; gotoxy(25,17); UNS; gotoxy(25,11); SEL; C_LEFT; break; }
      }
    }//end of switch
}//end of while



return(choice);

}//end of selectmode function..

void W_MODE()
{
struct dParts rMode;

int static choice=0, key;
int xc=0;
frames(2);
gotoxy(3,2);
cprintf("  CONTROL MENU   ");
gotoxy(26,2);
cprintf("                    WRITTING MODE                  ");
window(4,4,18,24);
xc=4;
Move(xc,6);	cprintf("WRITE");
Move(xc,9);	cprintf("CLEAR");
Move(xc,12);	cprintf("SAVE");
Move(xc,15);	cprintf("BACK");
Move (2,6);
SEL;
while(1){
 EXTRA:      //extra input
 key=getch();
// if(key==32) break;
 if(key==13){
	 if(choice==0)
	 {
		// struct dParts rMode;
		 char ch;
		 int ch_count=0;
		 window(22,4,77,24);
		 cprintf("Enter Date: ");
		 gets(rMode.date);
//		 scanf("%10s",rMode.date);
		 window(22,6,77,24);
		 Move(12,1);
		 cprintf("Write Your Diary for : %s",rMode.date);
		 Move(3,3);
		 fflush(stdin);
		 while(1)
		 {
			 hand:
			 ch=getch();
			 
			 if(ch==8){        //backspace
		     cprintf("\b \b");
		     ch_count--;
		     goto hand;
		     }
		     else if(ch==13)      //enter
		     {
		     cprintf("\n\r");
		     rMode.paragraph[ch_count++]=' ';
		     goto hand;
		     }
			 if(ch==27) {
   			 rMode.paragraph[ch_count]='\0';	 
			 break;
			 }
			 if((ch>=33)&&(ch<=126)||(ch==32)){	   			
			 rMode.paragraph[ch_count++]=ch;
			 cprintf("%c",ch);
			 }
		 }

		// cprintf("%s %s",rMode.date,rMode.paragraph);
		// getch();
		 window(4,4,18,24);
		 Move(2,6);



		 /*  off the first
		 char date[10];
		 char *string, *s, ch;
		 int  i_str=0,spc=0;

		 FILE *fp=fopen("diary.txt","a++");


		 window(22,4,77,24);
		 cprintf("Enter Date: ");
		 scanf("%10s",date);
		 fflush(stdin);
		 window(22,6,77,24);
		 Move(12,1);
		 cprintf("Write Your Diary for : %s",date);
		 Move(3,3);
		 while(1)
		 { hand:
		   ch=getch();
		   if(ch==8){        //backspace
		    cprintf("\b \b");
		    i_str--;
		    goto hand;
		   }
		  else if(ch==13)      //enter
		    {
		     cprintf("\n\r");
		    //string[i_str++]=ch;
		     i_str++;
		     goto hand;
		    }
		  else if(ch==27)  //((ch==9)||(ch=27))  //tab and esc
		    {
		     string[i_str]='\0';
		     fputs(date, fp);
		     fputs(string, fp);

		     spc=10-(strlen(string));
		     for(i_str=0;i_str<spc;i_str++)
		     {
		      s[i_str]='_';
		     } s[i_str]='\0';
		   //  cprintf("%s",string);
		     fputs(s, fp);

		     fputs((strrev(date)), fp);


		    //	 fputs(string, fp);
		     fclose(fp);
		     fflush(stdin);

		     window(1,1,80,25);
		     W_MODE();


		     //save and move
		    }
		   else if((ch>=33)&&(ch<=126)||(ch==32))
		   {
		   string[i_str++]=ch;
		   cprintf("%c",ch);
		   }
		   else goto hand;
		 }
	*///comment off inner


	 }//choice 0
	 else if(choice==1)
	 {
		 window(22,4,77,24);
		 clrscr();
		 Move(23,10);
		 cprintf("CLEARED...!");
		 getch();
		 clrscr();
		 window(4,4,18,24);
		 Move(2,9);
		 SEL;

	 }
	 else if(choice==2)
	 {
		 FILE *fp=fopen("diary.txt","a++");
		 char mega[1100];
		 char blank[10];
		 int len,c;
		 strcpy(mega,"");     //empty
		 strcat(mega, rMode.date);
		 strcat(mega, rMode.paragraph);
		// fprintf(fp,"%s",mega);    //line no 25
		 len=strlen(mega);
		 len=10-(len%10);
		// strcpy(mega,"");
		 for(c=0;c<len;c++)
		 {
		 blank[c]=' ';
		 } blank[c]='\0';
		 strcat(mega, blank);
		 strrev(rMode.date);
		 strcat(mega, rMode.date);
		 fprintf(fp,"%s",mega);
		 fflush(stdin);
		 fclose(fp);
		 window(22,4,77,24);
		 clrscr();
		 Move(23,10);
		 cprintf("SAVED...!");
		 getch();
		 clrscr();
		 window(4,4,18,24);
		 Move(2,12);
		 SEL;
	 }
	 if(choice==3){
		 window(1,1,80,25);
		 main();
		 
	 }  //back button
	 
 }
 switch(key)
 {
	case A_DOWN:
	{
		if(choice==0) {
			choice++;
			Move(2,6);
			UNS;
			Move(2,9);
			SEL;
		}
		else if(choice==1) {
			choice++;
			Move(2,9);
			UNS;
			Move(2,12);
			SEL;
		}
		else if(choice==2) {
			choice++;
			Move(2,12);
			UNS;
			Move(2,15);
			SEL;
		}
		else if(choice==3) {
			choice=0;
			Move(2,15);
			UNS;
			Move(2,6);
			SEL;
		}
	}
	break;

	case A_UP:
	{
	  if(choice==0) {
			choice=3;
			Move(2,6);
			UNS;
			Move(2,15);
			SEL;
		}
	  else if(choice==3) {
			choice--;
			Move(2,15);
			UNS;
			Move(2,12);
			SEL;
		}
	  else if(choice==2) {
			choice--;
			Move(2,12);
			UNS;
			Move(2,9);
			SEL;
		}
	  else if(choice==1) {
			choice--;
			Move(2,9);
			UNS;
			Move(2,6);
			SEL;
		}
	}
	break;
	case 9: //tab
	{
	Move(7,14); UNS;
	Move(7,17); UNS;
	Move(7,11); UNS;
	Move(7,8);
	SEL;
	}
	break;
	default:
	goto EXTRA;
 }//switch


	}//end of while

} //end of W_MODE

void S_MODE(){
	int choice=0, key;
	int i;
	frames(1);
	gotoxy(27,9);
	puts("\x1B[7m        SETTING         \x1B[0m");
	gotoxy(31,11);
	puts("Backup");
	gotoxy(31,13);
	puts("Change password");
	gotoxy(31,15);
	puts("Personalize");
	gotoxy(31,17);
	puts("Back to Menu");
	gotoxy(25,11);
	SEL;
	while(1)
{
  NONSENCE:
  key=getch();
  if(key==13)
    break;

  switch(key)
  {
  case A_UP:
      {    if(choice==0) { choice=3; gotoxy(25,11); UNS; gotoxy(25,17); SEL; C_LEFT; break;  }
      else if(choice==1) { choice=0; gotoxy(25,13); UNS; gotoxy(25,11); SEL; C_LEFT; break; }
      else if(choice==2) { choice=1; gotoxy(25,15); UNS; gotoxy(25,13); SEL; C_LEFT; break; }
      else if(choice==3) { choice=2; gotoxy(25,17); UNS; gotoxy(25,15); SEL; C_LEFT; break; }

      }
  case A_DOWN:
      {	    if(choice==0) { choice++; gotoxy(25,11); UNS; gotoxy(25,13); SEL; C_LEFT; break; }
       else if(choice==1) { choice++; gotoxy(25,13); UNS; gotoxy(25,15); SEL; C_LEFT; break; }
       else if(choice==2) { choice++; gotoxy(25,15); UNS; gotoxy(25,17); SEL; C_LEFT; break; }
       else if(choice==3) { choice=0; gotoxy(25,17); UNS; gotoxy(25,11); SEL; C_LEFT; break; }
      }
  default:  goto NONSENCE;
    }//end of switch
}//end of while

switch(choice)
{
case 0:

break;

case 1:
clrscr();
login(2);
break;

case 2:
personlize(2);
break;

case 3:
main();
break;




}//end of switch


}//S_MODE


void R_MODE(){
	int xc=0;
	int key;
	int choice=0;
	frames(2);
	gotoxy(3,2);
	cprintf("  CONTROL MENU   ");
	gotoxy(26,2);
	cprintf("                    READING MODE                  ");
	window(4,4,18,24);
	xc=4;
	Move(xc,6);	cprintf("SEARCH");
	Move(xc,9);	cprintf("CLEAR");
	Move(xc,12);	cprintf("DELETE");
	Move(xc,15);	cprintf("BACK");
	Move (2,6);
	SEL;
	while(1){
		NONSENCE:
		key=getch();
		if(key==13) {break;}
		switch(key){
			case A_DOWN:
			{
		if(choice==0) {
			choice++;
			Move(2,6);
			UNS;
			Move(2,9);
			SEL;
		}
		else if(choice==1) {
			choice++;
			Move(2,9);
			UNS;
			Move(2,12);
			SEL;
		}
		else if(choice==2) {
			choice++;
			Move(2,12);
			UNS;
			Move(2,15);
			SEL;
		}
		else if(choice==3) {
			choice=0;
			Move(2,15);
			UNS;
			Move(2,6);
			SEL;
		}
		}
			break;
			case A_UP:
			{
	  if(choice==0) {
			choice=3;
			Move(2,6);
			UNS;
			Move(2,15);
			SEL;
		}
	  else if(choice==3) {
			choice--;
			Move(2,15);
			UNS;
			Move(2,12);
			SEL;
		}
	  else if(choice==2) {
			choice--;
			Move(2,12);
			UNS;
			Move(2,9);
			SEL;
		}
	  else if(choice==1) {
			choice--;
			Move(2,9);
			UNS;
			Move(2,6);
			SEL;
		}
			}
			break;
			default:
			goto NONSENCE;
		}


	}

	switch(choice)
	{
		case 0:{
		FILE *fp=fopen("diary.txt","r");
		char match[11];
		char sDate[11];
		int ten;
		int reminder;
		char ch;
		window(22,6,77,24);
		cprintf("Enter Date to Search: ");
		scanf("%10s",sDate);

		   while(1)
		   {
		    for(ten=0;ten<10;ten++)
		    {
		      ch=fgetc(fp);
		      match[ten]=ch;
		    } match[ten]='\0';

		     if((reminder=strcmp(match,sDate))==0)
		     {
		    // cprintf("Found...");
		     break;
		     }
		     if(ch==EOF)
		     {
		     window(22,8,77,24);
		     cprintf("No Such Record Exist...");
		     getch();
		     cprintf("%d",reminder);
		     window(1,1,80,25);
		     R_MODE();
		     }

		   }//end of while till matching of date
		   strrev(sDate);
		   //puts(sDate); check
		   window(22,8,77,24);
		   while(1)
		   {
		    for(ten=0;ten<10;ten++)
		    {
		      ch=fgetc(fp);
		      match[ten]=ch;
		    } match[ten]='\0';
		    //puts(match); check
		     if((reminder=strcmp(match,sDate))==0)
		     {
		     //  cprintf("%s",match);
		     getch();
		     window(1,1,80,25);
		     R_MODE();
		     }
		     cprintf("%s",match);
		   }//end of while till matching of date
	       //	fclose(fp);
	       //	getch();
	       //	window(1,1,80,25);
	       //	R_MODE();

		}// break;

		case 1:{
		 window(22,4,77,24);
		 clrscr();
		 Move(23,10);
		 cprintf("CLEARED...!");
		 getch();
		 window(1,1,80,25);
		 clrscr();

		 R_MODE();
		 Move(2,9);
		 SEL;

		}

		case 2:{
		FILE *fp=fopen("diary.txt","r");
		char match[11];
		char sDate[11];
		int ten;
		int reminder;
		char ch;
		FILE *dfp=fopen("diary2.txt","w");

		window(22,6,77,24);

		cprintf("Enter Date to Delete: ");
		scanf("%10s",sDate);
		 while(1)
		 {
		    for(ten=0;ten<10;ten++)
		    {
		      ch=fgetc(fp);
		      if(ch==EOF)
		     {
		     goto HEREE;
			 /*fclose(fp);
		     getch();
		     window(1,1,80,25);
		     R_MODE();
			 */
		     }//if
			  match[ten]=ch;
		    } match[ten]='\0';

		     

		     if((reminder=strcmp(match,sDate))==0)
		     { //2
		      strrev(sDate);
		      while(1)
		      {//3
				if((reminder=strcmp(match,sDate))==0)
				{
				for(ten=0;ten<10;ten++)
				{
				ch=fgetc(fp);
				match[ten]=ch;
				} match[ten]='\0';
				break;
				}

			
				for(ten=0;ten<10;ten++)
				{
				ch=fgetc(fp);
				match[ten]=ch;
				} match[ten]='\0';

		      }//3

		     }//2
		     fprintf(dfp,"%s",match);





		}//while if found
		HEREE:

		if(ch==EOF){
			window(22,8,77,24);
		    cprintf("No Such Record Exist...");
		    getch();
			 
			
		}
		else{

		cprintf("DELETED...!");
		getch();
		}
		remove("diary.txt");
		fclose(fp);
		fclose(dfp);
		rename("diary2.txt","diary.txt");
		//rename("diary2.txt","diary.txt");
		
		cprintf("%d",reminder);
		window(1,1,80,25);
		R_MODE();

		} break;

		case 3:{
		 window(1,1,80,25);
		 main();

		} break;

	}



	window(1,1,80,25);
	getch();
}//R_MODE
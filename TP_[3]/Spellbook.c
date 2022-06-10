

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

////////////////////////////////////////////////////////////////////////// DATA Int.

int dataInt(int base, int top,char msg[]){

	int i;
	int j=0;
    int errorFlag=0;
    char numS[1022];
    char numS2[1022];
    int num;
    char digit[] = "-0123456789";

    do{

        for(i=0;i<1022;i++){
            numS[i]=0;
            numS2[i]=0;
        }

    	if(errorFlag==1){
    		printf("\n[ Error. \nOnly numbers within the range ]\n");
            	errorFlag=0;
                num=0;
                j=0;
    	}
    	printf("\n%s\n",msg);
    	//printf("Value between: [ %d ] to [ %d ] :\n\n ", base, top);

    	///////

    	fgets(numS,1022,stdin);
    	numS[strlen(numS)-1]='\0';

    	//////

    	if (strlen(numS) != strspn(numS, digit)){
    		errorFlag=1;
    	}

    	//////

    	for(i=0;i<strlen(numS);i++){
    		if(i==0 && numS[0]=='-'){
    			numS2[j]=numS[i];
    			j++;
    		}
    		else if(numS[i]<='9' && numS[i]>='0'){
    			numS2[j]=numS[i];
    			j++;
    		}
    	}

    	//////

    	num=atoi(numS2);
    	if(num>top || num<base){
    		errorFlag=1;
    	}

    }while(errorFlag==1);

    setbuf(stdin, NULL);

   	return num;
}
////////////////////////////////////////////////////////////////////////// DATA float.

float dataFloat(int base, int top,char msg[]){

    int i;
    int j=0;
    int dots=0;
    int errorFlag=0;
    char numS[1022];
    char numS2[1022];
    float num;
    char digit[] = "0123456789,.";

    do{

        for(i=0;i<1022;i++){
            numS[i]=0;
            numS2[i]=0;
        }

    	if(errorFlag==1){
    		printf("\n[ Error. \nOnly numbers within the range ]\n");
            	errorFlag=0;
                num=0;
                j=0;
            }
            printf("\n%s\n",msg);
            printf("Value between: [ %d ] to [ %d ] :\n\n ", base, top);

            /////// ENTER OF NUMBER

            fgets(numS,1022,stdin);
            numS[strlen(numS)-1]='\0';

            ////// CHECK IF NUMBERS

            if (strlen(numS) != strspn(numS, digit)){
                errorFlag=1;
            }

            ////// REPLACE OF COMMAS
            //printf("\nLargo del numero: %ld\n\n",(strlen(numS)));
            for(i=0;i<strlen(numS);i++){
            	if(i==0 && numS[0]=='-'){
            		numS2[j]=numS[i];
            		j++;
            	}
            	else if(dots==0 && (numS[i]==',' || numS[i]=='.')){
                    numS[i]='.';
                    dots=1;
                    numS2[j]=numS[i];
                    j++;
                }
                else if(numS[i]<='9' && numS[i]>='0'){
                    numS2[j]=numS[i];
                    j++;
                }
            }

            num=atof(numS2);
            if(num>top || num<base){
                errorFlag=1;
            }

    }while(errorFlag==1);

    setbuf(stdin, NULL);

   	return num;
}

////////////////////////////////////////////////////////////////////////// DATA string with numbers.

void stringEntry(int top, char *stringChain, char msg[]){

	int bugFlag=0;
	char auxChar[top];
	int i;

	for(i=0;i<top;i++){
		stringChain[i]=0;
		auxChar[i]=0;
	}

	do{
		fflush(stdin);

		if(bugFlag==2){
			printf("\n\n[ Error. Can't be empty. ]");
			bugFlag=0;
		}

		printf("%s",msg);

		fgets(auxChar,top,stdin);

		auxChar[strlen(auxChar)-1]='\0';//*

		if(strlen(auxChar)==0){
			bugFlag=2;
		}

	}while(bugFlag!=0);

	setbuf(stdin, NULL);

	strcpy(stringChain, auxChar);
}

////////////////////////////////////////////////////////////////////////// DATA string with NO NUMBERS NOR SYMBOLS

void stringEntry2(int top, char *stringChain, char msg[]){

	int bugFlag=0;
	char auxChar[top];
	int i;
	char alpha[] = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for(i=0;i<top;i++){
		stringChain[i]=0;
		auxChar[i]=0;
	}

	do{
		fflush(stdin);

        if(bugFlag==1){
            printf("\n\n[ Error. Enter only characters. ]");
            bugFlag=0;
        }

		if(bugFlag==2){
			printf("\n\n[ Error. Can't be empty. ]");
			bugFlag=0;
		}

		printf("%s",msg);

		fgets(auxChar,top,stdin);

		auxChar[strlen(auxChar)-1]='\0';//*

		if(strlen(auxChar)==0){
			bugFlag=2;
		}

		if (strlen(auxChar) != strspn(auxChar, alpha)){
            bugFlag=1;
        }


	}while(bugFlag!=0);

    setbuf(stdin, NULL);

	strcpy(stringChain, auxChar);
}

////////////////////////////////////////////////////////////////////////// PRESS ENTER

void pressKey(){
	char tecla;

	printf("\nPress ['Enter'] to continue...\n\n>>>> ");
    while ((tecla = getchar()) != '\n' && tecla != EOF);
}

////////////////////////////////////////////////////////////////////////// CLEAR

void clear(){

	int i;

	for(i=0;i<300;i++){
		printf("\n");
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "words.h"
#define ENV "WORD_FREAK"

int main(int argc, char *argv[], char* envp[]){
	int f;//file
	int i;//stored read() function return value
	char* c;//store readed char from file
	char* word_freak;//stored environment variable
	word_freak = getenv(ENV);
	
        char word[50];//stored single word from file
	int wordindex=0;//index for word[50]

	WORD* wordsList=NULL;//head of list of words
	WORD* readWord;//read in word from file
	
	c=(char*)malloc(sizeof(char));//allocate for raed in char

//=======read files from standard input============
	if(!isatty(0)){
		do{
			i = read(0, c, sizeof(char));

			//if read in char is alphabet
			if((c[0]>='a' && c[0]<='z')||(c[0]>='A' && c[0]<='Z')){
				word[wordindex]=c[0];//store char in word[50] array
				wordindex++;
			}
			else{
				if(wordindex>0){//if read in a word
					word[wordindex]='\0';
					wordindex=0;
					
					readWord = is_contain(word, wordsList);

					if(readWord!=NULL){//if word contain in list, count++
						readWord->count = (readWord->count)+1;
					}
					else{//if not in list, insert to list
						word_insert(word, &wordsList);
					}
				}
			}
		}while(i!=0);//end of do-while loop, end reading one file
	}
		
//---------end reading from std input----------

	else{
//======read single file from env=========
	if(word_freak!=NULL){//if env exist
		f=open(word_freak, O_RDONLY);
		if(f==-1){//if file not exits
			printf("Can't read file.\n");
			return -1;
		}
		
		do{
			i = read(f, c, sizeof(char));

			//if read in char is alphabet
			if((c[0]>='a' && c[0]<='z')||(c[0]>='A' && c[0]<='Z')){
				word[wordindex]=c[0];//store char in word[50] array
				wordindex++;
			}
			else{
				if(wordindex>0){//if read in a word
					word[wordindex]='\0';
					wordindex=0;
					
					readWord = is_contain(word, wordsList);

					if(readWord!=NULL){//if word contain in list, count++
						readWord->count = (readWord->count)+1;
					}
					else{//if not in list, insert to list
						word_insert(word, &wordsList);
					}
				}
			}
		}while(i!=0);//end of do-while loop, end reading one file
		
		close(f);//close current file

	}//end if
	
//-------end of reading from env-------------

//=======read files from command line========
	int j;
	wordindex=0;
	for(j=1; j<argc; j++){
		f=open(argv[j], O_RDONLY);
		if(f==-1){//if file not exits
			printf("Can't read file.\n");
			return -1;
		}
		
		do{
			i = read(f, c, sizeof(char));

			//if read in char is alphabet
			if((c[0]>='a' && c[0]<='z')||(c[0]>='A' && c[0]<='Z')){
				word[wordindex]=c[0];//store char in word[50] array
				wordindex++;
			}
			else{
				if(wordindex>0){//if read in a word
					word[wordindex]='\0';
					wordindex=0;
					
					readWord = is_contain(word, wordsList);

					if(readWord!=NULL){//if word contain in list, count++
						readWord->count = (readWord->count)+1;
					}
					else{//if not in list, insert to list
						word_insert(word, &wordsList);
					}
				}
			}
		}while(i!=0);//end of do-while loop, end reading one file
		
		close(f);//close current file

	}//end of for loop
	
//-------end reading from command line-------------
	}


	word_print(wordsList);//display list of words
	
	free(c);
        free(wordsList);
	
	
	return 0;
}

//Self Learning Dictionary using Hashing

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define HASHSIZE 101
struct dictionary { 
    char *name; 
    char *defn;
    struct dictionary *next;	 
};

static struct dictionary *hashtab[HASHSIZE]; 

unsigned hash(char *s)
{
    unsigned hashval;
   for (hashval = 0; *s != '\0'; s++)
      hashval = *s + (31 * hashval);
     return hashval % HASHSIZE;

}

struct dictionary *lookup(char *s)
{
    struct dictionary *t;
    for (t = hashtab[hash(s)] ; t != NULL; t = t->next)
        if (strcmp(s, t->name) == 0)
          return t; 
    return NULL; 

}



struct dictionary *addToDictionary(char *name, char *defn)
{
    struct dictionary *np;
    unsigned hashval;
    
        np = (struct dictionary *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
          return NULL;
	if ((np->defn = strdup(defn)) == NULL)
       	  return NULL;	
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    return np;
}

int main(int argc, char **argv)
{
	char word[20], def[40];
	char choice[10]; 
	char exit[10];
	struct dictionary *temp;
	printf("\nWelcome to the self-learning dictionary!\n");
	do
	{
	printf("\nPlease enter a word:\t");
	scanf("%s",word);
	temp = lookup(word);
	if(temp == NULL)
	{
		printf("\nSorry, not found. Add to Dictionary? (yes / no):\t");
				
		scanf("%s",choice);
		if(!strcmp(choice,"yes"))		
		{
		printf("\n plz enter meaning => \t ");
		scanf("%s",def);	
		addToDictionary(word, def);
		printf("\nThank You ");
		}
					
	}
	else
	{
		printf("\n defination  => %s",temp->defn);

	}
	printf("\n Do You Want To Exit Dictionary? (yes / no):\t");
	scanf("%s",exit);	
		
	}while(strcmp(exit,"yes"));
	return 0;
	
}


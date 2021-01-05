#include <stdio.h>
#include <string.h>
#include <ctype.h>

//determine if string 2 can be a substring of string 1
int SubString(char string1[], char string2[])
{
    //make sure neither of the strings are empty if so its impossible(answer = -1)

    //duplicate string1 until the length of the new string is at least 1 string1 length
    //longer than the length of string 2

    //keep track of the amount of duplicates( answer = )
    //check for substring

    //if not there substring is impossible(answer = -1)
    //else (its there), remove 1 copy of string 1 from the end of the new string and recheck for substring
    //be sure to update answer accordingly

    char Temp[100];
    char *start;
    int answer = 0;
    int impossible = 0;
    int length1 = 0;
    int length2 = 0;
    int newLength = 0;
    int targetLength = 0;
    int currentIndex = 0;
    int i = 0;

    //get length of strings 1 & 2
    length1 = strlen(string1);
    length2 = strlen(string2);

    
    
    //make sure neither string is empty 
    //a string is empty
    if(length1 == 0 | length2 == 0)
    {
        answer = -1;
        printf("String Empty\n");
    }
    //no string is empty
    else
    {
        //copy strings into new variables
        char string3[length1];
        char string4[length2];

        strcpy(string3,string1);
        strcpy(string4,string2);
        //capitalize each string
        for(int temp=0; temp<length1; temp++)
        {
            string3[temp]= toupper(string3[temp]);
        }
        for(int temp=0; temp<length2; temp++)
        {
            string4[temp]= toupper(string4[temp]);
        }
        
        targetLength = length2 + length1;
        //build new string keeping track of the amount of duplicates
        while(newLength <= targetLength)
        {
            strcat(Temp,string3);
            newLength = newLength + length1;
            answer++;
        }
        //check for substring
        start = strstr(Temp,string4);
        //if not there, its not possible
        if(start == NULL)
        {
            answer = -1;
        }
        //else (its) there begin to remove excess copies of string 1 from new string
        else
        {
            while(start != NULL)
            {
                currentIndex = strlen(Temp);
                i = 0;
                while(i <= length1)// remove last copy of string 1
                {
                    Temp[currentIndex - i] = '\0' ;
                    i++;
                }
                start = strstr(Temp,string4);
                if(start != NULL)
                {
                    answer--;
                }
            }
        }
        

        
    }
    

    return answer;

}




int main(void)
{
    char string1[20]= "Toucan";
    char string2[20]= "can";
    int answer = 0;

    answer = SubString(string1,string2);
    if(answer!=1)
    {
        printf("%s is not a substring of %s\n",string2, string1);
    }
    else
    {
        printf("%s is a substring of %s\n",string2, string1);
    }
    


    return 0;
}
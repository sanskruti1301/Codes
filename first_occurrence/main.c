#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int strStr(const char* haystack, const char* needle )
{
    int hLen= strlen(haystack);
    int nLen= strlen(needle);

    for(int i=0;i<= (hLen- nLen);i++)
    {
        if(haystack[i]==needle[0])
        {
            int j=0;
            while(needle[j] && haystack[i+j]== needle[j])
            {
                j++;
            }
            if(needle[j]=='\0')
            {
                return i;
            }
        }
    }
    return -1;
}






int main()
{   char haystack[100];
    char needle[50];
    printf("Enter haystack!\n");
    fgets(haystack, sizeof(haystack),stdin);
    haystack[strcspn(haystack,"\n")]= '\0';

    printf("Enter needle! \n");
    fgets(needle, sizeof(needle),stdin);
    needle[strcspn(needle,"\n")]='\0';

    int index= strStr(haystack, needle);
    printf("%d",index);
    return 0;
}

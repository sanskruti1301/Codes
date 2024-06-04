#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{ char s[100];
char t[100];
int i,j,count=0,n;
scanf("%s",&s);
n= strlen(s);
printf("%s",s);
for(int i=0;i<n;i++){
    t[i]=s[i];
}
for(int i=0;i<n;i++){
for(int j=0;j<i;j++){
    if(s[i]!=s[i+1] && s[i]!=t[j] && s[i+1]!=t[j]){
        count++;
    }
    }

}
printf("%d",count);


    return 0;
}

#include <stdio.h>
#include <string.h>

int opcount = 0;

int match_string(char *s1, char *s2){
    for(int i = 0; i < strlen(s2); i++){
        int flag = 1;
        for(int j = 0; j < strlen(s1); j++){
            opcount++;
            if(s1[j] != s2[i+j]){
                flag = 0;
                break;
            }
        }
        if(flag > 0) return i;
    }
    return -1;
}

int main(){
    char str[50], substr[20];
    printf("What is the word? ");
    fgets(str, 50, stdin);
    printf("What is the substr to match? ");
    fgets(substr, 20, stdin);

    // Remove newlines that get passed onto the string
    str[strcspn(str, "\n")] = 0;
    substr[strcspn(substr, "\n")] = 0;

    int foundat = match_string(substr, str);

    if(foundat >= 0) printf("Found the string at index %d\n", foundat);
    else printf("Could not find string\n");

    printf("Final opcount is: %d\n", opcount);

    return 0;
}
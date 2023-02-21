#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ABC 26
#define SPACE ' '
/*טיוטה
טריפת אותיות שאפשר לקחת את האותיות של מילה אחת וליצור מילה אחרת 
צריך להחזיר אם המחרוזות עושות את זה 
היסטוגרמה
*/
bool AreAnagrams(char *s1, char *s2);
void histogramMaker(char *s, int hist[]);
int main(){
    char s1[]="Tom Marvolo Riddle";
    char s2[]="I am Lord Voldemort";
    printf("answer is %d\n",AreAnagrams(s1,s2) );
    char s3[]="Tom Marvolo Riffle";
    char s4[]="I am Lord Voldemort";
    printf("answer is %d\n",AreAnagrams(s3,s4) );
}
bool AreAnagrams(char *s1, char *s2){
    int hist_s1[ABC]={0};
    int hist_s2[ABC]={0};
    histogramMaker(s1, hist_s1);
    histogramMaker(s2,hist_s2);
    for (int i=0; i<ABC; i++){
        if(hist_s1[i]!=hist_s2[i]){
            return false;
        }
    }
    return true;
    
}
void histogramMaker(char *s, int hist[]){
    for (int i=0;i<strlen(s);i++){
        if(s[i]==SPACE){
            continue;
        }
        else if(s[i]>='a'&& s[i]<='z'){
            hist[s[i]-'a']++;
        }
        else if(s[i]>='A'&& s[i]<='Z'){
            hist[s[i]-'A']++;
        }
        
    }
}
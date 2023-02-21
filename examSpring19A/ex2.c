#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*טיוטה
נתון מערך שלא בהכרח ממוין שמכיל מספרים שלמים 
כל המספרים במערך מופיעים בזוגות עוקבים 
פרט למספר אחד בדיוק שלו יש מופע בודד חסר בן זוג עוקב
נשים לב כי הזוגות הם מספרים ששווים אחד לשני
אז אם נמצא מישהו שאין ליד שני הצדדים שלו מישהו שדומה לו סיימנו
לנסות סיבוכיות הכי קטנה
יצא לי אן חלקי 2 אולי אפשר לעשות את זה יותר קטן עם לוג

*/
int FindOddOcucuring_n(int arr[],int n);
int FindOddOcucuring_logn(int arr[], int n);
int main(){
    int arr[11]={8,8,5,5,6,6,-1,-1,6,7,7};
    printf("answer  is %d\n", FindOddOcucuring_logn(arr, 11));


}
// n/2 סיבוכיות
int FindOddOcucuring_n(int arr[],int n){
    for(int i=0;i<n-1;i+=2){
        if(arr[i]==arr[i+1]){
            continue;
        }
        else{
            return arr[i];
        }
    }
}
// לבדוק למה זה עובד
int FindOddOcucuring_logn(int arr[], int n){
    int high=n/2, low=0;
    while(low<=high){
        int mid=(high+low)/2;
        if(arr[2*mid]==arr[2*mid+1]){
            low=mid+1;
        }
        else{
           high=mid-1;
        }
        
    }
    return arr[2*low];
}

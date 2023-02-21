#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 6
#define M 7
#define N_ALPH 2
#define LETTER 1
#define NO_LETTER 0


/*טיוטה
נתון מערך דו ממדי של אותיות באנגלית ומערך דו ממדי עם אותיות באנגלית
צריך למצוא את האורך של המסלול הארוך ביותר במטריצה שמורכב כולו מאותיות 
במערך החד ממדי 
אין אלכסונים 
נשים לב כי זה שאלה של מבוך עם בדיקה של מקסימלי 
נעשה פונקצית מעטפת קודם כל 
נשלח גם מקסימלי שיעקוב אחרי המסלול 
נשתמש בדוגמא שלהם כדי להבין יותר טוב

איך נפתור
נבדוק מכל מקום מסוים מה הדרך הכי ארוכה שהוא יכול לעשות
נעשה את זה ככה לכל המקומות גם אם זה לא יעיל בעליל
קודם בשביל הנוחות בכל מקום בו מופעיות האותיות נסמן ב1 והשאר ב0 
ואז זה הופך לחיפוש רגיל
אחרי זה נבדוק בעזרת מקסימום רגיל מה יותר טוב ונשמור כל הזמן על
*/
int FindLongestPath(char letters[N_ALPH], char matrix[N][M]);
int do_it(char matrix[N][M],int row, int col);
bool checkInArr(char letters[N_ALPH], char word);
bool isSafe(int row, int col);

int main(){
    char letters[N_ALPH]={'a','b'};
    char matrix[N][M]={ {'b','b','c','f','e','a','a'},
                        {'b','c','a','a','b','f','b'},
                        {'f','e','a','e','b','c','b'},
                        {'e','f','b','b','a','d','b'},
                        {'d','a','a','a','e','c','a'},
                        {'c','d','e','f','f','a','b'}

    };
    printf("answer is %d\n" ,FindLongestPath(letters,matrix));//11


}
// מעטפת
int FindLongestPath(char letters[N_ALPH], char matrix[N][M]){
    /*החלפנו את המערך כך שבכל מקום בו יש את האותיות במערך שאנחנו רוצים
    שמנו אחד ובשאר יש אפס כדי שנוכל לעבור ביותר קלות על המטריצה
    מבלי לבדוק כל הזמן האם האות בכל תא במטריצה נמצא במערך אותיות*/
    for (int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if (checkInArr(letters, matrix[i][j])){
                matrix[i][j]=LETTER;
            }
            else{
                matrix[i][j]=NO_LETTER;
            }
        }
    }
     // הדפסת המערך בשבילנו כדי לראות איך זה נראה
   
    for (int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int max=0;
    /*אנחנו נעבור על המבוך עבור כל מקום במטריצה
    כלומר אנחנו נבדוק עבור כל מקום מה הדרך הכי ארוכה שהוא עושה ונשים 
    במשתנה זמני וכל הזמן נבדוק מול המקסימום ששומר את ההכי גבוה
    ואת המקסימום הזה נחזיר למשתמש*/
    for (int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(matrix[i][j]!=NO_LETTER){ // אם לא מתחיל באות שאפשר להשתמש כלומר שהחלפנו אותה באחד אין צורך סתם לבדוק
                int temp= do_it(matrix,i,j);
                if(temp>max){
                    max=temp;
                }
            }
            
           
        }
    }
    return max;
}
//פונקציה שמוצאת את המסלול הארוך ביותר מנקודה מסוימת
int  do_it(char matrix[N][M], int row, int col){
    if(matrix[row][col]==NO_LETTER){ // אם במקום יש אפס אז זה לא דרך שאפשר לעבור
        return 0;
    } 
    /*
    אנחנו עושים פה מערך של הכיוונים כדי להקל עלינו במקום לעשות ארבע תנאים כל תנאי כיוון
    נשים לב כי כל המקומום הראשונים מסמנים את השורה
    וכל המקומות השני מסמנים את העמודה
*/
    int step[4][2]={{-1,0}, {1,0},{0,-1},{0,1}};
    int max=0;

    char letter = matrix[row][col];// האות במקום שאנחנו נמצאים יכול להיות אפס או אחד
    matrix[row][col]=NO_LETTER;// מסמן שהיינו במקום הזה ואין צורך לבדוק שוב
 
     
    for(int direction=0; direction<4;direction++){// 4 כי מספר הכיוונים
        int temp_row=row+step[direction][0]; 
        int temp_col=col+step[direction][1];
        if(!isSafe(temp_row,temp_col)) continue; //אם לא אפשרי להגיע לשם כי עבר את הגבולות לדלג על המקרה הזה

        int length = do_it(matrix,temp_row,temp_col);
        if(length>max){
            max=length;
        }
    }
    matrix[row][col]=letter;//מחזירים למצב הקודם
    return 1+max;
    
}
//פונקצית עזר בודקת אם האיבר נמצא במערך האותיות
bool checkInArr(char letters[N_ALPH], char word){
    for(int i=0;i<N_ALPH;i++){
        if(word==letters[i])
            return true;
    }
    return false;
}
//בודק אם אפשר להגיע לשם
bool isSafe(int row, int col){
    if(row<0||row>N||col<0||col>M) return false;
    return true;
}

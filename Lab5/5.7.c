#include <stdio.h>

int main() {
    int sec;
    int h,temp;
    double m;
    int i=0; 

    printf("Enter Seconds: ");
    scanf("%d",&sec);

    if (sec>=3600) {    
        m= (sec%3600)/60;
        temp= sec%3600;
        h = (sec-temp)/3600;
        i=sec%60;
        printf("%d hour(s) \n",h);
        printf("%0.2lf minute(s)\n",m);
        printf("%d second(s)\n",i);

        printf("Formatted: %d:%0.2f:%d\n",h,m,i);
        
    } 
    else if ( sec <3600 && sec>=60) {
        temp = sec%60;
        m = (sec-temp)/60;
        printf("%0.2lf minute(s)\n",m);
        printf("%d second(s)\n",temp);
        printf("Formatted: 00:%0.2f:%d\n",m,i);
    } else {
        printf("%d second(s))\n",sec);
        printf("Formatted: 00:00:%d\n",i);
    }
}

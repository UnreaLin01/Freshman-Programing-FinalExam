#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

void question16(){
    const int min = 0;
    const int max = 1000000;
    int randomNum = 0;
    int temp = 0;
    int sum = 0;
    int oddSum = 0;
    int evenSum = 0; 
    srand(time(0)); 

    randomNum = (rand() % ((max - min) + 1)) + min;
    printf("�п�J���n�G%d\n",randomNum);

    //3��������
    temp = randomNum;
    sum = 0;
    while(temp > 0){
        sum += temp % 10;
        temp /= 10;
    }
    if(sum % 3 == 0){
        printf("�O3������\n");
    }

    //11��������
    temp = randomNum;
    oddSum = 0;
    while(temp > 0){
        oddSum += temp % 10;
        temp /= 100;
    }
    temp = randomNum;
    temp /= 10;
    evenSum = 0;
    while(temp > 0){
        evenSum += temp % 10;
        temp /= 100;
    }
    
    if((oddSum - evenSum) % 11 == 0){
        printf("�O11������\n");
    }
}

void question17(){
    int num = 0;
    int numArray[4] = {0};
    int times = 1;
    int guess = 0;
    int guessArray[4] = {0};
    int finished = 0;

    while(finished == 0){
        int digits = 0;
        int temp = 0;
        
        printf("�ϥΪ�A��J�Ʀr�G");
        scanf("%d",&num);

        temp = num;
        digits = 0;
        while(temp > 0){
            temp /= 10;
            digits++;
        }

        if(digits == 4){
            int isSameValue = 0;
            int x = 0;
            int y = 0;
            
            numArray[0] = num % 10;
            numArray[1] = (num / 10) % 10;
            numArray[2] = (num / 100) % 10;
            numArray[3] = (num / 1000) % 10;

            for(x = 0; x < 4; x++){
                for(y = 0; y < 4; y++){
                    if(x == y){
                        continue;
                    }
                    if(numArray[x] == numArray[y]){
                        isSameValue = 1;
                    }
                }
            }
            if(isSameValue == 0){
                finished = 1;
            }else{
                printf("��J���~�G�п�J4�Ӥ��P�Ʀr��4���\n");
            }
        }else{
            printf("��J���~�G�п�J4���\n");
        }
    }

    while(times <= 15){
        int digits = 0;
        int temp = 0;
        int finished = 0;
        int x = 0;
        int y = 0;
        int A = 0;
        int B = 0;

        //�ϥΪ�B�Ʀr��������
        while(finished == 0){
            printf("�ϥΪ�B��%2d���q�G",times);
            scanf("%d",&guess);

            temp = guess;
            digits = 0;
            while(temp > 0){
                temp /= 10;
                digits++;
            }
            if(digits == 4){
                finished = 1;
            }else{
                printf("��J���~�G�п�J4���\n");
            }
        }

        guessArray[0] = guess % 10;
        guessArray[1] = (guess / 10) % 10;
        guessArray[2] = (guess / 100) % 10;
        guessArray[3] = (guess / 1000) % 10;

        A = 0;
        B = 0;
        for(x = 0; x < 4; x++){
            for(y = 0; y < 4; y++){
                if((guessArray[x] == numArray[y]) && (x == y)){
                    A++;
                }else if(guessArray[x] == numArray[y]){
                    B++;
                }
            }
        }
        
        if(A == 4){
            printf("%dA%dB�A�C���ӧQYou Win!\n",A,B);
            break;
        }else if(times == 15){
            printf("%dA%dB�A�C������You Lose!\n",A,B);
        }else{
            printf("%dA%dB\n",A,B);
        }
        times++;
    }
}

//subprogram for question 18
void moneyPartition(int floor, int money, int moneyType[4], int moneyMemory[4]){
    if(floor == 3){
        int x = 0;
        moneyMemory[3] = money;
        for(x = 0; x < 4; x++){
            printf("%d\t",moneyMemory[x]);
        }
        printf("\n");
    }else{
        int num = money / moneyType[floor];
        for(int x = num; x >= 0; x--){
            moneyMemory[floor] = x;
            int remainMoney = money - (moneyType[floor] * x);
            moneyPartition(floor + 1, remainMoney, moneyType, moneyMemory);
        }
    }
}

void question18(){
    int money = 0;
    int moneyType[4] = {50, 10, 5, 1};
    int moneyNumMemory[4] = {0, 0, 0, 0};

    printf("�п�J�Ʀrn�G");
    scanf("%d",&money);
    
    printf("$50\t$10\t$5\t$1\n");
    printf("--------------------------\n");
    moneyPartition(0, money, moneyType, moneyNumMemory);
}

//subprogram for question 19
void changeFormat(char date[10]){
    int month = ((date[0] - '0') * 10) + (date[1] - '0');
    int index = 0;
    for(index = 3; index <= 4; index++){
        printf("%c",date[index]);
    }
    printf(" ");
    switch(month){
        case 1:
            printf("January");
            break;
        case 2:
            printf("February");
            break;
        case 3:
            printf("March");
            break;
        case 4:
            printf("April");
            break;
        case 5:
            printf("May");
            break;
        case 6:
            printf("Jun");
            break;
        case 7:
            printf("July");
            break;
        case 8:
            printf("Augest");
            break;
        case 9:
            printf("September");
            break;
        case 10:
            printf("October");
            break;
        case 11:
            printf("November");
            break;
        case 12:
            printf("December");
            break;
    }
    printf(" ");
    for(index = 6; index <= 9; index++){
        printf("%c",date[index]);
    }

}

void question19(){
    int x = 0;
    char date[10] = {0};
    fgets(date, 11, stdin);
    changeFormat(date);
}

void question20(){
    int a = 0;
    int b = 0;
    int c = 0;
    int answer[2] = {0};
    
    printf("�ѤG���@����{���G\n");
    printf("��Ja�G");
    scanf("%d",&a);
    printf("��Jb�G");
    scanf("%d",&b);
    printf("��Jc�G");
    scanf("%d",&c);

    answer[0] = (-b + sqrt(pow(b,2) - (4 * a * c))) / (2 * a);
    answer[1] = (-b - sqrt(pow(b,2) - (4 * a * c))) / (2 * a);

    printf("�����Ѭ��G%d,%d",answer[0],answer[1]);
}

void question21(){
    FILE *source  = fopen("./question21/source.txt","r");
    FILE *even = fopen("./question21/even.txt","w+");
    FILE *odd = fopen("./question21/odd.txt","w+");
    //char dataTemp[100] = {0};
    int temp = 0;

    //check whether the file can open.
    if(source == NULL){
        printf("cannot find source.txt file");
        return;
    }
    if(even == NULL){
        printf("cannot find even.txt file");
        return;
    }
    if(odd == NULL){
        printf("cannot find odd.txt file");
        return;
    }


    //start reading the source file data.
    printf("Ū�J��source.txt���e��\n");
    while(fscanf(source,"%d", &temp) != EOF){
        printf("%d ", temp);
        if(temp % 2 == 0){
            fprintf(even, "%d ", temp);
        }else{
            fprintf(odd, "%d ", temp);
        }
    }
    printf("\n�g�Jodd.txt���e��\n");
    //don't forget to set the position
    fseek(odd, 0, SEEK_SET);
    while(fscanf(odd, "%d", &temp) != EOF){
        printf("%d ", temp);
    }
    
    fseek(even, 0, SEEK_SET);
    printf("\n�g�Jeven.txt���e��\n");
    while(fscanf(even, "%d", &temp) != EOF){
        printf("%d ", temp);
    }

    fclose(source);
    fclose(even);
    fclose(odd);
}

void question22(){
    int num = 0;
    int temp = 0;
    int studentScore[10000] = {0};
    double avgScore = 0;
    int underScoreCount = 0;
    int highestScore = 0;
    int lowestScore = 0;

    printf("�п�J�ǥͼ�n�G");
    scanf("%d",&num);
    srand(time(NULL));
    for(temp = num; temp > 0; temp--){
        int nowScore = (rand() % 101);
        studentScore[num - temp] = nowScore;
        avgScore += (double)nowScore;
        if(nowScore < 60){
            underScoreCount++;
        }
        if(nowScore > highestScore){
            highestScore = nowScore;
        }
        if(nowScore < lowestScore){
            lowestScore = nowScore;
        }
    }
    avgScore /= num;
    printf("�����G%2.2lf\n",avgScore);
    printf("%d�H���ή�\n",underScoreCount);
    printf("�t�G%d\n", highestScore - lowestScore);
    printf("���Z�G");
    for(temp = 0; temp < num; temp++){
        if(temp != 0){
            printf(",");
        }
        printf("%d",studentScore[temp]);
    }
}

void question23(){
    int length = 0;
    char data[100] = {0};
    
}

int main(){
    question21();
}
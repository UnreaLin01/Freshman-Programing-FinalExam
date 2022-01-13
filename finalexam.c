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

/*temporary giveup 23
void question23(){
    int length = 0;
    char *data;
    int x = 0;
    int y = 0;

    //user basic input
    printf("�п�J���סG");
    scanf("%d", &length);
    data = malloc(sizeof(char) * length);
    printf("�п�J���׬�%d���r��G", length);
    scanf("%s", data);
    

    free(data);
    
}

void recursion(int length; int floor; char *charList; int *usedList; char *printList){
    char *charList = charList;
    if((length - floor) >= 1){
        int x = 0;
        for(x = 0; x < length - floor){

            int temp = x;
            while(*(usedList + temp) == 1){
                temp++;
            }
            *(printList + floor) = *(charList + temp)
            *(usedList + temp) = 1;
            recursion(length, floor +1, charList, usedList, printList);
        }
    }else{
        int x = 0;
        for(x = 0; x < length; x++){
            printf("%c", *(printList + x));
        }
        return;
    }
*/


void question25(){
    double pointA[2] = {0};
    double pointB[2] = {0};
    double length[2] = {0};

    printf("�п�J���W���y�СG");
    scanf("%lf%lf", &pointA[0], &pointA[1]);
    printf("�п�J�k�U���y�СG");
    scanf("%lf%lf", &pointB[0], &pointB[1]);
    length[0] = pointA[0] - pointB[0];
    length[1] = pointA[1] - pointB[1];

    if(length[0] == length[1]){
        printf("�O����ΡA����%d�A�e��%d", abs(length[0]), abs(length[1]));
    }else{
        printf("���O����ΡA����%d�A�e��%d", abs(length[0]), abs(length[1]));
    }
}

//bubble sort!!! cannot forget!!!!
void bubbleSort(double *array, int length){
    int x = 0;
    int y = 0;
    for(x = 0; x < length - 1; x++){
        for(y = 0; y < length - 1 - x; y++){
            if(*(array + y) > *(array +y + 1)){
                double temp = 0;
                temp = *(array + y + 1);
                *(array + y + 1) = *(array + y);
                *(array + y) = temp;
            }
        }
    }
}

void question27(){
    FILE *file = fopen("./question27/data.txt", "r");
    double data[1000] = {0};
    int count = 0;
    double median = 0;
    
    printf("Ū��data.txt���e�p�U�G\n");
    while(fscanf(file, "%lf", &data[count]) != EOF){
        printf("%2.2lf ", data[count]);
        count++;
    }
    fclose(file);
    
    bubbleSort(data, 10);
    //notice! the array index is start from 0
    if(count % 2 == 0){
        double firstNum = data[(count / 2) - 1];
        double secondNum = data[(count / 2) + 1 - 1];
        median = (firstNum + secondNum) / 2.00;
        printf("\n����Ƭ�%2.2lf (%2.2lf�P%2.2lf������)", median, firstNum, secondNum);
    }else{
        median = data[(count + 1) / 2 - 1];
        printf("\n����Ƭ�%2.2lf", median);
    }
}

void getZigzagPath(int index, int *location){
    int zigzagPath[8][8] = 
    {{ 1,  2,  6,  7, 15, 16, 28, 29},
     { 3,  5,  8, 14, 17, 27, 30, 43},
     { 4,  9, 13, 18, 26, 31, 42, 44},
     {10, 12, 19, 25, 32, 41, 45, 54},
     {11, 20, 24, 33, 40, 46, 53, 55},
     {21, 23, 34, 39, 47, 52, 56, 61},
     {22, 35, 38, 48, 51, 57, 60, 62},
     {36, 37, 49, 50, 58, 59, 63, 64}};

    int x = 0;
    int y = 0;

    for(y = 0; y < 8; y++){
        for(x = 0; x < 8; x++){
            if(zigzagPath[y][x] == index){
                *location = x;
                *(location + 1) = y;
                break;
            }
        }
    }
}

void question29(){
    FILE *file = fopen("./question29/block.txt", "r");
    int rawData[8][8] = {0};
    int processedData[8][8] = {0};
    int count = 0;
    int targetPos[2] = {0};

    //save the data from block.txt
    printf("Ū�J��block.txt���e��\n");
    while(fscanf(file, "%d", &rawData[count / 8][count % 8]) != EOF){
        printf("%3d" , rawData[count / 8][count % 8]);
        count++;
        if(count % 8 == 0){
            printf("\n");
        }
    }


    //use zigzagPath information to project raw data array to the processed data array
    printf("ZigZag���y���G��\n");
    count = 0;
    while(count < 64){
        getZigzagPath(count + 1, targetPos);
        processedData[targetPos[1]][targetPos[0]] = rawData[count / 8][count % 8];
        count++;
        if(count % 8 == 0){
            printf("\n");
        }
    }

    //print the processed data array to the terminal
    count = 0;
    while(count < 64){
        printf("%3d" , processedData[count / 8][count % 8]);
        count++;
        if(count % 8 == 0){
            printf("\n");
        }
    }

    fclose(file);
}

//subfunction for question 30
int getStudentScore(char studentName[], char studentData[5][100], int scoreData[5]){
    int x = 0;
    int found = 0;
    for(x = 0; x < 4; x++){
        if(strcmp(studentName, studentData[x]) == 0){
            printf("�ӥͦ��Z��%d",scoreData[x]);
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("�䤣��ӦW�ǥ͡I");
    }
}

void question30(){
    char account[] = "admin";
    char password[] = "passwd";
    int finished = 0;
    char student[5][100] = {0};
    int score[5] = {0};
    int x = 0;
    char temp[100] = {0};

    while(finished == 0){
        char tempAccount[100] = {0};
        char tempPassword[100] = {0};
        printf("�п�J�ϥΪ̱b���G");
        scanf("%s", tempAccount);
        printf("�п�J�ϥΪ̱K�X�G");
        scanf("%s", tempPassword); 

        if(strcmp(tempAccount, account) == 0 && strcmp(tempPassword, password) == 0){
            //unknown problem bruhhhhhhhhhhhh ._.
            char sucess[] = "���Ҧ��\\\0";
            finished = 1;
            printf("%s\n", sucess);
        }else{
            printf("���ҥ��ѡA�Э��s��J\n");
        }
    }

    srand(time(NULL));
    for(x = 0; x < 5; x++){
        int temp = 0;
        printf("�п�J�ǥ�%d�m�W�G", x + 1);
        scanf("%s", student[x]);
        temp = rand() % 101;
        score[x] = temp;
        printf("�ӥͦ��Z��%d\n", temp);
    }

    printf("\n�п�J�d�߾ǥͩm�W�G");
    scanf("%s", temp);
    getStudentScore(temp, student, score);
}

void question24(){
    int answer = 0;
    int range[2] = {0, 100};
    int finished = 0;

    printf("���D��J�׷��K�X�G");
    scanf("%d", &answer);
    printf("\n");

    while(finished == 0){
        int guess = 0;
        int inputCorrect = 0;
        printf("���a��J�G");
        scanf("%d", &guess);
        if(guess > range[0] && guess < range[1]){
            inputCorrect = 1;
        }
        while(inputCorrect == 0){
            printf("����϶��A�Э��s��J�G");
            scanf("%d", &guess);
            if(guess > range[0] && guess < range[1]){
                inputCorrect = 1;
            }
        }

        if(guess == answer){
            finished = 1;
        }else if(guess > answer){
            printf("��%d�p\n", guess);
            range[1] = guess;
        }else{
            range[0] = guess;
            printf("��%d�j\n", guess);
        }
    }

    printf("�q��F�A�C���ӧQ�I");
}

//so many possibility that this code cannot deal all the situation
void question26(){
    char calculation[100] = {0};
    char formula[5] = {0};
    int bias = 0;
    int x = 0;

    int side = 0;//0 for left 1 for right
    int left = 0;
    int right = 0;
    int startPrint = 0;

    printf("inputs:\n");
    fflush(stdin);
    scanf("%s", calculation);
    
    
    for(x = 0; x < strlen(calculation); x++){
        if(calculation[x] == '('){
            left++;
        }else if(calculation[x] == ')'){
            right++;
        }
    }

    if(left != right || left == 0 || right == 0){
        printf("output:\nERROR INPUT");
        return;
    }

    for(x = 0; x < strlen(calculation); x++){
        if(calculation[x] == '('){
            left--;
            if(left == 0){
                startPrint = 1;
            }
        }
        if(startPrint == 1){
            formula[bias] = calculation[x];
            bias++;
        }
        if(startPrint == 1 && calculation[x] == ')'){
            break;
        }
    }

    printf("output:\n");
    

    if(formula[2] == '+'){
        printf("%d+%d\n", (formula[1] - '0'), (formula[3] - '0'));
        printf("%d", (formula[1] - '0') + (formula[3] - '0'));
    }else if(formula[2] == '-'){
        printf("%d-%d\n", (formula[1] - '0'), (formula[3] - '0'));
        printf("%d", (formula[1] - '0') - (formula[3] - '0'));
    }else if(formula[2] == '*'){
        printf("%d*%d\n", (formula[1] - '0'), (formula[3] - '0'));
        printf("%d", (formula[1] - '0') * (formula[3] - '0'));
    }
}

void question28(){
    int database[100][100] = {0};
    int datanum = 0;
    while(1){
        int temp = 0;
        int new = 1;
        int x = 0;
        int times = 0;
        printf("��J�G");
        scanf("%d", &temp);

        for(x = 0; x < datanum; x++){
            if(temp == database[x][0]){
                database[x][1]++;
                new = 0;
            }
        }

        if(new == 1){
            database[datanum][0] = temp;
            database[datanum][1] = 1;
            datanum++;
        }

        for(x = 0; x < datanum; x++){
            if(database[x][1] > times){
                times = database[x][1];
            }
        }
        
        printf("���ơG");
        for(x = 0; x < datanum; x++){
            if(database[x][1] == times){
                printf("%d ", database[x][0]);
            }
        }
        printf("(%d)\n", times);
    }
}


int main(){
    question16();
    question17();
    question18();
    question19();
    question20();
    question21();
    question22();
    //wtf question23();
    question24();
    question25();
    question26();
    question27();
    question29();
    question30();
    
}

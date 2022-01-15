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
    printf("請輸入整數n：%d\n",randomNum);

    //3倍數檢驗
    temp = randomNum;
    sum = 0;
    while(temp > 0){
        sum += temp % 10;
        temp /= 10;
    }
    if(sum % 3 == 0){
        printf("是3的倍數\n");
    }

    //11倍數檢驗
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
        printf("是11的倍數\n");
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
        
        printf("使用者A輸入數字：");
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
                printf("輸入錯誤：請輸入4個不同數字的4位數\n");
            }
        }else{
            printf("輸入錯誤：請輸入4位數\n");
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

        //使用者B數字長度驗證
        while(finished == 0){
            printf("使用者B第%2d次猜：",times);
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
                printf("輸入錯誤：請輸入4位數\n");
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
            printf("%dA%dB，遊戲勝利You Win!\n",A,B);
            break;
        }else if(times == 15){
            printf("%dA%dB，遊戲結束You Lose!\n",A,B);
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

    printf("請輸入數字n：");
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
    
    printf("解二元一次方程式：\n");
    printf("輸入a：");
    scanf("%d",&a);
    printf("輸入b：");
    scanf("%d",&b);
    printf("輸入c：");
    scanf("%d",&c);

    answer[0] = (-b + sqrt(pow(b,2) - (4 * a * c))) / (2 * a);
    answer[1] = (-b - sqrt(pow(b,2) - (4 * a * c))) / (2 * a);

    printf("公式解為：%d,%d",answer[0],answer[1]);
}

// binary mode write data and read data;
void question21extend(){
    FILE *source1 = fopen("./question21/source1.txt","w+b");
    int data[] = {64, 128 , 256, 512, 1024, 4096, 8192, 16384};
    int input[100] = {0};
    int dataSize = 0;
    int x = 0;
    
    fwrite(data, sizeof(int), sizeof(data), source1);

    //know how many interger data should deal
    fseek(source1, 0, SEEK_END);
    dataSize = ftell(source1) / 16;
    printf("%d\n", dataSize);

    fseek(source1, 0, SEEK_SET);
    fread(input, sizeof(int), dataSize, source1);
    for(x = 0; x < dataSize; x++){
        printf("%d\n", input[x]);
    }
    
    fclose(source1);

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
    printf("讀入的source.txt內容為\n");
    while(fscanf(source,"%d", &temp) != EOF){
        printf("%d ", temp);
        if(temp % 2 == 0){
            fprintf(even, "%d ", temp);
        }else{
            fprintf(odd, "%d ", temp);
        }
    }
    printf("\n寫入odd.txt內容為\n");
    //don't forget to set the position
    fseek(odd, 0, SEEK_SET);
    while(fscanf(odd, "%d", &temp) != EOF){
        printf("%d ", temp);
    }
    
    fseek(even, 0, SEEK_SET);
    printf("\n寫入even.txt內容為\n");
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

    printf("請輸入學生數n：");
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
    printf("平均：%2.2lf\n",avgScore);
    printf("%d人不及格\n",underScoreCount);
    printf("差：%d\n", highestScore - lowestScore);
    printf("成績：");
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
    printf("請輸入長度：");
    scanf("%d", &length);
    data = malloc(sizeof(char) * length);
    printf("請輸入長度為%d的字串：", length);
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

    printf("請輸入左上角座標：");
    scanf("%lf%lf", &pointA[0], &pointA[1]);
    printf("請輸入右下角座標：");
    scanf("%lf%lf", &pointB[0], &pointB[1]);
    length[0] = pointA[0] - pointB[0];
    length[1] = pointA[1] - pointB[1];

    if(length[0] == length[1]){
        printf("是正方形，長為%d，寬為%d", abs(length[0]), abs(length[1]));
    }else{
        printf("不是正方形，長為%d，寬為%d", abs(length[0]), abs(length[1]));
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
    
    printf("讀取data.txt內容如下：\n");
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
        printf("\n中位數為%2.2lf (%2.2lf與%2.2lf的平均)", median, firstNum, secondNum);
    }else{
        median = data[(count + 1) / 2 - 1];
        printf("\n中位數為%2.2lf", median);
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
    printf("讀入的block.txt內容為\n");
    while(fscanf(file, "%d", &rawData[count / 8][count % 8]) != EOF){
        printf("%3d" , rawData[count / 8][count % 8]);
        count++;
        if(count % 8 == 0){
            printf("\n");
        }
    }


    //use zigzagPath information to project raw data array to the processed data array
    printf("ZigZag掃描結果為\n");
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
            printf("該生成績為%d",scoreData[x]);
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("找不到該名學生！");
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
        printf("請輸入使用者帳號：");
        scanf("%s", tempAccount);
        printf("請輸入使用者密碼：");
        scanf("%s", tempPassword); 

        if(strcmp(tempAccount, account) == 0 && strcmp(tempPassword, password) == 0){
            //unknown problem bruhhhhhhhhhhhh ._.
            char sucess[] = "驗證成功\\0";
            finished = 1;
            printf("%s\n", sucess);
        }else{
            printf("驗證失敗，請重新輸入\n");
        }
    }

    srand(time(NULL));
    for(x = 0; x < 5; x++){
        int temp = 0;
        printf("請輸入學生%d姓名：", x + 1);
        scanf("%s", student[x]);
        temp = rand() % 101;
        score[x] = temp;
        printf("該生成績為%d\n", temp);
    }

    printf("\n請輸入查詢學生姓名：");
    scanf("%s", temp);
    getStudentScore(temp, student, score);
}

void question24(){
    int answer = 0;
    int range[2] = {0, 100};
    int finished = 0;

    printf("關主輸入終極密碼：");
    scanf("%d", &answer);
    printf("\n");

    while(finished == 0){
        int guess = 0;
        int inputCorrect = 0;
        printf("玩家輸入：");
        scanf("%d", &guess);
        if(guess > range[0] && guess < range[1]){
            inputCorrect = 1;
        }
        while(inputCorrect == 0){
            printf("不對區間，請重新輸入：");
            scanf("%d", &guess);
            if(guess > range[0] && guess < range[1]){
                inputCorrect = 1;
            }
        }

        if(guess == answer){
            finished = 1;
        }else if(guess > answer){
            printf("比%d小\n", guess);
            range[1] = guess;
        }else{
            range[0] = guess;
            printf("比%d大\n", guess);
        }
    }

    printf("猜對了，遊戲勝利！");
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
        printf("輸入：");
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
        
        printf("眾數：");
        for(x = 0; x < datanum; x++){
            if(database[x][1] == times){
                printf("%d ", database[x][0]);
            }
        }
        printf("(%d)\n", times);
    }
}


int main(){
    /*
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
    */
    question21extend();
}

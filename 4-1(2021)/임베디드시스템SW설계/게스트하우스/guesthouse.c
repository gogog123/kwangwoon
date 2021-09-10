#include "includes.h"
#include <time.h>

#define TASK_STK_SIZE 512
#define TASK_COUNT	5
#define TASK_PRIO   10

#define N_MSG   1000

//-----이동-----//
INT8U A_move[10];
INT8U B_move[10];
INT8U C_move[10];
INT8U D_move[10];
INT8U E_move[10];
INT8U F_move[10];
INT8U Move_arr[60];

//-----fee, fine, sum-----//
INT64U fee = 0;
INT64U fine = 0;

OS_STK TaskStk[TASK_COUNT][TASK_STK_SIZE]; // Task Stack Memory 지정

//---------------세마포어---------------//
OS_EVENT *sem_partyroom; //파티룸 세마포어
OS_EVENT *sem_kitchen; //주방 세마포어
OS_EVENT* sem_wc; //화장실 세마포어

//------------------큐------------------//
OS_EVENT *msg_q;
void *msg_array[N_MSG];

//----------------Task----------------//
void Task_gusethouse_open(void *data); // 시작 함수
void Task_Checkin(void *data); //게스트 체크인
void Task_Messagequeue_Post(void * data);
void Task_Move(void * data);
void Task_Pay(void* data);
static void Task_Screen();
int random_move();
void Move();
void Remove();

int main (void)
{
    OSInit(); // uC/OS-II 초기화
    
    //semaphore 생성
    sem_partyroom = OSSemCreate(6);
    sem_kitchen = OSSemCreate(4);
    sem_wc = OSSemCreate(1);

    //message queue 생성
    msg_q = OSQCreate(msg_array, (INT16U)N_MSG);
    if(msg_q == 0){
        printf("creating msg_q is faild\n");
        return -1;
    }

    //task 생성
    OSTaskCreate(Task_gusethouse_open, (void *)0, &TaskStk[0][TASK_STK_SIZE - 1], TASK_PRIO);
    
    OSStart(); // 멀티 테스킹 시작

    return 0;
}

void Task_gusethouse_open(void *data){
    Task_Screen(); //화면출력

    while (1) {
        //task 생성
        OSTaskCreate(Task_Checkin, (void*)0, &TaskStk[1][TASK_STK_SIZE - 1], TASK_PRIO + 1); //우선순위 +1
        OSTaskCreate(Task_Move, (void*)0, &TaskStk[3][TASK_STK_SIZE - 1], TASK_PRIO + 3);  //우선순위 +3
        OSTaskCreate(Task_Pay, (void*)0, &TaskStk[4][TASK_STK_SIZE - 1], TASK_PRIO + 4); //우선순위 +4
         
        OSTaskSuspend(TASK_PRIO); //guesthouse_open task 잠시 중단
    }
}

void Task_Checkin(void *data){
    INT8U i;
    INT8U ary[11] = {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3};
    srand(time(NULL));

    PC_DispStr(36, 14, "A", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY); //appear witch
    for(i = 0; i < 10; i++){
        A_move[i] = ary[rand() % 11]; 
    }
    fee += 10000;
    OSTaskResume(TASK_PRIO + 4); //pay출력 task 재개
    OSTimeDly(1); //Try every second

    PC_DispStr(42, 16, "B", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   //appear witch
    for(i = 0; i < 10; i++){
        B_move[i] = ary[rand() % 11]; 
    }
    fee += 10000;
    OSTaskResume(TASK_PRIO + 4); //pay출력 task 재개
    OSTimeDly(1); //Try every second

    PC_DispStr(36, 18, "C", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   //appear witch
    for(i = 0; i < 10; i++){
        C_move[i] = ary[rand() % 11]; 
    }
    fee += 10000;
    OSTaskResume(TASK_PRIO + 4); //pay출력 task 재개
    OSTimeDly(1); //Try every second

    PC_DispStr(57, 14, "D", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   //appear witch
    for(i = 0; i < 10; i++){
        D_move[i] = ary[rand() % 11]; 
    }
    fee += 10000;
    OSTaskResume(TASK_PRIO + 4); //pay출력 task 재개
    OSTimeDly(1); //Try every second

    PC_DispStr(63, 16, "E", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   //appear witch
    for(i = 0; i < 10; i++){
        E_move[i] = ary[rand() % 11]; 
    }
    fee += 10000;
    OSTaskResume(TASK_PRIO + 4); //pay출력 task 재개
    OSTimeDly(1); //Try every second

    PC_DispStr(57, 18, "F", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   //appear witch
    for(i = 0; i < 10; i++){
        F_move[i] = ary[rand() % 11]; 
    }
    fee += 10000;
    OSTaskResume(TASK_PRIO + 4); //pay출력 task 재개
    OSTimeDly(1); //Try every second

    OSTaskCreate(Task_Messagequeue_Post, (void*)0, &TaskStk[2][TASK_STK_SIZE - 1], TASK_PRIO + 2);

    OSTaskSuspend(TASK_PRIO + 1); //check in task 잠시 중단

} //A,B,C,D,E,F 체크인

void Task_Messagequeue_Post(void * data){

    INT8U err;
    INT8U i, j;
    char msg[100];

    for(i = 0; i<10; i++){
        for(j = 0; j < 6; j++){
            if(j == 0){
                sprintf(msg, "A : %d move\n", A_move[i]);
                Move_arr[(i * 6) + j] = A_move[i];
            }
            else if (j == 1){
                sprintf(msg, "B : %d move\n", B_move[i]);
                Move_arr[(i * 6) + j] = B_move[i];
            }
            else if(j == 2){
                sprintf(msg, "C : %d move\n", C_move[i]);
                Move_arr[(i * 6) + j] = C_move[i];
            }
            else if(j == 3){
                sprintf(msg, "D : %d move\n", D_move[i]);
                Move_arr[(i * 6) + j] = D_move[i];
            }
            else if(j == 4){
                sprintf(msg, "E : %d move\n", E_move[i]);
                Move_arr[(i * 6) + j] = E_move[i];
            }
            else if(j == 5){
                sprintf(msg, "F : %d move\n", F_move[i]);
                Move_arr[(i * 6) + j] = F_move[i];
            }

            err = OSQPost(msg_q, msg);

            OSTimeDly(1); //Try every second
        }
    }

    OSTaskResume(TASK_PRIO); //Task_gusethouse_open 재개
}

void Task_Move(void * data) {

    //open file
    FILE* moveLog;
    moveLog = fopen("log.txt", "w");

    INT8U err_q, err_sem;
    void* msg_pend;

    for (int i = 0; i < 60; i++) {

        msg_pend = OSQPend(msg_q, 0, &err_q);
        if (msg_pend != 0) {
            fprintf(moveLog, "%s", msg_pend); // log.txt에 움직임 저장
            fflush(moveLog); // fflush
        }

        if (i >= 6) { //두번째 이동 부터 Post
            if (Move_arr[i - 6] != 0) {
                if (Move_arr[i - 6] == 1)
                    OSSemPost(sem_partyroom); //파티룸 세마포어
                else if (Move_arr[i - 6] == 2)
                    OSSemPost(sem_kitchen);   //주방 세마포어
                else if (Move_arr[i - 6] == 3)
                    OSSemPost(sem_wc);  //화장실 세마포어
            }
        }

        Remove(i % 6); //모두 지우기

        if (Move_arr[i] == 1) {
            INT8U count = OSSemAccept(sem_partyroom);

            if (count > 0) {
            }
            else { //움직이지 못했을때
                Move_arr[i] = 0; 
                fine += 500; //벌금 500원
                OSTaskResume(TASK_PRIO + 4); //pay출력 task 재개
            }
            if (count <= 2) {
                fine += 1000; //벌금 1000원
                OSTaskResume(TASK_PRIO + 4); //pay출력 task 재개
            }

        }
        else if (Move_arr[i] == 2) {
            if (OSSemAccept(sem_kitchen) > 0) {
            }
            else {
                Move_arr[i] = 0;
                fine += 500;//벌금 500원
                OSTaskResume(TASK_PRIO + 4);//pay출력 task 재개
            }
        }

        if (Move_arr[i] == 3) {
            if (OSSemAccept(sem_wc) > 0) { // 획득을 시도, 1이상일 때 세마포어 획득

            }
            else {
                Move_arr[i] = 0;
                fine += 500;//벌금 500원
                OSTaskResume(TASK_PRIO + 4);//pay출력 task 재개
            }
        }

        Move(i % 6, Move_arr[i]); //움직이기

    }

    OSTaskSuspend(TASK_PRIO + 3); //Messagequeue_Post task 잠시 중단
}

void Task_Screen(){
    PC_DispStr(0, 0,  "                                                                                ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
	PC_DispStr(0, 1,  "          <party room>             <kitchen>                 <W.C>              ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
    PC_DispStr(0, 2,  "       -----------------       -----------------       -----------------        ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
    PC_DispStr(0, 3,  "      |                 |     |                 |     |                 |       ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
    PC_DispStr(0, 4,  "      |                 |     |                 |     |                 |       ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
    PC_DispStr(0, 5,  "      |                 |     |                 |     |                 |       ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
    PC_DispStr(0, 6,  "      |                 |     |                 |     |                 |       ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
    PC_DispStr(0, 7,  "      |                 |     |                 |     |                 |       ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
    PC_DispStr(0, 8,  "       -----------------       -----------------       -----------------        ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
    PC_DispStr(0, 9,  "                                                                                ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
    PC_DispStr(0, 10, "                                                                                ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
    PC_DispStr(0, 11, "                                   <room A>             <room B>                ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
	PC_DispStr(0, 12, "                                ---------------      --------------             ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
	PC_DispStr(0, 13, "                               |               |    |              |            ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
	PC_DispStr(0, 14, "                               |               |    |              |            ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
    PC_DispStr(0, 15, "                               |               |    |              |            ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
	PC_DispStr(0, 16, "                               |               |    |              |            ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
    PC_DispStr(0, 17, "                               |               |    |              |            ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
	PC_DispStr(0, 18, "                               |               |    |              |            ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
    PC_DispStr(0, 19, "                               |               |    |              |            ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
	PC_DispStr(0, 20, "                                ---------------      --------------             ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
    PC_DispStr(0, 21, "                                                                                ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);	

    //초기 화면 출력

}

int random_move(){
    INT8U ary[11] = {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3};
    srand(time(NULL));
    
    INT8U pos;
    pos = (INT8U)(rand() % 11); // 0~11까지 랜덤하게 생성

    return ary[pos];
}

void Move(INT8U person, INT8U location){
    if(person == 0){ 
        if (location == 0) {   //room move
            PC_DispStr(36, 14, "A", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   //appear A
        }
        else if(location == 1){  //party room move
            PC_DispStr(10, 4, "A", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);    //appear A
        }
        else if(location == 2){ //kitchen move
            PC_DispStr(34, 4, "A", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);    //appear A
        }
        else if(location == 3){ //wc move
            PC_DispStr(58, 4, "A", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);    //appear A
        }
    }
    else if(person == 1){

        if (location == 0) {   //room move
            PC_DispStr(42, 16, "B", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   //appear B
        }
        else if(location == 1){ //party room move
            PC_DispStr(15, 4, "B", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   //appear B
        }
        else if(location == 2){ //kitchen move
            PC_DispStr(39, 4, "B", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);    //appear B
        }
        else if(location == 3){ //wc move
            PC_DispStr(63, 4, "B", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);    //appear B
        }
    }
    else if(person == 2){
        if (location == 0) {   //room move
            PC_DispStr(36, 18, "C", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   //appear C
        }
        else if(location == 1){ //party room move
            PC_DispStr(20, 4, "C", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   //appear C
        }
        else if(location == 2){ //kitchen move
            PC_DispStr(44, 4, "C", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   //appear C
        }
        else if(location == 3){ //wc move
            PC_DispStr(68, 4, "C", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   //appear C
        }
    }
    else if(person == 3){
        if (location == 0) {   //room move
            PC_DispStr(57, 14, "D", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   //appear D
        }
        else if(location == 1){ //party room move
            PC_DispStr(10, 6, "D", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);    //appear D
        }
        else if(location == 2){ //kitchen move
            PC_DispStr(34, 6, "D", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   //appear D
        }
        else if(location == 3){ //wc move
            PC_DispStr(58, 6, "D", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   //appear D
        }
    }
    else if(person == 4){
        if (location == 0) {   //room move
            PC_DispStr(63, 16, "E", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   //appear E
        }
        else if(location == 1){ //party room move
            PC_DispStr(15, 6, "E", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   //appear E
        }
        else if(location == 2){ //kitchen move
            PC_DispStr(39, 6, "E", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   //appear E
        }
        else if(location == 3){ //wc move
            PC_DispStr(63, 6, "E", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   //appear E
        }
    }
    else if(person == 5){
        if (location == 0) {   //room move
            PC_DispStr(57, 18, "F", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   //appear F
        }
        else if(location == 1){ //party room move
            PC_DispStr(20, 6, "F", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);    //appear F
        }
        else if(location == 2){ //kitchen move
            PC_DispStr(44, 6, "F", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);    //appear F
        } 
        else if(location == 3){ //wc move
            PC_DispStr(68, 6, "F", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);    //appear F
        }
    }
}

//지우기
void Remove(INT8U person){
    if(person == 0){
        PC_DispStr(36, 14, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
        PC_DispStr(10, 4, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
        PC_DispStr(34, 4, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   
        PC_DispStr(58, 4, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   
    } // A가 위치할 수 있는 곳 모두 지우기
    else if(person == 1){
        PC_DispStr(42, 16, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
        PC_DispStr(15, 4, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
        PC_DispStr(39, 4, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
        PC_DispStr(63, 4, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
    } // B가 위치할 수 있는 곳 모두 지우기
    else if(person == 2){
        PC_DispStr(36, 18, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
        PC_DispStr(20, 4, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
        PC_DispStr(44, 4, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   
        PC_DispStr(68, 4, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   
        // C가 위치할 수 있는 곳 모두 지우기
    }
    else if(person == 3){
        PC_DispStr(57, 14, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
        PC_DispStr(10, 6, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
        PC_DispStr(34, 6, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   
        PC_DispStr(58, 6, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   
        // D가 위치할 수 있는 곳 모두 지우기
    }
    else if(person == 4){
        PC_DispStr(63, 16, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
        PC_DispStr(15, 6, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
        PC_DispStr(39, 6, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
        PC_DispStr(63, 6, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
        // E가 위치할 수 있는 곳 모두 지우기
    }
    else if(person == 5){
        PC_DispStr(57, 18, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
        PC_DispStr(20, 6, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
        PC_DispStr(44, 6, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   
        PC_DispStr(68, 6, " ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);   
    } // F가 위치할 수 있는 곳 모두 지우기
}

void Task_Pay() {
    while (1) {
        PC_DispStr(55, 13, "   ", DISP_FGND_BLACK + DISP_BGND_LIGHT_GRAY);
        printf("       SJ GUESTHOUSE\n");
        printf("       fee  : %lld\n", fee);
        printf("     - fine : %lld\n", fine);
        printf("      ----------------------\n");
        printf("       sum  : %lld\n", fee - fine);

        OSTaskSuspend(TASK_PRIO + 4);
    }
}
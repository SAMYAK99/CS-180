#include <stdio.h>
#include <stdlib.h>

typedef struct question_details question_details;

long prize_money[13] = {0, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000, 2500000, 5000000, 10000000, 50000000};
int l_50_50 = 1, l_flip = 1;

struct question_details{
    char* question;
    char* optn[4];
    int correct_optn;
};

question_details q_no[12];

question_details flip_q_no[12];

question_details create_question(char* q, char* optn1, char* optn2, char* optn3, char* optn4, int correct_optn){

    question_details new_question;
    new_question.question = q;
    new_question.optn[0] = optn1;
    new_question.optn[1] = optn2;
    new_question.optn[2] = optn3;
    new_question.optn[3] = optn4;
    new_question.correct_optn = correct_optn;

    return new_question;
}

void load_question_bank(){
    q_no[0] = create_question("What is the Capital of Uttarpradesh?", "Kanpur", "Bareily", "Lucknow", "Banaras", 2);
    q_no[1] = create_question("Who is called the Shehenshah of Bollywood?", "Shahrukh Khan", "Amitabh Bachchan", "Raj Kapoor", "Dilip Kumar", 1);
    q_no[2] = create_question("Writer of India's national anthem wrote the national anthem of another nation. Which nation?", "Bangladesh", "Bhutan", "Nepal", "Pakistan", 0);
    q_no[3] = create_question("From which two stations the first train in India was run?", "Mumbai-Chennai", "Mumbai-Pune", "Mumbai-Delhi", "Mumbai-Thane", 3);
    q_no[4] = create_question("The P in PTI, a short form of Indian news agency is?", "Print", "Press", "Publication", "Prime", 1);
    q_no[5] = create_question("When was Soviet Union disintegrated?", "1984", "1992", "1988", "1991", 4);
    q_no[6] = create_question("Who was India's first finance minister?", "R.K. Shanumukham Chetty", "John Mathai", "K.C. Neogy", "Jawaharlal Nehru", 0);
    q_no[7] = create_question("In which year did the Bhopal gas tragedy happen?", "1994", "1992", "1988", "1984", '4');
    q_no[8] = create_question("Who was the first ODI wicketkeeper of India?", "Surinder Khanna", "Farookh Engineer", "Bharath Reddy", "Kiran More", 1);
    q_no[9] = create_question("Who was the first person to be born in the continent of Antarctica?", "Nathaniel Palmar", "Emilio Palma", "James Weddel", "Charles Wikes", 1);
    q_no[10] = create_question("In which jail did Pandit Nehru write the 'Discovery of India'?", "Ahmdabad", "Tihar", "Ahmadnagar", "Gandhinagar", 2);
    q_no[11] = create_question("Who is the author of 'I do what I do'?", "Dr. Manmohan Singh", "Salman Rushdie", "Raghuram Rajan", "Ramchand Guha", 2);

    flip_q_no[0] = create_question("XWhat is the Capital of Uttarpradesh?", "Kanpur", "Bareily", "Lucknow", "Banaras", 2);
    flip_q_no[1] = create_question("XWho is called the Shehenshah of Bollywood?", "Shahrukh Khan", "Amitabh Bachchan", "Raj Kapoor", "Dilip Kumar", 1);
    flip_q_no[2] = create_question("XWriter of India's national anthem wrote the national anthem of another nation. Which nation?", "Bangladesh", "Bhutan", "Nepal", "Pakistan", 0);
    flip_q_no[3] = create_question("XFrom which two stations the first train in India was run?", "Mumbai-Chennai", "Mumbai-Pune", "Mumbai-Delhi", "Mumbai-Thane", 3);
    flip_q_no[4] = create_question("XThe P in PTI, a short form of Indian news agency is?", "Print", "Press", "Publication", "Prime", '2');
    flip_q_no[5] = create_question("XWhen was Soviet Union disintegrated?", "1984", "1992", "1988", "1991", 4);
    flip_q_no[6] = create_question("XWho was India's first finance minister?", "R.K. Shanumukham Chetty", "John Mathai", "K.C. Neogy", "Jawaharlal Nehru", 0);
    flip_q_no[7] = create_question("XIn which year did the Bhopal gas tragedy happen?", "1994", "1992", "1988", "1984", '4');
    flip_q_no[8] = create_question("XWho was the first ODI wicketkeeper of India?", "Surinder Khanna", "Farookh Engineer", "Bharath Reddy", "Kiran More", 1);
    flip_q_no[9] = create_question("XWho was the first person to be born in the continent of Antarctica?", "Nathaniel Palmar", "Emilio Palma", "James Weddel", "Charles Wikes", 1);
    flip_q_no[10] = create_question("XIn which jail did Pandit Nehru write the 'Discovery of India'?", "Ahmdabad", "Tihar", "Ahmadnagar", "Gandhinagar", 2);
    flip_q_no[11] = create_question("XWho is the author of 'I do what I do'?", "Dr. Manmohan Singh", "Salman Rushdie", "Raghuram Rajan", "Ramchand Guha", 2);
}

void display_rules(){

    printf("<--------------------------------WELCOME TO KBC!------------------------------------>\n\n");
    printf("There will be 12 levels and 3 intermediate levels with prize money as given below :\n\n");
    int i, c = 1;
    for(i=0; i<12; i++){
        printf("Level : %d\tPrize Money : Rs. %ld", i+1, prize_money[i]);
        if(i == 2 || i == 5 || i == 8){
            if(i == 2)
                printf("\t");
            printf("\tIntermediate Level %d", c);
            c++;
        }
        printf("\n");
    }
    printf("\nRULES : 1)If you give a wrong answer, your final prize money will be the prize money of last intermediate level you won.\n");
    printf("\t2) If you quit the game, your final prize money will be the prize money of the last level you won.\n\n");
    printf("Your available lifelines are:\n");
    printf("1. 50-50 :\t This lifeline will omit two wrong answers from the 4 options.\n");
    printf("2. Flip the question :\t This lifeline will replace the question with another question for the same prize money.\n");
    printf("NOTE : You can use each lifeline only once. You may use both the lifelines in the same level\n\n");
}

void display_current_level_details(int i){
    printf("Level : %d\t\tPrize Money : Rs. %ld\n", i+1, prize_money[i]);
    printf("---------------------------------------------------\n");
    printf("Available Lifelines :");
    if(l_50_50)
        printf("\t50-50");
    if(l_flip)
        printf("\tFlip the question");
    if(l_50_50 == 0 && l_flip == 0)
        printf("\tNone :(");
    printf("\n--------------------------------------------------\n");
}

int display_question_no(int i){
    printf("\nQ%d) %s\n", i+1, q_no[i].question);
    return q_no[i].correct_optn;
}

int display_flip_question_no(int i){
    printf("\nQ%d) %s\n", i+1, flip_q_no[i].question);
    return flip_q_no[i].correct_optn;
}

void display_option_no(int i, int j){
    printf("%d) %s\n", j+1, q_no[i].optn[j]);
}

void display_flip_option_no(int i, int j){
    printf("%d) %s\n", j+1, flip_q_no[i].optn[j]);
}

void display_input_options(){
    printf("\n[ Enter 1 for option A, 2 for option B, 3 for Option C & 4 for option D ]\n");
    if(l_50_50 !=0)
        printf("[ Enter x to choose lifeline '50-50' ]\n");
    if(l_flip !=0)
        printf("[ Enter y to choose lifeline 'Flip the question' ]\n");
    printf("[ Enter q to quit the game ]\n\n");
}

void lifeline_50_50(int i){
    int c = q_no[i].correct_optn;
    int rand_optn = rand()%3;
    while(rand_optn == c){
       rand_optn = rand()%3;
    }
    if(c < rand_optn){
        display_option_no(i, c);
        display_option_no(i, rand_optn);
    }else{
        display_option_no(i, rand_optn);
        display_option_no(i, c);
    }
    l_50_50 = 0;
}

int play_game(){
    int i, j, current_inter_level=0, correct_optn;
    char ch;
    for(i=0; i<12; i++){
        system("cls");
        display_current_level_details(i);
        correct_optn = display_question_no(i);
        for(j=0; j<4; j++)
            display_option_no(i, j);
        display_input_options();
        ch = getchar();
        getchar();
        if(ch == 'x' || ch == 'X'){
            printf("\nComputer, please remove two wrong answers\n\n");
            lifeline_50_50(i);
            display_input_options();
            ch = getchar();
            getchar();
        }
        if(ch == 'y' || ch == 'Y'){
            system("cls");
            display_current_level_details(i);
            correct_optn = display_flip_question_no(i);
            for(j=0; j<4; j++)
                display_flip_option_no(i, j);
            display_input_options();
            ch = getchar();
            getchar();
        }
        if(ch == 'q' || ch == 'Q'){
            printf("\nYou have quit the game!\n");
            return i;
        }
        if(ch-49 == correct_optn){
            printf("Correct Answer!!\nYou have won Rs. %ld\n", prize_money[i]);
            if(i == 2 || i == 5 || i == 8)
                current_inter_level = i;
            printf("Press ENTER to go to next level\n");
            getchar();
            continue;
        }
        else{
            printf("Wrong Answer!! :(\nPress ENTER to know you final winning amount\n");
            getchar();
            return current_inter_level;
        }
    }
}

int main()
{
    load_question_bank();
    display_rules();
    printf("Press ENTER key to start the game\n");
    getchar();
    int final_level = play_game();
    system("cls");
    printf("\n\n\n");

    if(final_level == 0) {
        printf("Sorry you could not win any amount :( Better luck next time.\n\n\n");
    } else if(final_level == 12) {
        printf("****************  Congratulations ! you have completed all the levels ***********************\n");
        printf("Congratulations! Your final prize money is %ld\n\n\n", prize_money[final_level]);
    } else {
        printf("SORRY your journey ends here \n\n");
        printf("Congratulations! Your final prize money is %ld\n\n\n", prize_money[final_level]);
    }


    return 0;
}

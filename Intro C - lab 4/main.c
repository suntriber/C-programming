#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void clearInputBuffer(void);

void printMenu();

void addOrSubMenu(int choiceOne, char *practiceOrTest);

void additionPractice();

void additionTest();

void subtractionPractice();

void subtractionTest();

void mixedPractice();

void mixedTest();

int generateRandomNumber();

char *positiveFeedBack();

char *negativeFeedBack();

void printTestStatistics(int testData[60], char testSigns[15]);


int main() {
    time_t t;
    srand((unsigned) time(&t));
    int choice;
    char *practiceOrTest[] = {"PRACTICE", "TEST"};
    char *name[20];
    printf("Please enter name:");
    scanf("%s", name);
    printf("Welcome %s!\n", name);
    while (choice != 3) {
        printMenu();
        scanf("%d", &choice);
        if (choice == 1) {
            addOrSubMenu(choice, *practiceOrTest);
        } else if (choice == 2) {
            addOrSubMenu(choice, *(practiceOrTest + 1));
        } else if (choice == 3) {
            printf("Good bye!");
        } else {
            printf("Invalid choice\n");
            clearInputBuffer();
        }
    }
    return 0;
}



void printMenu() {

    printf("*************************************************\n");
    printf("************    WELCOME TO MATH    **************\n");
    printf("******** 1. Practice                   **********\n");
    printf("******** 2. Do a test                  **********\n");
    printf("******** 3. Exit                       **********\n");
    printf("*************************************************\n");
    printf(">> ");
}

void addOrSubMenu(int choiceOne, char *practiceOrTest) {
    int choiceTwo = 0;
    while (choiceTwo != 4) {
        printf("*************************************************\n");
        printf("************  <<    %-9s>>    **************\n", practiceOrTest);
        printf("******** 1. Addition                   **********\n");
        printf("******** 2. Subtraction                **********\n");
        printf("******** 3. Mixed                      **********\n");
        printf("******** 4. Return                     **********\n");
        printf("*************************************************\n");
        printf(">> ");
        scanf("%d", &choiceTwo);
        if (choiceTwo == 1 && choiceOne == 1) {
            additionPractice();
        } else if (choiceTwo == 1 && choiceOne == 2) {
            additionTest();
        } else if (choiceTwo == 2 && choiceOne == 1) {
            subtractionPractice();
        } else if (choiceTwo == 2 && choiceOne == 2) {
            subtractionTest();
        } else if (choiceTwo == 3 && choiceOne == 1) {
            mixedPractice();
        } else if (choiceTwo == 3 && choiceOne == 2) {
            mixedTest();
        } else if (choiceTwo == 4) {
            return;
        } else {
            printf("Wrong input.\n");
            clearInputBuffer();
        }
    }
}


void additionPractice() {
    int counter, numberOne, numberTwo, userAnswer, correctAnswer;
    userAnswer = 0;
    printf("You will now be given 10 questions.\n");
    for (counter = 0; counter < 10; counter++) {
        numberOne = generateRandomNumber();
        numberTwo = generateRandomNumber();
        correctAnswer = numberOne + numberTwo;
        while (userAnswer != correctAnswer) {
            printf("%d + %d = ", numberOne, numberTwo);
            scanf("%d", &userAnswer);
            if (userAnswer == correctAnswer) {
                printf("%s\n", positiveFeedBack());
                break;
            } else {
                printf("%s\n", negativeFeedBack());
                clearInputBuffer();
            }
        }
    }

  system("pause");
}


void subtractionPractice() {
    int counter, numberOne, numberTwo, userAnswer, correctAnswer, temp;
    userAnswer = 0;
    printf("You will now be given 10 questions.\n");
    for (counter = 0; counter < 10; counter++) {
        numberOne = generateRandomNumber();
        numberTwo = generateRandomNumber();
        correctAnswer = numberOne - numberTwo;
        if (correctAnswer < 0) {
            temp = numberOne;
            numberOne = numberTwo;
            numberTwo = temp;
            correctAnswer = numberOne - numberTwo;
        }
        while (userAnswer != correctAnswer) {
            printf("%d - %d = ", numberOne, numberTwo);
            scanf("%d", &userAnswer);
            if (userAnswer == correctAnswer) {
                printf("%s\n", positiveFeedBack());
                break;
            } else {
                printf("%s\n", negativeFeedBack());
                clearInputBuffer();
            }
        }
    }
    system("pause");
}


void mixedPractice() {
    int counter, numberOne, numberTwo, userAnswer, correctAnswer;
    userAnswer = 0;
    char sign;
    printf("You will now be given 10 questions.\n");
    for (counter = 0; counter < 10; counter++) {
        numberOne = generateRandomNumber();
        numberTwo = generateRandomNumber();
        if (numberOne - numberTwo > 0) {
            correctAnswer = numberOne - numberTwo;
            sign = '-';
        } else if (numberOne - numberTwo <= 0) {
            correctAnswer = numberOne + numberTwo;
            sign = '+';
        }
        while (userAnswer != correctAnswer) {
            printf("%d %c %d = ", numberOne, sign, numberTwo);
            scanf("%d", &userAnswer);
            if (userAnswer == correctAnswer) {
                printf("%s\n", positiveFeedBack());
                break;
            } else {
                printf("%s\n", negativeFeedBack());
                clearInputBuffer();
            }
        }
    }
    system("pause");
}


void additionTest() {
    int numberOne, numberTwo, userAnswer, correctAnswer,
            counter, userAnswerCorrect, testStatistics[60];
    char testQuestionSigns[15];
    userAnswer = 0;
    for (counter = 0; counter < 60; counter += 4) {
        numberOne = generateRandomNumber();
        numberTwo = generateRandomNumber();
        correctAnswer = numberOne + numberTwo;

        printf("%d + %d = ", numberOne, numberTwo);
        scanf("%d", &userAnswer);
        if (userAnswer == correctAnswer) {
            userAnswerCorrect++;
        } else {
            clearInputBuffer();
        }
        testStatistics[counter] = numberOne;
        testStatistics[counter + 1] = numberTwo;
        testStatistics[counter + 2] = correctAnswer;
        testStatistics[counter + 3] = userAnswer;
        testQuestionSigns[(counter + 1) / 4] = '+';
    }
    printTestStatistics(testStatistics, testQuestionSigns);
}

void subtractionTest() {
    int numberOne, numberTwo, userAnswer, correctAnswer, temp,
            counter, userAnswerCorrect, testStatistics[60];
    char testQuestionSigns[15];
    userAnswer = 0;
    for (counter = 0; counter < 60; counter += 4) {
        numberOne = generateRandomNumber();
        numberTwo = generateRandomNumber();
        correctAnswer = numberOne - numberTwo;
        if (correctAnswer < 0) {
            temp = numberOne;
            numberOne = numberTwo;
            numberTwo = temp;
            correctAnswer = numberOne - numberTwo;
        }
        printf("%d - %d = ", numberOne, numberTwo);
        scanf("%d", &userAnswer);
        if (userAnswer == correctAnswer) {
            userAnswerCorrect++;

        } else {
            clearInputBuffer();
        }
        testStatistics[counter] = numberOne;
        testStatistics[counter + 1] = numberTwo;
        testStatistics[counter + 2] = correctAnswer;
        testStatistics[counter + 3] = userAnswer;
        testQuestionSigns[(counter + 1) / 4] = '-';
    }
    printTestStatistics(testStatistics, testQuestionSigns);
}

void mixedTest() {
    int numberOne, numberTwo, userAnswer, correctAnswer,
            counter, userAnswerCorrect, testStatistics[60];
    char sign, testQuestionSigns[15];
    userAnswer = 0;
    for (counter = 0; counter < 60; counter += 4) {
        numberOne = generateRandomNumber();
        numberTwo = generateRandomNumber();
        if (numberOne - numberTwo > 0) {
            correctAnswer = numberOne - numberTwo;
            sign = '-';
        } else if (numberOne - numberTwo <= 0) {
            correctAnswer = numberOne + numberTwo;
            sign = '+';
        }
        printf("%d %c %d = ", numberOne, sign, numberTwo);
        scanf("%d", &userAnswer);
        if (userAnswer == correctAnswer) {
            userAnswerCorrect++;
        } else {
            clearInputBuffer();
        }
        testStatistics[counter] = numberOne;
        testStatistics[counter + 1] = numberTwo;
        testStatistics[counter + 2] = correctAnswer;
        testStatistics[counter + 3] = userAnswer;
        testQuestionSigns[(counter + 1) / 4] = sign;
    }
    printTestStatistics(testStatistics, testQuestionSigns);
}

int generateRandomNumber() {
    int random = rand() % 100;
    return random;
}


void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

char *positiveFeedBack() {
    char *keepPositive[] = {"Very good!", "Excellent!", "Nice work!", "Well done!", "Great!",
                            "Keep up the good work!"};
    return *(keepPositive + rand() % 6);
}

char *negativeFeedBack() {
    char *keepNegative[] = {"No. Please try again.", "Wrong. Try once again.", "Don't give up!",
                            "No. Keep trying."};
    return *(keepNegative + rand() % 4);
}

void printTestStatistics(int testData[60], char testSigns[15]) {
    int i, temp = 0;
    double percent;
    for (i = 0; i < 60; i += 4) {
        if (testData[i + 2] == testData[i + 3])
            temp++;
    }
    percent = (double) temp / 15;

    printf("Your test result is %d (percentage)\nDetailed questions and answers:\n\n", (int) (percent * 100));
    printf("%-10s%-17s%-20s%-10s\n", "Nr", "Question", "Correct answer", "User answer");

    for (i = 0; i < 60; i += 4) {
        printf("%-10d%2d %c %2d%12d%20d\n", ((i + 1) / 4) + 1, testData[i], testSigns[(i + 1) / 4],
               testData[i + 1], testData[i + 2], testData[i + 3]);
    }
    system("pause");
}

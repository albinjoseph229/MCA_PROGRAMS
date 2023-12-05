#include <stdio.h>

struct Question {
    char text[200];
    char options[4][100];
    int correctAnswer;
};

struct Player {
    char name[100];
    int score;
};

int main() {
    int i, ans, totalPoints = 0;
    char playAgain;
    struct Player player;
    struct Player highScore = {"No one", 0};

    struct Question questions[5] = {
        {"Which one is the first search engine in internet?", {"Google", "Archie", "Wais", "Altavista"}, 1},
        {"Which one is the first web browser invented in 1990?", {"Internet Explorer", "Mosaic", "Mozilla", "Nexus"}, 2},
        {"First computer virus is known as?", {"Rabbit", "Creeper Virus", "Elk Cloner", "SCA Virus"}, 1},
        {"Firewall in computer is used for?", {"Security", "Data Transmission", "Monitoring", "Authentication"}, 0},
        {"Which of the following is not a database management software?", {"Mysql", "Oracle", "cobal", "Sybase"}, 2}
    };

    printf("Welcome to the Game\n\n");

    printf("Enter your name: ");
    scanf("%s", player.name);

    do {
        printf("> Press 7 to start the game\n");
        printf("> Press 0 to quit the game\n");
        printf("> Press 9 to view high score\n");

        scanf("%d", &i);

        if (i == 7) {
            printf("The game has started\n\n");

            for (int q = 0; q < 5; q++) {
                printf("%d) %s\n", q + 1, questions[q].text);
                for (int opt = 0; opt < 4; opt++) {
                    printf("%d)%s\n", opt + 1, questions[q].options[opt]);
                }

                printf("Enter Your Answer: ");
                scanf("%d", &ans);

                if (ans - 1 == questions[q].correctAnswer) {
                    printf("Correct Answer\n");
                    totalPoints += 5;
                } else {
                    printf("Wrong Answer\n");
                }
                printf("You have scored %d points\n\n", totalPoints);

                printf("Enter '0' to quit or any other key to continue: ");
                scanf(" %c", &playAgain);

                if (playAgain == '0') {
                    printf("Exiting the game.\n");
                    break;
                }
            }

            player.score = totalPoints;

            if (player.score > highScore.score) {
                highScore = player;
                printf("Congratulations! You've set a new high score of %d points!\n", player.score);
            }
        } else if (i == 0) {
            printf("The game has ended\n\n");
        } else if (i == 9) {
            printf("\nHigh Score:\n");
            printf("Player: %s\n", highScore.name);
            printf("Score: %d points\n", highScore.score);
        } else {
            printf("Invalid\n\n");
        }
    } while (i != 0);

    return 0;
}

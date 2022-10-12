
/*  Simple GuessTheName program written in C.
    Copyright (C) 2021 Aggelos Tselios.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
char help[512] = "\n\nAvailable commands:\n\"help\" - Displays this.\n\"load\" - Loads an existing game.\n\"start\" - Starts a new game.\n \n All commands are case sensitive.";
char license[1024] = "GuessTheNum Copyright (C) 2021, Aggelos Tselios." \
    "\nThis program comes with ABSOLUTELY NO WARRANTY, to the extend permitted by applicable law." \
    "\nThis is free software, and you are welcome to redistribute it" \
    "\nunder certain conditions; see GPL v3 for details.";

int cmdpr[16];
int nguesses = 1; // We will declare this as a global
		  // variable, so any function can
		  // access it.

int loadgame() {

	printf("Game Saving is under development.");

}

void rstate(void) {

	printf("\n[*] newgame(void) returned %d", nguesses);

}

int newgame(void) {
    int number, guess;
    srand(time(0));
    number = rand()%100 + 1; // Generates a random number between 1 and 100
    // Keep running the loop until the number is guessed
    while (guess!=number) {
        printf("Enter a number (1-100): ");
        scanf("%d", &guess);
        if(guess!=number){
            if (guess>number) {
                puts("\nIncorrect. Try lower.");
                nguesses++;
            } else if (guess<number) {
                puts("\nIncorrect. Go higher.");
                nguesses++;
            } else {
                printf("\nCorrect ! %d tries were recorded.", nguesses);
            }
        }
    }
	return nguesses;
}


void fevent(void) {

	printf("\n%s\n", license);
	printf("\nWelcome to GuessTheNumber, written by @sarrthac on GitHub and improved by @AndroGR.\nPlease contribute to this small program by writing code, updating the documentation and adding graphics / GUI <3\n \nSee github.com/AndroGR/AndroGR/guessthenum/README.md to see how to contribute, and the program needs.\n");
	printf("\n \n");
	printf("Enter a command, \"help\" for help: ");
	if (1) {
		scanf("%s", &cmdpr);

		if (strcmp(cmdpr, "help") == 0) {

			puts(help);

		} else if (strcmp(cmdpr, "start") == 0) {

			puts("Starting new game...");
			newgame();

		} else if (strcmp(cmdpr, "exit") == 0) {

			puts("Press Ctrl+C to exit.");

		} else if (strcmp(cmdpr, "load") == 0) {

			loadgame();

		} else {

			puts("Command not found, try again.");

		}

	}

}
int main(void) {

	system("clear");
	while(1) {
		fevent();
	} return 69;
}

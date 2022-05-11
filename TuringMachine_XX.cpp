#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;

	cout << "Enter string: ";
	getline(cin, input);

	input = "B" + input + "B"; // Append 'B' to either end to represent blank sections of tape

	int i = 1; // Starting at 1 to avoid an out of bounds error
	char state = 'A'; // Initial state is 'A'

	/*
	* The Turing machine will continue transitioning from state to state until it can't.
	* Each state in the TM has a termination rule, breaking the while loop when no other rules apply.
	* In this case, the while loop will terminate and the program will output as invalid.
	*/
	while(state != 'z') {

		// cout << "STRING: "<< input << " | STATE: " << state << " | POINT: " << i << endl; // DEBUG STRING

		/*
		* Turing machine states are represented by switch case statements.
		* Refer to attached diagram for a visual representation of these states.
		*/
		switch (state) {
		case 'A': // Initial state
			if (input.at(i) == 'a') {
				input[i] = 'X';
				i++;
				state = 'B';
			}

			else if (input.at(i) == 'b') {
				input[i] = 'u';
				i++;
				state = 'B';
			}

			else if (input.at(i) == 'Y') {
				i--;
				state = 'E';
			}

			else if (input.at(i) == 'w') {
				i--;
				state = 'E';
			}

			else if (input.at(i) == 'B') { // A blank string is accepted in the language XX.
				i++;
				state = 'Z';
			}

			else state = 'z';
			break;


		case 'B':
			if (input.at(i) == 'a') {
				i++;
			}

			else if (input.at(i) == 'b') {
				i++;
			}

			else if (input.at(i) == 'B') {
				i--;
				state = 'C';
			}

			else if (input.at(i) == 'Y') {
				i--;
				state = 'C';
			}

			else if (input.at(i) == 'w') {
				i--;
				state = 'C';
			}

			else state = 'z';
			break;


		case 'C':
			if (input.at(i) == 'a') {
				input[i] = 'Y';
				i--;
				state = 'D';
			}

			else if (input.at(i) == 'b') {
				input[i] = 'w';
				i--;
				state = 'D';
			}

			else state = 'z';
			break;


		case 'D':
			if (input.at(i) == 'a') {
				i--;
			}

			else if (input.at(i) == 'b') {
				i--;
			}

			else if (input.at(i) == 'X') {
				i++;
				state = 'A';
			}

			else if (input.at(i) == 'u') {
				i++;
				state = 'A';
			}

			else state = 'z';
			break;


		case 'E':
			if (input.at(i) == 'X') {
				i--;
			}

			else if (input.at(i) == 'u') {
				i--;
			}

			else if (input.at(i) == 'B') {
				i++;
				state = 'F';
			}

			else state = 'z';
			break;


		case 'F':
			if (input.at(i) == 'X') {
				input[i] = 'Z';
				i++;
				state = 'G';
			}

			else if (input.at(i) == 'u') {
				input[i] = 'Z';
				i++;
				state = 'H';
			}

			else if (input.at(i) == 'z') {
				i--;
				state = 'J';
			}

			else state = 'z';
			break;


		case 'G':
			if (input.at(i) == 'X') {
				i++;
			}

			else if (input.at(i) == 'u') {
				i++;
			}

			else if (input.at(i) == 'z') {
				i++;
			}

			else if (input.at(i) == 'Y') {
				input[i] = 'z';
				i--;
				state = 'I';
			}

			else state = 'z';
			break;


		case 'H':
			if (input.at(i) == 'X') {
				i++;
			}

			else if (input.at(i) == 'u') {
				i++;
			}

			else if (input.at(i) == 'z') {
				i++;
			}

			else if (input.at(i) == 'w') {
				input[i] = 'z';
				i--;
				state = 'I';
			}

			else state = 'z';
			break;


		case 'I':
			if (input.at(i) == 'X') {
				i--;
			}

			else if (input.at(i) == 'u') {
				i--;
			}

			else if (input.at(i) == 'z') {
				i--;
			}

			else if (input.at(i) == 'Z') {
				i++;
				state = 'F';
			}

			else state = 'z';
			break;


		case 'J':
			if (input.at(i) == 'Z') {
				i--;
			}

			else if (input.at(i) == 'B') {
				i++;
				state = 'K';
			}

			else state = 'z';
			break;


		case 'K':
			if (input.at(i) == 'Z') {
				input[i] = 'B';
				i++;
			}

			else if (input.at(i) == 'z') {
				input[i] = 'B';
				i++;
				state = 'L';
			}

			else state = 'z';
			break;


		case 'L':
			if (input.at(i) == 'z') {
				input[i] = 'B';
				i++;
			}

			else if (input.at(i) == 'B') {
				i--;
				state = 'Z';
			}

			else state = 'z';
			break;


		case 'Z': // Accepting state
			cout << "This string is valid." << endl;
			return 0; // Output 0 for valid string
			break;
		}
	}
	cout << "Invalid string!";
	return 1; // Output 1 for invalid string
}
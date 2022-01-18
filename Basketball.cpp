//============================================================================
// Name        : Basketball.cpp
// Author      : Dennis
// Version     :
// Copyright   : WA
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <stdio.h>

class Team {
public:
	class Player {
	public:

		int attack;
		int defense;
		int stamina;

//		Player() {
//
//		}
//		;
//		~Player() {
//		}
//		;

	};

	Player *player1;
	Player *player2;
	Player *player3;

};

//if player a is stronger than player b in 2 or more categories
bool Outmatched(Team::Player *a, Team::Player *b) {
	if ((a->attack > b->attack && a->defense > b->defense)
			|| (a->attack > b->attack && a->stamina > b->stamina)
			|| (a->defense > b->defense && a->stamina > b->stamina)) {

		return true;
	}
	return false;
}

bool Very_outmatched(Team::Player *a, Team::Player *b) {
	if (a->attack > b->attack && a->defense > b->defense
			&& a->stamina > b->stamina) {

		return true;
	}
	return false;
}

//ideal case where all players are outmatched

bool Ideal(Team *a, Team *b) {
	if (Outmatched(a->player1, b->player1) && Outmatched(a->player2, b->player2)
			&& Outmatched(a->player3, b->player3)) {
		return true;
	}
	return false;
}

bool Incompetent(Team::Player group[9], Team *opponent) {
	Team::Player *ptr = group;
	for (int i = 0; i < 9; i++) {
		//iterate through group array using ptr + i
		if (!Outmatched(ptr + i, opponent->player1)
				|| !Outmatched(ptr + i, opponent->player2)
				|| !Outmatched(ptr + i, opponent->player3)) {
			return false;
		}
	}
	return true;
}

//sort out team of players to find roster
void Sort_team(Team::Player group[9], Team *opponent) {

//	for (int i = 0; i < 9; i++) {
//		//sorts the highest of all three attributes to the top if there is any
//		if (!Very_outmatched(group, group + i)) {
//			//swap positions
//			Team::Player *temp = group;
//			group = group + i;
//			group + i = temp;
//			delete temp;
//		}
//
//	}

//while not ideal condition

	while (!(Very_outmatched(group, opponent->player1)
			&& Very_outmatched(group + 1, opponent->player2)
			&& Very_outmatched(group + 2, opponent->player3))) {

		//for player 1 who we assume to be opponents best player
		for (int i = 0; i < 9; i++) {
			if (Very_outmatched(group + i, opponent->player1)) {

				Team::Player *temp = group;
				group[0] = group[i];
				group[i] = temp;
				delete temp;
				break;
			} else if (Outmatched(group + i, opponent->player1)
					&& Outmatched(group + i, group)
					&& !(Outmatched(group, opponent->player1))) {
				Team::Player *temp = group;
				group[0] = group[i];
				group[i] = temp;
				delete temp;
				break;
			}
		}

		//for player2
		for (int i = 0; i < 9; i++) {
			if (Very_outmatched(group + i, opponent->player2)) {

				Team::Player *temp = group;
				group[0] = group[i];
				group[i] = temp;
				delete temp;
				break;
			} else if (Outmatched(group + i, opponent->player2)
					&& Outmatched(group + i, group)
					&& !(Outmatched(group, opponent->player2))) {
				Team::Player *temp = group;
				group[0] = group[i];
				group[i] = temp;
				delete temp;
				break;
			}
		}

		//for player3
		for (int i = 0; i < 9; i++) {
			if (Very_outmatched(group + i, opponent->player3)) {

				Team::Player *temp = group;
				group[0] = group[i];
				group[i] = temp;
				delete temp;
				break;
			} else if (Outmatched(group + i, opponent->player3)
					&& Outmatched(group + i, group)
					&& !(Outmatched(group, opponent->player3))) {
				Team::Player *temp = group;
				group[0] = group[i];
				group[i] = temp;
				delete temp;
				break;
			}
		}
	}

}

Team Final_select(Team::Player group[9]) {

	//after sorting the group
	Team *final_team = new Team;
	*final_team->player1 = group[0];
	*final_team->player2 = group[1];
	*final_team->player3 = group[2];
	return *final_team;
}

int main() {

	Team::Player roster[9];
	Team *Myteam = new Team();
	Team *opponent = new Team();

	opponent->player1->attack = 4;
	opponent->player1->defense = 5;
	opponent->player1->stamina = 6;

	Sort_team(roster, opponent);
	Final_select(roster);

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

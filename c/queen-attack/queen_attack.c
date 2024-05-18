#include "queen_attack.h"

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
	if (queen_1.row == queen_2.row && queen_1.column == queen_2.column) {
		return INVALID_POSITION;
	}

	if ((queen_1.column > 7  || queen_2.column > 7) && 
		(queen_1.row > 7 || queen_2.row > 7) &&
		(queen_1.row == 0 || queen_2.row == 0)) {
		return INVALID_POSITION;
	}
	
	if (queen_1.row == queen_2.row || queen_1.column == queen_2.column) {
		return CAN_ATTACK;
	}
		

	return INVALID_POSITION;
}

/*
  a b c d e f g h
8 _ _ _ _ _ _ _ _ 8
7 _ _ _ _ _ _ _ _ 7
6 _ _ _ _ W _ _ _ 6
5 _ _ _ _ _ _ _ _ 5
4 _ _ _ _ _ _ _ _ 4
3 _ _ _ _ _ _ _ _ 3
2 _ _ _ _ _ _ B _ 2
1 _ _ _ _ _ _ _ _ 1
  a b c d e f g h

*/

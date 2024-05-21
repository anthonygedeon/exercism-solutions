#include "queen_attack.h"
#include <stdio.h>

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
	if ((queen_1.row == queen_2.row && queen_1.column == queen_2.column) ||
		(queen_1.row >= 8 || queen_2.row >= 8) || 
		(queen_1.column >= 8 || queen_2.column >= 8)) return INVALID_POSITION;

	if (queen_1.row == queen_2.row) return CAN_ATTACK;
	if (queen_1.column == queen_2.column) return CAN_ATTACK;
	
	// diagonal bottom-right
	for (int i = 0; i < 8; i++) {
		int x = queen_1.row - i;
		int y = queen_1.column + i;
		if (x == queen_2.row && y == queen_2.column) 
			return CAN_ATTACK;
	}
	
	// diagonal top-left 
	for (int i = 0; i < 8; i++) {
		int x = queen_1.row + i;
		int y = queen_1.column - i;
		if (x == queen_2.row && y == queen_2.column) 
			return CAN_ATTACK;
	}
	
	// diagonal bottom-left
	for (int i = 0; i < 8; i++) {
		int x = queen_1.row - i;
		int y = queen_1.column - i;
		if (x == queen_2.row && y == queen_2.column) 
			return CAN_ATTACK;
	}

	// diagonal top-right
	for (int i = 0; i < 8; i++) {
		int x = queen_1.row + i;
		int y = queen_1.column + i;
		if (x == queen_2.row && y == queen_2.column) 
			return CAN_ATTACK;
	}

	return CAN_NOT_ATTACK;	
}

#include "queen_attack.h"

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
	if ((queen_1.row == queen_2.row && queen_1.column == queen_2.column) ||
		(queen_1.row <= 0 || queen_2.row <= 0) ||
		(queen_1.column <= 0 || queen_2.column <= 0) || 
		(queen_1.column > 8 || queen_2.column > 8)) return INVALID_POSITION;

	if (queen_1.row == queen_2.row) return CAN_ATTACK;
	if (queen_1.column == queen_2.column) return CAN_ATTACK;

	for (int i = queen_1.row; i < 8; i++) {
	}

	return CAN_NOT_ATTACK;	
}

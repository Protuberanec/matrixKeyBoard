#include "keyBoard.h"

//GPIO_IDR_8
int keysRow[NUM_ROW] = {4,5,6,7};
int keysCol[NUM_COL] = {0,1,2,3};

void GetRowData(int* keyboardStatus) {
	int currentRow = SetNextCol(0x00, false);
	int dataIn = (KEY_IN & 0x0F0) >> 4;
	
	currentRow * dataIn & 0x01 * 1
	currentRow * dataIn & 0x02 >> 1 * 2 
	currentRow * dataIn & 0x04 >> 2 * 3
	currentRow * dataIn & 0x08 >> 3 * 4
	
}

int SetNextCol(int setNumCol, bool next) {
	static int num_col = 0;
	if (next == false) {
		return num_col;
	}
	
	num_col = (++num_col) % NUM_COL;
	if (setNumCol & 0x80)  {
		num_col = (setNumCol & 0x7F) % NUM_COL;
	}
	
	int temp = 1 << keysCol[num_col];
	
	for (int i = 0; i < NUM_COL; i++) {
		KEY_OUT &= ~(1 << keysCol[i]);
	}
	
	KEY_OUT |= temp;
	
	return num_col;
}
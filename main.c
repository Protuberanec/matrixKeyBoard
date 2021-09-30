#include <stm32xx.h>

#include "keyBoard.h"



void (*ptrFunc[NUM_KEYS])(void*);

void process_A1(void*) { }
void process_A2(void*) { }
void process_A3(void*) { }
void process_A4(void*) { }
void process_B1(void*) { }
void process_B2(void*) { }
void process_D4(void*) { }

void ptrInit() {
	ptrFunc[0] = process_A1;
	.
	.
	.
	ptrFunc[15] = process_D4;
}


bool NextCol = true;
void Tim3_IRQHandler() {
	NextCol = true;
}

void GetDataFromMatrix() {
	if (NextCol == false) {
		GetRowData(&isPushedKeys[0]);
		return;
	}
	SetNextCol();
}


void ProcessKeyBoard() {
	static int isPushedKeys[NUM_KEYS] = {0,0};	//результаты нажатых кнопок
	static char isProcessedKeys[NUM_KEYS] = {0};
	GetDataFromMatrix();
	
	for (int i = 0; i < NUM_KEYS; i++) {
		if (isPushedKeys[i] == 1) {
			if (isProcessedKeys[i] == 0) {
				isProcessedKeys[i] = 1;
				//что-то делаем...
				ptrFunc[i]();
			}
		}
	}
}

void DbgKeys() {
	SetNextCol(0x80, false);
	GetRowData();
	
	
	SetNextCol(0x81, false);
	GetRowData();
	
	SetNextCol(0x82, false);
	GetRowData();

}

int main() {
	
	while(1) {
		DbgKeys();
		ProcessKeyBoard();
	}
	return 0;
}
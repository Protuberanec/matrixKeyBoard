#ifndef _keyBoard_h_
#define _keyBoard_h_

#define NUM_ROW	4
#define NUM_COL	4
#define NUM_KEYS	(NUM_COL * NUM_ROW)


#define PORT_IN	GPIOA
#define PORT_OUT	GPIOA

#define KEY_IN	(PORT_IN->IDR)
#define KEY_OUT	(PORT_OUT->ODR)

void GetRowData(int* keyboardStatus);
void SetNextCol();



#endif	/*_keyBoard_h_*/
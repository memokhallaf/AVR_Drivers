#include"LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HLCD_interface.h"
int main(void)
{
	hlcd_init();


	hlcd_creatCustomChar();
	hlcd_creatCustomChar1();

	hlcd_setCursor(ROW_0, COL_2);

	hlcd_displayCustomChar();
	hlcd_displayString("I LOVE YOU");
	hlcd_displayCustomChar();


	hlcd_setCursor(ROW_1, COL_2);
	hlcd_displayCustomChar1();
	hlcd_setCursor(ROW_1, COL_13);
	hlcd_displayCustomChar1();


	while(1);
	return 0;
}


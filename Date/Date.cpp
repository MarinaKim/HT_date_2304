#include"Date.h"
bool visokGod(int yy) {
	return (yy % 4 == 0 && yy % 100 != 0 && yy % 400 == 0);
}
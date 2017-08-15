#include "controller.h"

float **fingerPos;

int main() {
	while(1) {
	ex();
	for (int i = 0; i < 10; i++) {
		std::cout << "[ " << fingerPos[i][0] << ", " << fingerPos[i][1] << ", " << fingerPos[i][2] << " ]" << std::endl;
	}
	}
	return 0;
}
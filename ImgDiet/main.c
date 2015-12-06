// FORKED FROM HzImg

#include "main.h"


int main() {
	imgPot * test = Create_imgPot("lena_512x512.raw", 512, 512);
	imgPot * DFT_test = ForwardDCT(test);
	store_ImgPot(DFT_test, "Hz.raw", 64);



	//  비교


	//  소멸자
	BASH_STOP

		return 0;
}


#include "CmpData.h"

double MSEcmp(imgPot * src, imgPot * dst) {
	int ww, hh;
	int width, height;
	double temp, sum,divid;

	if(dst->width != src->width || dst->height != src->height)return 1.00;
	width = src->width;
	height = src->height;
	divid = (double)1.00 / (height*width);

	sum = 0.00;
	for (hh = 0; hh < height; ++hh) {
		for (ww = 0; ww < width; ++ww) {
			temp = (double)(src->data[hh*width + ww]) - (double)(dst->data[hh*width + ww]);
			if (temp < 0)temp = temp*(-1.00);
			sum = sum + (temp*temp/ divid);
		}
	}
	return sum;
}

double PSNRcmp(imgPot * src, imgPot * dst) {
	double mse = MSEcmp(src, dst);
	double MAX2ORI = 255 * 255;
	double temp = log10(MAX2ORI / mse) * 10.00;
	return temp;
}
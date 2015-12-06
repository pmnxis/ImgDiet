#include "DCT.h"

imgPot * ForwardDCT(imgPot * src) {
	int districtW, districtH;
	int dw, dh;  // distrct (Inter) width, district (inter) Height
	int iw, ih;  //  intra width, intra Height
	int m, n;
	double cu, cv;
	double NCF = 1.0 / sqrt(2);  //  Normalized Coeff
	double temp, result;

	imgPot * newElement = (imgPot *)calloc(1, sizeof(imgPot));

	newElement->data = (uint8_t *)calloc(src->width*src->height, sizeof(uint8_t));
	newElement->width = src->width;
	newElement->height = src->height;

	//double * ddata = calloc(src->height*src->width, sizeof(double));

	districtW = (int)(newElement->width / 8);
	districtH = (int)(newElement->height / 8);

	for (dh = 0; dh<districtH; dh++)
	{
		for (dw = 0; dw<districtW; dw++)
		{
			for (ih = 0; ih<8; ih++)
			{
				for (iw = 0; iw < 8; iw++)
				{
					temp = 0.00;
					for (m = 0; m < 8; m++)
					{
						for (n = 0; n < 8; n++)
						{
							temp += cos((((2.00 * (double)m + 1.00)*(double)ih*M_PI) / 16.00))*cos((((2.00 * (double)n + 1.00)*(double)iw*M_PI) / 16.00))*((double)src->data[((dh * 8) + m)*(src->width) + (dw * 8) + n]);
						}
					}
					if (ih == 0) { cu = NCF; }
					else { cu = 1.0; }

					if (iw == 0) { cv = NCF; }
					else { cv = 1.0; }
					//printf("%d , %d 8x8 , %d %d: %lf  - cucv: %lf , %lf , %lf \n", dh, dw, ih, iw, temp, cu , cv , (cu*cv));


					result = temp*(cu*cv);
					newElement->data[((dh * 8) + ih)*(newElement->width) + (iw * 8) + iw] = reviseUINT8(result);
					//ddata[((dh * 8) + ih)*(newElement->width) + (iw * 8) + iw] = result;

				}
			}
		}
	}
	printf("Foward DCT end \n");
	return newElement;
}

imgPot * InverseDCT(imgPot * src) {
	int districtW, districtH;
	int dw, dh;  // distrct (Inter) width, district (inter) Height
	int iw, ih;  //  intra width, intra Height
	int m, n;
	double cu, cv;
	double NCF = 1 / sqrt(2);  //  Normalized Coeff
	double temp;
	//  double real, imag;  /*  실수, 허수  */

	imgPot * newElement = (imgPot *)calloc(1, sizeof(imgPot));
	newElement->data = (uint8_t *)calloc(src->width*src->height, sizeof(uint8_t));
	newElement->width = src->width;
	newElement->height = src->height;

	districtW = (int)(newElement->width / 8);
	districtH = (int)(newElement->height / 8);


	for (dh = 0; dh<districtH; dh++) // i
	{
		for (dw = 0; dw<districtW; dw++) // j
		{
			for (ih = 0; ih<8; ih++)  // k
			{
				for (iw = 0; iw<8; iw++) // l
				{
					temp = 0.0;
					for (m = 0; m<8; m++)
					{
						for (n = 0; n<8; n++)
						{
							if (ih == 0) { cu = NCF; }
							else { cu = 1.0; }

							if (iw == 0) { cv = NCF; }
							else { cv = 1.0; }
							//  
							temp += ((cu*cv) / 4)*cos((((2 * (double)m + 1)*(double)dh*M_PI) / 16))*cos((((2 * (double)n + 1)*(double)iw*M_PI) / 16))*src->data[((dh * 8) + ih)*(src->width) + (dw * 8) + iw];
						}
					}
					newElement->data[((dh * 8) + m)*(newElement->width) + (dw * 8) + n] = (unsigned char)reviseUINT8(temp);
				}
			}
		}
	}
	return newElement;
}

#pragma once
#pragma once
#include "HzImg.h"


extern imgPot * ForwardDCT(imgPot * src);
extern imgPot * InverseDCT(imgPot * src);

extern doublePot * ForwardDCT_double(imgPot * src);
extern imgPot * InverseDCT_double(doublePot * src);

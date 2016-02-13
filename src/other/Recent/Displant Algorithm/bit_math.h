
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
unsigned char _BitScanFront32(
	uint32_t *index,
	uint32_t mask
	);

uint8_t _BitScanRight32(
	uint32_t *index,
	uint32_t mask
	);
int ceil_log2(unsigned long x);
double fast_sqrt_low(double _param);
double fast_sine_low(double _param);
// Convert Image to Gray at CPU
inline void ConvertImageToGrayCpu(unsigned char* imageRGBA, int width, int height) {


	struct Pixel
	{
		unsigned char red, green, blue, alpha;
	};
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			/*  Color to Grayscale Equation
			 Ylinear = 0.2126RLinear + 0.7152GLiners +0.0722BLiners */
			Pixel* ptrPixel = (Pixel*)&imageRGBA[y * width * 4 + 4 * x];
			unsigned char pixelValue = (unsigned char)(ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel->blue * 0.0722f);

			//float pixelValue = ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel-> blue * 0.0722f;
			//unsigned char pixelValue = pixelValue;
			ptrPixel->red = pixelValue;
			ptrPixel->green = pixelValue;
			ptrPixel->blue = pixelValue;
			ptrPixel->alpha = 255;

		}
	}

}

inline void ConvertImageToRed(unsigned char* imageRGBA, int width, int height) {


	struct Pixel
	{
		unsigned char red, green, blue, alpha;
	};
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			/*  Color to Grayscale Equation
			 Ylinear = 0.2126RLinear + 0.7152GLiners +0.0722BLiners */
			Pixel* ptrPixel = (Pixel*)&imageRGBA[y * width * 4 + 4 * x];
			unsigned char pixelValue = (unsigned char)(ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel->blue * 0.0722f);

			//float pixelValue = ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel-> blue * 0.0722f;
			//unsigned char pixelValue = pixelValue;
			ptrPixel->red = ptrPixel->red * 1;
			ptrPixel->green = ptrPixel->green*0.5f;
			ptrPixel->blue = ptrPixel->blue* 0.5f;
			ptrPixel->alpha = 255;

		}
	}


}

inline void ConvertImageToGreen(unsigned char* imageRGBA, int width, int height) {


	struct Pixel
	{
		unsigned char red, green, blue, alpha;
	};
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			/*  Color to Grayscale Equation
			 Ylinear = 0.2126RLinear + 0.7152GLiners +0.0722BLiners */
			Pixel* ptrPixel = (Pixel*)&imageRGBA[y * width * 4 + 4 * x];
			unsigned char pixelValue = (unsigned char)(ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel->blue * 0.0722f);

			//float pixelValue = ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel-> blue * 0.0722f;
			//unsigned char pixelValue = pixelValue;
			ptrPixel->red = ptrPixel->red * 0.5f;
			ptrPixel->green = ptrPixel->green * 1;
			ptrPixel->blue = ptrPixel->blue * 0.5f;
			ptrPixel->alpha = 255;

		}
	}


}

inline void ConvertImageToBlue(unsigned char* imageRGBA, int width, int height) {


	struct Pixel
	{
		unsigned char red, green, blue, alpha;
	};
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			/*  Color to Grayscale Equation
			 Ylinear = 0.2126RLinear + 0.7152GLiners +0.0722BLiners */
			Pixel* ptrPixel = (Pixel*)&imageRGBA[y * width * 4 + 4 * x];
			unsigned char pixelValue = (unsigned char)(ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel->blue * 0.0722f);

			//float pixelValue = ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel-> blue * 0.0722f;
			//unsigned char pixelValue = pixelValue;
			ptrPixel->red = ptrPixel->red * 0.5f;
			ptrPixel->green = ptrPixel->green * 0.5f;
			ptrPixel->blue = ptrPixel->blue * 1;
			ptrPixel->alpha = 255;

		}
	}


}


inline void ConvertImageInv(unsigned char* imageRGBA, int width, int height) {


	struct Pixel
	{
		unsigned char red, green, blue, alpha;
	};
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			/*  Color to Grayscale Equation
			 Ylinear = 0.2126RLinear + 0.7152GLiners +0.0722BLiners */
			Pixel* ptrPixel = (Pixel*)&imageRGBA[y * width * 4 + 4 * x];
			unsigned char pixelValue = (unsigned char)(ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel->blue * 0.0722f);

			//float pixelValue = ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel-> blue * 0.0722f;
			//unsigned char pixelValue = pixelValue;
			ptrPixel->red = ptrPixel->red * -1 + 255;
			ptrPixel->green = ptrPixel->green * -1 + 255;
			ptrPixel->blue = ptrPixel->blue * -1 + 255;
			ptrPixel->alpha = 255;

		}
	}


}







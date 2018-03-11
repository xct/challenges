#include "tiffio.h"
#include "stdio.h"

main(int argc, char* argv[])
{
    TIFF* tif = TIFFOpen(argv[1], "r");
    if (tif) {
	uint32 w, h;
	size_t npixels;
	uint32* raster;

	TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &w);
	TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &h);
	npixels = w * h;
	raster = (uint32*) _TIFFmalloc(npixels * sizeof (uint32));
	if (raster != NULL) {
	    if (TIFFReadRGBAImage(tif, w, h, raster, 0)) {
			printf("%p\n",tif);
	    }
	    _TIFFfree(raster);
	}
	TIFFClose(tif);
    }
}
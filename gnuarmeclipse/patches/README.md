These are small patches required to correct some problems identified in the official packages.

## sdl-image-1.2.10-setjmp.patch

There were too many errors, this patch actually updates the `IMG_png.c` file to the one used in 1.2.12.

## Memo

To create a patch:

	cd top
	cp folder/file folder/file.patched
	vi folder/file.patched
	diff -u folder/file folder/file.patched >my.patch

To apply the patch:

	cd top
	patch -p0 <my.patch

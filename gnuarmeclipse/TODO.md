## All

- make the flash persistent (use a file to save at the end, if it was written)

## System memory
- add flash size
	- F1: 0x1FFFF7E0
	- F1: 0x1FFF7A22
- add device ID
	- F1: 1FFFF7E8 (12 bytes)
	- F4: 1FFF7A10 (12 bytes)
- add content for System Memory
	- F1: 0x1FFFF000-0x1FFFF7FF (2K)
	- F4: 0x1FFF0000-0x1FFF77FF
- add Option bytes


BITS 16
ORG 32768
%INCLUDE "mikedev.inc"

start:
	call os_clear_screen
	mov si, msg
	call os_print_string
	call os_print_newline
	call os_print_string
	ret

	msg:
		db "Hello, World!",0x00

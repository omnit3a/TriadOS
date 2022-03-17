BITS 16
%INCLUDE "mikedev.inc"
ORG 32768

start:
	mov dl, 0
	mov si, 40
	mov di, 23
	call os_clear_screen
        call draw_block
	call draw_block
	call draw_block
	call draw_block
	call draw_block
	call draw_block
	call draw_block
	call draw_block
	call draw_block
	call draw_block
        call draw_block
        call draw_block
        call draw_block
        call draw_block
	sub bl, 0x0F
        call draw_block

	mov si, exit_msg
	call os_print_string
	call os_print_newline
	
	call os_wait_for_key
	call os_clear_screen
	ret
	
draw_block:
	add bl, 0x11
	add dh, 0x01
	call os_draw_block
	ret
exit_msg:
	db "Press any key to exit...",0x00

marquee:
	db "TriadOS",0x00

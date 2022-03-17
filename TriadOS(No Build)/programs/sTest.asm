BITS 16
%INCLUDE "mikedev.inc"
ORG 32768

	mov si, 0x07
start:
	mov ax, 220			; generate a random tone frequency
	mov bx, 420			
	call os_get_random
	push ax
	mov ax, cx
	call os_speaker_tone		; play that tone
	pop ax
	cmp si, 0x00			;repeat 8 times (7 maybe, idk)
	je .end
	dec si
	jmp start

.end:
	ret

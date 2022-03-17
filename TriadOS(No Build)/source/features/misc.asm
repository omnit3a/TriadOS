; ==================================================================
; MikeOS -- The Mike Operating System kernel
; Copyright (C) 2006 - 2019 MikeOS Developers -- see doc/LICENSE.TXT
;
; MISCELLANEOUS ROUTINES
; ==================================================================

; ------------------------------------------------------------------
; os_get_api_version -- Return current version of MikeOS API
; IN: Nothing; OUT: AL = API version number

os_get_api_version:
	mov al, MIKEOS_API_VER
	ret


; ------------------------------------------------------------------
; os_pause -- Delay execution for specified 110ms chunks
; IN: AX = 100 millisecond chunks to wait (max delay is 32767,
;     which multiplied by 55ms = 1802 seconds = 30 minutes)

os_pause:
	pusha
	cmp ax, 0
	je .time_up			; If delay = 0 then bail out

	mov cx, 0
	mov [.counter_var], cx		; Zero the counter variable

	mov bx, ax
	mov ax, 0
	mov al, 2			; 2 * 55ms = 110mS
	mul bx				; Multiply by number of 110ms chunks required 
	mov [.orig_req_delay], ax	; Save it

	mov ah, 0
	int 1Ah				; Get tick count	

	mov [.prev_tick_count], dx	; Save it for later comparison

.checkloop:
	mov ah,0
	int 1Ah				; Get tick count again

	cmp [.prev_tick_count], dx	; Compare with previous tick count

	jne .up_date			; If it's changed check it
	jmp .checkloop			; Otherwise wait some more

.time_up:
	popa
	ret

.up_date:
	mov ax, [.counter_var]		; Inc counter_var
	inc ax
	mov [.counter_var], ax

	cmp ax, [.orig_req_delay]	; Is counter_var = required delay?
	jge .time_up			; Yes, so bail out

	mov [.prev_tick_count], dx	; No, so update .prev_tick_count 

	jmp .checkloop			; And go wait some more


	.orig_req_delay		dw	0
	.counter_var		dw	0
	.prev_tick_count	dw	0


; ------------------------------------------------------------------
; os_fatal_error -- Display error message and halt execution
; IN: AX = error message string location

os_fatal_error:
	call .define_palette
	call os_clear_screen
	mov bx, ax			; Store string location for now

	mov dh, 0
	mov dl, 0
	call os_move_cursor

	mov dh, 0
	mov dl, 0
	call os_move_cursor

	mov si, .msg_inform		; Inform of fatal error
	call os_print_string
	
	mov si, .msg_reboot
	call os_print_string		; This is for printing the error code
	call os_hide_cursor

	jmp $				; Halt execution

	
	.msg_inform		db '>>> FATAL OPERATING SYSTEM ERROR', 13, 10, 0
	.msg_reboot		db '>>> PLEASE REBOOT SYSTEM', 13, 10 ,0
	
.define_palette:
	mov ax, 0x1010			; set color palette
	mov bx, 0x00			; color to define (black)
	mov dh, 0x1F			; Red (0 to 63)
	mov ch, 0x05			; Green ( 0 to 63)
	mov cl, 0x05			; Blue (0 to 63)
	
	int 0x10
	mov ax, 0x1010			; set color palette
	mov bx, 0x07			; color to define (light grey)
	mov dh, 0x3F			; Red (0 to 63)
	mov ch, 0x0A			; Green ( 0 to 63)
	mov cl, 0x0A			; Blue (0 to 63)
	int 0x10
	ret


; ==================================================================


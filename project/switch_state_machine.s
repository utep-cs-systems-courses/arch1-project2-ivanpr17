
	.arch msp430g2553
	.p2align 1,0 		;align memory cells

	.data
switch_state_changed:	
	.word
jt:				;Jump Table
	.word default
	.word case01
	.word case02
	.word case03
	.word case04

	.text
	.global switch_state_machine_assembly
	
switch_state_machine_assembly:
	cmp #5, r12		;checks if in range
	jc default		;if out of range goes to default
	add r12, r12
	mov jt(r12), r0
case01:
	mov.b #1, &switch_state_changed
	call #blinkLEDS
	call #ZeldaTheme
	jmp end

case02:
	mov.b #1, &switch_state_changed
	call #blinkLEDS
	jmp end

case03:
	mov.b #1, &switch_state_changed
	call #blinkLEDS
	call #ZeldaItem
	jmp end

case04:
	mov.b #1, &switch_state_changed
	call #ZeldaItem
	jmp end

default:
	jmp end

end:	ret

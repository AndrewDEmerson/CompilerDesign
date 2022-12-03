prog	START	0
	END	first
.stack variables
stack	RESW	64
stptr	RESW	1
.tmp variables
tempAreg	RESW	1
. VARIABLE DECLARATIONS
a	RESW	1
b	RESW	1
c	RESW	1

. FUNCTION subg
routinesubg	RMO	A,A

. store value in slot g 0
. store value in slot subg 1
. 007 subg:=g*2
	LDX	stptr
	LDA	9,X
	LDS	#2
	MULR	S,A
. emiting storelocal
	LDX	stptr
	STA	12,X
. Return a Value
	LDX	stptr
	LDA	12,X

	.return
	LDX	stptr
	LDL	0, X
	LDT	6, X
	STT	stptr
	RSUB

. FUNCTION subf
routinesubf	RMO	A,A

. store value in slot g 0
. store value in slot subf 1
. 012 subf:=subg(g)-3
. emittingFunctionCall
	LDA	stptr
	SUB	#9
	SUB	#6	.space for local vars
	RMO	A, X
	RMO	A, B
	LDA	stptr
	STA	6, X	.previous frame index
	LDL	#returnpt9829
	STL	0, X	.Return address
	LDA	#1	.value Inserted by compiler
	STA	3, X	.scope
. Add parameters to stack
	LDX	stptr
	LDA	9,X
	RMO	B, X
	STA	9,X
	STB	stptr
	JSUB	routinesubgI
returnpt9829	RMO	A, A
	STA	tempAreg
	LDA	#3
	RMO A,S
	LDS	tempAreg
	SUBR	S,A
. emiting storelocal
	LDX	stptr
	STA	12,X
. Return a Value
	LDX	stptr
	LDA	12,X

	.return
	LDX	stptr
	LDL	0, X
	LDT	6, X
	STT	stptr
	RSUB

. Main Method
first	LDA	#stack
	ADD	#189
	STA	stptr

. 016 b:=5+1
	LDA	#5
	STA	tempAreg
	LDA	#1
	RMO A,S
	LDS	tempAreg
	ADDR	S,A
	STA	b
. 017 a:=b*2+1
	LDA	b
	LDS	#2
	MULR	S,A
	STA	tempAreg
	LDA	#1
	RMO A,S
	LDS	tempAreg
	ADDR	S,A
	STA	a
. 018 c:=subf(4)
. emittingFunctionCall
	LDA	stptr
	SUB	#9
	SUB	#6	.space for local vars
	RMO	A, X
	RMO	A, B
	LDA	stptr
	STA	6, X	.previous frame index
	LDL	#returnpt5587
	STL	0, X	.Return address
	LDA	#1	.value Inserted by compiler
	STA	3, X	.scope
. Add parameters to stack
	LDA	#4
	RMO	B, X
	STA	9,X
	STB	stptr
	JSUB	routinesubfI
returnpt5587	RMO	A, A
	STA	c
. 019 repeatc:=c+1;untilc=50
L001
. 020 c:=c+1
	LDA	c
	STA	tempAreg
	LDA	#1
	RMO A,S
	LDS	tempAreg
	ADDR	S,A
	STA	c
	LDA	c
	LDA	#50
	COMP c
	JEQ L002
	J L001
L002	RMO A, A
. End Of Program, Halt
HALT	J	HALT

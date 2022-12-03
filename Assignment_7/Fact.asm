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
i	RESW	1
j	RESW	1

. Main Method
first	LDA	#stack
	ADD	#189
	STA	stptr

. 005 writeln('Enter any number:')
. 006 readln(j)
. 007 fori:=1tojdo<missing DO>begina:=i*a;fora:=1toadobeginb:=a;end;end
. 017 writeln('Factorial ',j,' is = ',b)
. 018 readln(<missing IDENTIFIER>)
. End Of Program, Halt
HALT	J	HALT

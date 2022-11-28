.class public function1
.super java/lang/Object

.field private static _sysin Ljava/util/Scanner;
.field private static a I
.field private static b I
.field private static calsum I

;
; Runtime input scanner
;
.method static <clinit>()V

	new	java/util/Scanner
	dup
	getstatic	java/lang/System/in Ljava/io/InputStream;
	invokespecial	java/util/Scanner/<init>(Ljava/io/InputStream;)V
	putstatic	function1/_sysin Ljava/util/Scanner;
	return

.limit locals 0
.limit stack 3
.end method

;
; Main class constructor
;
.method public <init>()V
.var 0 is this Lfunction1;

	aload_0
	invokespecial	java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
.end method

;
; FUNCTION sum
;
.method private static sum(II)I

.var 0 is a I
.var 1 is b I
.var 3 is sum I
.var 2 is tempsum I
;
; 015 tempSum:=a+b
;
	iload_0
	iload_1
	iadd
	istore_2
;
; 016 sum:=tempSum
;
	iload_2
	istore_3

	iload_3
	ireturn

.limit locals 4
.limit stack 2
.end method

;
; MAIN
;
.method public static main([Ljava/lang/String;)V
.var 0 is args [Ljava/lang/String;
.var 1 is _start Ljava/time/Instant;
.var 2 is _end Ljava/time/Instant;
.var 3 is _elapsed J

	invokestatic	java/time/Instant/now()Ljava/time/Instant;
	astore_1

;
; 020 a:=5
;
	iconst_5
	putstatic	function1/a I
;
; 021 b:=10
;
	bipush	10
	putstatic	function1/b I
;
; 022 calSum:=sum(a,b)
;
	putstatic	function1/calsum I
;
; 023 writeln(a,' + ',b,' = ',calSum)
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"%d + %d = %d\n"
	iconst_3
	anewarray	java/lang/Object
	dup
	iconst_0
	getstatic	function1/a I
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	dup
	iconst_1
	getstatic	function1/b I
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	dup
	iconst_2
	getstatic	function1/calsum I
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop

	invokestatic	java/time/Instant/now()Ljava/time/Instant;
	astore_2
	aload_1
	aload_2
	invokestatic	java/time/Duration/between(Ljava/time/temporal/Temporal;Ljava/time/temporal/Temporal;)Ljava/time/Duration;
	invokevirtual	java/time/Duration/toMillis()J
	lstore_3
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"\n[%,d milliseconds execution time.]\n"
	iconst_1
	anewarray	java/lang/Object
	dup
	iconst_0
	lload_3
	invokestatic	java/lang/Long/valueOf(J)Ljava/lang/Long;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop

	return

.limit locals 6
.limit stack 7
.end method

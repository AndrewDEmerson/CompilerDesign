program function1;
const
   concon = 3.141592654;
type
   vector = array [ 1..25] of array [1..10] of real;
   aaa = real;
var
   a, b, calSum : integer;
   
function sum(a, b: integer): integer;
var
   tempSum: integer;

begin
   tempSum := a + b;
   sum := tempSum;
end;

begin
   a := 5;
   b := 10;
   calSum := sum(a, b);
   writeln(a, ' + ', b, ' = ', calSum);
end.
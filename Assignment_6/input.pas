program function1;
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
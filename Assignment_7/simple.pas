program TESTNAME;
var
   a,b,c : integer;

function subg(g: integer): integer;
begin
   subg := g;
end;

function subf(g: integer): integer;
var
   tempSum: integer;
begin
   subf := subg(g);
end;

begin
   str := 'hello world';
   b := 5;
   a := b;
   c := subf(4);
end.
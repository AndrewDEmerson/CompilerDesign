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
   subf := subg(g) + 1;
end;

begin
   b := 5 + 1;
   a := b + 1;
   c := subf(4);
end.
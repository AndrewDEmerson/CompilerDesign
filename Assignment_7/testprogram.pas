program TESTNAME;
var
   a,b,c : integer;

function subg(g: integer): integer;
begin
   subg := g * 2;
end;

function subf(g: integer): integer;
begin
   subf := subg(g) - 3;
end;

begin
   b := 5 + 1;
   a := b * 2 + 1;
   c := subf(4);
   repeat
      c := c + 1;
   until c = 50;
end.
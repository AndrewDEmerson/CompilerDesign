Program HelloWorld;
begin
(*Test to assign to variables*)
  x:=0;
  Y:=5;
  SuperVariableName:=-1;
(*Test Repeat Statement*)
  repeat
    x:=1;
    y:=2;
  until
    y = 2;
(*Test For Statement*)
  for i := 0 to 10 do
    x:= x*10;
(*Test With Statement*)
  with myRecord do
    begin
      rval:=0;
    end
end.
Program HelloWorld;
begin
(*Test to assign to variables*)
  x:=0;
  Y:=5;
  SuperVariableName:=-1;
(*Test Repeat Statement*)
  repeat
    x:=1;
    y:=2
  until
    y = 2
(*Test Case Statement*)
  case grade of
      1 : Apple:=100;
      2: Bannana:=200;
      3,4: Cherry:= 300
   end;     
(*Test While Statement*)
 while x < 10 do
  begin
    if x*2 < 10+3 then
      x:= x+1
    else
      x:=x+2
    y:=y*2;
  end
(*Test For Statement*)
  for i := 0 to 10 do
    x:= x*10
(*Test With Statement*)
  with myRecord do
    begin
      rval:=0;
    end
end.
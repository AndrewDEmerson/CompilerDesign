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
 
(*Test While Statement*)
while x < 10 do
 begin
   if x*2 < 10+3 then
     x:= x+1
   else
     x:=x+2
   y:=y*2;
 end;
end.
program sumdigit;
var  n:string; i:byte; s:word;
begin
readln(n);
s:=0;
for i:=1 to length(n) do s:=s+ord(n[i])-48;
writeln(s);
end.

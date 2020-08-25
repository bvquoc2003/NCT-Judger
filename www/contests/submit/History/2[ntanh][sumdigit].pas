program sumdigit;
var n,m,s: longint;
begin
readln(n);
while n>0 do begin
m:=n mod 10;
s:=s+m;
n:=n div 10;
end;
write(s);
end.

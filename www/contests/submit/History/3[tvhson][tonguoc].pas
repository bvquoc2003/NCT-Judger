program tonguoc;
var n,i,s:double;
begin
readln(n);
s:=0; i:=0;
repeat
i:=i+1;
if (trunc(n) mod trunc(i) = 0) then s:=s+i;
until i=n;
write(trunc(s));
end.

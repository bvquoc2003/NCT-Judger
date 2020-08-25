program Tonguoc;
var i: longint;
    n,s: int64;
begin
readln(n);
for i:=1 to n do
If n mod i = 0 then s:=s+i;
write(s);
end.
program sort;
var a:array[1..100000] of longint;
    n,i,j,tg: longint;
begin
readln(n);
for i:=1 to n do readln(a[i]);
for i:=1 to n-1 do
 for j:=i+1 to n do
  If a[i]>a[j] then begin
   tg:=a[i];
   a[i]:=a[j];
   a[j]:=tg;
  end;
 for i:=1 to n do write(a[i],' ');
end.
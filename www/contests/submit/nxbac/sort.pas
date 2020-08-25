program sort;
type dk=1..1000000; mang = array[1..1000000] of integer;
var i,n,j:dk; tam:integer; a:mang;
begin
readln(n);
for i:=1 to n do read(A[i]);
for i:=1 to n-1 do
for j:=i+1 to n do
if (A[i]>A[j]) then begin tam:=a[i]; A[i]:=a[j]; A[j]:=tam; end;
For i:=1 to n do write(A[i],' ');
end.

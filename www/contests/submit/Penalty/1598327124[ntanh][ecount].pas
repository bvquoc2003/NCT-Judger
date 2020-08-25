Var a:array[1..100000] of integer;
n,i,j,k,dem:integer;
kt:boolean;
begin
readln(n);
for i:=1 to n do
readln(a[i]);
for i:=1 to n do
begin
dem:=0;
for k:=1 to n do
if a[i]=a[k] then inc(dem);
write(dem,' ');
end;
end.

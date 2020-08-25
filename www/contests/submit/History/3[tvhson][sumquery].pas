program Sumquery;
var l,r,s,n,i,j,q: longint;
    a,f:array [0..1000000] of int64;
begin
    readln(n);
    f[0] := 0;
    for i:=1 to n do
    begin
        readln(a[i]);
        f[i]:=f[i-1]+a[i];
    end;
    readln(q);
    for i:=1 to q do
    begin
        readln(l, r);
        A[i]:=f[r]-f[l-1];
    end;
    for i:=1 to q do write(A[i],' ');
end.

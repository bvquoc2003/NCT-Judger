program ecount;
type dk=1..1000000;
var a,s:array[1..1000000] of integer; n,i:dk;
begin
readln(n);
Fillchar(S,SizeOf(s),0);
For i:=1 to n do
begin
   Read(A[i]);
   S[A[i]]:=S[A[i]]+1;
end;
For i:=1 to n do Write(S[A[i]],' ');
end.

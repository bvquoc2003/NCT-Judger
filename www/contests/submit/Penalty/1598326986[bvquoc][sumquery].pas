var n, q, i, l, r: longint;
    a: array[1..200000] of longint;
    psum: array[0..200000] of int64;
begin

    readln(n);
    psum[0] := 0;
    for i:=1 to n do
    begin
        readln(a[i]);
        psum[i] := psum[i-1] + a[i];
    end;
    readln(q);
    for i:=1 to q do
    begin
        readln(l); readln(r);
        writeln(psum[r]-psum[l-1]);
    end;
end.
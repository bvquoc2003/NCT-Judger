var n, i: longint;
    a, cnt: array[1..100000] of integer;
begin
    readln(n);
    for i:=1 to n do 
    begin
        readln(a[i]);
        cnt[a[i]] := cnt[a[i]] + 1;
    end;

    for i:=1 to n do
    begin
        write(cnt[a[i]], ' ');
    end;
end.
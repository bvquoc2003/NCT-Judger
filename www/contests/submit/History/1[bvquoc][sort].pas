var n, i, j: longint;
    a : array[1..100000] of longint;
    cnt : array[-100000..100000] of longint;
    Min, Max: longint;
begin
    readln(n);
    Max := -50000;
    Min :=  50000;
    for i:=1 to n do
    begin
        readln(a[i]);
        cnt[a[i]] := cnt[a[i]] + 1;
        if (Max<a[i]) then Max := a[i];
        if (Min>a[i]) then Min := a[i];
    end;
    for i:=Min to Max do
    begin
        if (cnt[i]>0) then
        begin
            for j:=1 to cnt[i] do write(i,' ');
        end;
    end;
end.
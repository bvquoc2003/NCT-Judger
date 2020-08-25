var n, t: int64;
    i, canN: longint;
begin
    readln(n);
    t := 0;
    canN := trunc(sqrt(n));
    for i:=1 to canN do
    if (n mod i = 0) then begin
        t := t + i;
        if (i <> (n div i)) then t := t + (n div i);
    end;
    write(t);
end.
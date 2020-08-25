var n: string;
    i, l, x: integer;
    t: int64;
begin
    readln(n);
    t := 0;
    l := length(n);
    for i:=1 to l do
    begin
        x := ord(n[i])-48;
        t := t + x;
    end;
    write(t);
end.
create or replace function test_query_cursor_simple_nocond() return int as
i int;
begin
    i := 0;
    for r in (select code, name from athlete) loop
        i := r.code;
        EXIT;
    end loop;

    return i;
end;
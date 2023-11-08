declare
	stop number;
	a number := 0;
	b number := 1;
	next number;
begin
	stop := &stop;
	while a < stop loop
		dbms_output.put_line(a);
		next := b;
		b := a + next;
		a := next;
	end loop;
end;
/
